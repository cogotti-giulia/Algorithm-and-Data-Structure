/**
 * @file header.hpp
 * @author cogotti-giulia (cogotti.giulia.irl@gmail.com)
 * @brief definizione metodi e funzioni
 * @version 1.0
 * @date 2023-12-05
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include "structs_used.hpp"
#include <string>

int altezza_nodi(pnode r, int k);
int altezza_nodi_AUX(pnode u, int k, int *h);

void pre_order(pnode u);
void in_order(pnode u);

pnode crea_albero(parr vet_padri);

std::vector<T> get_trees_from_file(std::string file_name);