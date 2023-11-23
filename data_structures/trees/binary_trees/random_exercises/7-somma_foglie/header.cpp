/**
 * @file header.cpp
 * @author me, myself and I
 * @brief implementazione metodi e funzioni
 * @version 1.1
 * @date 2023-11-23
 */
#include "header.hpp"
#include <iostream>
#include <queue>
#include <unordered_map>

int somma_foglie(T tree) {
  int sum = 0;
  somma_foglie_aux(tree->root, &sum);
  return sum;
}

int somma_foglie_aux(pnode u, int *sum) {
  if (u == nullptr) {
    *sum = 0;
    return 0;
  } else {

    // u è una foglia
    if (u->left == nullptr && u->right == nullptr) {
      *sum = *sum + u->key;
    } else {
      int sumSX = *sum, sumDX = *sum;

      somma_foglie_aux(u->left, &sumSX);
      somma_foglie_aux(u->right, &sumDX);
      *sum = sumSX + sumDX;
    }

    return *sum;
  }
}

/*versione minimale*/
int somma_foglie_minimal(T tree) {
  return somma_foglie_minimal_aux(tree->root);
}

int somma_foglie_minimal_aux(pnode u) {
  if (u == nullptr) {
    return 0;
  } else {
    // u è una foglia
    if (u->left == nullptr && u->right == nullptr)
      return u->key;
    else
      return somma_foglie_minimal_aux(u->left) +
             somma_foglie_minimal_aux(u->right);
  }
}

void visita_in_ampiezza(pnode u) {
  std::queue<pnode> q;
  q.push(u);

  while (!q.empty()) {
    pnode tmp = q.front();
    q.pop();

    if (tmp != nullptr) {
      if (tmp->left == nullptr && tmp->right == nullptr)
        std::cout << "F:";

      std::cout << tmp->key << " ";

      q.push(tmp->left);
      q.push(tmp->right);
    }
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
