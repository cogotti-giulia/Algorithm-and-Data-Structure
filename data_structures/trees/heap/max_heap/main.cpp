/**
 * @file main.cpp
 * @author me, myself and I
 * @brief test di costruzione di un max heap
 * @version 1.0
 * @date 2023-11-18
 */
#include "header.cpp"
#include <iostream>

int main() {

  int n = 10;
  int A[10] = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7};

  std::cout<<"array disordinato [0...length]"<<std::endl;

  for(int i = 0; i < n; i++)
    std::cout<<A[i]<<" ";

  std::cout<<std::endl;

  p_heap heap = new my_heap(A, 0, n);

  stampa_heap(heap);
  build_max_heap(heap);

  std::cout<<"heap [0...heap_size]"<<std::endl;
  stampa_heap(heap);
}