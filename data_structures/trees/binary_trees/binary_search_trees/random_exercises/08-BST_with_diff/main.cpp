/**
 * @file main.cpp
 * @author cogotti-giulia (cogotti.giulia.irl@gmail.com)
 * @brief test
 * @version 1.0
 * @date 2023-12-12
 *
 * @copyright Copyright (c) 2023
 *
 */
#include "header.cpp"
#include <iostream>
#include <vector>

int main() {

  std::vector<int> keys = {5, 4, 3, 1, 2};
  std::vector<int> keys_1 = {5, -3, 8, 9, 7, 6, 14};
  std::vector<int> keys_2 = {5, 3, 0, 8, 9, 7, 6, -5};
  std::vector<int> keys_3 = {5, 3, 12, 4, 1, -7};

  std::vector<std::vector<int>> tests = {keys, keys_1, keys_2, keys_3};

  for (int t = 0; t < tests.size(); t++) {
    T_d my_tree = new tree();

    for (int i = 0; i < tests.at(t).size(); i++) {
      pnode_d nuovo = new node(tests.at(t).at(i));
      std::cout << "insert z.key = " << nuovo->key << std::endl;
      tree_insert_diff(my_tree, nuovo);
      visita_simmetrica(my_tree);
      std::cout << std::endl;
    }
    std::cout << std::endl;
  }
}