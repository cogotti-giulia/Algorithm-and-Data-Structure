/**
 * @file main.cpp
 * @author me, myself and I
 * @brief test verifica se l'albero è k limitato
 * @version 1.0
 * @date 2023-11-09
 */
#include "header.cpp"
#include <iostream>

int main() {
  T t = crea_albero();

  int k = 7;
  if (k_limitato(t->root, k))
    std::cout << "yep! t è k = " << k << " limitato";
  else
    std::cout << "nope! t NON è k = " << k << " limitato";
}