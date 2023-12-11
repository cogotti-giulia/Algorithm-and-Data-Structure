/**
 * @file main.cpp
 * @author cogotti-giulia (cogotti.giulia.irl@gmail.com)
 * @brief test
 * @version 1.0
 * @date 2023-12-11
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include "header.cpp"
#include <vector>

int main(){

  std::vector<int> keys = {5, 3, 7, 12, 6, 13};

  T_s t = new tree();

  for(int i = 0; i < keys.size(); i++){
    pnode_s nuovo = new node(keys.at(i));
    tree_insert_sum(t, nuovo);
    visita_simmetrica(t);
    std::cout<<std::endl;
  }
}