/**
 * @file structs_used.hpp
 * @author me, myself and I
 * @brief strutture dati utilizzate per rappresentare l'albero
 * @version 1.0
 * @date 2023-11-08
 */
struct Node {
  int key;
  char col;
  Node *left;
  Node *right;

  Node(int k, char c, Node *sx = nullptr, Node *dx = nullptr)
      : key{k}, col{c}, left{sx}, right{dx} {}
};
typedef Node *PNode;

struct tree {
  Node *root;

  tree() : root{nullptr} {};
};

typedef tree *T;