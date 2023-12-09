/**
 * @file header.cpp
 * @author cogotti-giulia
 * @brief implementazione metodi e funzioni
 * @version 1.2
 * @date 2023-11-29
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
