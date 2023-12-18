/**
 * @file header.cpp
 * @author cogotti-giulia (cogotti.giulia.irl@gmail.com)
 * @brief implementazione metodi e funzioni
 * @version 1.0
 * @date 2023-12-11
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include "header.hpp"
#include <cstdlib>
#include <iostream>

void tree_insert_sum(T_s t, pnode_s z) {
  pnode_s scorri_down = t->root;
  pnode_s padre = nullptr;
  while (scorri_down != nullptr) {
    padre = scorri_down;
    if (z->key <= scorri_down->key)
      scorri_down = scorri_down->left;
    else
      scorri_down = scorri_down->right;
  }

  z->p = padre;
  if (z->p == nullptr)
    t->root = z;
  else {
    if (z->key <= z->p->key)
      z->p->left = z;
    else
      z->p->right = z;
  }

  pnode_s scorri_up = z->p;

  int nodi_SX = 0;
  int nodi_DX = 0;

  while (scorri_up != nullptr) {

    if (scorri_up->left == z) {
      nodi_DX = abs(scorri_up->sum - nodi_SX);
      nodi_SX++;
    } else {
      nodi_SX = abs(scorri_up->sum - nodi_DX);

      nodi_DX++;
    }

    int new_sum = nodi_DX + nodi_SX;

    scorri_up->sum = new_sum;
    z = scorri_up;
    scorri_up = scorri_up->p;
  }
}

pnode_s tree_minimum(pnode_s x) {
  while (x->left != nullptr)
    x = x->left;

  return x;
}

pnode_s tree_successor(pnode_s x) {
  if (x->right != nullptr)
    return tree_minimum(x->right);
  else {
    pnode_s y = x->p;

    while (y != nullptr && y->left != x) {
      x = y;
      y = y->p;
    }

    return x->p;
  }
}

void visita_simmetrica(T_s t) {
  if (t->root != nullptr) {
    pnode_s min = tree_minimum(t->root);
    pnode_s succ = tree_successor(min);

    if (min != nullptr) {
      std::cout << " k:" << min->key << " d:" << min->sum << " ";
      while (succ != nullptr) {
        std::cout << " k:" << succ->key << " d:" << succ->sum << " ";
        pnode_s tmp = succ;
        succ = tree_successor(tmp);
      }
    }
  }
}