/**
 * @file header.hpp
 * @author cogotti-giulia
 * @brief definizione metodi e funzioni
 * @version 1.1
 * @date 2023-12-01
 */
#include "structs_used.hpp"

pnodeG crea_albero(parrG vet_padri);

/**
 * @brief visita il nodo, poi fa le chiamate ricorsive ai figli SX e DX
 *
 * @param u radice dell'albero
 */
void visita_preorder_DFS(pnodeG u);

/**
 * @brief chiamata ricorsiva al figlio SX, visita la radice, chiamata ricorsiva
 * al figlio DX
 *
 * @param u radice dell'albero
 */
void visita_in_order_simmetrica(pnodeG u);
// TODO: implementare visita in order

/**
 * @brief chiamata ricorsiva ai figli SX e DX e poi visita la radice
 *
 * @param u radice dell'albero
 */
void visita_post_order(pnodeG u);

/**
 * @brief tramite una coda fifo visita l'albero dal livello zero al livello h
 *
 * @param u radice dell'albero
 */
void visita_in_ampiezza_BFS(pnodeG u);
