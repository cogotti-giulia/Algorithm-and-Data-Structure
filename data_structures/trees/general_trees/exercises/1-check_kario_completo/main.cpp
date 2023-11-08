/**
 * @file main.cpp
 * @author me, myself and I
 * @brief test verifica se l'albero generale è k ario completo
 * @version 1.0
 * @date 2023-11-08
 */
#include "header.cpp"
#include <iostream>

int main() {
  T t = crea_albero();

  if (is_k_ario(t->root, 3))
    std::cout << "yey";
  else
    std::cout << "nope";
}