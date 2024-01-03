/**
 * @file header.hpp
 * @author cogotti-giulia (cogotti.giulia.irl@gmail.com)
 * @brief definizione metodi e funzioni utilizzate
 * @version 1.0
 * @date 2024-01-03
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "structs_used.hpp"
#include <vector>

T build_BST_even_keys(T t);

std::vector<int> get_even_keys_from_T(T t);

T build_BST_OTT(std::vector<int> A);
pnode build_BST_OTT_AUX(std::vector<int> A, int p, int r, pnode padre);

pnode tree_minimum(pnode x);
pnode tree_successor(pnode x);

void in_order(T t);
