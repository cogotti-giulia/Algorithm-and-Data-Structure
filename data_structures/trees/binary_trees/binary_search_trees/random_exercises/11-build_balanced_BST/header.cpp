/**
 * @file header.cpp
 * @author cogotti-giulia (cogotti.giulia.irl@gmail.com)
 * @brief implementazione metodi e funzioni
 * @version 1.0
 * @date 2023-12-16
 *
 * @copyright Copyright (c) 2023
 *
 */
#include "header.hpp"
#include <cmath>
#include <iostream>
#include <vector>

T build_bst_height_logn(std::vector<int> &A) {
  my_merge_sort(A, 0, A.size() - 1);
  T t = new tree();
  t->root = build_bst_height_logn_AUX(A, 0, A.size() - 1);
  return t;
}

pnode build_bst_height_logn_AUX(const std::vector<int> &A, int p, int r) {
  if (p > r)
    return nullptr;
  else {
    int med = std::floor((p + r) / 2);
    pnode nuovo = new node(A.at(med));
    nuovo->left = build_bst_height_logn_AUX(A, p, med - 1);
    nuovo->right = build_bst_height_logn_AUX(A, med + 1, r);
    return nuovo;
  }
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

void in_order(pnode u) {
  if (u != nullptr) {
    in_order(u->left);
    std::cout << u->key << " ";
    in_order(u->right);
  }
}

void stampa_array(const std::vector<int> &A) {
  for (int i = 0; i < A.size(); i++)
    std::cout << A.at(i) << " ";

  std::cout << std::endl;
}