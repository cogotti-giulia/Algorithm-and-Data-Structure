/**
 * @file header.cpp
 * @author me, myself and I
 * @brief implementazione metodi e funzioni
 * @version 1.1
 * @date 2023-11-23
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

