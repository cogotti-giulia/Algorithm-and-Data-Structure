/**
 * @file header.cpp
 * @author cogotti-giulia (cogotti.giulia.irl@gmail.com)
 * @brief implementazione metodi e funzioni
 * @version 1.0
 * @date 2023-11-30
 */
#include "header.hpp"
#include <iostream>
#include <vector>

void sort_BST(std::vector<int> A) {
  T t = new tree();

  for (int i = 0; i < A.size(); i++) {
    pnode nuovo = new node(A.at(i)); // crea un nodo con p=left=right=nullptr
    tree_insert(t, nuovo);
  }

  visita_simmetrica_BST(t->root);
}

void tree_insert(T t, pnode z) {
  pnode padre = nullptr;
  pnode scorri = t->root;

  while (scorri != nullptr) {
    padre = scorri;
    if (z->key > scorri->key)
      scorri = scorri->right;
    else
      scorri = scorri->left;
  }

  z->p = padre;
  if (padre == nullptr) // albero vuoto
    t->root = z;
  else {
    if (z->key <= padre->key)
      padre->left = z;
    else
      padre->right = z;
  }
}

void visita_simmetrica_BST(pnode r) {
  std::cout << "BST: ";

  if (r != nullptr) {
    pnode min = tree_minimum(r);
    pnode succ = tree_successor(min);

    while (succ != nullptr) {
      std::cout << succ->key << " ";
      pnode tmp = succ;
      succ = tree_successor(tmp);
    }

    std::cout << std::endl;
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
    pnode y = x->p;
    while (y != nullptr && y->right == x) {
      x = y;
      y = y->p;
    }

    return x->p;
  }
}

void print_array(std::vector<int> A) {
  std::cout << "A: ";
  for (int i = 0; i < A.size(); i++)
    std::cout << A.at(i) << " ";
  std::cout << std::endl;
}