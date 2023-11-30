/**
 * @file structs_used.hpp
 * @author cogotti-giulia (cogotti.giulia.irl@gmail.com)
 * @brief strutture dati utilizzate per rappresentare l'albero
 * @version 1.0
 * @date 2023-11-30
 */
#include <string>
#include <vector>

struct node {
  std::string color; // 'black' or 'white'
  node *left;
  node *right;

  node(std::string c, node *sx = nullptr, node *dx = nullptr)
      : color{c}, left{sx}, right{dx} {};
};
typedef node *pnode;

struct tree {
  node *root;

  tree() : root{nullptr} {};
};
typedef tree *T;

struct vector_parent {
  std::vector<int> parent;
  std::vector<std::string> info;
  std::vector<char> child_position;

  vector_parent(std::vector<int> p, std::vector<std::string> i,
                std::vector<char> c_posi)
      : parent{p}, info{i}, child_position{c_posi} {};
};
typedef vector_parent *parr;
