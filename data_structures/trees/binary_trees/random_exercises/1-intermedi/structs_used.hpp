/**
 * @file structs_used.hpp
 * @author cogotti-giulia
 * @brief strutture dati utilizzate per implementare l'albero
 * @version 1.1
 * @date 2023-11-29
 */

#include <vector>
struct node {
  // node *p;  //puntatore al padre
  node *left;  // puntatore al figlio sinistro
  node *right; // puntatore al figlio destro
  int key;     // contenuto informativo nodo

  // costruttore
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
  std::vector<int> parent;
  std::vector<int> info;
  std::vector<char> child_position;

  vector_parent(const std::vector<int>& p, const std::vector<int>& i,
                const std::vector<char>& c_posi)
      : parent{p}, info{i}, child_position{c_posi} {};
};
typedef vector_parent *parr;