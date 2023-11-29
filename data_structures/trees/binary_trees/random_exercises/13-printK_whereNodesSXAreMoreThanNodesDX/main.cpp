/**
 * @file main.cpp
 * @author cogotti-giulia (cogotti.giulia.irl@gmail.com)
 * @brief test 
 * @version 1.0
 * @date 2023-11-29
 */
#include "header.cpp"
#include <vector>

int main(){

  std::vector<int> info = {30, 25, 40, 21, 35, 45, 50};
  std::vector<int> parent = {-1, 0, 0, 1, 2, 2, 5};
  std::vector<char> child_posi = {'x', 'l', 'r', 'l', 'l', 'r', 'r'};

  parr vet_parent = new vector_parent(parent, info, child_posi);

  T t = new tree();
  t->root = crea_albero(vet_parent);

  pre_order(t->root);

  std::cout<<std::endl;

  stampaK_nodeSX_mag_nodeDX(t->root);
}