/**
 * @file structs_used.hpp
 * @author me, myself and I
 * @brief struttura dati utilizzata per implementare l'heap
 * @version 1.0
 * @date 2023-11-18
 */

struct my_heap {
  int *arr;
  int heap_size;
  int length;

  my_heap(int *a, int hs = 0, int l = 0) : arr{a}, heap_size{hs}, length{l} {};

  void decrement_heap_size() { this->heap_size--; }
};
typedef my_heap *p_heap;