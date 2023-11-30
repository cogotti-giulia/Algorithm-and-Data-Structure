/**
 * @file header.hpp
 * @author cogotti-giulia (cogotti.giulia.irl@gmail.com)
 * @brief definizione metodi e funzioni
 * @version 1.0
 * @date 2023-11-30
 */
#include "structs_used.hpp"

/**
 * @brief calcola il numero di nodi i cui discendenti hanno lo stesso numero di
 * nodi bianchi e neri
 * @param u nodo
 * @return int numero di nodi i cui discendenti hanno lo stesso numero di
 * nodi bianchi e neri
 */
int discendenti_bw_sameNum(pnode u);

/**
 * @brief funzione ausiliaria per scorrere l'albero (post order) e verificare la
 proprietà su ogni nodo
 * @param u nodo
 * @param totBlack contiene il numero di nodi neri nel sottoalbero con radice in u
 * @param totWhite contiene il numero di nodi neri nel sottoalbero con radice in u 
 * @return int numero di nodi i cui discendenti hanno lo stesso numero di
 * nodi bianchi e neri
 */
int discendenti_bw_sameNum_aux(pnode u, int *totBlack, int *totWhite);

pnode crea_albero(parr vet_padri);

void post_order(pnode u);