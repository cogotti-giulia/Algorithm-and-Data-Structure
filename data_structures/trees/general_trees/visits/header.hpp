/**
 * @file header.hpp
 * @author me, myself and I
 * @brief definizione metodi e funzioni
 * @version 1.0
 * @date 2023-11-08
 */
#include "structs_used.hpp"

/**
 * @brief restituisce l'albero creato
 *
 * @return albero generale
 */
T crea_albero_lc_rsib();

/**
 * @brief visita il nodo, poi fa le chiamate ricorsive ai figli SX e DX
 *
 * @param u radice dell'albero
 */
void visita_preorder_DFS(pnode u);

/**
 * @brief chiamata ricorsiva al figlio SX, visita la radice, chiamata ricorsiva
 * al figlio DX
 *
 * @param u radice dell'albero
 */
void visita_in_order_simmetrica(pnode u);
// TODO: implementare visita in order

/**
 * @brief chiamata ricorsiva ai figli SX e DX e poi visita la radice
 *
 * @param u radice dell'albero
 */
void visita_post_order(pnode u);

/**
 * @brief tramite una coda fifo visita l'albero dal livello zero al livello h
 *
 * @param u radice dell'albero
 */
void visita_in_ampiezza_BFS(pnode u);
