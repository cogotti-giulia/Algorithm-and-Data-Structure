## Esame 11/09/2018 (parte II, esercizio II)

Dato un insieme di parole di 4 lettere tale che ciascuna lettera appartiene all’alfabeto inglese {A, ..., X, Y, Z}, ordinare l’insieme in senso decrescente rispetto all’ordinamento lessicografico.

1. Quale algoritmo di ordinamento risulta più adeguato a questo problema? Scrivere l’algoritmo scelto.
2. Analizzare la complessità della soluzione proposta.
3. Simulare l’esecuzione dell’algoritmo scelto sul seguente insieme: `HAND, BUSY, LAMP, ARMS, ZOOM, RING, LAST`

### Idea!

Dato che ho un inseme di parole di dimensione fissa (d = 4) e con lettere in un intervallo finito (k = 27), posso ordinare l'insieme in un tempo lineare utilizzando _radix sort_ e _counting sort_ !

Il radix sort, per ogni cifra (da d a 1) utilizza il counting sort per ordinare sulla i-esima cifra.

Per ogni cifra salvo le lettere di quella in una stringa che poi verrà ordinata salvando. Mi creo anche un vettore in cui salvare la posizione della parola prima di ordinare sulla cifra i (così risalgo subito alla parola intera!). Questo procedimento costa Teta(n) dove n sono il numero di parole nell'insieme

<br>

Poi chiamo il counting sort che in tempo Teta(n) ordina la stringa (cifra i-esima di ogni parola dell'insieme).

Creo un vettore c di dimensione 26 (numero di lettere presenti nell'alfabeto inglese) e lo inizializzo a zero (operazione costante).

Poi scorro la mia stringa di input e per ogni lettera incremento c nella posizione di quella lettera che è data da A[i] - 97 (perché devo traslare di 97 dato che la lettera a in ascii è 97, così mi finirà in posizione zero del vettore, e così tutte le altre vanno nelle posizioni successive!)

```
c[i] = { x in (0...n-1) | A[x]-97 = i}
```

Poi scorro il mio vettore c (in tempo costante dato che ha dimensione fissa) dalla posizione 1 fino alla fine, e sommo i valori a due a due, questo permette di ottenere in posizione i il numero di elementi minori o uguali alla lettera che rappresenta quella posizione del vettore.

```
c[i] = { x in (0...n-1) | A[x]-97 <= i}
```

Infine utilizzo un altro ciclo for per ordinare (scorrendo la stringa dalla fine all'inizio, con costo Teta(n)). La posizione c[(letters_posi[i] - 97)] mi dice quanti elementi minori o uguali alla lettera nella stringa in posizione [i]. Quindi nel mio vettore ordinato dove mi salvo le vecchie posizioni inserisco **i** in posizione c[(letters_posi[i] - 97)]-1 (-1 perché parto da zero). Poi quella posizione di c la decremento dato che ho preso un elemento.

<br>

Torno al mio radix sort, copio gli elementi dell'insieme in un insieme temporaneo (costo Teta(n)), e scorro il vettore delle posizioni ordinate che mi ha modificato il counting sort. Qua dentro metto nelle posizioni di A la stringa presa dalla copia di A in posizione data dal vettore!

### Simulazione

```
0123
hand
busy
lamp
arms
zoom
ring
last

~> cifra d = 3
ordino stringa : dypsmgt
vettore vecchie posizioni (ordinato) : 0542361
 hand
 ring
 zoom
 lamp
 arms
 last
 busy

~> cifra d = 2
ordino stringa : nnommss
vettore vecchie posizioni (ordinato) : 3401256
 lamp
 arms
 hand
 ring
 zoom
 last
 busy

~> cifra d = 1
ordino stringa : araioau
vettore vecchie posizioni (ordinato) : 0253416
 lamp
 hand
 last
 ring
 zoom
 arms
 busy


~> cifra d = 0
ordino stringa : lhlrzab
vettore vecchie posizioni (ordinato) : 5610234
 arms
 busy
 hand
 lamp
 last
 ring
 zoom
```

```
output

<<< sorting from A to Z >>>
arms
busy
hand
lamp
last
ring
zoom
<<< sorting from Z to A >>>
zoom
ring
last
lamp
hand
busy
arms
```

### Codice c++

```c++

constexpr int alphabet = 26;
constexpr int ascii_code_a = 97;
constexpr int ascii_code_z = 122;
constexpr int d = 4;

// T(n) = Teta(n)
void my_counting_sort_fromA_toZ(std::string &letters_posi,
                                std::vector<int> &prev_posi) {
  std::vector<int> c(alphabet);

  int n = letters_posi.size();

  // k volte !
  for (int i = 0; i < alphabet; i++)
    c.at(i) = 0;

  // Teta(n)
  for (int j = 0; j < n; j++)
    c.at((letters_posi.at(j) - ascii_code_a))++;

  // k volte !
  for (int i = 1; i < alphabet; i++)
    c.at(i) = c.at(i) + c.at(i - 1);

  // Teta(n)
  for (int j = n - 1; j >= 0; j--) {
    int index = (letters_posi.at(j) - ascii_code_a);
    prev_posi[c.at(index) - 1] = j;
    c.at(index)--;
  }
}
void my_counting_sort_fromZ_toA(std::string &letters_posi,
                                std::vector<int> &prev_posi) {
  std::vector<int> c(alphabet);

  int n = letters_posi.size();

  // k volte !
  for (int i = 0; i < alphabet; i++)
    c.at(i) = 0;

  // Teta(n)
  for (int j = 0; j < n; j++)
    c.at((ascii_code_z - letters_posi.at(j)))++;

  // k volte !
  for (int i = 1; i < alphabet; i++)
    c.at(i) = c.at(i) + c.at(i - 1);

  // Teta(n)
  for (int j = n - 1; j >= 0; j--) {
    int index = (ascii_code_z - letters_posi.at(j));
    prev_posi[c.at(index) - 1] = j;
    c.at(index)--;
  }
}
void my_radix_sort(std::vector<std::string> &A, bool is_from_A_to_Z) {

  int n = A.size();

  // eseguito d volte
  for (int i = d - 1; i >= 0; i--) {
    std::string letters_posi;
    std::vector<int> prev_posi(n);

    // Teta(n)
    for (int j = 0; j < n; j++)
      letters_posi.push_back(A.at(j).at(i));

    // Teta(n)
    if (is_from_A_to_Z)
      my_counting_sort_fromA_toZ(letters_posi, prev_posi);
    else
      my_counting_sort_fromZ_toA(letters_posi, prev_posi);

    std::vector<std::string> cpy_A = A; // Teta(n)

    // Teta(n)
    for (int k = 0; k < prev_posi.size(); k++)
      A.at(k) = cpy_A.at(prev_posi.at(k));
  }
}
```

#### Analisi complessità

**Counting sort**

Ciclo for per inizializzare il vettore a zero, eseguito un numero costante di volte

```c++
for (int i = 0; i < alphabet; i++)
  c.at(i) = 0;
```

Ciclo for per incrementare le posizioni del vettore corrispondenti alla lettera della stringa, eseguito n volte.

```c++
for (int j = 0; j < n; j++)
  c.at((letters_posi.at(j) - ascii_code_a))++;
```

Ciclo for per sommare gli elementi di c a due a due in modo da ottenere in ogni posizione il numero di elementi minori o uguali ad i, eseguito un numero costante di volte

```c++
  for (int i = 1; i < alphabet; i++)
    c.at(i) = c.at(i) + c.at(i - 1);
```

Ultimo ciclo per ordinare davvero eseguito n volte

```c++
for (int j = n - 1; j >= 0; j--) {
  int index = (letters_posi.at(j) - ascii_code_a);
  prev_posi[c.at(index) - 1] = j;
  c.at(index)--;
}
```

Siano

- n = numero di stringhe presenti nell'insieme da ordinare
- k = costante, dimensione del vettore c

Allora T(n) = Teta(n+k) = **Teta(n)**.

**Radix sort**

Siano

- d = costante, indica il numero di cifre delle stringhe
- n = numero di stringhe presenti nell'insieme da ordinare

- Teta(n) = costo del ciclo for per creare la stringa relativa all'i-esima cifra
  ```c++
  for (int j = 0; j < n; j++)
    letters_posi.push_back(A.at(j).at(i));
  ```
- Teta(n) = costo del counting sort
- Teta(n) = costo del ciclo for per ordinare le stringhe utilizzando il vettore delle posizioni ordinate
  ```c++
  for (int k = 0; k < prev_posi.size(); k++)
    A.at(k) = cpy_A.at(prev_posi.at(k));
  ```

Allora **T(n) = Teta(d \* (n+n+n+n)) = Teta(n)**

> In conclusione, tramite un ordinamento _non_ basato su confronti, è possibile ordinare un inseme di n stringhe di dimensione prefissata in tempo lineare!
