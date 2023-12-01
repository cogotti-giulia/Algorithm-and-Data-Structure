/**
 * @file structs_used.hpp
 * @author cogotti-giulia
 * @brief strutture dati utilizzate per rappresentare l'albero
 * @version 1.1
 * @date 2023-12-01
 */
#include <vector>
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

struct vector_parent {
  std::vector<int> parent;
  std::vector<char> info; 
  std::vector<bool> is_left_child;

  vector_parent(std::vector<int> p, std::vector<char> i,
                std::vector<bool> is_lfc)
      : parent{p}, info{i}, is_left_child{is_lfc} {};
};
typedef vector_parent *parrG;