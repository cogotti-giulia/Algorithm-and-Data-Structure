/**
 * @file header.cpp
 * @author cogotti-giulia (cogotti.giulia.irl@gmail.com)
 * @brief implementazione metodi e funzioni
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

T crea_BST_interval(T t, int k) {
  T new_tree = new tree();

  if (t->root != nullptr) {

    pnode new_root = new node(t->root->key);
    new_tree->root = new_root;

    pnode nuovo = new_tree->root;
    pnode succ = tree_successor(t->root);

    while (succ != nullptr && succ->key <= k) {

      nuovo->right = new node(succ->key);
      nuovo->right->p = nuovo;
      nuovo = nuovo->right;
      

      pnode tmp = succ;
      succ = tree_successor(tmp);
    }
  }

  return new_tree;
}

T crea_BST_interval_BALANCED(T t, int k) {
  T new_tree = new tree();
  std::vector<int> nuovo_keys;

  pnode scorri = t->root;

  while (scorri != nullptr && scorri->key <= k) {
    nuovo_keys.push_back(scorri->key);

    pnode tmp = scorri;
    scorri = tree_successor(tmp);
  }

  new_tree->root = build_BST_OTT_RIC(nuovo_keys, 0, nuovo_keys.size()-1, nullptr);

  return new_tree;
}

pnode build_BST_OTT_RIC(const std::vector<int>& A, int inf, int sup, pnode padre) {
  if (inf > sup)
    return nullptr;
  else {
    int med = std::floor((inf+sup)/2);
    pnode nuovo = new node(A.at(med));
    nuovo->p = padre;
    nuovo->left = build_BST_OTT_RIC(A, inf, med-1, nuovo);
    nuovo->right = build_BST_OTT_RIC(A, med+1, sup, nuovo);

    return nuovo;
  }
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

    return y;
  }
}

pnode tree_minimum(pnode x) {
  while (x->left != nullptr)
    x = x->left;

  return x;
}

void visita_simmetrica(T t) {
  if (t->root != nullptr) {
    pnode min = tree_minimum(t->root);
    std::cout << min->key << " ";
    pnode succ = tree_successor(min);

    while (succ != nullptr) {
      std::cout << succ->key << " ";
      pnode tmp = succ;
      succ = tree_successor(tmp);
    }
  }
  std::cout << std::endl;
}

void tree_insert(T tree, pnode z) {
  // padre del nodo con cui scorro
  pnode y = nullptr;
  // nodo per scendere lungo l'albero
  pnode scorri = tree->root;

  while (scorri != nullptr) {
    y = scorri; // scendo di livello
    if (z->key < scorri->key)
      scorri = scorri->left;
    else
      scorri = scorri->right;
  }
  // y è proprio il padre di z
  z->p = y;
  // caso in cui l'albero risulti essere vuoto
  if (y == nullptr)
    tree->root = z;
  else {
    // sistemo il figlio nella giusta posizione in base alla chiave
    if (z->key < y->key)
      y->left = z;
    else
      y->right = z;
  }
}