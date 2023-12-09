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

void stampa_livello(pnode u, int k) {
  if (u != nullptr) {
    if (k == 0)
      std::cout << u->key << " ";
    else {
      // scendo di livello!
      stampa_livello(u->left, k - 1);
      stampa_livello(u->right, k - 1);
    }
  }
}

T crea_albero() {
  T t = new tree();

  pnode n6 = new node(6, nullptr, nullptr);
  pnode n4 = new node(4, n6, nullptr);
  pnode n5 = new node(5, nullptr, nullptr);
  pnode n3 = new node(3, n4, n5);
  pnode n2 = new node(2, nullptr, nullptr);
  pnode n1 = new node(1, n2, n3);

  t->root = n1;
  return t;
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