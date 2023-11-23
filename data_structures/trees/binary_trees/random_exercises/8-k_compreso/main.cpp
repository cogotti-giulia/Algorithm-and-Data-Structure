/**
 * @file main.cpp
 * @author me, myself and I
 * @brief test verifica se l'albero binario è k-compreso
 * @version 1.0
 * @date 2023-11-23
 */
#include "header.cpp"
#include <iostream>
#include <vector>

int main() {

  int info[7] = {5, 4, -2, 0, 7, -3, 1};
  int parent[7] = {-1, 0, 0, 1, 1, 4, 4};
  parr vet_padri = new vector_parent(parent, info, 7);

  T t = new tree();
  t->root = crea_albero(vet_padri);

  visita_in_order_simmetrica(t->root);
  std::cout << std::endl;

  int k[4] = {11, 12, 1, 13};

  for (int i = 0; i < 4; i++) {
    if (k_compreso(t->root, k[i]))
      std::cout << "T è " << k[i] << " compreso" << std::endl;
    else
      std::cout << "T non è " << k[i] << " compreso" << std::endl;
  }

  /*
  std::cout<<std::endl;

  T t1 = new tree(); //albero vuoto

  for (int i = 0; i < 4; i++) {
    if (k_compreso(t1->root, k[i]))
      std::cout << "T è " << k[i] << " compreso"<<std::endl;
    else
      std::cout << "T non è " << k[i] << " compreso"<<std::endl;

  }
  */
}