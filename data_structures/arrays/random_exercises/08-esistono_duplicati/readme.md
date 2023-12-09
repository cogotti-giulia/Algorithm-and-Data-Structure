## Esercizio

Si consideri un array A[1..n] composto da n numeri interi; l'array A è ordinato in senso non decrescente. Scrivere un algoritmo divide et impera per decidere se l'array contiene oppure no elementi duplicati.

Analizzare il costo computazionale dell'algoritmo proposto. Secondo voi l'algoritmo potrebbe essere reso asintoticamente più efficiente?

### Codice c++

```c++
bool ha_duplicati(const std::vector<int> &A, int p, int r) {
  if (p < r) { // almeno due elementi
    int med = std::floor((p + r) / 2);
    bool risSX = ha_duplicati(A, p, med);
    bool risDX = ha_duplicati(A, med + 1, r);

    if (A.at(med) == A.at(med + 1))
      return true;
    else
      return risSX || risDX;
  } else {
    return false;
  }
}
```

#### Analisi complessità


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

La complessità non potrebbe essere resa più efficiente in quanto deve essere letto almeno ogni elemento (il duplicato potrebbe essere alla fine), quindi si ha un limite inferiore dato da **Omega(n)**.