/**
 * @file header.hpp
 * @author cogotti-giulia (cogotti.giulia.irl@gmail.com)
 * @brief definizione metodi e funzioni
 * @version 1.0
 * @date 2024-01-04
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "structs_used.hpp"
#include <string>

T_h build_tree_with_height(T t);

pnode_h build_tree_with_height_AUX(pnode u, int *h);

void in_order(pnode u);
void in_order_h(pnode_h u);

void pre_order(pnode u);
void pre_order_h(pnode_h u);

pnode crea_albero(parr vet_padri);

std::vector<T> get_trees_from_file(std::string file_name);