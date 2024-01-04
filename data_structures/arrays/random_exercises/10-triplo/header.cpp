/**
 * @file header.cpp
 * @author cogotti-giulia (cogotti.giulia.irl@gmail.com)
 * @brief implementazione metodi e funzioni
 * @version 1.0
 * @date 2024-01-04
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>

#include "header.hpp"

bool triplo(const std::vector<int> &A, int *i, int *j) {
  std::vector<pii> a;

  for (int i = 0; i < A.size(); i++) // n
    a.push_back(new ii(A.at(i), i));

  return my_merge_sort(a, 0, a.size() - 1, i, j); // nlogn
}

bool my_merge_sort(std::vector<pii> &a, int p, int r, int *i, int *j) {
  if (p < r) {
    int med = std::floor((p + r) / 2);
    bool ris1 = my_merge_sort(a, p, med, i, j);
    bool ris2 = my_merge_sort(a, med + 1, r, i, j);

    if (my_merge(a, p, med, r, i, j))
      return true;
    else {
      return ris1 || ris2;
    }
  } else {
    return false;
  }
}

bool my_merge(std::vector<pii> &a, int p, int q, int r, int *index1,
              int *index2) {
  int n1 = q - p + 1;
  int n2 = r - q;

  std::vector<pii> L;
  std::vector<pii> R;

  for (int i = 0; i < n1; i++)
    L.push_back(a.at(p + i));

  for (int j = 0; j < n2; j++)
    R.push_back(a.at(q + j + 1));

  int k = p;
  int i = 0, j = 0;

  bool is_triplo = false;

  while (k <= r && !is_triplo) {
    if (i < n1 && j < n2) {
      if ((L.at(i)->info * 3 == R.at(j)->info) ||
          (R.at(j)->info * 3 == L.at(i)->info)) {
        is_triplo = true;

        if (abs(L.at(i)->info) < abs(R.at(j)->info)) {
          *index1 = L.at(i)->index;
          *index2 = R.at(j)->index;
        } else {
          *index1 = R.at(j)->index;
          *index2 = L.at(i)->index;
        }
      }
      if (L.at(i)->info <= R.at(j)->info) {
        a.at(k) = L.at(i);
        i++;
      } else {
        a.at(k) = R.at(j);
        j++;
      }
    } else {
      if (i < n1) {
        a.at(k) = L.at(i);
        i++;
      } else {
        a.at(k) = R.at(j);
        j++;
      }
    }

    k++;
  }

  return is_triplo;
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