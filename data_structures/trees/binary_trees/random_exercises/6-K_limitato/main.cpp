/**
 * @file main.cpp
 * @author cogotti-giulia
 * @brief test verifica se l'albero è k limitato
 * @version 1.2
 * @date 2023-11-29
 */
#include "header.cpp"
#include <iostream>

int main() {

  std::vector<int> info = {1, 2, 5, 4, -2, 1, 3};
  std::vector<int> parent = {-1, 0, 0 ,1, 1, 2, 4};
  std::vector<char> child_posi = {'z', 'l', 'r', 'l', 'r', 'l', 'l'};
  parr vet_parent = new vector_parent(parent, info, child_posi);

  T t = new tree();
  t->root = crea_albero(vet_parent);

  int k = 7;
  if (k_limitato(t->root, k))
    std::cout << "yep! t è k = " << k << " limitato";
  else
    std::cout << "nope! t NON è k = " << k << " limitato";
}