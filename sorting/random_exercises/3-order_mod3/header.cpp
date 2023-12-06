/**
 * @file header.cpp
 * @author cogotti-giulia (cogotti.giulia.irl@gmail.com)
 * @brief implementazione metodi e funzioni
 * @version 1.0
 * @date 2023-12-06
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include "header.hpp"
#include <cmath>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

void merge_sort_mod3(std::vector<int> *A, int p, int r) {
  if (p < r) {
    int q = std::floor((p + r) / 2);
    merge_sort_mod3(A, p, q);
    merge_sort_mod3(A, q + 1, r);
    merge_mod3(A, p, q, r);
  }
}

void merge_mod3(std::vector<int> *A, int p, int q, int r) {
  int n1 = q - p + 1;
  int n2 = r - q;

  std::vector<int> L(n1);
  std::vector<int> R(n2);

  for (int i = 0; i < n1; i++)
    L.at(i) = A->at(p + i);
  for (int j = 0; j < n2; j++)
    R.at(j) = (A->at(q + 1 + j));

  int k = p;
  int i = 0, j = 0;

  while (k <= r) { // eseguito r-p+1 volte
    if (i < n1 && j < n2) {
      if (L.at(i) % 3 <= R.at(j) % 3) {
        A->at(k) = L.at(i);
        i++;
      } else {
        A->at(k) = R.at(j);
        j++;
      }
    } else if (i < n1) {
      A->at(k) = L.at(i);
      i++;
    } else {
      A->at(k) = R.at(j);
      j++;
    }
    k++;
  }
}

std::vector<std::vector<int>> get_arrays_from_file(std::string file_name) {
  std::vector<std::vector<int>> vv;

  std::ifstream my_file(file_name);
  std::string line;

  if (my_file.is_open()) {
    while (getline(my_file, line)) {
      std::vector<int> v;

      std::stringstream ss(line);
      int el;
      while (ss >> el) {
        v.push_back(el);
      }

      vv.push_back(v);
    }

    my_file.close();
  } else {
    std::cout << "The file doesn t exist!";
    exit(false);
  }

  return vv;
}

void print_vector_and_mod3(const std::vector<int> &A) {
  std::cout << "A: \t\t\t";
  for (int i = 0; i < A.size(); i++)
    std::cout << A.at(i) << " ";
  std::cout << std::endl;

  std::cout << "A[i]%3: ";
  for (int i = 0; i < A.size(); i++)
    std::cout << (A.at(i) % 3) << " ";

  std::cout << std::endl << std::endl;
}