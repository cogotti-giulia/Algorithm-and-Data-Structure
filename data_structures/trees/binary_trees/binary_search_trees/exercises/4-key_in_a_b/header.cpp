/**
 * @file header.cpp
 * @author me, myself and I
 * @brief implementazione metodi e funzioni
 * @version 1.0
 * @date 2023-11-23
 */

#include "header.hpp"
#include <cmath>
#include <iostream>

//! T(n) = O(n) in quando effettuando una visita simmetrica, ogni nodo viene
//! visitato al più una volta. Inoltre la visita si interrompe quando si
//! incontra un nodo che viola la condizione

bool is_bst_in_a_b(T tree, int a, int b) {
  if (tree->root == nullptr)
    return true; // un albero vuoto è bst e le chiavi sono comprese in [a, b]
  else {
    pnode min = tree_minimum(tree->root);

    bool is_ok = true;

    if (min->key >= a && min->key <= b) {
      pnode succ = tree_successor(min);
      pnode prev = min;

      while (succ != nullptr && is_ok) {
        if (prev->key > succ->key || succ->key < a || succ->key > b)
          is_ok = false;

        prev = succ;
        succ = tree_successor(prev);
      }
    } else
      is_ok = false;

    return is_ok;
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
    // salgo di figlio in padre fino a trovare la prima svolta a dx
    pnode scorri = x;

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
  if (inf > sup) {
    return nullptr;
  } else {
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
