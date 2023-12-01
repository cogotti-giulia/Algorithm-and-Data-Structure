/**
 * @file header.hpp
 * @author cogotti-giulia
 * @brief definizione metodi e funzioni
 * @version 1.0
 * @date 2023-12-01
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

pnodeG crea_albero(parrG vet_padri);

