/**
 * @file header.cpp
 * @author cogotti-giulia (cogotti.giulia.irl@gmail.com)
 * @brief implementazione metodi e funzioni
 * @version 1.0
 * @date 2023-12-12
 *
 * @copyright Copyright (c) 2023
 *
 */
#include "header.hpp"
#include <iostream>

T build_new_tree(T t1, T t2) {
  T new_tree = new tree();

  if (t2->root == nullptr)
    new_tree->root = t1->root;
  else {
    pnode min_t2 = tree_minimum(t2->root);
    pnode r = new node(min_t2->key);

    tree_delete(t2, min_t2);

    r->left = t1->root;
    r->right = t2->root;
    r->right->p = r;
    r->left->p = r;

    new_tree->root = r;
  }

  return new_tree;
}

pnode tree_minimum(pnode x) {
  while (x->left != nullptr)
    x = x->left;

  return x;
}

void transplant(T tree, pnode old, pnode neww) {
  if (old->p == nullptr)
    tree->root = neww;
  else {
    if (old->p->left == old)
      old->p->left = neww;
    else
      old->p->right = neww;
  }

  if (neww != nullptr)
    neww->p = old->p;
}

void tree_delete(T tree, pnode z) {
  if (z->left == nullptr)
    transplant(tree, z, z->right);
  else if (z->right == nullptr)
    transplant(tree, z, z->left);
  else {
    pnode y = tree_minimum(z->right);

    if (y->p != z) {
      transplant(tree, y, y->right);
      y->right = z->right;
      y->right->p = y;
    }

    transplant(tree, z, y);
    y->left = z->left;
    y->left->p = y;
  }
}

pnode tree_successor(pnode x) {
  if (x->right != nullptr)
    return tree_minimum(x->right);
  else {
    pnode padre = x->p;

    while (padre != nullptr && x == padre->right) {
      x = padre;
      padre = padre->p;
    }

    return padre;
  }
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