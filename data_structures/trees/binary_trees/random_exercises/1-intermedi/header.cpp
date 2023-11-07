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

int intermedi(pnode r) {
  int sumKeys = 0; // somma chiavi sotto albero
  return intermedi_AUX(r, 0, &sumKeys);
}

//! T(n) = T(k)+T(n-k-1)+d = ... = Teta(n)
int intermedi_AUX(pnode u, int sumPercorso, int *sumKeys) {
  if (u == nullptr) {
    *sumKeys = 0;
    return 0;
  } else {
    int sumKeysSX = *sumKeys;
    int risSX = intermedi_AUX(u->left, sumPercorso + u->key, &sumKeysSX);

    int sumKeysDX = *sumKeys;
    int risDX = intermedi_AUX(u->right, sumPercorso + u->key, &sumKeysDX);

    int sum = sumKeysDX + sumKeysSX + u->key;
    if (sum == sumPercorso) {
      *sumKeys = sum;
      return risSX + risDX + 1;
    } else {
      *sumKeys = sum;
      return risSX + risDX;
    }
  }
}

T crea_albero() {
  T t = new tree();
  pnode n1 = new node(1, nullptr, nullptr);
  pnode n7 = new node(7, n1, nullptr);
  pnode n9 = new node(9, nullptr, nullptr);

  pnode n0 = new node(0, n7, n9);
  pnode n17 = new node(17, nullptr, nullptr);

  pnode r = new node(17, n17, n0);

  t->root = r;
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
