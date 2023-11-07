/**
 * @file main.cpp
 * @author me, myself and I
 * @brief test albero t bilanciato
 * @version 1.0
 * @date 2023-11-07
 */
#include <iostream>
#include "header.cpp"

int main() {
  T t = crea_albero();

  visita_in_ampiezza_BFS(t->root);

  std::cout << endl;
  std::cout << t_bilanciato(t->root);
}