/**
 * @file header.cpp
 * @author cogotti-giulia (cogotti.giulia.irl@gmail.com)
 * @brief implementazione metodi e funzioni utilizzate
 * @version 1.0
 * @date 2023-12-18
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include "header.hpp"
#include <cmath>
#include <iostream>
#include <vector>

/**
 * @brief elimina i nodi di t che hanno chiavi maggiori di k
 * @pre k è una chiave sicuramente presente in t
 * @param t albero binario di ricerca
 * @param k chiave in t
 */
void elimina_maggiori_k(T t, int k) {
  if (t->root != nullptr) {
    pnode scorri = tree_maximum(t->root);

    while (scorri != nullptr && scorri->key > k) {
      pnode tmp = scorri;
      scorri = tree_predecessor(scorri);
      tree_delete(t, tmp);
    }
  }
}

pnode tree_maximum(pnode x) {
  while (x->right != nullptr)
    x = x->right;

  return x;
}

pnode tree_predecessor(pnode x) {
  if (x->left != nullptr)
    return tree_maximum(x->left);
  else {
    pnode padre = x->p;
    while (padre != nullptr && padre->left == x) {
      x = padre;
      padre = padre->p;
    }
    return padre;
  }
}

void transplant(T t, pnode old, pnode neww) {
  if (old->p == nullptr)
    t->root = neww;
  else if (old->p->left == old)
    old->p->left = neww;
  else
    old->p->right = neww;

  if (neww != nullptr)
    neww->p = old->p;
}

pnode tree_minimum(pnode x) {
  while (x->left != nullptr)
    x = x->left;
  return x;
}

void tree_delete(T t, pnode z) {
  if (z->left == nullptr)
    transplant(t, z, z->right);
  else if (z->right == nullptr)
    transplant(t, z, z->left);
  else {
    pnode y = tree_minimum(z->right);

    if (z->right != nullptr) {
      transplant(t, y, y->right);
      y->right = z->right;
      z->right->p = y;
    }

    transplant(t, z, y);
    y->left = z->left;
    y->left->p = y;
  }
}

T build_BST_OTT(const std::vector<int>& A) {
  T t = new tree();
  t->root = build_BST_OTT_AUX(A, 0, A.size() - 1, nullptr);
  return t;
}

pnode build_BST_OTT_AUX(const std::vector<int>& A, int p, int r, pnode padre) {
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

void reverse_in_order(T t, int k) {
  if (t->root != nullptr) {
    pnode scorri = tree_maximum(t->root);

    while (scorri != nullptr) {
      if (scorri->key == k)
        std::cout << "[" << scorri->key << "] ";
      else
        std::cout << scorri->key << " ";

      pnode tmp = scorri;
      scorri = tree_predecessor(tmp);
    }
    std::cout << std::endl;
  }
}