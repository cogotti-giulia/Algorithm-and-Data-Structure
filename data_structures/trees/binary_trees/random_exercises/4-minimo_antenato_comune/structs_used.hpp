/**
 * @file structs_used.hpp
 * @author me, myself and I
 * @brief strutture dati utilizzate per implementare l'albero
 * @version 1.0
 * @date 2023-11-07
 */

//! nodo con profondità
struct node_with_prof {
  int key;
  int prof;          // profondità
  node_with_prof *p; // padre
  node_with_prof *left;
  node_with_prof *right;
};
typedef node_with_prof *pnode_prof;

struct tree_with_prof {
  node_with_prof *root;

  tree_with_prof() : root{nullptr} {};
};
typedef tree_with_prof *T_prof;

//! nodo senza profondità
struct node {
  node *p;
  node *left;
  node *right;
  int key;

  node(int k, node *sx = nullptr, node *dx = nullptr, node *padre = nullptr)
      : key{k}, left{sx}, right{dx}, p{padre} {};
};
typedef node *pnode;

struct tree {
  node *root;

  tree() : root{nullptr} {};
};
typedef tree *T;
