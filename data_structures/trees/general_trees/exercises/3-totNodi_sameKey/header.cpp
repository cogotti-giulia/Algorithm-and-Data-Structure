/**
 * @file header.cpp
 * @author me, myself and I
 * @brief implementazione metodi e funzioni
 * @version 1.0
 * @date 2023-11-29
 */
#include "header.hpp"
#include <iostream>

int node_childrenSameKey(pnodeG u) {
  int ris = 0;
  node_childrenSameKey_AUX(u, &ris);
  return ris;
}

//! T(n) = O(n) perché ogni nodo è visitato al più una volta
void node_childrenSameKey_AUX(pnodeG u, int *ris) {
  if (u == nullptr) {
    // i figli non hanno la stessa chiave perché non esistono quindi ris è zero
    *ris = 0;
  } else {
    bool is_first_key = true;         // mi serve a capire se mi trovo nel primo child oppure no
    int tot_same_key = 0;      // conta i fratelli con la stessa chiave
    int grado = 0;    // conta il grado del nodo, quindi il numero di figli
    int k_left_child; // chiave del figlio più a sinistra

    pnodeG figlio = u->left_child;

    // scorro i figli andando da figlio a right sibling
    // all'interno vado in ricorsione per calcolare il risultato dei figli del
    // nodo che sto scorrendo
    while (figlio != nullptr) {

      // se è il primo figlio allora setto la chiave
      if (is_first_key) {
        is_first_key = false;
        k_left_child = figlio->key;
      }
      grado++; // ho un figlio in più

      // se la chiave è uguale a quella del primo figlio incremento key
      if (figlio->key == k_left_child)
        tot_same_key++;

      // vado in ricorsione sul figlio più a sinistra
      node_childrenSameKey_AUX(figlio, ris);

      // se il grado coincide con key, quindi se tutti i figli hanno la stessa
      // chiave e mi trovo sul figlio più a destra (ultimo, non ha un fratello)
      if (grado == tot_same_key && figlio->right_sibling == nullptr)
        *ris = *ris + 1; // incremento ris

      // mi sposto al fratello
      figlio = figlio->right_sibling;
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

T crea_albero() {
  T t = new tree();

  pnodeG k = new node(4);

  pnodeG j = new node(-7);
  pnodeG i = new node(7, nullptr, j);

  pnodeG h = new node(6, i, nullptr);
  pnodeG g = new node(5, k, h);

  pnodeG f = new node(4);
  pnodeG e = new node(3, nullptr, f);

  pnodeG d = new node(1, g, nullptr);
  pnodeG c = new node(1, nullptr, d);
  pnodeG b = new node(1, e, c);

  pnodeG a = new node(2, b, nullptr);

  t->root = a;
  return t;
}