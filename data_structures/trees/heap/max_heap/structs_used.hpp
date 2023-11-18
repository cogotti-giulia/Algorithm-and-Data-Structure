/**
 * @file structs_used.hpp
 * @author me, myself and I
 * @brief struttura dati utilizzata per rappresentare l'heap
 * @version 1.0
 * @date 2023-11-18
 */

struct my_heap {
  int *arr;
  int heap_size;
  int length;

  my_heap(int *a, int hs, int l) : arr{a}, heap_size{hs}, length{l} {};
};
typedef my_heap *p_heap;