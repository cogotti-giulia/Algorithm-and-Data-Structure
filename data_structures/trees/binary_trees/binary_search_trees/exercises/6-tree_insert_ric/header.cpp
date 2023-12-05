/**
 * @file header.cpp
 * @author cogotti-giulia (cogotti.giulia.irl@gmail.com)
 * @brief implementazione metodi e funzioni
 * @version 1.0
 * @date 2023-12-05
 *
 * @copyright Copyright (c) 2023
 *
 */
#include "header.hpp"
#include <iostream>

void tree_insert_ric(T t, pnode z) {
  if (t->root == nullptr) // albero vuoto
    t->root = z;
  else
    tree_insert_ric_AUX(t->root, z, nullptr);
}

void tree_insert_ric_AUX(pnode u, pnode z, pnode padre) {
  if (u != nullptr) {
    // scendo di padre in figlio (conservandomi il padre)
    // in base alla proprietà delle chiavi del bst
    // finché non raggiungo il punto in cui attaccare z
    if (u->key > z->key) {
      tree_insert_ric_AUX(u->left, z, u);
    } else {
      tree_insert_ric_AUX(u->right, z, u);
    }

  } else {
    // so che padre esiste per forza (ho almeno un nodo, altrimenti non viene
    // chiamata questa procedura)
    z->p = padre;
    // attacco z in base alla chiave
    if (padre->key > z->key)
      padre->left = z;
    else
      padre->right = z;
  }
}

void visita_simmetrica(pnode u) {
  if (u != nullptr) {
    pnode min = tree_minimum(u);

    std::cout << min->key << " ";

    pnode succ = tree_successor(min);

    while (succ != nullptr) {
      std::cout << succ->key << " ";
      pnode tmp = succ;
      succ = tree_successor(tmp);
    }
  }
}

pnode tree_minimum(pnode u) {
  while (u->left != nullptr)
    u = u->left;

  return u;
}

pnode tree_successor(pnode u) {
  if (u->right != nullptr)
    return tree_minimum(u->right);
  else {
    pnode y = u->p;

    while (y != nullptr && y->right == u) {
      u = y;
      y = y->p;
    }

    return y;
  }
}