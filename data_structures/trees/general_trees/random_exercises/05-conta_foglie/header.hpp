/**
 * @file header.hpp
 * @author cogotti-giulia (cogotti.giulia.irl@gmail.com)
 * @brief definizione metodi e funzioni
 * @version 1.0
 * @date 2023-12-07
 */
#include "structs_used.hpp"
#include <string>
#include <vector>

/**
 * @brief conta il numero di foglie presenti nell'albero radicato in u
 * @param u nodo
 * @return numero di foglie dell'albero
 */
int conta_foglie(pnodeG u);

std::vector<T> get_trees_from_file(std::string file_name);

pnodeG crea_albero(parrG vet_padri);

void visita_post_order(pnodeG u);