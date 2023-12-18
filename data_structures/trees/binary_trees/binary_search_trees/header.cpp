/**
 * @file header.cpp
 * @author me, myself and I
 * @brief implementazione funzioni e metodi
 * @version 1.0
 * @date 2023-11-07
 */
#include "header.hpp"
#include <cmath>
#include <iostream>

//! T(n) = O(h) dove h rappresenta l'altezza dell'albero
//! si segue un cammino che scende dalla radice a una foglia lungo al più h
void tree_insert(T tree, pnode z) {
  // padre del nodo con cui scorro
  pnode y = nullptr;
  // nodo per scendere lungo l'albero
  pnode scorri = tree->root;

  while (scorri != nullptr) {
    y = scorri; // scendo di livello
    if (z->key < scorri->key)
      scorri = scorri->left;
    else
      scorri = scorri->right;
  }
  // y è proprio il padre di z
  z->p = y;
  // caso in cui l'albero risulti essere vuoto
  if (y == nullptr)
    tree->root = z;
  else {
    // sistemo il figlio nella giusta posizione in base alla chiave
    if (z->key < y->key)
      y->left = z;
    else
      y->right = z;
  }
}

//! T(n) = O(h) dove h rappresenta l'altezza dell'albero
//! si segue un cammino che scende dalla radice a una foglia lungo al più h
pnode tree_search(pnode x, int k) {
  // in ogni caso il valore da rendere sarà o null o il valore cercato
  if (x == nullptr || x->key == k)
    return x;
  else {
    // cerca nei diversi sotto alberi in base al valore del campo key
    if (k < x->key) {
      return tree_search(x->left, k);
    } else {
      return tree_search(x->right, k);
    }
  }
}

//! T(n) = O(h) dove h rappresenta l'altezza dell'albero
//! si segue un cammino che scende dalla radice a una foglia lungo al più h
pnode tree_minimum(pnode x) {
  while (x->left != nullptr)
    x = x->left;

  return x;
}

//! T(n) = O(h) dove h rappresenta l'altezza dell'albero
//! si segue un cammino che scende dalla radice a una foglia lungo al più h
pnode tree_maximum(pnode x) {
  while (x->right != nullptr)
    x = x->right;

  return x;
}

//! T(n) = O(h) dove h rappresenta l'altezza dell'albero
//! si segue un cammino che scende dalla radice a una foglia lungo al più h
pnode tree_successor(pnode x) {
  if (x->right != nullptr)
    return tree_minimum(x->right);
  else {
    pnode y = x->p;
    //? x == y->right x è il figlio DX del padre, se è il sinistro (prima svolta
    //a DX) esco e ho trovato ciò che cercavo
    while (y != nullptr && x == y->right) {
      x = y;
      y = y->p;
    }
    return y;
  }
}

//! T(n) = O(h) dove h rappresenta l'altezza dell'albero
//! si segue un cammino che scende dalla radice a una foglia lungo al più h
pnode tree_predecessor(pnode x) {
  if (x->left != nullptr)
    return tree_maximum(x->left);
  else {
    pnode y = x->p;
    while (y != nullptr && x == y->left) {
      x = y;
      y = y->p;
    }
    return y;
  }
}

//! T(n) = Teta(1) costante
void transplant(T tree, pnode u, pnode v) {
  if (u->p == nullptr)
    tree->root = v;
  else if (u == u->p->left)
    u->p->left = v;
  else
    u->p->right = v;

  if (v != nullptr)
    v->p = u->p;
}

//! T(n) = O(h) dove h rappresenta l'altezza dell'albero
void tree_delete(T tree, pnode z) {
  //! i. z è ha solo un figlio SX => stacco z e creo un collegamento tra suo
  //! figlio e il padre di z
  if (z->left == nullptr)
    transplant(tree, z, z->right);
  else {
    //! ii. z è ha solo un figlio DX => stacco z e creo un collegamento tra suo
    //! figlio e il padre di z
    if (z->right == nullptr)
      transplant(tree, z, z->left);

    //? ATTENZIONE: i due casi sopra coprono anche il caso in cui z sia una
    //foglia
    else {
      //! iii. z ha due figli => trovo il successore di z (lo chiamo y) e lo
      //! metto nella posizione di z

      // potrei usare anche la tree_successore, ma so già che esiste un sotto
      // albero DX quindi mi basta la tree minimum
      pnode y = tree_minimum(z->right);

      // se i due nodi non sono collegati direttamente
      // so che per definizione y (successore di z) non ha un figlio sinistro
      // quindi sposto il sotto albero radicato in y.right (figlio boh lo chiamo
      // x) al posto di y sistemo i puntatori
      if (y->p != z) {
        transplant(tree, y, y->right);
        y->right = z->right;
        z->right->p = y;
      }

      // ora posso mettere y al posto di z
      transplant(tree, z, y);
      // attacco il sotto albero SX di z a y
      y->left = z->left;
      y->left->p = y;
    }
  }
}

/* analisi complessità
 * sommatori di i che va da 0 a n-1 di (c + di) = ... = n^2
 * dove i rappresenta la variazione dell'altezza dell'albero
 * //! quindi T(n) = Teta(n^2)
 *
 * se l'array fosse ordinato in modo crescente/decrescente avrei un albero
 * completamente sbilanciato :(
 */
T build_BST(int *A, size_t n) {
  T t = new tree();                // crea un albero vuoto
  for (size_t i = 0; i < n; i++) { //? eseguito n volte
    pnode u = new node(
        A[i]);         // crea un nodo con key=A[i] e u.p=u.right=u.left=nullptr
    tree_insert(t, u); //? O(h)
  }

  return t;
}

T build_BST_OTT(int *A, std::size_t n) {
  T t = new tree();
  t->root = build_BST_OTT_AUX(A, 0, n - 1, nullptr);
  return t;
}

pnode build_BST_OTT_AUX(int *A, int inf, int sup, pnode padre) {
  if (inf > sup) // array vuoto
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

//! T(n) = Teta(n) dove n rappresenta il numero di nodi dell'albero
void in_order(pnode u) {
  if (u != nullptr) {
    in_order(u->left);
    std::cout << u->key << " ";
    in_order(u->right);
  }
}
