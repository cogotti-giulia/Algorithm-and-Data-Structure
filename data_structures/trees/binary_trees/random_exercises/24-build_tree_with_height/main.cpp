/**
 * @file main.cpp
 * @author cogotti-giulia (cogotti.giulia.irl@gmail.com)
 * @brief test :)
 * @version 1.0
 * @date 2024-01-04
 *
 * @copyright Copyright (c) 2024
 *
 */
#include "header.cpp"
#include <vector>

int main() {

  std::vector<T> trees = get_trees_from_file("test.txt");

  for (int i = 0; i < trees.size(); i++) {
    T t = trees.at(i);
    std::cout << "T\n";
    std::cout << "in order: ";
    in_order(t->root);
    std::cout << std::endl;

    std::cout << "pre order: ";
    pre_order(t->root);
    std::cout << std::endl;
    T_h tree_height = build_tree_with_height(t);
    std::cout << std::endl;
    std::cout << "T'\n";
    std::cout << "in order: ";
    in_order_h(tree_height->root);
    std::cout << std::endl;

    std::cout << "pre order: ";
    pre_order_h(tree_height->root);
    std::cout << std::endl;
  }
}