/**
 * @file header.cpp
 * @author me, myself and I
 * @brief implementazione metodi e funzioni
 * @version 1.0
 * @date 2023-11-23
 */
#include "header.hpp"
#include <iostream>
#include <queue>

int somma_foglie(T tree) {
  int sum = 0;
  somma_foglie_aux(tree->root, &sum);
  return sum;
}

int somma_foglie_aux(pnode u, int *sum) {
  if (u == nullptr) {
    *sum = 0;
    return 0;
  } else {

    // u è una foglia
    if (u->left == nullptr && u->right == nullptr) {
      *sum = *sum + u->key;
    } else {
      int sumSX = *sum, sumDX = *sum;

      somma_foglie_aux(u->left, &sumSX);
      somma_foglie_aux(u->right, &sumDX);
      *sum = sumSX + sumDX;
    }

    return *sum;
  }
}

/*versione minimale*/
int somma_foglie_minimal(T tree) {
  return somma_foglie_minimal_aux(tree->root);
}

int somma_foglie_minimal_aux(pnode u) {
  if (u == nullptr) {
    return 0;
  } else {
    // u è una foglia
    if (u->left == nullptr && u->right == nullptr)
      return u->key;
    else
      return somma_foglie_minimal_aux(u->left) +
             somma_foglie_minimal_aux(u->right);
  }
}

void visita_in_ampiezza(pnode u) {
  std::queue<pnode> q;
  q.push(u);

  while (!q.empty()) {
    pnode tmp = q.front();
    q.pop();

    if (tmp != nullptr) {
      if (tmp->left == nullptr && tmp->right == nullptr)
        std::cout << "F:";

      std::cout << tmp->key << " ";

      q.push(tmp->left);
      q.push(tmp->right);
    }
  }
}

T crea_albero() {
  T t = new tree();

  pnode n = new node(9);
  pnode m = new node(3);

  pnode l = new node(1, m, n);

  pnode i = new node(4, nullptr, l);

  pnode h = new node(-2, i, nullptr);

  pnode g = new node(2);
  pnode f = new node(7);

  pnode e = new node(10, f, g);
  pnode d = new node(-1);
  pnode c = new node(-2, h);
  pnode b = new node(40, d, e);
  pnode a = new node(12, b, c);

  t->root = a;
  return t;
}