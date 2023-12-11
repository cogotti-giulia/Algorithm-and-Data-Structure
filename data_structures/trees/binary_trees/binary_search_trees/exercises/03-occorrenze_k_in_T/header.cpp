/**
 * @file header.cpp
 * @author me, myself and I
 * @brief implementazione metodi e funzioni
 * @version 1.0
 * @date 2023-11-09
 */
#include "header.hpp"
#include <cmath>
#include <iostream>

// uso la proprietà che se T è un BST allora la visita simmetrica elenca le
// chiavi in ordine non decrescente quindi, le chiavi uguali a k si troveranno
// consecutive
int occorrenze_k(T t, int k) {
  if (t->root == nullptr)
    return 0;
  else {
    // esiste almeno un nodo
    pnode min = tree_minimum(t->root);
    pnode succ = tree_successor(min);

    int ris_k = 0;
    bool found_k = false;

    // se key = k si trova nel minimo, posso già andare a scorrere e contare
    if (min->key == k) {
      ris_k++;
      found_k = true;
    } else {
      // trovo il primo nodo con chiave k se esiste e setto found_k a true
      while (succ != nullptr && !found_k) {
        if (succ->key == k)
          found_k = true;
        else {
          pnode y = succ;
          succ = tree_successor(y);
        }
      }
    }

    // se esiste almeno un nodo con chiave k, scorro i successori e conto finché
    // hanno chiave uguale a k
    if (found_k) {
      while (succ != nullptr && succ->key == k) {
        ris_k++;
        pnode y = succ;
        succ = tree_successor(y);
      }
    }

    return ris_k;
  }
}

pnode tree_minimum(pnode x) {
  while (x->left != nullptr)
    x = x->left;

  return x;
}

pnode tree_successor(pnode x) {
  if (x->right != nullptr)
    return tree_minimum(x->right);
  else {
    pnode scorri = x;
    pnode padre = scorri->p;

    while (scorri->p != nullptr && scorri->p->left != scorri) {
      scorri = scorri->p;
    }

    return scorri->p;
  }
}

T build_BST_OTT(int *A, std::size_t n) {
  T t = new tree();
  t->root = build_BST_OTT_AUX(A, 0, n - 1, nullptr);
  return t;
}

pnode build_BST_OTT_AUX(int *A, int inf, int sup, pnode padre) {
  if (inf > sup)
    return nullptr;
  else {
    int med = std::floor((inf + sup) / 2);
    pnode nuovo = new node(A[med]);
    nuovo->p = padre;
    nuovo->left = build_BST_OTT_AUX(A, inf, med - 1, nuovo);
    nuovo->right = build_BST_OTT_AUX(A, med + 1, sup, nuovo);

    return nuovo;
  }
}

void in_order(pnode u) {
  if (u != nullptr) {
    in_order(u->left);
    std::cout << u->key << " ";
    in_order(u->right);
  }
}