## Max Heap

Per ogni nodo **i**, _diverso dalla radice_, vale che `A[parent(i)<<] >= A[i]`. (Si dimostra per induzione e transitività del <=).

La proprietà di max heap garantisce che il _massimo_ elemento si trova nella radice e che il sotto albero di un nodo contiene valori **non** maggiori di quelli contenuti nel nodo stesso.

```
                  16
                /    \
              14      10
            /    \    / \
           8      7  9   3
          / \    /
         2   4  1


      T.root                floor(n/2) + 1
        |                     |
        V                   + V
A:   | 16 | 14 | 10 | 8 | 7 | 9 | 3 | 2 | 4 | 1 |
                            + ----------------- +
                                   foglie !
```

### Proprietà

> L'altezza di un heap di **n** elementi è **parte_int_inf(log n)**.

_dimostrazione_

dato che un heap è un albero binario quasi completo, se ha altezza h, allora ha 2^h <= n(numero di nodi) <= 2^(h+1) - 1

```
              /\        albero completo di altezza h
             /  \        h
            /    \       E 2^i = (2^h+1)-1 nodi
           /      \     i=0
          /________\


              /\        albero completo fino al livello h
             /  \       un nodo a livello h-1
            /    \      h-1
           /  ____\      E  2^i+1 = 2^h nodi
          /__/          i=0
```

ma allora 2^h <= n(numero di nodi) <= 2^(h+1) - 1 = h <= log(2) n < h+1 ~> h = parte_int_inf(log n)

> Nell'array che rappresenta un heap di n elementi, le _foglie_ sono i nodi con indici parte_int_inf(n/2)+1, parte_int_inf(n/2)+2, ..., n

> Ci sono al massimo parte_int_sup(n/(2^(h+1)) nodi di altezza h in un qualsiasi heap di n elementi

Questo significa che ci sono tanti nodi che hanno altezze piccole (massima lunghezza del cammino da nodo a foglia).<br>
_se h=0 (altezza nodo foglia) allora numero_foglie<=parte_int_sup(n/2)=parte_int_suo(n/2)_

### Max Heapify

La max heapify serve per mantenere vera la proprietà di max heap.

```pseudocode
# pre: gli alberi binari con radice left(i) e right(i) sono max heap
# post: l'albero radicato in i è un max_heap
max_heapify(A, i)
  l = left(i)
  r = right(i)

  # prendo il massimo tra figlio sx, figlio dx e padre
  if l <= A.heap_size and A[l] > A[i]
    max = l
  else
    max = i

  if r <= A.heap_size and A[r] > A[max]
    max = r

  // metto il massimo come padre
  if i != max
    scambia A[i] e A[max]
    max_heapify(A, max) # l'eccezione potrebbe propagarsi
```

```c++
void max_heapify(p_heap heap, int i) {
  int l = left(i);
  int r = right(i);

  int max;

  if (l <= heap->heap_size && heap->arr[l] > heap->arr[i])
    max = l;
  else
    max = i;

  if (r <= heap->heap_size && heap->arr[r] > heap->arr[max])
    max = r;

  if (i != max) {
    swap(heap, i, max);
    max_heapify(heap, max);
  }
}
```

#### Analisi complessità

Il tempo di esecuzione è O(h), dove h è l'altezza del nodo **i** a cui applico la funzione, perché ad ogni chiamata ricorsiva scendo di un livello dell'albero.

### Build Max Heap

Costruisce un heap dato un vettore disordinato.

```pseudocode
build_max_heap(A)
  A.heap_size = A.length
  for i = floor(A.length/2) down to 1
    max_heapify(A, i)
```

```c++
void build_max_heap(p_heap heap) {
  heap->heap_size = heap->length;
  for (int i = floor(heap->length / 2)-1; i >= 0; i--)
    max_heapify(heap, i);
}
```

Applica la max heapify da metà array perché dal successivo elemento ho solo foglie e le foglie del nodo sono dei banali max heap, quindi la pre condizione sulla max heapify non viene violata.

#### Invariante ciclo for

INV = ogni nodo i+1, i+2, ..., n è radice di un max heap, dove n = A.length

_conclusione_<br>
quando il ciclo termina i=0

INV[0 / i] = ogni nodo da 1, 2, ..., n è radice di max heap. in particolare il nodo 1, che contiene la radice dell'albero, p un max heap.

#### Analisi complessità

- limite superiore (non stretto): ogni chiamata di max_heapify costa O(log n) e ci sono O(n) chiamate, quindi il tempo di esecuzione è limitato da O(n logn)
- limite superiore (**stretto**): il tempo di max_heapify è O(h) e varia con l'altezza del nodo a cui si applica!<br>
  se applico la max_heapify a tutti i nodi dell'albero<br>
  ```
   int_inf(log_n)
             E   int_sup(n/2(h-1)) = ... = O(2n) = O(n)
            h=0
  ```
