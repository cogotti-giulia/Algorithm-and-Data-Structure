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
#include <cmath>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

int min_distance_abs(std::vector<int> &A, int *x, int *y) {
  int n = A.size();
  my_merge_sort(A, 0, n - 1); // n log n
  print_array(A);

  int i = 0;
  int j = 1;
  int min = A.at(j) - A.at(i);
  *x = A.at(i);
  *y = A.at(j);

  while (j < n - 1) {
    i++;
    j++;

    if ((A.at(j) - A.at(i)) < min) {
      *x = A.at(i);
      *y = A.at(j);
      min = A.at(j) - A.at(i);
    }
  }

  return min;
}

void my_merge_sort(std::vector<int> &A, int p, int r) {
  if (p < r) {
    int q = std::floor((p + r) / 2);
    my_merge_sort(A, p, q);
    my_merge_sort(A, q + 1, r);

    my_merge(A, p, q, r);
  }
}

void my_merge(std::vector<int> &A, int p, int q, int r) {
  int n1 = q - p + 1;
  int n2 = r - q;

  std::vector<int> L, R;

  for (int i = 0; i < n1; i++)
    L.push_back(A.at(p + i));

  for (int j = 0; j < n2; j++)
    R.push_back(A.at(q + j + 1));

  int k = p;
  int i = 0, j = 0;

  while (k <= r) {
    if (i < n1 && j < n2) {
      if (L.at(i) <= R.at(j)) {
        A.at(k) = L.at(i);
        i++;
      } else {
        A.at(k) = R.at(j);
        j++;
      }
    } else {
      if (i < n1) {
        A.at(k) = L.at(i);
        i++;
      } else {
        A.at(k) = R.at(j);
        j++;
      }
    }
    k++;
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