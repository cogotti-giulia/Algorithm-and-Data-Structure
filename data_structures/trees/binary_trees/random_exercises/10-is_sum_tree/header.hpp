/**
 * @file header.hpp
 * @author me, myself and I
 * @brief definizione metodi e funzioni
 * @version 1.0
 * @date 2023-11-23
 */
#include "structs_used.hpp"

bool is_sum_tree(pnode u);
bool is_sum_tree_AUX(pnode u, int *sum);

/**
 * @brief crea un albero binario a partire dal vettore dei padri
 *
 * @param vet_padri vettore dei padri (contiene due vettori info e parent e
 * un intero che indica la dimensione di questi array)
 * @return pnode radice albero
 */
pnode crea_albero(parr vet_padri);

void visita_in_order_simmetrica(pnode u);