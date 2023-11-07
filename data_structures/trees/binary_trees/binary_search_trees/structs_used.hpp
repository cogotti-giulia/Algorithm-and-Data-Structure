/**
 * @file structs_used.hpp
 * @author me, myself and I
 * @brief strutture dati utilizzate per implementare i BST
 * @version 1.0
 * @date 2023-11-07
 */

struct node {
  int key;
  node *p;
  node *left;
  node *right;

  node(int k, node *padre = nullptr, node *sx = nullptr, node *dx = nullptr)
      : key{k}, p{padre}, left{sx}, right{dx} {};
};

typedef node *pnode;

struct tree {
  pnode root;

  tree() : root{nullptr} {};
};

typedef tree *T;
