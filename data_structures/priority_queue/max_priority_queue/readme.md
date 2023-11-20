## Code di massima priorità

Viene utilizzato un max heap per implementare le operazioni della coda.

### Maximum

```pseudocode
q_max_heap_maximum(A)
  if A.heap_size < 1
    errore "heap underflow"
  else
    return A[1]
```

```c++
int q_heap_maximum(p_heap heap) {
  if (heap->heap_size < 1)
    throw "heap underflow";
  else
    return heap->arr[0];
}
```

Il tempo di esecuzione risulta essere costante: **T(n) = Teta(1)**

### Extract maximum

```pseudocode
q_max_heap_extract_max(A)
  if A.heap_size < 1
    errore "heap underflow"
  else
    max = A[1]
    A[1] = A[A.heap_size] # per mantenere la proprietà di albero quasi completo
    A.heap_size = A.heap_size-1
    max_heapify(A, 1)
    return max
```

```c++
int q_max_heap_extract_max(p_heap heap) {
  if (heap->heap_size < 1)
    throw "heap underflow";
  else {
    int max = heap->arr[0];
    heap->arr[0] = heap->arr[heap->heap_size - 1];
    heap->heap_size--;
    max_heapify(heap, 0);
    return max;
  }
}
```

Il tempo di esecuzione è **T(n) = O(logn)** in quanto la max_heapify viene sempre applicata alla radice dell'albero.


### Increase key

```pseudocode
q_max_heap_increase_key(A, i, key) # i è la posizione del nodo del vettore
  if key < A[i]
    errore "la nuova chiave è minore di quella corrente"
  A[i] = key
  # essendo key >= chiave di x se sono sulla radice i=1 allora è tutto ok 
  # perché l'albero sarà comunque un max heap
  while i>1 and A[parent(i)] < A[i] # l'unica violazione se esiste si trova nel padre!
    scambia A[i] e A[parent(i)]
    i = parent(i) # propago l'eventuale eccezione
```
``
INV = l'array A[1...heap_size] soddisfa la proprietà di max heap, tranne una possibile violazione: A[i] potrebbe essere più grande dell'elemento in posizione A[parent(i)]

_conclusione_<br>
il ciclo termina in due casi:
- i=1 : l'invariante è soddisfatto perché è la radice dell'albero e non possono esserci violazioni;
- A[i] <= A[parent(i)]: l'unica violazione potrebbe essere in i ma, la guardia del ciclo mi assicura che non ci sono violazioni.


```c++
void q_max_heap_increase_key(p_heap heap, int i, int key) {
  if (key < heap->arr[i])
    throw "la nuova chiave è minore di quella corrente";
  else {
    heap->arr[i] = key;
    while (i > 0 && heap->arr[parent(i)] < heap->arr[i]) {
      swap(heap, i, parent(i));
      i = parent(i);
    }
  }
}
```

Il tempo di esecuzione è **T(n) = O(logn)** in quanto si segue un cammino che va al più da un nodo alla radice dell'albero.

### Insert

```pseudocode
q_max_heap_insert(A, key)
  A.heap_size++
  # se inserissi subito la key potrei violare la condizione di max heap
  # per usare la heap_increase_key devo assicurarmi che key > A[A.heap_size]
  A[A.heap_size] = -inf
  # nella realtà mi basta scrivere il codice qua senza chiamare nessuna funzione
  heap_increase_key(A, A.heap_size, key)
```

```c++
void q_max_heap_insert(p_heap heap, int key) {
  heap->increase_heap_size();
  int i = heap->heap_size;
  heap->arr[i] = key;
  while (i > 0 && heap->arr[parent(i)] < heap->arr[i]) {
    swap(heap, i, parent(i));
    i = parent(i);
  }
}
```

Il tempo di esecuzione risulta essere **T(n) = O(logn)** (costo della heap_increase_key)