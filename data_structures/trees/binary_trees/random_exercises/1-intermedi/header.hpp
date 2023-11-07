#include "structs_used.hpp"

T crea_albero(); 

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
int intermedi_AUX(pnode u, int sumPercorso, int* sumKeys);

void visita_in_ampiezza_BFS(pnode u);