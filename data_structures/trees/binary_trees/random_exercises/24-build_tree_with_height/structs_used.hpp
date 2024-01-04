/**
 * @file structs_used.hpp
 * @author cogotti-giulia (cogotti.giulia.irl@gmail.com)
 * @brief strutture dati utilizzate per implementare gli alberi binari
 * @version 1.0
 * @date 2024-01-04
 *
 * @copyright Copyright (c) 2024
 *
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

struct node_h {
  int key;
  int height;
  node_h *left;
  node_h *right;

  node_h(int k, int h = -1, node_h *sx = nullptr, node_h *dx = nullptr)
      : key{k}, height{h}, left{sx}, right{dx} {};
};
typedef node_h *pnode_h;

struct tree {
  node *root;

  tree() : root{nullptr} {};
};
typedef tree *T;

struct tree_h {
  node_h *root;

  tree_h() : root{nullptr} {};
};
typedef tree_h *T_h;

struct vector_parent {
  std::vector<int> parent;
  std::vector<int> info;
  std::vector<char> child_position;

  vector_parent(const std::vector<int> &p, const std::vector<int> &i,
                const std::vector<char> &c_posi)
      : parent{p}, info{i}, child_position{c_posi} {};
};
typedef vector_parent *parr;
