/**
 * @file header.hpp
 * @author me, myself and I
 * @brief definizione metodi e funzioni
 * @version 1.0
 * @date 2023-11-08
 */
#include "structs_used.hpp"

/**
 * @brief dimezza i valori contenuti nelle chiavi dei livelli pari dell'albero
 * @pre u.key != 0
 * @param u radice dell'albero
 */
void trasforma(pnodeG u);

T crea_albero();

void visita_preorder_DFS(pnodeG u);