/**
 * @file header.cpp
 * @author cogotti-giulia
 * @brief implementazioni metodi e funzioni
 * @version 1.1
 * @date 2023-12-01
 */
#include "header.hpp"
#include <iostream>
#include <unordered_map>

void trasforma(pnodeG u) {
  if (u != nullptr) {
    u->key = u->key / 2;         // all'inizio sono in un livello pari
    trasforma(u->right_sibling); // anche i fratelli di u sono a livello pari

    pnodeG iter = u->left_child;
    while (iter != nullptr) {
      trasforma(iter->left_child); // salto il livello dispari
      iter = iter->right_sibling;
    }
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

void visita_preorder_DFS(pnodeG u) {
  if (u != nullptr) {
    std::cout << u->key << " ";
    pnodeG iter = u->left_child;
    while (iter != nullptr) {
      visita_preorder_DFS(iter);
      iter = iter->right_sibling;
    }
  }
}