/**
 * @file main.cpp
 * @author me, myself and I
 * @brief test insertion sort
 * @version 1.0
 * @date 2023-11-14
 */
#include "header.cpp"

int main() {
  int n = 5;
  int a[] = {5, 2, 7, 3, 1};

  my_array arr = new array(a, n);

  stampa_array(arr);

  insertion_sort(arr);

  stampa_array(arr);
}