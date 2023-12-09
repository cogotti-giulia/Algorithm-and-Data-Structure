/**
 * @file header.cpp
 * @author cogotti-giulia (cogotti.giulia.irl@gmail.com)
 * @brief implementazione metodi e funzioni
 * @version 1.0
 * @date 2023-12-09
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include "header.hpp"
#include <cmath>
#include <fstream>
#include <iostream>
#include <sstream>

pnode build_tree_balanced(const std::vector<int> &A, int p, int r) {
  if (p < r) {
    pnode nuovo = new node(A.at(r));
    int med = std::floor((p + r) / 2);
    
    nuovo->left = build_tree_balanced(A, p, med);
    nuovo->right = build_tree_balanced(A, med + 1, r-1);

    return nuovo;
  } else if(p==r){
    //* NON DIMENTICARTI DEL CASO BASE
    pnode nuovo = new node(A.at(r));
    return nuovo;
  }else{
    return nullptr;
  }
}

void post_order(pnode u) {
  if (u != nullptr) {
    post_order(u->left);
    post_order(u->right);
    std::cout << u->key << " ";
  }
}

void print_array(const std::vector<int> &a) {
  for (int i = 0; i < a.size(); i++)
    std::cout << a.at(i) << " ";

  std::cout << std::endl;
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