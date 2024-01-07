/**
 * @file main.cpp
 * @author cogotti-giulia (cogotti.giulia.irl@gmail.com)
 * @brief test
 * @version 1.0
 * @date 2024-01-07
 *
 * @copyright Copyright (c) 2024
 *
 */
#include "header.cpp"
#include <vector>

int main() {
  std::vector<std::vector<char>> arrays = get_arrays_from_file("test.txt");

  for (int i = 0; i < arrays.size(); i++) {
    std::vector<char> A = arrays.at(i);
    print_array(A);
    italian_flag(A);
    std::cout << " ~> ";
    print_array(A);
    std::cout << std::endl;
  }
}