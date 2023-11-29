/**
 * @file header.cpp
 * @author cogotti-giulia (cogotti.giulia.irl@gmail.com)
 * @brief implementazione metodi e funzioni
 * @version 1.1
 * @date 2023-11-29
 */
#include "header.hpp"
#include <iostream>
#include <unordered_map>

bool is_sum_tree(pnode u) {
  int sum = 0;
  return is_sum_tree_AUX(u, &sum);
}

bool is_sum_tree_AUX(pnode u, int *sum) {
  if (u == nullptr) {
    *sum = 0;
    return true;
  } else {
    int sumSX, sumDX;
    bool risSX = is_sum_tree_AUX(u->left, &sumSX);
    bool risDX = is_sum_tree_AUX(u->right, &sumDX);

    *sum = u->key + sumSX + sumDX;
    bool ris;

    // ATTENZIONE caso in cui u è una foglia con u.key < 0, dato che i figli non
    // esistono la proprietà è banalmente verificata
    if (u->key < 0 && u->left == nullptr && u->right == nullptr) {
      ris = true;
    } else {
      if (u->key >= sumSX && u->key >= sumDX)
        ris = true;
      else
        ris = false;
    }

    return ris && risSX && risDX;
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

void visita_in_order_simmetrica(pnode u) {
  if (u != nullptr) {
    visita_in_order_simmetrica(u->left);
    std::cout << u->key << " ";
    visita_in_order_simmetrica(u->right);
  }
}