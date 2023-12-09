/**
 * @file structs_used.hpp
 * @author cogotti-giulia (cogotti.giulia.irl@gmail.com)
 * @brief strutture dati utilizzate per rappresentare l'albero binario
 * @version 1.0
 * @date 2023-12-09
 * 
 * @copyright Copyright (c) 2023
 * 
 */

struct node {
  int key;
  node *left;
  node *right;

  node(int k, node *sx = nullptr, node *dx = nullptr)
      : key{k}, left{sx}, right{dx} {};
};
typedef node *pnode;

