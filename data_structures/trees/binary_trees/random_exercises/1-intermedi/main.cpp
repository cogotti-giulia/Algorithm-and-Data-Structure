/**
 * @file main.cpp
 * @author cogotti-giulia
 * @brief test nodi intermedi
 * @version 1.1
 * @date 2023-11-29
 */
#include "header.cpp"
#include <iostream>

int main() {
  
  std::vector<int> info = {17, 17, 0, 7, 9, 1};
  std::vector<int> parent = {-1, 0, 0, 1, 1, 3};
  std::vector<char> child_posi = {'z', 'l', 'r', 'l', 'r', 'l'};
  parr vet_parent = new vector_parent(parent, info, child_posi);

  T t = new tree();
  t->root = crea_albero(vet_parent);

  visita_in_ampiezza_BFS(t->root);
  std::cout << std::endl;
  std::cout << "numero di nodi intermedi: " << intermedi(t->root);
}
