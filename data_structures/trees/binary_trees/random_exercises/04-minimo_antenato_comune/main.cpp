/**
 * @file main.cpp
 * @author me, myself and I
 * @brief test minimo antenato comune
 * @version 1.0
 * @date 2023-11-07
 */

#include "header.cpp"
#include <iostream>

int main() {

  T t = crea_albero();
  in_order(t->root);
  std::cout << std::endl;

  T_prof t_with_prof = new tree_with_prof();
  t_with_prof->root = build_albero_con_prof(t->root);

  in_order_prof(t_with_prof->root);
  std::cout << std::endl << std::endl;

  pnode_prof u = find_node(t_with_prof->root, 5);
  pnode_prof v = find_node(t_with_prof->root, 7);
  std::cout << "mac(5, 7) = " << mac(u, v)->key << std::endl;

  u = find_node(t_with_prof->root, 4);
  v = find_node(t_with_prof->root, 5);
  std::cout << "mac(4, 5) = " << mac(u, v)->key << std::endl;

  u = find_node(t_with_prof->root, 4);
  v = find_node(t_with_prof->root, 2);
  std::cout << "mac(4, 2) = " << mac(u, v)->key << std::endl;
}