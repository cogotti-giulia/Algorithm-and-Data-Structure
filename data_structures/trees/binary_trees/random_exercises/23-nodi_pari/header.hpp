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
#include <string>

int nodi_pari(pnode u);
int nodi_pari_AUX(pnode u, int *foglie);

void post_order(pnode u);
std::vector<T> get_trees_from_file(std::string file_name);
pnode crea_albero(parr vet_padri);