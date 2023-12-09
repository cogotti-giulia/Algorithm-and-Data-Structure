/**
 * @file main.cpp
 * @author me, myself and I
 * @brief test differenza heap
 * @version 1.0
 * @date 2023-11-25
 */
#include "header.cpp"
#include <iostream>

int main() {
  int n1 = 7;
  int A1[7] = {11, 5, 7, 3, -1, 3, 1};
  p_heap h1 = new my_heap(A1, 0, n1);

  int n2 = 8;
  int A2[8] = {15, 4, 8, 5, 2, -7, -2, 3};
  p_heap h2 = new my_heap(A2, 0, n2);

  build_max_heap(h1);
  std::cout << "h1 [0..." << h1->heap_size << "]" << std::endl;
  stampa_heap(h1);

  build_max_heap(h2);
  std::cout << "h2 [0..." << h2->heap_size << "]" << std::endl;
  stampa_heap(h2);

  int A_diff[h1->heap_size];
  // il nuovo heap avrà al più h1.heap_size elementi (perché contiene gli
  // elementi di h1 che non stanno in h2)
  p_heap h_diff = new my_heap(A_diff, 0, h1->heap_size);

  differenza(h_diff, h1, h2);
  std::cout << "h_diff [0..." << h_diff->heap_size << "]" << std::endl;
  // std::cout<<h_diff->arr[0];
  stampa_heap(h_diff);
}