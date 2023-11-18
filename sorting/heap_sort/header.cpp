/**
 * @file header.cpp
 * @author me, myself and I
 * @brief implementazione metodi e funzioni
 * @version 1.0
 * @date 2023-11-18
 */
#include "header.hpp"
#include <cmath>
#include <iostream>
#include <math.h>

//! T(n) = O(n logn)
void my_heap_sort(p_heap heap) {
  build_max_heap(heap); //? O(n)

  for (int i = heap->length - 1; i > 0; i--) { //? eseguito n-1 volte
    swap(heap, 0, i);
    heap->decrement_heap_size();
    max_heapify(heap, 0); //? applico sempre alla radice, quindi impiega O(logn)
  }
}

int parent(int i) { return std::floor(i / 2); }

int left(int i) { return i * 2 + 1; }

int right(int i) { return i * 2 + 2; }

void swap(p_heap heap, int i1, int i2) {
  int tmp = heap->arr[i1];
  heap->arr[i1] = heap->arr[i2];
  heap->arr[i2] = tmp;
}

void stampa_array(p_heap heap) {
  for (int i = 0; i < heap->length; i++)
    std::cout << heap->arr[i] << " ";

  std::cout << std::endl;
}

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

void build_max_heap(p_heap heap) {
  heap->heap_size = heap->length;
  for (int i = floor(heap->length / 2) - 1; i >= 0; i--)
    max_heapify(heap, i);
}
