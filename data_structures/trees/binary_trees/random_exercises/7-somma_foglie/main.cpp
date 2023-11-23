/**
 * @file main.cpp
 * @author me, myself and I
 * @brief test somma chiavi su un albero binario
 * @version 1.1
 * @date 2023-11-23
 */
#include "header.cpp"
#include <iostream>

int main() {

  int parent[11] = {-1, 0, 0, 1, 1, 2, 4, 4, 5, 8, 8};
  int info[11] = {12, 40, -2, -1, 10, 4, 7, 2, 1, 3, 9};
  char child_posi[11] = {'x', 'l', 'r', 'l', 'r', 'l', 'l', 'r', 'r', 'l', 'r'};
  parr vvv = new vector_parent(parent, info, child_posi, 11);

  T t = new tree();
  t->root = crea_albero(vvv);

  std::cout << "Visita a livelli (le foglie hanno una F davanti)" << std::endl;
  visita_in_ampiezza(t->root);
  std::cout << std::endl << std::endl;

  std::cout << "Somma chiavi foglie:" << somma_foglie(t);
}