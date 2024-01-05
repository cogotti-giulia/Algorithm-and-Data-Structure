/**
 * @file main.cpp
 * @author cogotti-giulia (cogotti.giulia.irl@gmail.com)
 * @brief test
 * @version 1.0
 * @date 2024-01-05
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "header.cpp"
#include <vector>

int main(){
  std::vector<int> N;
  std::vector<std::vector<int>> arrays = get_arrays_from_file("test.txt", N);

  for(int i = 0; i < arrays.size(); i++){
    std::vector<int> A = arrays.at(i);

    print_array(A);

    print_missing_numbers(A, N.at(i));
  }
}