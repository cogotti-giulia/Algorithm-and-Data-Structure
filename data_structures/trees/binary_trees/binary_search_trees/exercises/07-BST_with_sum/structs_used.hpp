/**
 * @file structs_used.hpp
 * @author cogotti-giulia (cogotti.giulia.irl@gmail.com)
 * @brief strutture dati usate per rappresentare l'albero
 * @version 1.0
 * @date 2023-12-11
 * 
 * @copyright Copyright (c) 2023
 * 
 */

struct node {
  int key;
  int sum;
  node *p;
  node *left;
  node *right;

  node(int k, int s = 0, node *padre = nullptr, node *sx = nullptr, node *dx = nullptr)
      : key{k}, sum{s}, p{padre}, left{sx}, right{dx} {};
};

typedef node *pnode_s;

struct tree {
  pnode_s root;

  tree() : root{nullptr} {};
};

typedef tree *T_s;