/**
 * @file header.hpp
 * @author cogotti-giulia
 * @brief descrizione funzioni e metodi
 * @version 1.1
 * @date 2023-11-29
 */
#include "structs_used.hpp"

pnode crea_albero(parr vet_padri);

/**
 * @brief conta il numero di nodi intermedi presenti nell'albero radicato in r
 *
 * @param r radice dell'albero
 * @return numero di nodi intermedi nell'albero
 */
int intermedi(pnode r);

/**
 * @brief funzione ausiliaria che conta il numero di nodi intermedi
 *
 * @param u nodo
 * @param sumPercorso somma sul percorso che va dalla radice al nodo u
 * @param sumKeys somma delle chiavi del sotto albero
 * @return numero di nodi intermedi nell'albero
 */
int intermedi_AUX(pnode u, int sumPercorso, int *sumKeys);

void visita_in_ampiezza_BFS(pnode u);