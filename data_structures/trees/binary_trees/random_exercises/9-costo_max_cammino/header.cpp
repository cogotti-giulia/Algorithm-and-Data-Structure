/**
 * @file header.cpp
 * @author me, myself and I
 * @brief implementazione metodi e funzioni
 * @version 1.0
 * @date 2023-11-23
 */
#include "header.hpp"
#include <algorithm>
#include <unordered_map>

int costo_max_cammino(pnode u) {
  if (u == nullptr)
    return 0;
  else {
    return std::max(costo_max_cammino(u->left), costo_max_cammino(u->right)) +
           u->key;
  }
}

pnode crea_albero(parr vet_padri) {

  // numero di nodi
  int n = vet_padri->size;

  // crea una mappa vuota
  std::unordered_map<int, pnode> map;

  // crea un nuovo nodo per ogni info del padre e la mette nella mappa
  for (int i = 0; i < n; i++) {
    map[i] = new node(vet_padri->info[i]);
  }

  // radice
  pnode root = nullptr;

  // scorre tutte le celle
  for (int i = 0; i < n; i++) {
    // indice del padre
    int index_parent = vet_padri->parent[i];

    // nodo corrente
    pnode nuovo = map[i];

    // se è -1 allora è la radice
    if (index_parent == -1) {
      root = nuovo;
    } else {
      // prende il padre del nodo corrente, tramite la mappa
      pnode padre = map[index_parent];

      // se ha già un figlio sinistro allora metto il nuovo nodo come figlio
      // destro, altrimenti come figlio sinistro
      if (padre->left != nullptr)
        padre->right = nuovo;
      else
        padre->left = nuovo;
    }
  }

  return root;
}