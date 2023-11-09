/**
 * @file structs_used.hpp
 * @author me, myself and I
 * @brief strutture dati utilizzate per implementare il BST
 * @version 1.0
 * @date 2023-11-09
 */
struct node {
  int key;
  node *p;
  node *left;
  node *right;

  node(int k) : key{k}, p{nullptr}, left{nullptr}, right{nullptr} {};
};
typedef node *pnode;

struct tree {
  node *root;

  tree() : root{nullptr} {};
};
typedef tree *T;