/**
 * @file structs_used.hpp
 * @author cogotti-giulia (cogotti.giulia.irl@gmail.com)
 * @brief strutture dati utilizzate per implementare l'albero generale
 * @version 1.0
 * @date 2023-12-01
 */
#include <vector>

struct node {
  int key;
  node *left_child;
  node *right_sibling;

  node(int k, node *lc = nullptr, node *rs = nullptr)
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
  std::vector<int> info;
  std::vector<bool> is_left_child;

  vector_parent(std::vector<int> p, std::vector<int> i,
                std::vector<bool> is_lfc)
      : parent{p}, info{i}, is_left_child{is_lfc} {};
};
typedef vector_parent *parrG;