/**
 * @file main.cpp
 * @author cogotti-giulia (cogotti.giulia.irl@gmail.com)
 * @brief test su qualche albero a caso
 * @version 1.0
 * @date 2023-12-09
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include "header.cpp"

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

    std::cout << (check_proprieta_max_heap(t->root)
                      ? "proprietà max heap valida"
                      : "proprietà max heap NON valida")
              << std::endl;
  }
}