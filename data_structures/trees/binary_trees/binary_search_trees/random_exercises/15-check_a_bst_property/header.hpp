/**
 * @file header.hpp
 * @author cogotti-giulia (cogotti.giulia.irl@gmail.com)
 * @brief definizione metodi e funzioni
 * @version 1.0
 * @date 2024-01-05
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "structs_used.hpp"
#include <string>
#include <vector>

bool check_property(T t);

pnode tree_minumum(pnode x);

pnode tree_successor(pnode x);

/**
 * @pre requires an ordered array!
 */
T build_BST(const std::vector<int>& A);

pnode build_BST_AUX(const std::vector<int>& A, int p, int r, pnode padre);

void print_bst(T t);

std::vector<std::vector<int>> get_arrays_from_file(std::string file_name);