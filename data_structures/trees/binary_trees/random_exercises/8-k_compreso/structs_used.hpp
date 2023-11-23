/**
 * @file structs_used.hpp
 * @author me, myself and I
 * @brief strutture dati utilizzate per rappresentare l'albero
 * @version 1.0
 * @date 2023-11-23
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

/**
 * @brief struttura per rappresentare il vettore dei padri!
 * 
 */
struct vector_parent {
  int *parent;
  int *info;
  int size;

  vector_parent(int *p, int *i, int s) : parent{p}, info{i}, size{s} {};
};
typedef vector_parent *parr;
