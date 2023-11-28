/**
 * @file header.hpp
 * @author me, myself and I
 * @brief definizione metodi e strutture usate
 * @version 1.0
 * @date 2023-11-28
 */
#include "structs_used.hpp"

/**
 * @brief data la radice di un albero aggiunge ad ogni foglia un nuovo nodo con
 * la somma del percorso dalla radice alla foglia come chiave. figlio sinistro
 * se la somma del percorso è positiva, figlio destro altrimenti
 *
 * @param u nodo albero
 */
void aggiungi_figli(pnode u);
/**
 * @brief funzione ausiliaria
 *
 * @param u nodo albero
 * @param sumP tiene traccia della somma lungo il percorso
 */
void aggiungi_figli_aux(pnode u, int *sumP);

void visita_dfs(pnode u);

pnode crea_albero(parr vet_padri);