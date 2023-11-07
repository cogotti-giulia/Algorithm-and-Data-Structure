
#include "structs_used.hpp"

T crea_albero(); 

/**
 * @brief stampa le chiavi contenute nei nodi dell'albero a livello k
 * 
 * @pre k >= 0
 * @param u radice dell'albero
 * @param k intero >= 0
 */
void stampa_livello(pnode u, int k);

void visita_in_ampiezza_BFS(pnode u);