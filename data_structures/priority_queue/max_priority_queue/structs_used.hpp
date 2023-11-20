/**
 * @file structs_used.hpp
 * @author me, myself and I
 * @brief struttura dati utilizzata per rappresentare il max heap
 * @version 1.0
 * @date 2023-11-20
 */
struct my_heap {
  int *arr;
  int heap_size;
  int length;

  my_heap(int *a, int hs = 0, int l = 0) : arr{a}, heap_size{hs}, length{l} {};

  void increase_heap_size() { this->heap_size = heap_size + 1; }
};
typedef my_heap *p_heap;