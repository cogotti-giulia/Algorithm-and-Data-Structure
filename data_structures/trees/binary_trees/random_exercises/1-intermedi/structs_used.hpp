/**
 * @file structs_used.hpp
 * @author me, myself and I
 * @brief strutture dati utilizzate per implementare l'albero
 * @version 1.0
 * @date 2023-11-07
 */

struct node {
  // node *p;  //puntatore al padre
  node *left;  // puntatore al figlio sinistro
  node *right; // puntatore al figlio destro
  int key;     // contenuto informativo nodo

  // costruttore
  node(int k, node *sx = nullptr, node *dx = nullptr)
      : key{k}, left{sx}, right{dx} {};
};
typedef node *pnode;

struct tree {
  node *root;

  tree() : root{nullptr} {};
};
typedef tree *T;
