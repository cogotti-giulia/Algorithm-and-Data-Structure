/**
 * @file structs_used.hpp
 * @author cogotti-giulia (cogotti.giulia.irl@gmail.com)
 * @brief strutture dati utilizzate per implementare il BST
 * @version 1.0
 * @date 2023-12-12
 * 
 * @copyright Copyright (c) 2023
 * 
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