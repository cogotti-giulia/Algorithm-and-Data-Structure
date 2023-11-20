/**
 * @file header.cpp
 * @author me, myself and I
 * @brief implementazione metodi e funzioni
 * @version 1.0
 * @date 2023-11-20
 */

#include "header.hpp"
#include <cmath>
#include <iostream>

//! T(n) = Teta(1) costante
int q_heap_maximum(p_heap heap) {
  if (heap->heap_size < 1)
    throw "heap underflow";
  else
    return heap->arr[0];
}

//! T(n) = O(log n) in quanto applica la max heapify alla radice
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

//! T(n) = O(log n), segue un cammino che va al più da un nodo alla radice
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

  if (i != max) {
    swap(heap, i, max);
    max_heapify(heap, max);
  }
}

//! T(n) = O(log n) segue un cammino che va al più da un nodo alla radice
//! (l'unica eccezione presente potrebbe essere nel padre)
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

//! T(n) = O(log n) segue un cammino che va al più da un nodo alla radice
void q_max_heap_insert(p_heap heap, int key) {
  heap->increase_heap_size();
  int i = heap->heap_size;
  heap->arr[i] = key;
  while (i > 0 && heap->arr[parent(i)] < heap->arr[i]) {
    swap(heap, i, parent(i));
    i = parent(i);
  }
}

int left(int i) { return i * 2 + 1; }
int right(int i) { return i * 2 + 2; }
int parent(int i) { return std::floor(i / 2); }

void swap(p_heap heap, int i1, int i2) {
  int tmp = heap->arr[i1];
  heap->arr[i1] = heap->arr[i2];
  heap->arr[i2] = tmp;
}

void stampa_heap(p_heap heap) {
  for (int i = 0; i < heap->heap_size; i++)
    std::cout << heap->arr[i] << " ";

  std::cout << std::endl;
}