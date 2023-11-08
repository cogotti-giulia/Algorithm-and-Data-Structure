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

  pnode o = new node('O');
  pnode r = new node('R');
  pnode e = new node('E', nullptr, r);

  pnode b = new node('B', o, nullptr);
  pnode l = new node('L', e, b);
  pnode a = new node('A', l, nullptr);

  t->root = a;
  return t;
}

void visita_preorder_DFS(pnode u) {
  if (u != nullptr) {
    std::cout << u->key << " ";
    pnode scorri_bro = u->left_child;
    while (scorri_bro != nullptr) {
      visita_preorder_DFS(scorri_bro);
      scorri_bro = scorri_bro->right_sibling;
    }
  }
}

void visita_post_order(pnode u) {
  if (u != nullptr) {
    pnode scorri_bro = u->left_child;
    while (scorri_bro != nullptr) {
      visita_post_order(scorri_bro);
      scorri_bro = scorri_bro->right_sibling;
    }
    std::cout << u->key << " ";
  }
}

void visita_in_order_simmetrica(pnode u) {
}

void visita_in_ampiezza_BFS(pnode u) {
  std::queue<pnode> q;
  q.push(u);

  while (!q.empty()) {
    pnode tmp = q.front();
    q.pop();

    while (tmp != nullptr) {
      std::cout << tmp->key << " ";
      q.push(tmp->left_child);
      tmp = tmp->right_sibling;
    }
  }
}
