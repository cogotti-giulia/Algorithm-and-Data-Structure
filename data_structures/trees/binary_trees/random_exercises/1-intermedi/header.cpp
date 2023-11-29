/**
 * @file header.cpp
 * @author cogotti-giulia
 * @brief implementazione funzioni e metodi
 * @version 1.1
 * @date 2023-11-29
 */

#include "header.hpp"
#include <iostream>
#include <queue>
#include <unordered_map>

int intermedi(pnode r) {
  int sumKeys = 0; // somma chiavi sotto albero
  return intermedi_AUX(r, 0, &sumKeys);
}

//! T(n) = T(k)+T(n-k-1)+d = ... = Teta(n)
int intermedi_AUX(pnode u, int sumPercorso, int *sumKeys) {
  if (u == nullptr) {
    *sumKeys = 0;
    return 0;
  } else {
    int sumKeysSX;
    int risSX = intermedi_AUX(u->left, sumPercorso+u->key, &sumKeysSX);

    int sumKeysDX;
    int risDX = intermedi_AUX(u->right, sumPercorso+u->key, &sumKeysDX);

    int sum = sumKeysDX + sumKeysSX + u->key;

    if (sum == sumPercorso) {
      *sumKeys = sum;
      return risSX + risDX + 1;
    } else {
      *sumKeys = sum;
      return risSX + risDX;
    }
  }
}

pnode crea_albero(parr vet_padri) {
  // numero di nodi
  int n = vet_padri->info.size();
  // crea una mappa vuota
  std::unordered_map<int, pnode> map;
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
