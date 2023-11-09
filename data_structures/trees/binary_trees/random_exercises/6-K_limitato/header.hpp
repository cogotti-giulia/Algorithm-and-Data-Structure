/**
 * @file header.hpp
 * @author me, myself and I
 * @brief definizione metodi e funzioni
 * @version 1.0
 * @date 2023-11-09
 */
#include "structs_used.hpp"

/**
 * @brief verifica se l'albero radicato in u è k limitato, ovvero se le somme
 * delle chiavi contenute nei sotto alberi radicati in u sono minori o uguali a
 * k
 *
 * @param u nodo
 * @param k limite per cui l'albero risulta k limitato
 * @return true se l'albero è k limitato, false altrimenti
 */
bool k_limitato(pnode u, int k);

/**
 * @brief funzione ausiliaria per verificare se l'albero è k limitato
 *
 * @param u nodo
 * @param k limite per cui l'albero risulta k limitato
 * @param sum tiene traccia della somma del sotto albero
 * @return true se il sotto albero è k limitato, false altrimenti
 */
bool k_limitato_AUX(pnode u, int k, int *sum);

T crea_albero();