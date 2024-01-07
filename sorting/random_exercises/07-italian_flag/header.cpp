/**
 * @file header.cpp
 * @author cogotti-giulia (cogotti.giulia.irl@gmail.com)
 * @brief implementazione
 * @version 1.0
 * @date 2024-01-07
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "header.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

void italian_flag(std::vector<char> &A) {
  int i = 0, j = 0;
  int k = A.size() - 1;

  while (j <= k) {
    if (A.at(j) == 'V') {
      my_swap(A, i, j);
      i++;
      j++;
    } else if (A.at(j) == 'B') {
      j++;
    } else {
      my_swap(A, j, k);
      k--;
    }
  }
}

void my_swap(std::vector<char> &A, int i1, int i2) {
  char tmp = A.at(i1);
  A.at(i1) = A.at(i2);
  A.at(i2) = tmp;
}

void print_array(const std::vector<char> &A) {
  for (int i = 0; i < A.size(); i++)
    std::cout << A.at(i) << " ";
}

std::vector<std::vector<char>> get_arrays_from_file(std::string file_name) {
  std::string line;

  std::vector<std::vector<char>> arrays;

  std::ifstream my_file(file_name);
  if (my_file.is_open()) {
    while (!my_file.eof()) {
      std::vector<char> arr;

      if (getline(my_file, line)) {
        std::stringstream ss(line);
        char n;
        while (ss >> n)
          arr.push_back(n);
      }
      arrays.push_back(arr);
    }

    my_file.close();
  }

  return arrays;
}
