/**
 * @file main.cpp
 * @author me, myself and I
 * @brief test merge sort su un array di my_elem
 * @version 1.0
 * @date 2023-11-15
 */
#include "header.cpp"

int main() {

  int n = 6;
  my_elem arr[6] = {new elem{3, 'A'}, new elem{-1, 'B'}, new elem{7, 'C'},
                    new elem{0, 'D'}, new elem{3, 'E'},  new elem{5, 'F'}};

  stampa_array(arr, n);

  std::cout << std::endl;

  std::cout << "... merge sort ..." << std::endl;
  my_merge_sort(arr, 0, n - 1);

  stampa_array(arr, n);
}