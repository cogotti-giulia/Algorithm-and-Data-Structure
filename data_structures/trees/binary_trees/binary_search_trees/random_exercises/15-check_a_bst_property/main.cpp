/**
 * @file main.cpp
 * @author cogotti-giulia (cogotti.giulia.irl@gmail.com)
 * @brief test
 * @version 1.0
 * @date 2024-01-05
 *
 * @copyright Copyright (c) 2024
 *
 */
#include "header.cpp"
#include <vector>

int main() {

  std::vector<std::vector<int>> arrays = get_arrays_from_file("test.txt");

  for (int i = 0; i < arrays.size(); i++) {
    T t = build_BST(arrays.at(i));

    print_bst(t);
    if (check_property(t))
      std::cout << "proprietà verificata";
    else
      std::cout << "proprietà non verificata :(";

    std::cout << std::endl;
  }
}