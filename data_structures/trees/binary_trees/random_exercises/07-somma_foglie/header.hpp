/**
 * @file header.hpp
 * @author me, myself and I
 * @brief definizione metodi e funzioni
 * @version 1.1
 * @date 2023-11-23
 */
#include "structs_used.hpp"

/**
 * @brief somma i valori delle chiavi contenute nelle foglie
 *
 * @param tree albero binario
 * @return somma delle chiavi contenute nei nodi foglia, zero se l'albero è
 * vuoto
 */
int somma_foglie(T tree);
/**
 * @brief funzione ausiliaria per portarmi dietro la somma
 *
 * @param u nodo
 * @param sum somma chiavi mentre scorro l'albero
 * @return somma delle chiavi contenute nei nodi foglia, zero se l'albero è
 * vuoto
 */
int somma_foglie_aux(pnode u, int *sum);

/**
 * @brief somma i valori delle chiavi contenute nelle foglie
 *
 * @param tree albero binario
 * @return somma delle chiavi contenute nei nodi foglia, zero se l'albero è
 * vuoto
 */
int somma_foglie_minimal(T tree);

/**
 * @brief funzione ausiliaria per effettuare la ricorsione sui figli
 *
 * @param u nodo
 * @return somma delle chiavi contenute nei nodi foglia, zero se l'albero è
 * vuoto
 */
int somma_foglie_minimal_aux(pnode u);

/**
 * @brief costruisce un albero binario a partire dal vettore dei padri
 *
 * @param vet_padri vettore dei padri
 * @return radice dell'albero
 */
pnode crea_albero(parr vet_padri);

void visita_in_ampiezza(pnode u);
