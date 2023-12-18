/**
 * @file header.cpp
 * @author me, myself and I
 * @brief implementazione funzioni e metodi
 * @version 1.0
 * @date 2023-11-08
 */
#include "header.hpp"
#include <cmath>
#include <cstddef>
#include <iostream>

int min_distance(T t) {
  // per ipotesi esistono almeno due nodi in t
  pnode x = tree_minimum(t->root);
  pnode y = tree_successor(x);

  int min_distance = std::abs(y->key - x->key);
  x = tree_successor(y);
  while (x != nullptr) {

    int diff = std::abs(x->key - y->key);
    if (diff < min_distance)
      min_distance = diff;
    y = x;
    x = tree_successor(y);
  }
  return min_distance;
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
    pnode scorri = x;
    while (scorri->p != nullptr && scorri != scorri->p->left) {
      scorri = scorri->p;
    }

    return scorri->p;
  }
}

T build_BST_OTT(int *A, size_t n) {
  T t = new tree();
  t->root = build_BST_OTT_AUX(A, 0, n - 1, nullptr);
  return t;
}

pnode build_BST_OTT_AUX(int *A, int inf, int sup, pnode padre) {
  if (inf > sup) // vettore vuoto
    return nullptr;
  else {
    int med = std::floor((inf + sup) / 2);
    pnode nuovo = new node(A[med]);
    nuovo->p = padre;
    nuovo->left = build_BST_OTT_AUX(A, inf, med - 1, nuovo);
    nuovo->right = build_BST_OTT_AUX(A, med + 1, sup, nuovo);
    return nuovo;
  }
}

void in_order(pnode u) {
  if (u != nullptr) {
    in_order(u->left);
    std::cout << u->key << " ";
    in_order(u->right);
  }
}