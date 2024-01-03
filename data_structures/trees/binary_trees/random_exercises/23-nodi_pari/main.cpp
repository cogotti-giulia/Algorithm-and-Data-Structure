/**
 * @file main.cpp
 * @author cogotti-giulia (cogotti.giulia.irl@gmail.com)
 * @brief test su alberi presi da file
 * @version 1.0
 * @date 2024-01-03
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
    post_order(t->root);
    std::cout << "\nnodi pari: " << nodi_pari(t->root) << std::endl;
  }
}