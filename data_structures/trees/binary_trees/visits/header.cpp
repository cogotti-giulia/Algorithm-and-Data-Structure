/**
 * @file header.cpp
 * @author me, myself and I
 * @brief implementazione funzioni e metodi
 * @version 1.1
 * @date 2023-11-23
 */
#include "header.hpp"
#include <iostream>
#include <queue>
#include <unordered_map>

pnode crea_albero(parr vet_padri) {
  // numero di nodi
  int n = vet_padri->info.size();
  // crea una mappa vuota
  std::unordered_map<char, pnode> map;
  // crea un nuovo nodo per ogni info del padre e la mette nella mappa
  for (int i = 0; i < n; i++) {
    map[i] = new node(vet_padri->info.at(i));
  }
  // radice
  pnode root = nullptr;
  // scorre tutte le celle
  for (int i = 0; i < n; i++) {
    // indice del padre
    int index_parent = vet_padri->parent.at(i);
    // nodo corrente
    pnode nuovo = map.at(i);
    // posizione del nodo corrente ('l': figlio sinistro, 'r': figlio destro,
    // 'z': radice)
    char child_posi = vet_padri->child_position.at(i);

    // se è -1 allora è la radice
    if (index_parent == -1) {
      root = nuovo;
    } else {
      // prende il padre del nodo corrente, tramite la mappa
      pnode padre = map[index_parent];

      // se è 'l' lo attacca come figlio sinistro
      if (child_posi == 'l')
        padre->left = nuovo;
      else if (child_posi == 'r') // altrimenti come figlio destro
        padre->right = nuovo;
    }
  }
  return root;
}

void visita_preorder_DFS(pnode u) {
  if (u != nullptr) {
    std::cout << u->key << " ";
    visita_preorder_DFS(u->left);
    visita_preorder_DFS(u->right);
  }
}

void visita_in_order_simmetrica(pnode u) {
  if (u != nullptr) {
    visita_in_order_simmetrica(u->left);
    std::cout << u->key << " ";
    visita_in_order_simmetrica(u->right);
  }
}

void visita_post_order(pnode u) {
  if (u != nullptr) {
    visita_post_order(u->left);
    visita_post_order(u->right);
    std::cout << u->key << " ";
  }
}

void visita_in_ampiezza_BFS(pnode u) {
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
