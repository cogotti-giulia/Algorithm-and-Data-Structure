/**
 * @file main.cpp
 * @author cogotti-giulia (cogotti.giulia.irl@gmail.com)
 * @brief test
 * @version 1.0
 * @date 2023-12-01
 */
#include "header.cpp"
#include <iostream>

int main() {
  std::vector<int> info = {4, 2, 3, 3, -1, -87, 7};
  std::vector<int> parent = {-1, 0, 0, 0, 1, 1, 3};
  std::vector<bool> is_left_child = {false, true,  false, false,
                                     true,  false, true};

  parrG vet_parent = new vector_parent(parent, info, is_left_child);

  T t = new tree();
  t->root = crea_albero(vet_parent);
  
  visita_post_order(t->root);
  std::cout << std::endl;

  if (is_not_decr(t->root)) {
    std::cout << "le chiavi dei figli di ogni nodo sono tutte non decrescenti";
  } else {
    std::cout
        << "le chiavi dei figli di ogni nodo NON sono tutte non decrescenti";
  }
}