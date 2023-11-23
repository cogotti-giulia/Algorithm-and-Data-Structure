/**
 * @file header.hpp
 * @author me, myself and I
 * @brief definizione metodi e funzioni
 * @version 1.0
 * @date 2023-11-23
 */
#include "structs_used.hpp"

/**
 * @brief dato un k appartenente ai numeri naturali verifica se l'albero
 * radicato in u è k compreso (per ogni nodo x la somma delle chiavi dei nodi
 * dell’albero radicato in x è compresa tra -k e k)
 *
 * @param u radice albero
 * @param k intero >= 0
 * @return true se l'albero è k compreso, false altrimenti
 */
bool k_compreso(pnode u, int k);

/**
 * @brief funzione ausiliaria per aiutarmi nel calcolare la somma dei
 * sotto alberi
 *
 * @param u nodo corrente
 * @param k intero >= 0
 * @param sum somma dei sotto alberi
 * @return true se l'albero è k compreso, false altrimenti
 */
bool k_compreso_aux(pnode u, int k, int *sum);

/**
 * @brief crea un albero binario a partire dal vettore dei padri
 *
 * @param vet_padri vettore dei padri (contiene due vettori info e parent e un
 * intero che indica la dimensione di questi array)
 * @return pnode radice albero
 */
pnode crea_albero(parr vet_padri);

void visita_in_order_simmetrica(pnode u);