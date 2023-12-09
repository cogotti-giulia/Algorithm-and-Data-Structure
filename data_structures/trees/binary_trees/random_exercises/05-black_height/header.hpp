/**
 * @file header.hpp
 * @author me, myself and I
 * @brief definizione metodi e funzioni
 * @version 1.0
 * @date 2023-11-08
 */
#include "structs_used.hpp"

/**
 * @brief verifica se per ogni nodo, il cammino da quel nodo a qualsiasi foglia
 * contiene lo stesso numero di nodi neri (altezza nera del nodo x
 *
 * @param u radice albero
 * @return altezza nera della radice se è rispettata la condizione, -1
 * altrimenti
 */
int blackHeight(PNode u);

T crea_albero();