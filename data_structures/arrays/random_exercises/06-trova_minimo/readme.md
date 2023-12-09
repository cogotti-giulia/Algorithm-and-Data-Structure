## Esercizio

Si consideri il seguente problema: dato un array A[1..n] di n ≥ 1 valori reali non ordinati, restituire il valore minimo in A.

1. Scrivere un algoritmo ricorsivo di tipo divide et impera per risolvere il problema di cui sopra; 
2. Calcolare la complessità asintotica dell'algoritmo proposto, motivando la risposta;

### Codice c++

```c++
int minimum(const std::vector<int>& A, int p, int r){
  if(p == r){
    return A.at(p);
  }else if(p < r){
    int med = std::floor((p+r)/2);
    int minSX = minimum(A, p, med);
    int minDX = minimum(A, med+1, r);

    return std::min(minSX, minDX);
  }else {
    throw "ERRORE! L'array è vuoto, non esiste un elemento minimo";
    exit(false);
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

