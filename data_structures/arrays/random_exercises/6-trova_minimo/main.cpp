/**
 * @file main.cpp
 * @author cogotti-giulia (cogotti.giulia.irl@gmail.com)
 * @brief test trova minimo su array (approccio divide et impera)
 * @version 1.0
 * @date 2023-12-09
 */

#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

int minimum(const std::vector<int> &A, int p, int r) {
  if (p == r) {
    return A.at(p);
  } else if (p < r) {
    int med = std::floor((p + r) / 2);
    int minSX = minimum(A, p, med);
    int minDX = minimum(A, med + 1, r);

    return std::min(minSX, minDX);
  } else {
    throw "ERRORE! L'array è vuoto, non esiste un elemento minimo";
    exit(false);
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
    std::vector<int> a = arrays.at(i);
    print_array(a);

    std::cout << "minimo: " << minimum(a, 0, a.size() - 1);
    std::cout << std::endl;
  }
}