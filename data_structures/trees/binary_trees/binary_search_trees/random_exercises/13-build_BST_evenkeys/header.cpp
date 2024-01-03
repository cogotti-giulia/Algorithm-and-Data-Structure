/**
 * @file header.cpp
 * @author cogotti-giulia (cogotti.giulia.irl@gmail.com)
 * @brief implementazione metodi e funzioni
 * @version 1.0
 * @date 2024-01-03
 *
 * @copyright Copyright (c) 2024
 *
 */
#include "header.hpp"
#include <cmath>
#include <iostream>
#include <vector>

T build_BST_even_keys(T t) {
  T tris = new tree();

  if (t != nullptr) {
    std::vector<int> A = get_even_keys_from_T(t);
    tris = build_BST_OTT(A);
  }

  return tris;
}

std::vector<int> get_even_keys_from_T(T t) {
  std::vector<int> A;

  pnode scorri = tree_minimum(t->root);

  while (scorri != nullptr) {
    if (scorri->key % 2 == 0)
      A.push_back(scorri->key);

    pnode tmp = scorri;
    scorri = tree_successor(tmp);
  }

  return A;
}

pnode tree_minimum(pnode x) {
  while (x->left != nullptr)
    x = x->left;

  return x;
}

pnode tree_successor(pnode x) {
  if (x->right != nullptr)
    return tree_minimum(x->right);
  else {
    pnode y = x->p;

    while (y != nullptr && y->left != x) {
      x = y;
      y = y->p;
    }

    return y;
  }
}

T build_BST_OTT(std::vector<int> A) {
  T t = new tree();
  t->root = build_BST_OTT_AUX(A, 0, A.size() - 1, nullptr);
  return t;
}

pnode build_BST_OTT_AUX(std::vector<int> A, int p, int r, pnode padre) {
  if (p > r)
    return nullptr;
  else {
    int med = std::floor((p + r) / 2);
    pnode nuovo = new node(A.at(med));
    nuovo->p = padre;
    nuovo->left = build_BST_OTT_AUX(A, p, med - 1, nuovo);
    nuovo->right = build_BST_OTT_AUX(A, med + 1, r, nuovo);

    return nuovo;
  }
}

void in_order(T t) {
  pnode scorri = tree_minimum(t->root);

  while (scorri != nullptr) {
    std::cout << scorri->key << " ";
    pnode tmp = scorri;
    scorri = tree_successor(tmp);
  }

  std::cout << std::endl << std::endl;
}