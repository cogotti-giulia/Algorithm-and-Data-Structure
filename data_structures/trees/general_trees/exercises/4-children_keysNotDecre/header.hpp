/**
 * @file header.hpp
 * @author cogotti-giulia (cogotti.giulia.irl@gmail.com)
 * @brief definizione metodi e funzioni utilizzate
 * @version 1.0
 * @date 2023-12-01
 */
#include "structs_used.hpp"

/**
 * @brief verifica se per ogni nodo u vale la seguente proprietà: i figli di u
 * hanno chiavi non decrescenti
 * @param r nodo radice di un albero generale (rappresentato tramite left child
 * e right sibling)
 * @return true se la proprietà è verificata, false altrimenti
 */
bool is_not_decr(pnodeG r);

pnodeG crea_albero(parrG vet_padri);

void visita_post_order(pnodeG u);