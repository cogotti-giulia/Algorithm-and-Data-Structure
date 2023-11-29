/**
 * @file main.cpp
 * @author cogotti-giulia
 * @brief test verifica se l'albero binario è k-compreso
 * @version 1.1
 * @date 2023-11-29
 */
#include "header.cpp"
#include <iostream>
#include <vector>

int main() {

  std::vector<int> info = {5, 4, -2, 0, 7, -3, 1};
  std::vector<int> parent = {-1, 0, 0, 1, 1, 4, 4};
  std::vector<char> child_posi = {'z', 'l', 'r', 'l', 'r', 'l', 'r'};
  parr vet_parent = new vector_parent(parent, info, child_posi);

  T t = new tree();
  t->root = crea_albero(vet_parent);


  visita_in_order_simmetrica(t->root);
  std::cout << std::endl;

  int k[4] = {11, 12, 1, 13};

  for (int i = 0; i < 4; i++) {
    if (k_compreso(t->root, k[i]))
      std::cout << "T è " << k[i] << " compreso" << std::endl;
    else
      std::cout << "T non è " << k[i] << " compreso" << std::endl;
  }

}