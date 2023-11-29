/**
 * @file header.hpp
 * @author me, myself and I
 * @brief definizione metodi e funzioni
 * @version 1.0
 * @date 2023-11-29
 */

#include "structs_used.hpp"

/**
 * @brief conta i nodi i cui figli hanno tutti chiave uguale
 *
 * @param u nodo
 * @return int numero di nodi i cui figli hanno chiave uguale
 */
int node_childrenSameKey(pnodeG u);

/**
 * @brief funzione ausiliaria
 *
 * @param u nodo
 * @param ris alla fine contiene il numero di nodi dove i figli hanno chiave
 * uguale
 */
void node_childrenSameKey_AUX(pnodeG u, int *ris);

void visita_post_order(pnodeG u);
T crea_albero();