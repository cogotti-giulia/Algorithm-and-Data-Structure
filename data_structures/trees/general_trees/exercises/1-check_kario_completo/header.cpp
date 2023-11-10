/**
 * @file header.cpp
 * @author me, myself and I
 * @brief implementazione metodi e funzioni
 * @version 1.0
 * @date 2023-11-08
 */
#include "header.hpp"

bool is_k_ario(pnodeG u, int k) {
  int h = -1;
  return is_k_ario_AUX(u, k, &h);
}

bool is_k_ario_AUX(pnodeG u, int k, int *h) {
  if (u == nullptr) {
    *h = -1;
    return true;
  } else {
    int hF = -1;   // non so ancora nulla
    int grado = 0; // figli del nodo
    pnodeG figlio = u->left_child;
    bool ris = true; // assumo sia k ario completo

    while (figlio != nullptr && ris) {
      grado++; // ho un figlio sicuro
      int h_subtree;
      bool risF = is_k_ario_AUX(figlio, k, &h_subtree);
      if (hF == -1)     // sono al primo figlio
        hF = h_subtree; // tutti dovranno avere la sua stessa altezza

      ris = ris && risF && grado <= k && h_subtree == hF;
      figlio = figlio->right_sibling;
    }

    *h = hF + 1;
    // grado è k oppure 0 se è una foglia
    return ris && (grado == k || grado == 0);
  }
}

T crea_albero() {
  T t = new tree();

  //rimuovere i commenti per renderlo k ario completo con k = 3
  /*
  pnode z = new node(2, nullptr, nullptr);
  pnode y = new node(5, nullptr, z);
  pnode x = new node(-1, nullptr, y);
  */

  pnodeG xyz = new node(1, /*x*/nullptr, nullptr);

  pnodeG c = new node(-9, nullptr, nullptr);
  pnodeG b = new node(12, nullptr, c);
  pnodeG a = new node(17, nullptr, b);

  pnodeG abc = new node(3, a, xyz);

  pnodeG r = new node(-9, nullptr, nullptr);
  pnodeG q = new node(12, nullptr, r);
  pnodeG p = new node(17, nullptr, q);

  pnodeG pqr = new node(3, p, abc);

  pnodeG groot = new node(0, pqr, nullptr);

  t->root = groot;
  return t;
}