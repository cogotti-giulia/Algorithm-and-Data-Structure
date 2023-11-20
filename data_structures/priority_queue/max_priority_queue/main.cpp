/**
 * @file main.cpp
 * @author me, myself and I
 * @brief test sulle code di priorità utilizzando un max heap
 * @version 1.0
 * @date 2023-11-20
 */
#include "header.cpp"

int main() {
  int n = 10;

  int A[10] = {};

  p_heap heap = new my_heap(A, 0, 10);

  q_max_heap_insert(heap, 10);
  q_max_heap_insert(heap, 3);
  q_max_heap_insert(heap, 9);
  q_max_heap_insert(heap, 4);
  q_max_heap_insert(heap, 16);
  q_max_heap_insert(heap, 2);
  q_max_heap_insert(heap, 7);
  q_max_heap_insert(heap, 8);
  q_max_heap_insert(heap, 1);

  stampa_heap(heap);

  std::cout << std::endl;
  std::cout << "increase key (index=5)... " << std::endl;
  // i è l'indice del nodo nell'array!
  q_max_heap_increase_key(heap, 5, 11);
  stampa_heap(heap);

  std::cout << std::endl;
  std::cout << "maximum : " << q_heap_maximum(heap) << std::endl;
  stampa_heap(heap);

  std::cout << std::endl;
  std::cout << "extract maximum ..." << std::endl;
  q_max_heap_extract_max(heap);
  stampa_heap(heap);
}