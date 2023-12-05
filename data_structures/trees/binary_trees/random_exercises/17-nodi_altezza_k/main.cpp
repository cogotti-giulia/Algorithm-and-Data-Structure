/**
 * @file main.cpp
 * @author cogotti-giulia (cogotti.giulia.irl@gmail.com)
 * @brief test con alberi binari presi da file
 * @version 1.0
 * @date 2023-12-05
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include "header.cpp"
#include <iostream>

int main() {

  std::vector<T> trees = get_trees_from_file("test.txt");

  for (int i = 0; i < trees.size(); i++) {
    T t = trees.at(i);
    std::cout << "pre order: ";
    pre_order(t->root);
    std::cout << std::endl;
    std::cout << "in order: ";
    in_order(t->root);

    std::cout << std::endl;
    int k = 2;
    std::cout << "numero nodi altezza " << k << " ~> "
              << altezza_nodi(t->root, k) << std::endl;
    std::cout << std::endl;
  }
}