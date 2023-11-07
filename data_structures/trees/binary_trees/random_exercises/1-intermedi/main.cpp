/**
 * @file main.cpp
 * @author me, myself and I
 * @brief test nodi intermedi
 * @version 1.0
 * @date 2023-11-07
 */
#include "header.cpp"
#include <iostream>

int main() {
  T tree = crea_albero();

  visita_in_ampiezza_BFS(tree->root);
  std::cout << std::endl;
  std::cout << "numero di nodi intermedi: " << intermedi(tree->root);
}
