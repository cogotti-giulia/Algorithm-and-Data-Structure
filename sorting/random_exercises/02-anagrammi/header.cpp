/**
 * @file header.cpp
 * @author me, myself and I
 * @brief implementazioni metodi e funzioni
 * @version 1.0
 * @date 2023-11-28
 */
#include "header.hpp"
#include <cmath>
#include <iostream>
#include <vector>

//! T(n) = O(n logn)
bool anagramma(std::vector<char> *A, std::vector<char> *B) {
  int n = A->size();
  my_merge_sort(A, 0, n - 1); //? T(n) = O(n logn)
  my_merge_sort(B, 0, n - 1); //? T(n) = O(n logn)

  bool is_anagramma = true;
  int i = 0;

  while (i < n && is_anagramma) { //? T(n) = O(n)
    if (A->at(i) != B->at(i))
      is_anagramma = false;
    i++;
  }
  return is_anagramma;
}

void my_merge_sort(std::vector<char> *A, int p, int r) {
  if (p < r) {
    int q = std::floor((p + r) / 2);
    my_merge_sort(A, p, q);
    my_merge_sort(A, q + 1, r);

    my_merge(A, p, q, r);
  }
}

void my_merge(std::vector<char> *A, int p, int q, int r) {
  int n1 = q - p + 1;
  int n2 = r - q;

  std::vector<char> L(n1);

  std::vector<char> R(n2);

  for (int i = 0; i < n1; i++)
    L.at(i) = A->at(p + i);

  for (int j = 0; j < n2; j++)
    R.at(j) = A->at(q + j + 1);

  int i = 0, j = 0, k = p;

  while (i < n1 && j < n2) {
    if (L.at(i) <= R.at(j)) {
      A->at(k) = L.at(i);
      i++;
    } else {
      A->at(k) = R.at(j);
      j++;
    }
    k++;
  }

  while (i < n1) {
    A->at(k) = L.at(i);
    i++;
    k++;
  }

  while (j < n2) {
    A->at(k) = R.at(j);
    j++;
    k++;
  }
}

void print_string(std::vector<char> A) {
  for (int i = 0; i < A.size(); i++) {
    std::cout << A.at(i) << " ";
  }
  std::cout << std::endl;
}