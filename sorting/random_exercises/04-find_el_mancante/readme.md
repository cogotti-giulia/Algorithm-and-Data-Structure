## Esercizio random

Si consideri un array A[1..n], non vuoto, contenente tutti gli interi appartenenti all'insieme {1, 2, ..., n+1}, tranne uno. L'array A è ordinato in senso crescente.

1. Scrivere un algoritmo efficiente che, dato l'array A[1..n], determina il valore mancante. Ad esempio, se A=[1, 2, 3, 4, 6, 7], l'algoritmo deve restituire il valore 5.
2. Determinare il costo computazionale dell'algoritmo di cui al punto 1.

### Idea

```
A: 0 1 2 3 5 6
   0 1 2 3 4 5

med = 2
A[med] = 2 si, allora cerco a destra A[med+1 ... r] [3...5]

med = 4
A[med] != 4 allora vedo se ho violazioni a sinistra A[3...4]

med = 3
A[med] = 3 si, allora A[4...4]

ho trovato l'elemento mancante p = 4

```

### Codice

```c++

int find_elemento_mancante(std::vector<int> a, int p, int r) {
  if (p < r) {
    int med = std::floor((p + r) / 2);

    // se l'elemento a metà non coincide col suo indice
    // cerco a sinistra fino a trovare il primo elemento mancante che sfasa gli
    // indici
    //  altrimenti si troverà a destra se fino ad ora ho tutti gli indici a
    //  posto
    if (a.at(med) != med)
      return find_elemento_mancante(a, p, med);
    else
      return find_elemento_mancante(a, med + 1, r);

  } else {
    // quando p == r ho trovato l'elemento
    return p;
  }
}
```

#### Analisi complessità

Divido l'array in sottoarray sempre più piccoli, ma allora **T(n) = O(nlogn)**