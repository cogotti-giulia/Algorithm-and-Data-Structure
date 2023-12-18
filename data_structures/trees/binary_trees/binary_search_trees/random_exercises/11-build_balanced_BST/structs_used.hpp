/**
 * @file structs_used.hpp
 * @author cogotti-giulia (cogotti.giulia.irl@gmail.com)
 * @brief strutture dati utilizzate per implementare il bst
 * @version 1.0
 * @date 2023-12-16
 *
 * @copyright Copyright (c) 2023
 *
 */

struct node {
  int key;

  node *left;
  node *right;

  node(int k, node *sx = nullptr, node *dx = nullptr)
      : key{k}, left{sx}, right{dx} {};
};

typedef node *pnode;

struct tree {
  pnode root;

  tree() : root{nullptr} {};
};

typedef tree *T;
