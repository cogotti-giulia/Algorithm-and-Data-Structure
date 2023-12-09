/**
 * @file header.cpp
 * @author me, myself and I
 * @brief implementazione metodi e funzioni
 * @version 1.0
 * @date 2023-11-25
 */

#include "header.hpp"
#include <algorithm>
#include <iostream>

//! T(n1, n2) = O(n1*(log n1 + log n2))
void differenza(p_heap h_diff, p_heap h1, p_heap h2) {
  while (h1->heap_size > 0) {
    // se ho elementi in h1 e h2 e se il massimo di h1 è maggiore del massimo di
    // h2 allora posso inserire in h_diff il max di h1 in quanto so con certezza
    // che esso non sarà presente in h2! ovviamente poi estraggo il massimo e
    // sistemo l'heap
    if (h1->heap_size > 0 && h2->heap_size > 0 &&
        max_heap_maximum(h1) > max_heap_maximum(h2)) {

      int max_h1 = max_heap_extract_max(h1);
      max_heap_insert(h_diff, max_h1);
    }

    // se ho elementi in h1 e h2 e il massimo di h1 è minore del massimo di h2,
    // estraggo il massimo di h2 (gli elementi non potranno di certo essere
    // anche in h1), se gli elementi dovessero essere uguali li estraggo da
    // entrambi gli heap, questo assicura che se un elemento è presente due
    // volte in h1 e una in h2 allora esso sarà presente una volta in h_diff
    if (h1->heap_size > 0 && h2->heap_size > 0 &&
        max_heap_maximum(h1) <= max_heap_maximum(h2)) {
      if (max_heap_maximum(h1) == max_heap_maximum(h2)) {
        max_heap_extract_max(h1);
      }

      max_heap_extract_max(h2);
    }

    // se ho finito l'heap h2 inserisco gli elementi rimanenti di h1,
    // infatti essi per forza saranno presenti solo in h1
    if (h2->heap_size == 0)
      if (h1->heap_size > 0) {
        int max_h1 = max_heap_extract_max(h1);
        max_heap_insert(h_diff, max_h1);
      }
  }
}

//! T(n) = Teta(1)
int max_heap_maximum(p_heap heap) {
  if (heap->heap_size < 1)
    throw "heap underflow";
  else
    return heap->arr[0];
}

//! T(n) = O(log n)
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

//! T(n) = Teta(1)
void max_heap_insert(p_heap heap, int k) {
  heap->arr[heap->heap_size] = k;
  heap->increase_heap_size();

  // non serve fare altro perché sto inserendo il massimo tra h1 e h2 che è
  // minore dell'eventuale massimo precedentemente inserito, ma allora la
  // proprietà di max heap è verificata e non possono esserci violazioni (in
  // quanto essa dovrebbe trovarsi nel parent ma ho appena detto che non è
  // possibile!)
}

int parent(int i) { return std::floor(i / 2); };
// aggiungo un +1 perché l'array inizia dalla posizione zero!
int left(int i) { return i * 2 + 1; };
int right(int i) { return i * 2 + 2; };

//! T(n) = O(log n)
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

//! T(n) = Teta(1)
void swap(p_heap heap, int i1, int i2) {
  int tmp = heap->arr[i1];
  heap->arr[i1] = heap->arr[i2];
  heap->arr[i2] = tmp;
}

//! T(n) = O(n)
void build_max_heap(p_heap heap) {
  heap->heap_size = heap->length;
  for (int i = (heap->length / 2) - 1; i >= 0; i--)
    max_heapify(heap, i);
}

//! T(n) = Teta(n)
void stampa_heap(p_heap heap) {
  for (int i = 0; i < heap->heap_size; i++) {
    std::cout << heap->arr[i] << " ";
  }

  std::cout << std::endl;
}
