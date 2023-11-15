## Merge sort

Utilizza la tecnica del **divide-et-impera** volendo ordinare il sottoarray _A[p...r]_ nel quale inizialmente _p=1_ e _r=A.length=n_:

- divide l'array in due sottoarray A[p...**q**] e A[**q+1**...r] dove _q=floor((p+r)/2)_ (parte intera inferiore)
- impera ordinando i due sottoarray (ricorsivamente) utilizzando il _merge sort_
- combina fondendo insieme i due sottoarray ordinati per generare un singolo array ordinato _A[p...r]_q

Vantaggi del merge sort:
- la complessità è Teta(n logn)
- è stabile: i numeri con lo stesso valore (duplicati) si presentano nell'array di output nello stesso ordine in cui si trovano nell'array di input
  ```
        info:            | 1 | -3 | 1 | 7 | -3 | 8 |       
        dati satellite:  | A |  B | C | D |  E | F |

        dopo l'esecuzione del merge sort

        info:            | -3 | -3 | 1 | 1 | 7 | 8 |       
        dati satellite:  |  B |  E | A | C | D | F |
  ```

Svantaggi del merge sort:
- **non** è in loco, necessita di una memoria aggiuntiva pari a O(n), quindi proporzionale al numero di elementi da ordinare
- **non** è sensibile all'ordinamento degli elementi, il tempo di calcolo dipende solo dal numero di elementi (chiavi) da ordinare


### Codice funzioni (in pseudocodice)

```
merge_sort(A, p, r)
  if p < r  # ho almeno due elementi!
    q = floor((p+r)/2)
    merge_sort(A, p, q)     # T(n/2)
    merge_sort(A, q+1, r)   # T(n/2)
    merge (A, p, q, r)      # Teta(n)
```

```
effetto della merge sort, come lo fa? 
non mi importa, devo pensare solo all'effetto!

A:  | 3 | -1 | 7 | 0 | 12 | 5 |
      p                     r

ottengo i due sottoarray ordinati

    | -1 | 3 | 7 |  e  | 0 | 5 | 12 |
      p        q        q+1      r
```

La funzione di merge prende in ingresso l'array _A_ e gli indici _p, q, r_. Restituisce i due sottoarray fusi in un unico array ordinato A[p...q]. Sono presenti alcuni vincoli sui parametri di input:

- p <= q < r ~> nessuno dei due sottoarray è vuoto!
- il sottoarray A[p...q] è ordinato
- il sottoarray A[q+1...r] è ordinato

Quello che fa è prendere il primo elemento da ciascun sottoarray, confrontarli, prendere il minore e passare al successivo elemento fino a quando l'array non sarà completamente ordinato.

```
merge(A, p, q, r)
  n1 = r-q+1  # numero di elementi in A[p...q]
  n2 = r-q  # numero di elementi in A[q+1...r]

  crea gli array L[1...n1+1] e R[1...n2+1]
  # copio gli elementi dei due sottoarray in L ed R
  for i = 1 to n1
    L[i] = A[p+i-1]
  for j = 1 to n2
    R[j] = A[q+j]

  # valori sentinella, in c++ uso un while 
  # ma qua mi semplifica la scrittura e dimostrazione dell'invariante
  L[n1 + 1] = +inf
  R[n2 + 1] = +inf

  i=1
  j=1
  for k=p to r
    if L[i] <= R[j]
      A[k] = L[i]
      i = i+1
    else
      A[k] = R[j]
      j=j+1
```

#### Simulazione

```
L:  | -1 | 3 | 7 | +inf |
       i

R:  | 0 | 5 | 12 | +inf |
      j

A : | . | . | . | . | . | . |
~> L[i] <= R[j] ? si, allora copio L[i] in A[k] e incremento i

L:  | -1 | 3 | 7 | +inf |
        ~> i

R:  | 0 | 5 | 12 | +inf |
      j

A   | -1 | . | . | . | . | . |
        ~> k

alla fine dell'esecuzione dell'algoritmo:

L:  | -1 | 3 | 7 | +inf |
                     i   

R:  | 0 | 5 | 12 | +inf |
                     j

A   | -1 | 0 | 3 | 5 | 7 | 12 |
```

#### Invariante terzo ciclo for

INV = il sottoarray A[p...k-1] contiene _ordinati_ i k-p elementi più piccoli di L[1...n1+1] e R[1...n2+2]. Inoltre L[i] e R[j] sono i più piccoli elementi dei loro array che **non** sono ancora stati copiati in A.

_conclusione_<br>
quando il ciclo termina k = r+1

INV[r+1 / k] = il sottoarray A[p...r+1-1] contiene _ordinati i  r-p+1 elementi più piccoli di L[1...n1+1] e R[1...n2+2]. Inoltre L[i] e R[j] sono i più piccoli elementi dei loro array che **non** sono ancora stati copiati in A.

Il numero di elementi in L ed R è rispettivamente n1+1 e n2+1. In totale (q-p+1)+1 + (r-q)+1 = r-p+3 _ma_ io ne ho copiati r-p+1. Ma allora ciò significa che ho escluso i valori sentinella.

## Analisi complessità

La complessità risulta essere **T(n) = Teta(n logn)**

```
        --- Teta(1)             n <= 1
T(n) = |
        --- 2T(n/2) + Teta(n)   n > 1
```

Risolvo la ricorrenza tramite il master theorem.

a = 2<br>
b = 2<br>
d = log in base b di a = log(2)2 = 1
f(n) = Teta(n)<br>
g(n) = n^d = n^1 = n

ma allora sono nel secondo caso dove f(n) = Teta(n)

di conseguenza, applicando il teorema, si ha che **T(n) = Teta(n logn)**

### Codice funzione in c++

```c++

//! T(n) = Teta(n logn)
void my_merge_sort(my_elem *arr, int p, int r) {
  if (p < r) { // ho almeno due elementi
    int q = std::floor((p + r) / 2);
    my_merge_sort(arr, p, q);  //? T(n/2)
    my_merge_sort(arr, q + 1, r);   //? T(n/2)

    my_merge(arr, p, q, r);   //? Teta(n)
  }
}

//! T(n) = Teta(n)
void my_merge(my_elem *arr, int p, int q, int r) {
  int n1 = q - p + 1;
  int n2 = r - q;

  my_elem left[n1];  // L[p...q]
  my_elem right[n2]; // R[q+1...r]

  // copia gli elementi di sinistra nell'array L
  for (int i = 0; i < n1; i++)
    left[i] = arr[p + i];

  // copia gli elementi di destra nell'array R
  for (int j = 0; j < n2; j++)
    right[j] = arr[q + 1 + j];

  int i = 0;
  int j = 0;
  int k = p;

  // finché ho elementi nei sottoarray
  while (i < n1 && j < n2) {
    // prende il più piccolo elemento tra i due sottoarray e lo mette nella
    // giusta posizione di A
    if (left[i]->get_key() <= right[j]->get_key()) {
      arr[k] = left[i];
      i++;
    } else {
      arr[k] = right[j];
      j++;
    }
    k++;
  }

  // quando esco dal ciclo while ho finito gli elementi in L oppure in R
  // se uno dei due non è finito, finisco di aggiungere i suoi elementi ad A

  while (i < n1) {
    arr[k] = left[i];
    k++;
    i++;
  }

  while (j < n2) {
    arr[k] = right[j];
    k++;
    j++;
  }
}
```