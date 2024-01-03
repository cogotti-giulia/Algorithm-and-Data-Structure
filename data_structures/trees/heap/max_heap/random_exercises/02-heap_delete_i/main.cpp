/**
 * @file main.cpp
 * @author cogotti-giulia (cogotti.giulia.irl@gmail.com)
 * @brief test
 * @version 1.0
 * @date 2024-01-03
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "header.cpp"
#include <vector>

int main() {
  std::vector<int> arr = {15, 9, 3, 8, 5, -3, 2, 6, 7};

  p_heap heap = new my_heap(arr, 9, 9);

  stampa_heap(heap);

  int i = 6;
  std::cout << "\ndelete i = " << i << "\n";
  heap_delete(heap, i);
  stampa_heap(heap);

  i = 1;
  std::cout << "\ndelete i = " << i << "\n";
  heap_delete(heap, i);
  stampa_heap(heap);

  i = 0;
  std::cout << "\ndelete i = " << i << "\n";
  heap_delete(heap, i);
  stampa_heap(heap);
}