## Prima prova intermedia 10/01/2023 (esercizio II)

Dato un vettore A di n numeri naturali, scrivere una procedura efficiente che ordini A in modo tale che nel vettore risultante, dati i e j con 1 <= i <= j<=n, vale _mod(A[i], 3) <= mod(A[j], 3)_, dove mod(x, 3) è il resto della divisione di x per 3.

1. Dire se la soluzione proposta è in loco e se è stabile.
2. Valutare e giustificare la complessità della procedura proposta.

### Idea

Utilizzo il merge sort ordinando in base al risultato del modulo. L'algoritmo riesce ad ordinare in tempo **O(nlogn)**, è _stabile_ ma non ordina in loco. Però per quel che mi riguarda preferisco che sia stabile rispetto all'ordine in loco, perché così facendo mantengo l'ordine originali degli elementi dell'array che hanno modulo 3 uguale!

```

Qualche esempio

A: 			3 -1 4 12 2 2 7 
A[i]%3: 0 -1 1 0 2 2 1 

*** SORTING A[i] % 3 ***
A: 			-1 3 12 4 7 2 2 
A[i]%3: -1 0 0 1 1 2 2 

~~~~~~~~~~~~~~~~~~~~~~~~

A: 			36 8 0 99 3 9 6 
A[i]%3: 0 2 0 0 0 0 0 

*** SORTING A[i] % 3 ***
A: 			36 0 99 3 9 6 8 
A[i]%3: 0 0 0 0 0 0 2 
```


### Codice

```c++

void merge_sort_mod3(std::vector<int> *A, int p, int r) {
  if (p < r) {
    int q = std::floor((p + r) / 2);
    merge_sort_mod3(A, p, q);
    merge_sort_mod3(A, q + 1, r);
    merge_mod3(A, p, q, r);
  }
}


void merge_mod3(std::vector<int> *A, int p, int q, int r) {
  int n1 = q - p + 1;
  int n2 = r - q;

  std::vector<int> L(n1);
  std::vector<int> R(n2);

  for (int i = 0; i < n1; i++)
    L.at(i) = A->at(p + i);
  for (int j = 0; j < n2; j++)
    R.at(j) = (A->at(q + 1 + j));

  int k = p;
  int i = 0, j = 0;

  while (k <= r) {
    if (i < n1 && j < n2) {
      if (L.at(i) % 3 <= R.at(j) % 3) {
        A->at(k) = L.at(i);
        i++;
      } else {
        A->at(k) = R.at(j);
        j++;
      }
    } else if (i < n1) {
      A->at(k) = L.at(i);
      i++;
    } else {
      A->at(k) = R.at(j);
      j++;
    }
    k++;
  }
}
```

#### Analisi complessità

La procedura merge_mod3 impiega un tempo pari a **T(n) = Teta(n)**

```
I cicli for per riempire gli array L ed R costano rispettivamente Teta(n1) e Teta(n2), n1 = q-p+1, n2 = r-q
n1 + n2 ~> q - p + 1 + r - q = r - p + 1 = n

Il ciclo while viene eseguito r-p+1 volte che è uguale ad n quindi Teta(n).

ma allora ho T(n) = Teta(n1) + Teta(n2) + Teta(n) = Teta(n) + Teta(n) = Teta(n)
```

La procedura merge_sort_mod3 ha costo **T(n) = Teta(n logn)**

```
Le due chiamate ricorsive sono eseguite entrambe per un tempo pari a T(n/2) dato che divido l'array a metà

Ma quindi ottengo la seguente ricorrenza

        --- c                           n <= 1
T(n) = |
        --- 2T(n/2) + Teta(n)           n > 1

master theorem

a = 2
b = 2
d = log(b) a = log(2) 2 = 1
f(n) = n
g(n) = n^d = n^1 = n

caso II
f(n) = Teta(g(n) = n) 

ma allora T(n) = Teta(n logn)
```
