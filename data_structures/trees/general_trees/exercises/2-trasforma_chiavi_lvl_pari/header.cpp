/**
 * @file header.cpp
 * @author me, myself and I
 * @brief implementazioni metodi e funzioni
 * @version 1.0
 * @date 2023-11-08
 */
#include "header.hpp"
#include <iostream>

void trasforma(pnodeG u) {
  if (u != nullptr) {
    u->key = u->key / 2;         // all'inizio sono in un livello pari
    trasforma(u->right_sibling); // anche i fratelli di u sono a livello pari

    pnodeG iter = u->left_child;
    while (iter != nullptr) {
      trasforma(iter->left_child); // salto il livello dispari
      iter = iter->right_sibling;
    }
  }
}

T crea_albero() {
  T t = new tree();

  pnodeG z = new node(80, nullptr, nullptr);
  pnodeG y = new node(18, nullptr, z);
  pnodeG x = new node(-12, nullptr, y);

  pnodeG xyz = new node(2, x, nullptr);

  pnodeG c = new node(4, nullptr, nullptr);
  pnodeG b = new node(12, nullptr, c);
  pnodeG a = new node(20, nullptr, b);

  pnodeG abc = new node(8, a, xyz);

  pnodeG groot = new node(50, abc, nullptr);

  t->root = groot;
  return t;
}

void visita_preorder_DFS(pnodeG u) {
  if (u != nullptr) {
    std::cout << u->key << " ";
    pnodeG iter = u->left_child;
    while (iter != nullptr) {
      visita_preorder_DFS(iter);
      iter = iter->right_sibling;
    }
  }
}