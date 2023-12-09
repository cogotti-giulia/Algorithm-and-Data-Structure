/**
 * @file header.cpp
 * @author cogotti-giulia
 * @brief implementazione metodi e funzioni
 * @version 1.1
 * @date 2023-12-01
 */
#include "header.hpp"
#include <iostream>
#include <unordered_map>

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

pnodeG crea_albero(parrG vet_padri) {
  // numero di nodi
  int n = vet_padri->info.size();
  // crea una mappa vuota
  std::unordered_map<int, pnodeG> map;
  // crea un nuovo nodo per ogni info del padre e la mette nella mappa
  for (int i = 0; i < n; i++) {
    map[i] = new node(vet_padri->info.at(i));
  }
  // radice
  pnodeG root = nullptr;

  // figlio sinistro
  pnodeG left_child = nullptr;
  // ultimo fratello
  pnodeG last_sib = nullptr;

  for (int i = 0; i < n; i++) {

    // indice del padre
    int index_parent = vet_padri->parent.at(i);
    // nodo corrente
    pnodeG nuovo = map.at(i);

    // radice!
    if (index_parent == -1) {
      root = nuovo;
    } else {
      // prende il padre del nodo corrente, tramite la mappa
      pnodeG padre = map[index_parent];
      bool is_lfc = vet_padri->is_left_child.at(i);

      // se è un left child
      if (is_lfc) {
        // attacco il left child al padre e me lo salvo come last sibling
        left_child = nuovo;
        last_sib = left_child;
        padre->left_child = left_child;
      } else {
        // altrimenti se è un fratello attacco il nuovo nodo all'ultimo fratello
        // e mando avanti last sib dato che ne ho aggiunto uno
        last_sib->right_sibling = nuovo;
        last_sib = nuovo;
      }
    }
  }
  return root;
}