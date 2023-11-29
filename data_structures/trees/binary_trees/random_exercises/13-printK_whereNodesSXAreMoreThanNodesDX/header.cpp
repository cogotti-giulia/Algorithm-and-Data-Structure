/**
 * @file header.cpp
 * @author cogotti-giulia (cogotti.giulia.irl@gmail.com)
 * @brief implementazione metodi e funzioni
 * @version 1.0
 * @date 2023-11-29
 */

#include "header.hpp"
#include <iostream>
#include <unordered_map>


void stampaK_nodeSX_mag_nodeDX(pnode u) { 
  stampaK_nodeSX_mag_nodeDX_AUX(u); 
}

int stampaK_nodeSX_mag_nodeDX_AUX(pnode u) {
  if (u == nullptr)
    return 0;
  else {
    int totSX, totDX;
    totSX = stampaK_nodeSX_mag_nodeDX_AUX(u->left);
    totDX = stampaK_nodeSX_mag_nodeDX_AUX(u->right);

    if (totSX > totDX)
      std::cout << u->key << " ";

    int tot = totSX + totDX + 1;
    return tot;
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

void pre_order(pnode u) {
  if (u != nullptr) {
    std::cout << u->key << " ";
    pre_order(u->left);
    pre_order(u->right);
  }
}
