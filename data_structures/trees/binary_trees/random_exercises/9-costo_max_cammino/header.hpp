/**
 * @file header.hpp
 * @author me, myself and I
 * @brief definizione metodi e funzioni
 * @version 1.0
 * @date 2023-11-23
 */
#include "structs_used.hpp"

/**
 * @brief calcola ricorsivamente il costo massimo tra i cammini dell'albero
 *
 * @param u radice albero
 * @return costo massimo trovato
 */
int costo_max_cammino(pnode u);

pnode crea_albero(parr vet_padre);