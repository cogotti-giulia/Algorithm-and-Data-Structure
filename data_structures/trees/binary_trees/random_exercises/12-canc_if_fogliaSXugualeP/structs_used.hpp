/**
 * @file structs_used.hpp
 * @author me, myself and I
 * @brief strutture dati utilizzate per rappresentare l'albero binario
 * @version 1.0
 * @date 2023-11-28
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
  node *root;

  tree() : root{nullptr} {};
};
typedef tree *T;

struct vector_parent {
  int *parent;
  int *info;
  char *child_position;
  int size;

  vector_parent(int *p, int *i, char *c_posi, int s) : parent{p}, info{i}, child_position{c_posi}, size{s} {};
};
typedef vector_parent *parr;