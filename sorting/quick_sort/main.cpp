/**
 * @file main.cpp
 * @author me, myself and I
 * @brief test ordinamento tramite quick sort (tutte le versioni)
 * @version 1.0
 * @date 2023-11-18
 */
#include "header.cpp"
#include <iostream>

int main() {

  int n = 8;

  std::cout << "quick sort" << std::endl;
  // esempio che mostra la non stabilità del quick sort
  my_elem arr_not_stable[8] = {
      new elem{1, 'A'}, new elem{1, 'B'}, new elem{1, 'C'}, new elem{1, 'D'},
      new elem{1, 'E'}, new elem{1, 'F'}, new elem{1, 'G'}, new elem{0, 'H'}};

  stampa_array(arr_not_stable, n);
  my_quick_sort(arr_not_stable, 0, n - 1);
  stampa_array(arr_not_stable, n);
  /*
   * output
   * 1:A 1:B 1:C 1:D 1:E 1:F 1:G 0:H
   * 0:H 1:B 1:C 1:D 1:E 1:F 1:G 1:A
   */

  std::cout << std::endl;
  std::cout << "quick sort" << std::endl;
  my_elem arr[8] = {new elem{2, 'A'},  new elem{1, 'B'}, new elem{-12, 'C'},
                    new elem{0, 'D'},  new elem{7, 'E'}, new elem{9, 'F'},
                    new elem{-5, 'G'}, new elem{3, 'H'}};

  stampa_array(arr, n);
  my_quick_sort(arr, 0, n - 1);
  stampa_array(arr, n);

  std::cout << std::endl;
  std::cout << "randomized quick sort" << std::endl;
  my_elem arr_rand[8] = {
      new elem{2, 'A'}, new elem{1, 'B'}, new elem{-12, 'C'}, new elem{0, 'D'},
      new elem{7, 'E'}, new elem{9, 'F'}, new elem{-5, 'G'},  new elem{3, 'H'}};

  stampa_array(arr_rand, n);
  my_randomized_quick_sort(arr_rand, 0, n - 1);
  stampa_array(arr_rand, n);

  std::cout << std::endl;
  std::cout << "triparted quick sort" << std::endl;
  my_elem arr_trip[8] = {
      new elem{2, 'A'}, new elem{1, 'B'}, new elem{-12, 'C'}, new elem{0, 'D'},
      new elem{7, 'E'}, new elem{9, 'F'}, new elem{-5, 'G'},  new elem{3, 'H'}};

  stampa_array(arr_trip, n);
  my_quick_sort_tripart(arr_trip, 0, n - 1);
  stampa_array(arr_trip, n);

  std::cout << std::endl;
  std::cout << "triparted quick sort" << std::endl;
  my_elem arr_rand_trip[8] = {new elem{9, 'A'},  new elem{21, 'B'},
                              new elem{-7, 'C'}, new elem{0, 'D'},
                              new elem{14, 'E'}, new elem{11, 'F'},
                              new elem{-3, 'G'}, new elem{1, 'H'}};

  stampa_array(arr_rand_trip, n);
  my_randomized_quick_sort_tripart(arr_rand_trip, 0, n - 1);
  stampa_array(arr_trip, n);
}
