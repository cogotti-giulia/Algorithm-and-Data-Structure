/**
 * @file main.cpp
 * @author me, myself and I
 * @brief test
 * @version 1.0
 * @date 2023-11-29
 */
#include "header.cpp"
#include <iostream>

int main() {
  T t = crea_albero();

  visita_post_order(t->root);
  std::cout << std::endl;

  std::cout << "Nodi i cui i figli hanno la stessa chiave: "
            << node_childrenSameKey(t->root);
}