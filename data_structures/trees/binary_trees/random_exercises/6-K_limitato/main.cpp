/**
 * @file main.cpp
 * @author me, myself and I
 * @brief test verifica se l'albero è k limitato
 * @version 1.1
 * @date 2023-11-23
 */
#include "header.cpp"
#include <iostream>

int main() {
  int info[7] = {1, 2, 5, 4, -2, 1, 3};
  int parent[7] = {-1, 0, 0 ,1, 1, 2, 4};
  char child_posi[7] = {'x', 'l', 'r', 'l', 'r', 'l', 'l'};
  
  parr vvv = new vector_parent(parent, info, child_posi, 7);

  T t = new tree();
  t->root = crea_albero(vvv);

  int k = 7;
  if (k_limitato(t->root, k))
    std::cout << "yep! t è k = " << k << " limitato";
  else
    std::cout << "nope! t NON è k = " << k << " limitato";
}