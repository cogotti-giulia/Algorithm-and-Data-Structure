/**
 * @file main.cpp
 * @author cogotti-giulia (cogotti.giulia.irl@gmail.com)
 * @brief test
 * @version 1.1
 * @date 2023-12-01
 */
#include "header.cpp"
#include <iostream>

int main() {


  std::vector<char> info = {'A', 'L', 'B', 'E', 'R', 'O'};
  std::vector<int> parent = {-1, 0, 0, 1, 1, 2};
  std::vector<bool> is_left_child = {false, true, false, true, false, true};

  parrG vet_parent = new vector_parent(parent, info, is_left_child);

  T t = new tree();
  t->root = crea_albero(vet_parent);

  std::cout << "pre order (DFS):\t\t";
  visita_preorder_DFS(t->root);
  std::cout << std::endl;
  std::cout << "post order:\t\t\t\t\t";
  visita_post_order(t->root);
  std::cout << std::endl;
  std::cout << "ampiezza (BFS):\t\t\t";
  visita_in_ampiezza_BFS(t->root);
  std::cout << std::endl;
  std::cout << std::endl;
}