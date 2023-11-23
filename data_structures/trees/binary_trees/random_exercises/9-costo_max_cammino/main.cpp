/**
 * @file main.cpp
 * @author me, myself and I
 * @brief test costo massimo albero binario
 * @version 1.0
 * @date 2023-11-23
 */
#include "header.cpp"
#include <iostream>

int main(){

  int parent[6] = {-1, 0, 0, 1, 2, 2};
  int info[6] = {1, 5, -2, 3, 7, -9};
  char child_posi[6] = {'x', 'l', 'r', 'l', 'l', 'r'};

  parr vet_padri = new vector_parent(parent, info, child_posi, 6);

  T t = new tree();
  t->root = crea_albero(vet_padri);

  std::cout<<"costo massimo: "<<costo_max_cammino(t->root);
}