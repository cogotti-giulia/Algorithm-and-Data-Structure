## Esame 01/09/2015 (parte II, esercizio I)

Supponete di avere un min-heap di n elementi, e di cercare il valore massimo. In quali posizioni del vettore cercate? Giustificare la risposta

Scrivere un algoritmo che dato un min-heap non vuoto restituisca il massimo. Calcolare la complessità.

### Idea

Cerco nelle posizioni che vanno dalla parte intera inferiore di n/2 ad n-1. Ovvero nelle foglie. Sono certa che il massimo si troverà lì perché me lo assicura la proprietà di min_heap

> Per ogni nodo i diverso dalla radice **A[ parent(i) ] <= A[ i ]**

### Codice c++

```c++
int find_maximum(const p_heap &A) {
  int index_first_leaf = std::floor(A->heap_size / 2) - 1;
  return find_maximum_AUX(A, index_first_leaf, A->heap_size - 1);
}

int find_maximum_AUX(const p_heap &A, int p, int r) {
  if (p == r) {
    return A->arr.at(p);
  } else if (p < r) {
    int med = std::floor((p + r) / 2);
    int maxSX = find_maximum_AUX(A, p, med);
    int maxDX = find_maximum_AUX(A, med + 1, r);

    return std::max(maxSX, maxDX);
  } else {
    throw "error, heap empty :(";
  }
}
```

#### Analisi complessità

In un heap ci sono n/2 foglie, cerco il massimo in metà array, ma allora **T(n) = O(n)**