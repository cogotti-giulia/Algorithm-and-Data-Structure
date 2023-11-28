/**
 * @file header.hpp
 * @author me, myself and I
 * @brief definizione metodi e funzioni utilizzate
 * @version 1.0
 * @date 2023-11-28
 */
#include "structs_used.hpp"

/**
 * @brief per ogni nodo elimina il figlio sinistro se esso è una foglia e ha
 * chiave uguale al nodo padre
 *
 * @param u radice albero
 */
void cancella(pnode u);
/**
 * @brief funzione ausiliaria, mi serve tenere traccia del padre per poter
 * confrontare il valore delle chiavi tra padre e figlio (quando il figlio è una
 * foglia) ed eventualmente cancellare il figlio
 *
 * @param u nodo albero
 * @param padre padre del nodo u
 */
void cancella_aux(pnode u, pnode padre);

void visita_dfs(pnode u);

pnode crea_albero(parr vet_padri);