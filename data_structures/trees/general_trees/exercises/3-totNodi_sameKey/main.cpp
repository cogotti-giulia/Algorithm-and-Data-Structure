/**
 * @file main.cpp
 * @author cogotti-giulia
 * @brief test
 * @version 1.1
 * @date 2023-12-01
 */
#include "header.cpp"
#include <iostream>

int main() {


  std::vector<int> info = {2, 1, 1, 1, 3, 4, 5, 6, 4, 7, -7};
  std::vector<int> parent = {-1, 0, 0, 0, 1, 1, 3, 3, 6, 7, 7};
  std::vector<bool> is_left_child = {false, true, false, false, true, false, true, false, true, true, false};

  parrG vet_parent = new vector_parent(parent, info, is_left_child);

  T t = new tree();
  t->root = crea_albero(vet_parent);

  visita_post_order(t->root);
  std::cout << std::endl;

  std::cout << "Nodi i cui i figli hanno la stessa chiave: "
            << node_childrenSameKey(t->root);
}