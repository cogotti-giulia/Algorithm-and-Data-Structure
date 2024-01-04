/**
 * @file main.cpp
 * @author cogotti-giulia (cogotti.giulia.irl@gmail.com)
 * @brief test
 * @version 1.0
 * @date 2024-01-04
 *
 * @copyright Copyright (c) 2024
 *
 */
#include "header.cpp"

int main() {
  std::vector<std::vector<int>> arrays = get_arrays_from_file("test.txt");

  for (int k = 0; k < arrays.size(); k++) {
    std::vector<int> A = arrays.at(k);
    print_array(A);

    int i = -1, j = -1;
    if (triplo(A, &i, &j)) {
      std::cout << "yep, i = " << i << " j = " << j << std::endl << std::endl;
    } else {
      std::cout << "nope" << std::endl << std::endl;
    }
  }
}