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
#include <vector>

/**
 * @brief verifica se l'albero radicato in r è binario completo
 * @param r radice albero
 * @return true se l'albero è binario completo, false altrimenti
 */
bool is_binario_completo(pnode r);

/**
 * @brief funzione ausiliaria per verificare la proprietà di albero binario
 * completo
 * @param u nodo albero
 * @param profondita profondita del nodo
 * @param prof_foglia profondità, deve essere uguale per tutte le foglie,
 * settata alla prima foglia incontrata
 * @return true se l'albero è binario completo, false altrimenti
 */
bool is_binario_completo_AUX(pnode u, int profondita, int *prof_foglia);

void pre_order(pnode u);
void in_order(pnode u);

std::vector<T> get_trees_from_file(std::string file_name);
pnode crea_albero(parr vet_padri);
