/**
 * @file header.cpp
 * @author me, myself and I
 * @brief implementazione funzioni e metodi
 * @version 1.0
 * @date 2023-11-08
 */
#include "header.hpp"
#include <cmath>
#include <iostream>

/****************************check con definizione BST*************************/
bool check_BST_DEF(pnode u) {
  if (u == nullptr)
    return true; // albero vuoto è BST
  else {
    int min = u->key;
    int max = u->key;
    return check_BST_DEF_AUX(u, &min, &max);
  }
}

bool check_BST_DEF_AUX(pnode u, int *min, int *max) {
  bool risSX, risDX;
  int minSX, maxSX, minDX, maxDX;

  if (u->left == nullptr) {
    risSX = true;
    minSX = u->key;
    maxSX = u->key;
  } else
    risSX = check_BST_DEF_AUX(u->left, &minSX, &maxSX);

  if (u->right == nullptr) {
    risDX = true;
    minDX = u->key;
    maxDX = u->key;
  } else
    risDX = check_BST_DEF_AUX(u->right, &minDX, &maxDX);

  if (!risSX || !risDX || u->key < maxSX || u->key > minDX)
    return false;
  else {
    *min = minSX;
    *max = maxDX;
    return true;
  }
}
/***************************************end************************************/

/****************************check altra proprietà BST*************************/
bool check_BST_NO_DEF(pnode u) {
  if (u == nullptr)
    return true;
  else {
    bool is_bst = true;
    pnode x = tree_minimum(u);
    pnode y = tree_successor(x);

    if (y->key < x->key) {
      is_bst = false;
    } else {
      x = tree_successor(y);
      while (x != nullptr && is_bst) {
        if (x->key < y->key)
          is_bst = false;

        y = x;
        x = tree_successor(x);
      }
    }
    return is_bst;
  }
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
    while (scorri->p != nullptr && scorri->p->left != scorri)
      scorri = scorri->p;
    return scorri->p;
  }
}

/***************************************end************************************/

T build_BST_OTT(int *A, std::size_t n) {
  T t = new tree();
  t->root = build_BST_OTT_AUX(A, 0, n - 1, nullptr);
  return t;
}

pnode build_BST_OTT_AUX(int *A, int inf, int sup, pnode padre) {
  if (inf > sup)
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