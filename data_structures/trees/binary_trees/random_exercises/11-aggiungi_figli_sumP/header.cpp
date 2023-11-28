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

void aggiungi_figli(pnode u) {
  int sumP = 0;
  // sumP tiene traccia della somma lungo il percorso
  aggiungi_figli_aux(u, &sumP);
}

void aggiungi_figli_aux(pnode u, int *sumP) {
  // se l'albero è vuoto non ho nodi a cui aggiungere figli
  if (u != nullptr) {
    // somma mentre scendo nell'albero
    int sumPK = *sumP + u->key;

    aggiungi_figli_aux(u->left, &sumPK);
    aggiungi_figli_aux(u->right, &sumPK);

    // quando arrivo a una foglia
    if (u->left == nullptr && u->right == nullptr) {
      // la somma nel percorso viene incrementata del valore della chiave della
      // foglia, creo un nuovo nodo con chiave la somma del percorso dalla
      // radice alla foglia, se è maggiore di zero attacco a sinistra altrimenti
      // a destra
      int value = *sumP + u->key;
      pnode nuovo = new node(value);
      if (*sumP >= 0)
        u->left = nuovo;
      else
        u->right = nuovo;
    }
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
