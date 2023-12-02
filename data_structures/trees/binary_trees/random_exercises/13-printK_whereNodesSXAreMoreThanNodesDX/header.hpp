/**
 * @file header.hpp
 * @author cogotti-giulia (cogotti.giulia.irl@gmail.com)
 * @brief definizione metodi e funzioni
 * @version 1.0
 * @date 2023-11-29
 */

#include "structs_used.hpp"
#include <string>
#include <vector>

void stampaK_nodeSX_mag_nodeDX(pnode u);

int stampaK_nodeSX_mag_nodeDX_AUX(pnode u);

pnode crea_albero(parr vet_padri);

void pre_order(pnode u);

std::vector<T> get_trees_from_file(std::string file_name);