/**
 * @file main.cpp
 * @author me, myself and I
 * @brief test della trasformazione delle chiavi a livello pari
 * @version 1.0
 * @date 2023-11-08
 */
#include "header.cpp"
#include <iostream>

int main() {
  T t = crea_albero();

  visita_preorder_DFS(t->root);
  trasforma(t->root);
  std::cout << std::endl;
  visita_preorder_DFS(t->root);
}