/**
 * @file header.cpp
 * @author cogotti-giulia (cogotti.giulia.irl@gmail.com)
 * @brief implementazione metodi e funzioni
 * @version 1.0
 * @date 2024-01-05
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "header.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

void print_missing_numbers(const std::vector<int> &S, int N) {

  std::vector<int> occ(N + 1);

  for (int i = 0; i < occ.size(); i++) // Teta(n)
    occ.at(i) = 0;

  for (int j = 0; j < S.size(); j++) // Teta(k)
    occ.at(S.at(j))++;

  for (int i = 1; i < occ.size(); i++) // Teta(n)
    if (occ.at(i) == 0)
      std::cout << i << " ";

  std::cout << std::endl;
}

void print_array(const std::vector<int> &A) {
  for (int i = 0; i < A.size(); i++)
    std::cout << A.at(i) << " ";

  std::cout << std::endl;
}


std::vector<std::vector<int>> get_arrays_from_file(std::string file_name, std::vector<int>& N) {
  std::string line;

  std::vector<std::vector<int>> arrays;

  std::ifstream my_file(file_name);
  if (my_file.is_open()) {
    while (!my_file.eof()) {
      std::vector<int> arr;

      if (getline(my_file, line)) {
        std::stringstream ss(line);
        int n;

        ss >>n;
        N.push_back(n);
        
        while (ss >> n)
          arr.push_back(n);
      }
      arrays.push_back(arr);
    }

    my_file.close();
  }

  return arrays;
}