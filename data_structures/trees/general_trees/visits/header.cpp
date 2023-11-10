/**
 * @file header.cpp
 * @author me, myself and I
 * @brief implementazione metodi e funzioni
 * @version 1.0
 * @date 2023-11-08
 */
#include "structs_used.hpp"
#include <iostream>
#include <queue>

T crea_albero_lc_rsib() {

  T t = new tree();

  pnodeG o = new node('O');
  pnodeG r = new node('R');
  pnodeG e = new node('E', nullptr, r);

  pnodeG b = new node('B', o, nullptr);
  pnodeG l = new node('L', e, b);
  pnodeG a = new node('A', l, nullptr);

  t->root = a;
  return t;
}

void visita_preorder_DFS(pnodeG u) {
  if (u != nullptr) {
    std::cout << u->key << " ";
    pnodeG scorri_bro = u->left_child;
    while (scorri_bro != nullptr) {
      visita_preorder_DFS(scorri_bro);
      scorri_bro = scorri_bro->right_sibling;
    }
  }
}

void visita_post_order(pnodeG u) {
  if (u != nullptr) {
    pnodeG scorri_bro = u->left_child;
    while (scorri_bro != nullptr) {
      visita_post_order(scorri_bro);
      scorri_bro = scorri_bro->right_sibling;
    }
    std::cout << u->key << " ";
  }
}

void visita_in_order_simmetrica(pnodeG u) {
}

void visita_in_ampiezza_BFS(pnodeG u) {
  std::queue<pnodeG> q;
  q.push(u);

  while (!q.empty()) {
    pnodeG tmp = q.front();
    q.pop();

    while (tmp != nullptr) {
      std::cout << tmp->key << " ";
      q.push(tmp->left_child);
      tmp = tmp->right_sibling;
    }
  }
}
