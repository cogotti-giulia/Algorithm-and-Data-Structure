/**
 * @file header.hpp
 * @author cogotti-giulia (cogotti.giulia.irl@gmail.com)
 * @brief definizione metodi e funzioni
 * @version 1.0
 * @date 2023-12-06
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include "structs_used.hpp"
#include <string>
#include <vector>

bool is_simmetrico(pnode u);
bool is_simmetrico_AUX(pnode left, pnode right);

void pre_order(pnode u);
void in_order(pnode u);

pnode crea_albero(parr vet_padri);
std::vector<T> get_trees_from_file(std::string file_name);