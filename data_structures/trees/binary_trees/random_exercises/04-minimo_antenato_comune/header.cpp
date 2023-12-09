/**
 * @file header.cpp
 * @author me, myself and I
 * @brief implementazione funzioni e metodi
 * @version 1.0
 * @date 2023-11-07
 */
#include "header.hpp"
#include <cmath>
#include <iostream>

//! T(n) = O(h)
pnode_prof mac(pnode_prof u, pnode_prof v) {
  // allineo alla stessa profondità i due nodi
  while (u->prof != v->prof) {
    if (u->prof > v->prof)
      u = u->p;
    else
      v = v->p;
  }

  // sono esattamente lo stesso nodo, ma allora ho trovato il mac
  if (u == v)
    return u;
  else {
    // la radice è antenato comune a tutti, quindi prima o poi mi allineo
    while (u->p != v->p) {
      u = u->p;
      v = v->p;
    }
    return u->p;
  }
}

//! T(n) = Teta(n)
pnode_prof build_albero_con_prof(pnode u) {
  return build_albero_con_prof_AUX(u, nullptr, 0);
}

//? T(n) = Teta(n)
pnode_prof build_albero_con_prof_AUX(pnode u, pnode_prof padre,
                                     int profondita) {
  if (u == nullptr)
    return nullptr;
  else {
    pnode_prof nuovo = new node_with_prof();
    nuovo->key = u->key;
    nuovo->p = padre;
    nuovo->prof = profondita;

    //! PENSA SOLO ALL'EFFETTO DELLA CHIAMATA RICORSIVA
    //! NON SROTOLARLA, ALTRIMENTI NON CAPISCI PIÙ NULLA

    nuovo->left = build_albero_con_prof_AUX(u->left, nuovo, profondita + 1);
    nuovo->right = build_albero_con_prof_AUX(u->right, nuovo, profondita + 1);
    return nuovo;
  }
}

//! T(n) = Teta(1)
T crea_albero() {
  T t = new tree();

  pnode n7 = new node(7, nullptr, nullptr);
  pnode n6 = new node(6, n7, nullptr);
  pnode n5 = new node(5, nullptr, nullptr);
  pnode n3 = new node(3, n5, n6);
  pnode n4 = new node(4, nullptr, nullptr);
  pnode n2 = new node(2, n4, nullptr);
  pnode n1 = new node(1, n2, n3);

  n1->p = nullptr;
  n7->p = n6;
  n5->p = n6->p = n3;
  n4->p = n2;
  n2->p = n3->p = n1;

  t->root = n1;
  return t;
}

//? T(n) = O(n)
pnode_prof find_node(pnode_prof u, int k) {
  if (u == nullptr)
    return nullptr;
  else {
    // se la chiave corrisponde rende il nodo
    if (u->key == k)
      return u;
    else {
      // cerca a sinistra
      pnode_prof x = new node_with_prof();
      x = find_node(u->left, k);
      // se non ha trovato nulla cerca a destra
      if (x == nullptr)
        x = find_node(u->right, k);
      // x alla fine sarà null oppure l'elemento con chiave k
      return x;
    }
  }
}

//! T(n) = Teta(n)
void in_order(pnode u) {
  if (u != nullptr) {
    in_order(u->left);
    std::cout << u->key << " ";
    in_order(u->right);
  }
}

//! T(n) = Teta(n)
void in_order_prof(pnode_prof u) {
  if (u != nullptr) {
    in_order_prof(u->left);
    std::cout << "[" << u->key << ";" << u->prof << "] ";
    in_order_prof(u->right);
  }
}
