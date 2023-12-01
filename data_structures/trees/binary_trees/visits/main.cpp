/**
 * @file main.cpp
 * @author me, myself and I
 * @brief test visite ad un albero binario implementato tramite strutture
 * collegate con puntatori ai figli left e right e campo key
 * @version 1.1
 * @date 2023-11-23
 */
#include "header.cpp"
#include <iostream>

int main() {

  std::vector<char> info = {'A', 'L', 'B', 'E', 'R', 'O'};
  std::vector<int> parent = {-1, 0, 0, 1, 1, 2};
  std::vector<char> child_posi = {'x', 'l', 'r', 'l', 'r', 'r'};

  parr vet_parent = new vector_parent(parent, info, child_posi);

  T t = new tree();
  t->root = crea_albero(vet_parent);


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

  //esame 12-09-2016, esercizio 1
  /*
   *            a
   *          /   \
   *        b       h
   *      /   \       \
   *     c     g       i
   *      \           /
   *       d         l
   *      / \
   *     e   f
   * 
   */
  info.clear();
  parent.clear();
  child_posi.clear();

  info = {'a', 'b', 'h', 'c', 'g', 'i', 'd', 'l', 'e', 'f'};
  child_posi = {'x', 'l', 'r', 'l', 'r', 'r', 'r', 'l', 'l', 'r'};
  parent = {-1, 0, 0, 1, 1, 2, 3, 5, 6, 6};

  
  parr vet_parent_ = new vector_parent(parent, info, child_posi);

  T t1 = new tree();
  t1->root = crea_albero(vet_parent_);

  std::cout << "pre order (DFS):\t\t";
  visita_preorder_DFS(t1->root);
  std::cout << std::endl;
  std::cout << "in order (simmetrica):\t";
  visita_in_order_simmetrica(t1->root);
  std::cout << std::endl;
  std::cout << "post order:\t\t\t\t";
  visita_post_order(t1->root);
  std::cout << std::endl;
}
