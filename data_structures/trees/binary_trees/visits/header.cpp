/**
 * @file header.cpp
 * @author me, myself and I
 * @brief implementazione funzioni e metodi
 * @version 1.0
 * @date 2023-11-07
 */
#include "header.hpp"
#include <iostream>
#include <queue>

T crea_albero_sx_dx() {
  T tree = new tree_left_right();

  pnode o = new node_left_right('O');
  pnode r = new node_left_right('R');
  pnode e = new node_left_right('E');

  pnode b = new node_left_right('B', nullptr, o);
  pnode l = new node_left_right('L', e, r);

  pnode a = new node_left_right('A', l, b);

  tree->root = a;
  return tree;
}

void visita_preorder_DFS(pnode u) {
  if (u != nullptr) {
    std::cout << u->key << " ";
    visita_preorder_DFS(u->left);
    visita_preorder_DFS(u->right);
  }
}

void visita_in_order_simmetrica(pnode u) {
  if (u != nullptr) {
    visita_in_order_simmetrica(u->left);
    std::cout << u->key << " ";
    visita_in_order_simmetrica(u->right);
  }
}

void visita_post_order(pnode u) {
  if (u != nullptr) {
    visita_post_order(u->left);
    visita_post_order(u->right);
    std::cout << u->key << " ";
  }
}

void visita_in_ampiezza_BFS(pnode u) {
  std::queue<pnode> q;
  q.push(u);
  while (!q.empty()) {
    pnode tmp = q.front();
    q.pop();
    if (tmp != nullptr) {
      std::cout << tmp->key << " ";
      q.push(tmp->left);
      q.push(tmp->right);
    }
  }
}
