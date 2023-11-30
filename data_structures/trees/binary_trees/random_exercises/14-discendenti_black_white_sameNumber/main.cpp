/**
 * @file main.cpp
 * @author cogotti-giulia (cogotti.giulia.irl@gmail.com)
 * @brief test
 * @version 1.0
 * @date 2023-11-30
 */
#include "header.cpp"
#include <string>

int main() {
  std::vector<std::string> info = {"black", "white", "white", "black", "white",
                                   "black", "white", "white", "black", "white"};
  std::vector<int> parent = {-1, 0, 0, 1, 1, 2, 3, 5, 5, 8};
  std::vector<char> child_posi = {'z', 'l', 'r', 'l', 'r', 'l', 'r', 'l', 'r', 'l'};
  parr vet_parent = new vector_parent(parent, info, child_posi);

  T t = new tree();
  t->root = crea_albero(vet_parent);

  std::cout<<"post order visit"<<std::endl;
  post_order(t->root);
  std::cout<<std::endl;

  std::cout<<"Numero nodi: "<<discendenti_bw_sameNum(t->root);
}