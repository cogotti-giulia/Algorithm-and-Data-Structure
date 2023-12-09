## Esercizio

Si consideri un array A[1..n] composto da n ≥ 1 numeri reali, non necessariamente ordinato.
1. Scrivere un algoritmo ricorsivo, di tipo divide-et-impera, per determinare il numero di elementi in A il cui valore sia maggiore o uguale a zero;
2. Analizzare il costo computazionale dell'algoritmo proposto.

### Codice c++

```c++
int conta_non_negativi(const std::vector<int> &A, int p, int r) {
  if (p == r)
    return (A.at(p) >= 0) ? 1 : 0;
  else if (p < r) {
    int med = std::floor((p + r) / 2);
    int totSX = conta_non_negativi(A, p, med);
    int totDX = conta_non_negativi(A, med + 1, r);

    return totSX + totDX;
  } else {
    return 0;
  }
}
```


#### Analisi complessità

Se l'array ha uno o zero elementi risolve direttamente, altrimenti effettua due chiamate ricorsive nelle quali l'array viene diviso esattamente a metà, quindi ognuna di esse costa T(n/2) dove n rappresenta il numero di elementi dell'array di input. Si ottiene dunque la seguente ricorrenza risolvibile tramite teorema master.

```
        --- Teta(1)              se n <=1
T(n) = |
        --- 2*T(n/2) + c        se n > 1
```

_teorema master_

a = 2<br>
b = 2<br>
f(n) = c<br>
d = log(b)a = log(2)2 = 1<br>
g(n) = n^d = n^1 = n

confronto asintoticamente f(n) e g(n)

sono nel primo caso! f(n) = O(n^(d-epsilon))<br>
fisso epsilon = 1 e ottengo che f(n) = O(1)

quindi **T(n) = Teta(n)**

