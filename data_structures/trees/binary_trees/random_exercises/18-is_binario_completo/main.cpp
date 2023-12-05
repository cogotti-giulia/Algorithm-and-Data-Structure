/**
 * @file main.cpp
 * @author cogotti-giulia (cogotti.giulia.irl@gmail.com)
 * @brief test su alberi presi da file test.txt
 * @version 1.0
 * @date 2023-12-05
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include "header.cpp"
#include <vector>

int main(){
  std::vector<T> trees;

  trees = get_trees_from_file("test.txt");

  for(int i=0; i<trees.size(); i++){
    T t = trees.at(i);

    std::cout<<"preorder: ";
    pre_order(t->root);
    std::cout<<std::endl;
    std::cout<<"inorder: ";
    in_order(t->root);
    std::cout<<std::endl;

    if(is_binario_completo(t->root))
      std::cout<<"yep"<<std::endl;
    else
     std::cout<<"nope"<<std::endl;

    std::cout<<std::endl;

  }
}