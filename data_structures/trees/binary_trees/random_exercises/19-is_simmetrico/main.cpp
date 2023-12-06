/**
 * @file main.cpp
 * @author cogotti-giulia (cogotti.giulia.irl@gmail.com)
 * @brief test su alcuni alberi binari
 * @version 1.0
 * @date 2023-12-06
 *
 * @copyright Copyright (c) 2023
 *
 */
#include "header.cpp"
#include <iostream>
#include <vector>

int main() {
  std::vector<T> trees;

  trees = get_trees_from_file("test.txt");

  for (int i = 0; i < trees.size(); i++) {
    T t = trees.at(i);

    std::cout << "pre order: ";
    pre_order(t->root);
    std::cout << std::endl;

    std::cout << "in order: ";
    in_order(t->root);
    std::cout << std::endl;

    if (is_simmetrico(t->root))
      std::cout << "yep" << std::endl;
    else
      std::cout << "nope" << std::endl;

    std::cout << std::endl;
  }
}