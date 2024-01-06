/**
 * @file main.cpp
 * @author cogotti-giulia (cogotti.giulia.irl@gmail.com)
 * @brief test e funzioni
 * @version 1.0
 * @date 2024-01-06
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

void ordina_01(std::vector<int>& A){
  int i = 0;
  int j = A.size()-1;

  while(i < j){
    if(A.at(i) == 0)
      i++;
    else{
      if(A.at(j) == 0){
        //scambio
        int tmp = A.at(i);
        A.at(i) = A.at(j);
        A.at(j) = tmp;
        i++;
        j--;
      }else
        j--;
    }
  }
}

void print_array(const std::vector<int> &A){
  for(int i = 0; i < A.size(); i++)
    std::cout<<A.at(i)<<" ";
}

std::vector<std::vector<int>> get_arrays_from_file(std::string file_name) {
  std::string line;

  std::vector<std::vector<int>> arrays;

  std::ifstream my_file(file_name);
  if (my_file.is_open()) {
    while (!my_file.eof()) {
      std::vector<int> arr;

      if (getline(my_file, line)) {
        std::stringstream ss(line);
        int n;
        while (ss >> n)
          arr.push_back(n);
      }
      arrays.push_back(arr);
    }

    my_file.close();
  }

  return arrays;
}

int main(){
  
  std::vector<std::vector<int>> arrays = get_arrays_from_file("test.txt");

  for(int i = 0; i < arrays.size(); i++){
    std::vector<int> A = arrays.at(i);
    print_array(A);
    std::cout<<" ~> ";
    ordina_01(A);
    print_array(A);

    std::cout<<std::endl<<std::endl;
  }
}