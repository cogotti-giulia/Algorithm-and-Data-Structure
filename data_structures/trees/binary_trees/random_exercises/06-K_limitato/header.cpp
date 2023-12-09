/**
 * @file header.cpp
 * @author cogotti-giulia
 * @brief implementazione metodi e funzioni
 * @version 1.2
 * @date 2023-11-29
 */
#include "header.hpp"
#include <unordered_map>

bool k_limitato(pnode u, int k) {
  int sum = 0;
  return k_limitato_AUX(u, k, &sum);
}

bool k_limitato_AUX(pnode u, int k, int *sum) {
  if (u == nullptr) {
    *sum = 0;
    return true;
  } else {
    bool risSX, risDX;
    int sumSX, sumDX;

    risSX = k_limitato_AUX(u->left, k, &sumSX);
    risDX = k_limitato_AUX(u->right, k, &sumDX);

    if (!risSX || !risDX || sumSX > k || sumDX > k)
      return false;

    *sum = sumSX + sumDX + u->key;
    return true;
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