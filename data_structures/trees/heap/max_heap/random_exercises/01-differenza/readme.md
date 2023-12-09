## Esercizio

Si consideri la struttura dati Max-Heap implementata tramite un vettore (secondo lo schema visto a lezione).

1. Si scriva la definizione di Max-Heap.
2. Si realizzi in modo efficiente in pseudocodice la funzione Differenza(H1,H2) che dati due Max-Heap H1 e H2 contenenti rispettivamente n1 e n2 interi (anche ripetuti), ritorna in output un nuovo Max-Heap contenente gli elementi che appartengono a H1 ma non appartengono a H2. In presenza di duplicati se x compare k1 volte in H1 e k2 volte in H2, nel Max-Heap differenza x dovrà comparire max{0, k1-k2}.

3. Si determini e giustifichi la complessità in funzione di n1 e n2. Si devono scrivere le eventuali funzioni/procedure ausiliarie utilizzate.

L'idea è quella di estrarre ripetutamente l'elemento massimo da ciascun heap, se il max di h1 è maggiore del max di h2 allora so con certezza che esso appartiene solo ad h1, quindi estraggo e inserisco nel nuovo heap.

Se invece il max di h2 è maggiore del max di h1, scarto gli elementi di h2 finché non si allineano. Quando i due elementi in cima ai due heap sono uguali estraggo il massimo da entrambi (questo assicura che, se ho k1 elementi in h1 e k2 elementi in h2 allora l'elemento x compare max{0, k1-k2} volte nel nuovo heap, ad esempio se ho 3 elementi uguali in h1 e 1 in h2 allora compare 2 volte!)

### Codice funzione principale

Per compiere le operazioni utilizzo le code di priorità! Permettono di effettuare le operazioni su un heap in tempo O(log n)

```c++

//! T(n) = O(n1*(logn1 + logn2))
void differenza(p_heap h_diff, p_heap h1, p_heap h2) {

    //? eseguito al più n1 volte
  while (h1->heap_size > 0) {
    // se ho elementi in h1 e h2 e se il massimo di h1 è maggiore del massimo di
    // h2 allora posso inserire in h_diff il max di h1 in quanto so con certezza
    // che esso non sarà presente in h2! ovviamente poi estraggo il massimo e
    // sistemo l'heap

    /***** (A) *****/
    if (h1->heap_size > 0 && h2->heap_size > 0 &&
        max_heap_maximum(h1) > max_heap_maximum(h2)) {
      max_heap_extract_max(h1); //? T(n) = O(log n1)
    }

    // se ho elementi in h1 e h2 e il massimo di h1 è minore del massimo di h2,
    // estraggo il massimo di h2 (gli elementi non potranno di
    // certo essere anche in h1), se gli elementi dovessero essere uguali li
    // estraggo da entrambi gli heap, questo assicura che se un elemento è
    // presente due volte in h1 e una in h2 allora esso sarà presente una volta
    // in h_diff

    /***** (B) *****/
    if (h1->heap_size > 0 && h2->heap_size > 0 &&
           max_heap_maximum(h1) <= max_heap_maximum(h2)) {

      if (max_heap_maximum(h1) == max_heap_maximum(h2)){
        max_heap_extract_max(h1); //? T(n) = O(log n1)
      }
      max_heap_extract_max(h2); //? T(n) = O(log n2)
    }

    // se ho finito l'heap h2 inserisco tutti gli elementi rimanenti di h1,
    // infatti essi per forza saranno presenti solo in h1

    /***** (C) *****/
    if (h2->heap_size == 0)
      if (h1->heap_size > 0) {
        max_heap_insert(h_diff, max_heap_maximum(h1));
        max_heap_extract_max(h1);
      }
  }
}
```

#### Analisi complessità

Assumendo che **n1** rappresenti il numero di nodi di H1 e **n2** rappresenti il numero di nodi di H2 si ha che:

- il ciclo while è eseguito n1 volte
- la max_heap_extract_max(h1) del primo if (A) costa O(log n1)
- la max_heap_extract_max(h1) + la max_heap_extract_max(h2) del secondo if costa O(log n1 + log n2), dato che nel caso peggiore entra in entrambi gli if
- la max_heap_extract_max(h1) del primo if costa O(log n1)

quindi ottengo che

T(n1, n2) = n1\*O(log n1 + log n1 + log n1 + log n2) = n1\*O(3 log n1 + log n2) = n1\*O(log n1 + log n2) = **O(n1\*(log n1 + log n2))**

Direi O grande e non teta perché se H1 è vuoto non fa niente e ha tempo costante!

### Funzioni ausiliarie utilizzate

#### Max heap maximum

Estrae il massimo da un heap, il tempo di esecuzione è costante: **T(n) = Teta(1)**

```c++
int max_heap_maximum(p_heap heap) {
  if (heap->heap_size < 1)
    throw "heap underflow";
  else
    return heap->arr[0];
}
```

#### Max heap extract max

Rimuove l'elemento massimo da un heap e lo restituisce. Per fare questo salva l'elemento in posizione zero, decrementa l'heap size e scambia l'elemento nella radice con l'ultimo elemento dell'array, applica poi la max heapify alla radice (i figli sono sicuramente dei max heap perché non li ho toccati).

La max heapify trova il massimo tra radice e figli sx e dx, scambia il massimo tra radice e figlio e riapplica la max heapify (l'eventuale violazione si trova nella cella appena scambiata, quindi verso il basso).

Quindi questa operazione (eseguita tramite una coda di priorità rappresentata da un heap) segue un cammino che va dalla radice a una foglia e la sua complessità risulta essere **O(log n)** dove log n rappresenta l'altezza dell'heap.

```c++
int max_heap_extract_max(p_heap heap) {
  if (heap->heap_size < 1)
    throw "heap underflow";
  else {
    int max = heap->arr[0];
    heap->arr[0] = heap->arr[heap->heap_size - 1];
    heap->heap_size = heap->heap_size - 1;

    max_heapify(heap, 0);
    return max;
  }
}

//aggiungo un +1 perché l'array inizia dalla posizione zero!
int left(int i) { return i * 2 + 1; };
int right(int i) { return i * 2 + 1 + 1; };

void max_heapify(p_heap heap, int i) {
  int l = left(i);
  int r = right(i);

  int max;
  if (l < heap->heap_size && heap->arr[l] > heap->arr[i])
    max = l;
  else
    max = i;

  if (r < heap->heap_size && heap->arr[r] > heap->arr[max])
    max = r;

  if (max != i) {
    swap(heap, i, max);
    max_heapify(heap, max);
  }
}
```

#### Max heap insert

Inserisce il nuovo valore k nell'heap. In questo caso ha tempo di esecuzione costante perché oltre all'inserimento e incremento dell'heap size non occorre fare altre operazioni dato che sto inserendo il massimo tra h1 e h2 che è minore dell'eventuale massimo precedentemente inserito, ma allora la proprietà di max heap è verificata e non possono esserci violazioni (in quanto essa dovrebbe trovarsi nel parent ma ho appena detto che non è possibile!)

Dunque la complessità risulta essere **T(n) = Teta(1)**

```c++
void max_heap_insert(p_heap heap, int k) {
heap->arr[heap->heap_size] = k;
heap->increase_heap_size();

// non serve fare altro perché sto inserendo il massimo tra h1 e h2 che è
// minore dell'eventuale massimo precedentemente inserito, ma allora la
// proprietà di max heap è verificata e non possono esserci violazioni (in
// quanto essa dovrebbe trovarsi nel parent ma ho appena detto che non è
// possibile!)
}
```
