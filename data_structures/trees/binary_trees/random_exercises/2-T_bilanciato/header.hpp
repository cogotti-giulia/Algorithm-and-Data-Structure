#include "structs_used.hpp"

/**
 * @brief rende il minimo t per cui l'albero risulta t-bilanciato
 * 
 * @param u nodo
 * @return minimo t se l'albero non è vuoto, 0 altrimenti
 */
int t_bilanciato(pnode u);
/**
 * @brief rende il minimo t per cui l'albero risulta t-bilanciato
 * 
 * @param u nodo
 * @param h altezza albero
 * @return minimo t se l'albero non è vuoto, 0 altrimenti
 */
int t_bilanciato_AUX(pnode u, int* h);


T crea_albero(); 
void visita_in_ampiezza_BFS(pnode u);