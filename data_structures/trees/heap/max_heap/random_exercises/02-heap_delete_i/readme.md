## Esame 29/05/2014 (parte II, esercizio I)

L’operazione Heap-Delete(A, i), cancella l’elemento nel nodo i dallo heap A. Implementare la procedura Heap-Delete in modo che il suo tempo di esecuzione sia O(lg n) per un max-heap di n elementi.

### Idea

Scambio l'elemento in posizione i con l'elemento in posizione heap_size e decremento l'heap_size (questo permette di mantenere vera la proprietà dell'heap che afferma che tutti i livelli dell'albero sono riempiti tranne eventualmente l'ultimo nel quale le foglie sono addossate a sinistra). Poi se il valore che ho era maggiore di quello nuovo che ho messo potrei avere un eventuale anomalia verso il basso e quindi applico la max heapify, altrimenti potrei avere anomalia verso l'alto e scambio nodo e parent fino a quando non ho ristabilito l'ordine corretto.


### Codice c++

```c++
void heap_delete(p_heap &A, int i) {
  if (A->heap_size == 1)
    A->heap_size--;
  else {
    int del = A->arr.at(i);
    A->arr.at(i) = A->arr.at(A->heap_size - 1);
    A->heap_size--;
    if (del > A->arr.at(i))
      max_heapify(A, i);
    else {
      while (i > 0 && (A->arr.at(parent(i)) < A->arr.at(i))) {
        my_swap(A, parent(i), i);
        i = parent(i);
      }
    }
  }
}
```

#### Analisi complessità

Dopo aver scambiato l'elemento da eliminare con quello in posizione heap_size (fine dell'array) e aver decrementato l'heap size, si potrebbe verificare un eventuale anomalia verso l'alto o verso il basso. Ma allora o applico la max heapify (verso il basso) o scambio padre e figlio fino a risolvere i problemi (verso l'alto). In ogni caso seguo un percorso che va al più dal nodo a una foglia (o dal nodo alla radice), dunque la complessità risulta essere O(h) dove h rappresenta l'altezza dell'albero. Essendo un heap ottengo che h = logn quindi **T(n) = O(log n)**