/**
 * @file header.hpp
 * @author cogotti-giulia
 * @brief definizione metodi e funzioni
 * @version 1.1
 * @date 2023-12-01
 */
#include "structs_used.hpp"

/**
 * @brief dimezza i valori contenuti nelle chiavi dei livelli pari dell'albero
 * @pre u.key != 0
 * @param u radice dell'albero
 */
void trasforma(pnodeG u);

pnodeG crea_albero(parrG vet_padri);

void visita_preorder_DFS(pnodeG u);