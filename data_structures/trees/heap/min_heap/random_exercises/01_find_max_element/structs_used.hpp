/**
 * @file structs_used.hpp
 * @author cogotti-giulia (cogotti.giulia.irl@gmail.com)
 * @brief strutture dati utilizzate per rappresentare il min heap
 * @version 1.0
 * @date 2024-01-05
 *
 * @copyright Copyright (c) 2024
 *
 */
#include <vector>

struct my_heap {
  std::vector<int> arr;
  int heap_size;
  int length;

  my_heap(std::vector<int> a, int hs, int l)
      : arr{a}, heap_size{hs}, length{l} {};
};
typedef my_heap *p_heap;