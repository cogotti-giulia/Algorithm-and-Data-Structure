/**
 * @file main.cpp
 * @author cogotti-giulia (cogotti.giulia.irl@gmail.com)
 * @brief codice funzioni e test su vettori presi da file
 * @version 1.0
 * @date 2024-01-03
 *
 * @copyright Copyright (c) 2024
 *
 */
#include <cmath>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

bool kind_of_merge(std::vector<int> &A, int p, int q, int r) {
  int n1 = q - p + 1;
  int n2 = r - q;

  std::vector<int> L;
  std::vector<int> R;

  for (int i = 0; i < n1; i++)
    L.push_back(A.at(p + i));

  for (int j = 0; j < n2; j++)
    R.push_back(A.at(q + j + 1));

  int k = p;
  int i = 0, j = 0;

  bool ris = true;

  while (k <= r && ris) {
    if (i < n1 && j < n2) {
      if (L.at(i) < R.at(j)) {
        A.at(k) = L.at(i);
        i++;
      } else if (L.at(i) > R.at(j)) {
        A.at(k) = R.at(j);
        j++;
      } else {
        ris = false;
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

  return ris;
}

bool has_valori_distinti(std::vector<int> &A, int p, int r) {
  if (p < r) {
    int q = std::floor((p + r) / 2);
    has_valori_distinti(A, p, q);
    has_valori_distinti(A, q + 1, r);

    return kind_of_merge(A, p, q, r);
  } else {
    return true;
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

int main() {
  std::vector<std::vector<int>> arrays = get_arrays_from_file("test.txt");

  for (int i = 0; i < arrays.size(); i++) {
    std::vector<int> A = arrays.at(i);
    print_array(A);

    std::cout << (has_valori_distinti(A, 0, A.size() - 1) == 1
                      ? "i valori sono tutti distinti"
                      : "esiste almeno un valore duplicato")
              << std::endl
              << std::endl;
  }
}