/**
 * @file main.cpp
 * @author me, myself and I
 * @brief test insertion sort
 * @version 1.0
 * @date 2023-11-14
 */
#include "header.cpp"
#include <array>

int main() {
  std::array<my_elem, 6> arr = {new elem(5, 'A'), new elem(2, 'B'),
                                new elem(7, 'C'), new elem(3, 'D'),
                                new elem(1, 'E'), new elem(2, 'F')};

  stampa_array(arr);

  insertion_sort(arr);

  stampa_array(arr);
}