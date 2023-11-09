/**
 * @file header.cpp
 * @author me, myself and I
 * @brief implementazione metodi e funzioni
 * @version 1.0
 * @date 2023-11-09
 */
#include "header.hpp"

bool k_limitato(pnode u, int k) {
  int sum = 0;
  return k_limitato_AUX(u, k, &sum);
}

bool k_limitato_AUX(pnode u, int k, int *sum) {
  if (u == nullptr) {
    *sum = 0;
    return true;
  } else {
    bool risSX, risDX;
    int sumSX, sumDX;

    risSX = k_limitato_AUX(u->left, k, &sumSX);
    risDX = k_limitato_AUX(u->right, k, &sumDX);

    if (!risSX || !risDX || sumSX > k || sumDX > k)
      return false;

    *sum = sumSX + sumDX + u->key;
    return true;
  }
}

T crea_albero() {
  T t = new tree();

  pnode g = new node(3);
  pnode f = new node(1);
  pnode d = new node(4);
  pnode e = new node(-2, g);
  pnode c = new node(5, f);
  pnode b = new node(2, d, e);
  pnode a = new node(1, b, c);

  t->root = a;
  return t;
}