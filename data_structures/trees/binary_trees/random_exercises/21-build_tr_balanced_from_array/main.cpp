/**
 * @file main.cpp
 * @author cogotti-giulia (cogotti.giulia.irl@gmail.com)
 * @brief test
 * @version 1.0
 * @date 2023-12-09
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include "header.cpp"
#include <vector>

int main(){
  std::vector<std::vector<int>> arrays = get_arrays_from_file("test.txt");

  for(int i = 0; i < arrays.size(); i++){
    std::vector<int> a = arrays.at(i);
    std::cout<<"A: ";
    print_array(a);
    pnode u = build_tree_balanced(a, 0, a.size()-1);

    std::cout<<"T: ";
    post_order(u);

    std::cout<<std::endl;

  }
}