/**
 * @file main.cpp
 * @author cogotti-giulia
 * @brief test costo massimo albero binario
 * @version 1.1
 * @date 2023-11-29
 */
#include "header.cpp"
#include <iostream>

int main() {

  std::vector<int> info = {1, 5, -2, 3, 7, -9};
  std::vector<int> parent = {-1, 0, 0, 1, 2, 2};
  std::vector<char> child_posi = {'z', 'l', 'r', 'l', 'l', 'r'};
  parr vet_parent = new vector_parent(parent, info, child_posi);

  T t = new tree();
  t->root = crea_albero(vet_parent);

  std::cout << "costo massimo: " << costo_max_cammino(t->root);
}