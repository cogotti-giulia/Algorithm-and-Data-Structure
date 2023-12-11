/**
 * @file main.cpp
 * @author cogotti-giulia (cogotti.giulia.irl@gmail.com)
 * @brief test
 * @version 1.0
 * @date 2023-11-30
 */
#include "header.cpp"
#include <vector>

int main(){
  std::vector<int> A = {-1, 7, 3, 4, 11, 0, -2, 5, 3};

  print_array(A);
  sort_BST(A);
} 