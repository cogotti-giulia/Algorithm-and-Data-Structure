/**
 * @file main.cpp
 * @author cogotti-giulia (cogotti.giulia.irl@gmail.com)
 * @brief test
 * @version 1.0
 * @date 2023-12-01
 */
#include "header.cpp"
#include <vector>

int main(){
  std::vector<int> va = {1, 2, 4, 5, 3, 6};
  std::vector<int> vs = {4, 2, 5, 1, 3, 6};

  std::cout<<"array pre order (anticipata): ";
  print_vector(va);
   std::cout<<"array in order: (simmetrica): ";
  print_vector(vs);

  T t = new tree();
  t->root = ricostruisci(va, vs);
  
  std::cout<<"visita pre order albero costruito: ";
  pre_order(t->root);
  std::cout<<std::endl;
    
  std::cout<<"visita in order albero costruito: ";
  in_order(t->root);
}