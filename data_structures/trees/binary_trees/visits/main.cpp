/**
 * @file main.cpp
 * @author me, myself and I
 * @brief test visite ad un albero binario implementato tramite strutture
 * collegate con puntatori ai figli left e right e campo key
 * @version 1.1
 * @date 2023-11-23
 *
 * @copyright Copyright (c) 2023
 *
 */
#include "header.cpp"
#include <iostream>

int main() {

  char info[6] = {'A', 'L', 'B', 'E', 'R', 'O'};
  char child_posi[6] = {'x', 'l', 'r', 'l', 'r', 'r'};
  int parent[6] = {-1, 0, 0, 1, 1, 2};

  parr vvv = new vector_parent(parent, info, child_posi, 6);
  
  T t = new tree();
  t->root = crea_albero(vvv);

  std::cout << "*** LEFT and RIGHT IMPLEMENTATION ***" << std::endl;
  std::cout << "pre order (DFS):\t\t";
  visita_preorder_DFS(t->root);
  std::cout << std::endl;
  std::cout << "in order (simmetrica):\t";
  visita_in_order_simmetrica(t->root);
  std::cout << std::endl;
  std::cout << "post order:\t\t\t\t";
  visita_post_order(t->root);
  std::cout << std::endl;
  std::cout << "ampiezza (BFS):\t\t\t";
  visita_in_ampiezza_BFS(t->root);
  std::cout << std::endl;
  std::cout << std::endl;
}
