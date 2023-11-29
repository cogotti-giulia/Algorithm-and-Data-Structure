/**
 * @file structs_used.hpp
 * @author cogotti-giulia
 * @brief strutture dati utilizzate per rappresentare l'albero
 * @version 1.1
 * @date 2023-11-29
 */
#include <vector>
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
  std::vector<int> parent;
  std::vector<int> info;
  std::vector<char> child_position;

  vector_parent(std::vector<int> p, std::vector<int> i,
                std::vector<char> c_posi)
      : parent{p}, info{i}, child_position{c_posi} {};
};
typedef vector_parent *parr;
