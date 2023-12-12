/**
 * @file header.cpp
 * @author cogotti-giulia (cogotti.giulia.irl@gmail.com)
 * @brief implementazione metodi e funzioni
 * @version 1.0
 * @date 2023-12-12
 *
 * @copyright Copyright (c) 2023
 *
 */
#include "header.hpp"
#include <cstdlib>
#include <iostream>

void tree_insert_diff(T_d t, pnode_d z) {
  pnode_d scorri_down = t->root;
  pnode_d padre_z = nullptr;

  //! O(h)
  while (scorri_down != nullptr) {
    padre_z = scorri_down;
    if (z->key <= scorri_down->key)
      scorri_down = scorri_down->left;
    else
      scorri_down = scorri_down->right;
  }

  z->p = padre_z;
  if (z->p == nullptr)
    t->root = z;
  else {
    if (z->key <= z->p->key)
      z->p->left = z;
    else
      z->p->right = z;
  }

  // scorro dal padre del nodo che ho aggiunto fino alla radice
  // tenendomi figlio perché devo sapere se è destro o sinistro
  pnode_d padre = z->p;
  pnode_d figlio = z;

  // conta i nodi nei sottoalberi di padre
  int nodi_SX = 0;
  int nodi_DX = 0;

  //! O(h)
  while (padre != nullptr) {
    // se il figlio sta nel sottoalbero sinistro, significa che la somma dei
    // nodi dei sottoalberi sinistro e destro precedentemente calcolata è la
    // somma dei nodi del sottoalbero sinistro corrente
    // ma allora al momento io il numero lo conosco ma non conosco quello
    // dell'altro sottoalbero che mi calcolo

    // vedo se ha anche un figlio destro, in caso positivo, con la differenza e
    // il numero di nodi a sinistra (prima di aggiungere z) mi trovo il numero
    // dei nodi di quel sottoalbero (MI HA FATTA DANNARE RIUSCIRE A CALCOLARE IL
    // NUMERO AAAAAAAAAAA)

    // alla fine incremento il numero di nodi nel sottoalbero sinistro perché in
    // quel cammino io ho aggiunto z
    if (padre->left == figlio) {
      nodi_SX = nodi_DX + nodi_SX;
      nodi_DX = 0;
      if (padre->right != nullptr) {
        if (nodi_SX <= padre->diff)
          nodi_DX = (padre->diff) + nodi_SX;
        else
          nodi_DX = nodi_SX - padre->diff;
      }
      nodi_SX++;
    } else if (padre->right == figlio) {
      nodi_DX = nodi_DX + nodi_SX;
      nodi_SX = 0;
      if (padre->left != nullptr) {
        if (nodi_DX <= padre->diff)
          nodi_SX = (padre->diff + nodi_DX);
        else
          nodi_SX = nodi_DX - padre->diff;
      }
      nodi_DX++;
    }

    // la differenza sarà il valore assoluto tra la differenza dei sottoalberi
    // (esclusa la radice)
    int new_diff = abs(nodi_DX - nodi_SX);
    padre->diff = new_diff;

    figlio = padre;
    padre = padre->p;
  }
}

pnode_d tree_minimum(pnode_d x) {
  while (x->left != nullptr)
    x = x->left;

  return x;
}

pnode_d tree_successor(pnode_d x) {
  if (x->right != nullptr)
    return tree_minimum(x->right);
  else {
    pnode_d y = x->p;

    while (y != nullptr && y->left != x) {
      x = y;
      y = y->p;
    }

    return x->p;
  }
}

void visita_simmetrica(T_d t) {
  if (t->root != nullptr) {
    pnode_d min = tree_minimum(t->root);
    pnode_d succ = tree_successor(min);

    if (min != nullptr) {
      std::cout << " k:" << min->key << " d:" << min->diff << " ";
      while (succ != nullptr) {
        std::cout << " k:" << succ->key << " d:" << succ->diff << " ";
        pnode_d tmp = succ;
        succ = tree_successor(tmp);
      }
    }
  }
}