/**
 * @file header.hpp
 * @author cogotti-giulia (cogotti.giulia.irl@gmail.com)
 * @brief definizione metodi e funzioni
 * @version 1.0
 * @date 2024-01-03
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "structs_used.hpp"
#include <vector>

ptree modify_key(ptree t, pnode x, int key);

pnode tree_predecessor(pnode x);
pnode tree_successor(pnode x);

pnode tree_minimum(pnode x);
pnode tree_maximum(pnode x);

void in_order(pnode u);

ptree build_BST_OTT(std::vector<int> A);
pnode build_BST_OTT_AUX(std::vector<int> A, int p, int r, pnode padre);

pnode find_node_by_key(pnode u, int key);