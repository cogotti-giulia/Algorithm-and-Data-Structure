## Esame 17/05/2016 (parte II, esercizio II)

Scrivere un algoritmo efficiente che, dato un vettore v di n interi distinti (n≥2), determina una coppia di elementi distinti x e y in v che minimizza | x – y |. Discutere la complessità della soluzione proposta.

### Idea

Ordino l'array perché così la minima distanza si troverà fra coppie successive! Poi lo scorro tutto e trovo il minimo confrontando le coppie successive.

### Codice c++

```c++
int min_distance_abs(std::vector<int> &A, int *x, int *y) {
  int n = A.size();
  my_merge_sort(A, 0, n - 1); // n log n
  print_array(A);

  int i = 0;
  int j = 1;
  int min = A.at(j) - A.at(i);
  *x = A.at(i);
  *y = A.at(j);

  while (j < n - 1) {
    i++;
    j++;

    if ((A.at(j) - A.at(i)) < min) {
      *x = A.at(i);
      *y = A.at(j);
      min = A.at(j) - A.at(i);
    }
  }

  return min;
}
```

#### Analisi complessità

La procedura merge_sort per ordinare impiega un tempo pari a O(n logn). La ricerca del minimo è eseguita in Teta(n) in quanto il ciclo while viene eseguito un numero di volte pari alla dimensione dell'array (-1 ma è costante quindi non conta)

Quindi **T(n) = O(n logn) + Teta(n) = O(n logn)** che è comunque meglio del Teta(n^2) che servirebbe per risolvere il problema senza ordinare!