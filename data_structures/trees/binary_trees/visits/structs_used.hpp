/**
 * @file structs_used.hpp
 * @author me, myself and I
 * @brief strutture dati utilizzate per implementare l'albero
 * @version 1.1
 * @date 2023-11-23
 */

// realizzazione tramite strutture collegate: puntatore a left e right
#include <vector>
struct node {
  // node *p; //puntatore al padre
  node *left;  // puntatore al figlio sinistro
  node *right; // puntatore al figlio destro
  char key;    // contenuto informativo nodo

  // costruttore
  node(char k, node *sx = nullptr, node *dx = nullptr)
      : key{k}, left{nullptr}, right{nullptr} {}
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
  std::vector<char> info;
  std::vector<char> child_position;

  vector_parent(const std::vector<int> &p, const std::vector<char> &i,
                const std::vector<char> &c_posi)
      : parent{p}, info{i}, child_position{c_posi} {};
};
typedef vector_parent *parr;