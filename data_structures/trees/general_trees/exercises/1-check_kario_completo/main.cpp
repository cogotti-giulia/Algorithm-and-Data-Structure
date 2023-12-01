/**
 * @file main.cpp
 * @author cogotti-giulia
 * @brief test verifica se l'albero generale è k ario completo
 * @version 1.1
 * @date 2023-12-01
 */
#include "header.cpp"
#include <iostream>

int main() {
  std::vector<int> info = {5, 4, -2, 12, 3, 4, 8, 9, 3, -1, 3, 4, -5};
  std::vector<int> parent = {-1, 0, 0, 0, 1, 1, 1, 2, 2, 2, 3, 3, 11};
  std::vector<bool> is_left_child = {false, true,  false, false, true,
                                     false, false, true,  false, false,
                                     true,  false, true};

  parrG vet_parent = new vector_parent(parent, info, is_left_child);

  T t = new tree();
  t->root = crea_albero(vet_parent);

  if (is_k_ario(t->root, 3))
    std::cout << "yey";
  else
    std::cout << "nope";
}