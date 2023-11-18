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

int parent(int i) { return std::floor(i / 2); }

//aggiungo il +1 perché parto da zero!
int left(int i) { return i * 2+1; }

//aggiungo il +1 perché parto da zero!
int right(int i) { return i * 2 + 2; }

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

void build_max_heap(p_heap heap) {
  heap->heap_size = heap->length;
  for (int i = floor(heap->length / 2)-1; i >= 0; i--)
    max_heapify(heap, i);
}

void swap(p_heap heap, int i1, int i2) {
  int tmp = heap->arr[i1];
  heap->arr[i1] = heap->arr[i2];
  heap->arr[i2] = tmp;
}


void stampa_heap(p_heap heap){
  for(int i=0; i<heap->heap_size; i++){
    std::cout<<heap->arr[i]<<" ";
  }

  std::cout<<std::endl;
}
