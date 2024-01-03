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

ptree modify_key(ptree t, pnode x, int key) {
  if (x != nullptr) {
    x->key = key;

    pnode prev = tree_predecessor(x);
    pnode succ = tree_successor(x);

    if (prev != nullptr && prev->key > x->key)
      return nullptr;

    if (succ != nullptr && succ->key < x->key)
      return nullptr;
  }

  return t;
}

pnode tree_successor(pnode x) {
  if (x->right != nullptr)
    return tree_minimum(x->right);
  else {
    pnode y = x->p;

    while (y != nullptr && y->left != x) {
      x = y;
      y = x->p;
    }
    return y;
  }
}

pnode tree_minimum(pnode x) {
  while (x->left != nullptr)
    x = x->left;

  return x;
}

pnode tree_predecessor(pnode x) {
  if (x->left != nullptr)
    return tree_maximum(x->left);
  else {
    pnode y = x->p;

    while (y != nullptr && y->right != x) {
      x = y;
      y = x->p;
    }
    return y;
  }
}

pnode tree_maximum(pnode x) {
  while (x->right != nullptr)
    x = x->right;

  return x;
}

void in_order(pnode u, pnode x) {
  if (u != nullptr) {
    pnode scorri = tree_minimum(u);

    while (scorri != nullptr) {
      if (scorri == x)
        std::cout << "[ " << scorri->key << " ]"
                  << " ";
      else
        std::cout << scorri->key << " ";
      pnode tmp = scorri;
      scorri = tree_successor(tmp);
    }
  }

  std::cout << std::endl;
}

ptree build_BST_OTT(std::vector<int> A) {
  ptree t = new tree();
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

pnode find_node_by_key(pnode u, int key) {
  pnode scorri = u;
  while (scorri != nullptr && scorri->key != key) {
    if (scorri->key < key)
      scorri = scorri->right;
    else
      scorri = scorri->left;
  }

  return scorri;
}