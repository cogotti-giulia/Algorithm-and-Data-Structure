## Insertion sort

Utilizza una **tecnica incrementale**, mantenendo _k_ elementi già ordinati ed estendendo la soluzione all'elemento _k+1_.

```

               ___
              v   |
    +---------------------+
    | ordinato  | j |     |
    +---------------------+
```

Ordina **in loco**: in ogni istante **al più** un numero _costante_ di elementi dell'array di input sono registrati all'esterno dell'array.

Inoltre è un algoritmo **stabile**: in presenza di chiavi duplicate mantiene l'ordine originale di esse (utile quando si hanno dati satellite associati alla chiave).

> È un algoritmo sensibile all'ordinamento dei dati in ingresso! 

> Spesso usato per input di piccole dimensioni

### Codice funzione (in pseudocodice)

```pseudocode
# post: ordina A[1...A.length]
insertion_sort(A)
  # sono in pseudocodice, gli indici iniziano da 1
  # il primo elemento è già ordinato (è da solo)
  for j = 2 to A.length
    key = A[j]
    i = j-1
    while i > 0 AND A[i] > key
      A[i+1] = A[i]
      i = i-1;
    A[i+1] = key
```

```
       swap
        _
      |   |
      v   v
    | 5 | 2 | 7 | 3 | 1 |
      i   j

      key = 2   i=1 ~> _ 5 7 3 1
                i=0 ~> 2 5 7 3 1
      ...
    alla fine ottengo

    | 1 | 2 | 3 | 5 | 7 |

```

#### Invariante del ciclo for

INV = il sottoarray A[1 ... j-1] è formato dagli elementi _ordinati_ che originariamente erano in A[1 ... j-1].

_conclusione_<br>
quando il ciclo termina j=A.length+1 e l'INV è vero<br>
INV[A.length+1 / j] = il sottoarray A[1 ... A.length+1-1] è formato dagli elementi ordinati che originariamente erano in A[1 .. A.length+1-1].

ma allora ho ordinato l'array di partenza ottenendo un permutazione degli elementi dell'input di partenza!

#### Analisi complessità

L'algoritmo ordina _in loco_ n elementi, eseguendo nel caso peggiore **Teta(n^2)** confronti.

_dimostrazione_<br>
- ordina in loco perché ha un solo elemento (key) memorizzato fuori dall'array di input
- il ciclo esterno è eseguito n-1 volte ed esegue un numero di **confronti** pari a :
  ``` n               n-1
     E (j-1)     =     E (k) = [(n-1)(n-1+1)]/2 = [n(n-1)]/2 = Teta(n^2)
     j=2         ^    k=1     
                 |
                k = j-1

    dove n = A.length
  ```

Se A è ordinato in verso **non** decrescente allora _T(n) = Teta(n)_, se invece è ordinato in senso inverso (decrescente) allora **T(n) = Teta(n^2)**


### Codice funzione (in c++)

```c++
void insertion_sort(my_array arr) {
  // inizio dall'elemento uno
  // l'elemento in posizione zero si trova già nella porzione ordinata del
  // vettore
  for (int j = 1; j < arr->size; j++) {
    int key = arr->key[j];
    int i = j - 1;
    // sposta i valori lasciando un "buco" nel posto in cui inserire l'elemento
    // con chiave key
    while (i >= 0 && arr->key[i] > key) {
      arr->key[i + 1] = arr->key[i];
      i = i - 1;
    }
    arr->key[i + 1] = key;
  }
}
```

