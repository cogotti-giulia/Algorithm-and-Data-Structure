/**
 * @file main.cpp
 * @author me, myself and I
 * @brief test visite ad un albero binario implementato tramite strutture
 * collegate con puntatori ai figli left e right e campo key
 * @version 0.1
 * @date 2023-11-07
 *
 * @copyright Copyright (c) 2023
 *
 */
#include "header.cpp"
#include <iostream>

int main() {

  T tree = crea_albero_sx_dx();

  std::cout << "*** LEFT and RIGHT IMPLEMENTATION ***" << std::endl;
  std::cout << "pre order (DFS):\t\t";
  visita_preorder_DFS(tree->root);
  std::cout << std::endl;
  std::cout << "in order (simmetrica):\t";
  visita_in_order_simmetrica(tree->root);
  std::cout << std::endl;
  std::cout << "post order:\t\t\t\t";
  visita_post_order(tree->root);
  std::cout << std::endl;
  std::cout << "ampiezza (BFS):\t\t\t";
  visita_in_ampiezza_BFS(tree->root);
  std::cout << std::endl;
  std::cout << std::endl;
}
