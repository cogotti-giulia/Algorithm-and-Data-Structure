## Heap sort

Algoritmo di ordinamento basato sulla struttura dati heap. Prende un array, costruisce un max heap a partire dagli elementi dell'array di input, estrae n-1 volte l'elemento massimo e  lo inserisce come ultimo elemento.

### Codice funzione (pseudocode)

```pseudocode
heap_sort(A)
  build_max_heap(A)
  for i=A.length down to 2
    scambia A[1] con A[i]
    A.heap_size = A.heap_size-1
    max_heapify(A, 1)
```

#### Invariante

INV = il sottoarray A[1...i] è un max heap e contiene gli i elementi più piccoli del vettore di partenza A[1...n] e il sottoarray A[i+1...n] contiene gli (n-i) elementi più grandi di A[1...n] ordinati!

_conclusione_<br>
quando il ciclo termina i = 1

INV[1 / i] = il sottoarray A[1] è un max heap e contiene gli i elementi più piccoli del vettore di partenza A[1...n] e il sottoarray A[2...n] contiene gli (n-1) elementi più grandi di A[1...n] ordinati!

ma allora il vettore A è ordinato!

#### Complessità

T(n) = O(n) + O(n logn) = O(n logn)

La build_max_heap impiega un tempo O(n), la max_heapify impiega O(log n) in quanto viene applicata sempre alla radice dell'albero ed è eseguita n-1 volte. 

Quindi nel caso peggiore, l'heap sort effettua **O(n logn)** confronti. 

> _Da notare che il quick sort, in media (con le ottimizzazioni), risulta essere comunque più veloce dell'heap sort!_


### Codice funzione (c++)

```c++
//! T(n) = O(n logn)
void my_heap_sort(p_heap heap) {
  build_max_heap(heap); //? O(n)

  for (int i = heap->length - 1; i > 0; i--) { //? eseguito n-1 volte
    swap(heap, 0, i);
    heap->decrement_heap_size();
    max_heapify(heap, 0); //? applico sempre alla radice, quindi impiega O(logn)
  }
}
```

