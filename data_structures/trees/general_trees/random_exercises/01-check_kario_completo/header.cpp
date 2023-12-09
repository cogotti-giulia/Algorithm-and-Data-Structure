/**
 * @file header.cpp
 * @author cogotti-giulia
 * @brief implementazione metodi e funzioni
 * @version 1.1
 * @date 2023-12-01
 */
#include "header.hpp"
#include <unordered_map>

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