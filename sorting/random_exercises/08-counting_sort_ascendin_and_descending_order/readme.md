## Counting sort in ordine crescente e decrescente

Utilizzato quando i numeri da ordinare sono _interi_ in un **intervallo** (insieme limitato) che va da 0 a k (con k appartenente ai numeri interi).

input: A[1...n], dove A[j] in [0...k] per ogni j in{1,..,n}<br>
output: B[1...n] _ordinato_<br>
memoria ausiliaria: C[0...k] _vettore delle occorrenze_

> **Stabile** se scorro dalla fine dell'array!

In ordine crescente è il classico counting sort, in ordine decrescente basta che utilizzo C accedendo a C[k-A[j]] quindi trattandolo al contrario

### Codice c++

```c++

void counting_sort_descending(std::vector<int> A, std::vector<int> &B, int n,
                              int k) {

  std::vector<int> C(k + 1);

  for (int i = 0; i <= k; i++)
    C.at(i) = 0;

  for (int j = 0; j < n; j++)
    C.at(k - A.at(j))++; //!!!!!!!

  for (int i = 1; i <= k; i++)
    C.at(i) = C.at(i) + C.at(i - 1);

  for (int j = n - 1; j >= 0; j--) {
    C.at(k - A.at(j))--; //!!!!!!!
    B.at(C.at(k - A.at(j))) = A.at(j); //!!!!!!!
  }
}

void counting_sort(std::vector<int> A, std::vector<int> &B, int n, int k) {

  std::vector<int> C(k + 1);

  for (int i = 0; i <= k; i++)
    C.at(i) = 0;

  for (int j = 0; j < n; j++)
    C.at(A.at(j))++;

  for (int i = 1; i <= k; i++)
    C.at(i) = C.at(i) + C.at(i - 1);

  for (int j = n - 1; j >= 0; j--) {
    C.at(A.at(j))--;
    B.at(C.at(A.at(j))) = A.at(j);
  }
}
```



### Analisi complessità

- n dimensione array da ordinare
- k limite superiore intervallo dei numeri dell'array

Il tempo di esecuzione risulta essere **T(n) = Teta(n + k)**. Se _k_ è _costante_ allora il tempo si riduce a _Teta(n)_, ma nello sfortunato caso in cui _k = n^2_ la complessità sale e diventa quadratica (_Teta(n^2)_)
