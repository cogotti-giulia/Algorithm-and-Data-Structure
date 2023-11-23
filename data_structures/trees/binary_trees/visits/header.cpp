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
  int n = vet_padri->size; // numero di nodi
  // crea una mappa vuota
  std::unordered_map<int, pnode> map;

  // crea un nuovo nodo per ogni info del padre e la mette nella mappa
  for (int i = 0; i < n; i++)
    map[i] = new node(vet_padri->info[i]);

  pnode root = nullptr; // radice

  // scorre tutte le celle
  for (int i = 0; i < n; i++) {
    int index_parent = vet_padri->parent[i]; // indice del padre
    char posi_child = vet_padri->child_position[i];

    pnode nuovo = map[i]; // nodo corrente

    // se è -1 allora è la radice
    if (index_parent == -1) {
      root = nuovo;
    } else {
      // prende il padre del nodo corrente, tramite la mappa
      pnode padre = map[index_parent];
      // se ha già un figlio sinistro allora metto il nuovo nodo come figlio
      // destro, altrimenti come figlio sinistro

      if(posi_child == 'l')
        padre->left = nuovo;
    


      else if(posi_child == 'r')
        padre->right = nuovo;
      /*if (padre->left != nullptr)
        padre->right = nuovo;
      else
        padre->left = nuovo;*/
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
