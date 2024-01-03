/**
 * @file header.cpp
 * @author cogotti-giulia (cogotti.giulia.irl@gmail.com)
 * @brief implementazione metodi e funzioni usate
 * @version 1.0
 * @date 2024-01-03
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "header.hpp"
#include <cmath>
#include <iostream>

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

// pre left(i) e right(i) sono max heap!
void max_heapify(p_heap &A, int i) {
  int l = left(i);
  int r = right(i);

  int max;

  if (l < A->heap_size && (A->arr.at(l) > A->arr.at(i)))
    max = l;
  else
    max = i;

  if (r < A->heap_size && (A->arr.at(r) > A->arr.at(max)))
    max = r;

  if (max != i) {
    my_swap(A, i, max);
    max_heapify(A, max);
  }
}

int parent(int i) { return std::ceil(i / 2) - 1; }

int left(int i) { return i * 2 + 1; }

int right(int i) { return i * 2 + 2; }

void my_swap(p_heap &A, int i1, int i2) {
  int tmp = A->arr.at(i1);
  A->arr.at(i1) = A->arr.at(i2);
  A->arr.at(i2) = tmp;
}

void stampa_heap(p_heap A) {
  for (int i = 0; i < A->heap_size; i++)
    std::cout << A->arr.at(i) << " ";

  std::cout << std::endl;
}