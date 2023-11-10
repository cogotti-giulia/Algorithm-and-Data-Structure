/**
 * @file structs_used.hpp
 * @author me, myself and I
 * @brief strutture dati utilizzate per rappresentare l'albero
 * @version 1.0
 * @date 2023-11-08
 */
struct node {
  char key;
  node *left_child;
  node *right_sibling;

  node(char k, node *lc = nullptr, node *rs = nullptr)
      : key{k}, left_child{lc}, right_sibling{rs} {};
};
typedef node *pnodeG;

struct tree {
  node *root;

  tree() : root{nullptr} {};
};
typedef tree *T;