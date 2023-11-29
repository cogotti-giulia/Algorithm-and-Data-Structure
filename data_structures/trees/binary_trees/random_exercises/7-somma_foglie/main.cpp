/**
 * @file main.cpp
 * @author cogotti-giulia
 * @brief test somma chiavi su un albero binario
 * @version 1.2
 * @date 2023-11-29
 */
#include "header.cpp"
#include <iostream>

int main() {

  std::vector<int> info = {-1, 0, 0, 1, 1, 2, 4, 4, 5, 8, 8};
  std::vector<int> parent = {-1, 0, 0, 1, 1, 2, 4, 4, 5, 8, 8};
  std::vector<char> child_posi = {'x', 'l', 'r', 'l', 'r', 'l', 'l', 'r', 'r', 'l', 'r'};
  parr vet_parent = new vector_parent(parent, info, child_posi);

  T t = new tree();
  t->root = crea_albero(vet_parent);

  std::cout << "Visita a livelli (le foglie hanno una F davanti)" << std::endl;
  visita_in_ampiezza(t->root);
  std::cout << std::endl << std::endl;

  std::cout << "Somma chiavi foglie:" << somma_foglie(t);
}