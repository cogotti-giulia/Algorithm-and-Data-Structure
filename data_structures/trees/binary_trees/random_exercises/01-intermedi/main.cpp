/**
 * @file main.cpp
 * @author cogotti-giulia
 * @brief test nodi intermedi
 * @version 1.1
 * @date 2023-11-29
 */
#include "header.cpp"
#include <iostream>
#include <vector>

int main() {

  std::vector<T> v_tree = get_trees_from_file("test.txt");

  for (int i = 0; i < v_tree.size(); i++) {
    pnode root = v_tree.at(i)->root;
    visita_in_ampiezza_BFS(root);
    std::cout << std::endl;
    std::cout << "numero di nodi intermedi: " << intermedi(root);
    std::cout << std::endl;
  }
}
