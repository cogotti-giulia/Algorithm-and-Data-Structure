/**
 * @file header.hpp
 * @author cogotti-giulia (cogotti.giulia.irl@gmail.com)
 * @brief definizione metodi e funzioni usate
 * @version 1.0
 * @date 2023-12-09
 *
 * @copyright Copyright (c) 2023
 *
 */
#include "structs_used.hpp"
#include <string>

/**
 * @brief verifica se la proprietà di max heap vale per l'albero binario
 * radicato in u, ovvero controlla se per ogni nodo i diverso dalla radice vale
 * che la chiave del padre è maggiore o uguale alla chiave del nodo i
 * @param u nodo albero
 * @return true se la proprietà è verificata, false altrimenti
 */
bool check_proprieta_max_heap(pnode u);

void pre_order(pnode u);
void in_order(pnode u);

pnode crea_albero(parr vet_padri);
std::vector<T> get_trees_from_file(std::string file_name);