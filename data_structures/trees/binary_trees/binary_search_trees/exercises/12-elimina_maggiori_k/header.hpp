/**
 * @file header.hpp
 * @author cogotti-giulia (cogotti.giulia.irl@gmail.com)
 * @brief definizione metodi e funzioni utilizzate
 * @version 1.0
 * @date 2023-12-18
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include "structs_used.hpp"
#include <vector>

void elimina_maggiori_k(T t, int k);

pnode tree_minimum(pnode x);
pnode tree_maximum(pnode x);
pnode tree_predecessor(pnode x);
void transplant(T t, pnode old, pnode neww);
void tree_delete(T t, pnode z);

void reverse_in_order(T t, int k);

T build_BST_OTT(std::vector<int> A);
pnode build_BST_OTT_AUX(std::vector<int> A, int p, int r, pnode padre);