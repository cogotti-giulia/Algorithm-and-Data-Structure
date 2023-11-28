/**
 * @file header.cpp
 * @author me, myself and I
 * @brief implementazione metodi e funzioni utilizzate
 * @version 1.0
 * @date 2023-11-28
 */
#include "header.hpp"
#include <iostream>
#include <queue>
#include <unordered_map>

void cancella(pnode u) {
  cancella_aux(u, nullptr); // radice, non ha un padre!
}

void cancella_aux(pnode u, pnode padre) {
  if (u != nullptr) {
    // il nodo corrente è il padre
    cancella_aux(u->left, u);
    cancella_aux(u->right, u);

    if (u->left == nullptr && u->right == nullptr) // è una foglia
      if (padre->left == u && padre->key == u->key)
        // è figlio sinistro con chiave uguale al padre
        padre->left = nullptr;
  }
}

void visita_dfs(pnode u) {
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
