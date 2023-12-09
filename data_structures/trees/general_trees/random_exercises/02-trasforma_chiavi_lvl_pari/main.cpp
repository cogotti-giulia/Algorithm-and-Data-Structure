/**
 * @file main.cpp
 * @author cogotti-giulia
 * @brief test della trasformazione delle chiavi a livello pari
 * @version 1.1
 * @date 2023-12-01
 */
#include "header.cpp"
#include <iostream>

int main() {
  std::vector<int> info = {50, 8, 2, 20, 12, 4, -12, 18, 80};
  std::vector<int> parent = {-1, 0, 0, 1, 1, 1, 2, 2, 2};
  std::vector<bool> is_left_child = {false, true, false, true, false, false, true, false, false};

  parrG vet_parent = new vector_parent(parent, info, is_left_child);

  T t = new tree();
  t->root = crea_albero(vet_parent);
  visita_preorder_DFS(t->root);
  trasforma(t->root);
  std::cout << std::endl;
  visita_preorder_DFS(t->root);
}