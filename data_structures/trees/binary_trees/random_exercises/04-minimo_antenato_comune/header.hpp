/**
 * @file header.hpp
 * @author me, myself and I
 * @brief descrizione funzioni e metodi
 * @version 1.0
 * @date 2023-11-07
 */
#include "structs_used.hpp"
#include <cstddef>

/**
 * @brief calcola il minimo antenato comune (l'antenato di u e v che si trova
 * più lontano dalla radice)
 *
 * @param u nodo nell'albero
 * @param v nodo nell'albero
 * @return int
 */
pnode_prof mac(pnode_prof u, pnode_prof v);

/**
 * @brief crea un albero con profondità a partire dalla radice di un albero
 * senza essa
 *
 * @param u radice albero senza profondità
 * @return radice albero con profondità
 */
pnode_prof build_albero_con_prof(pnode u);

/**
 * @brief funzione ausiliaria per creare un albero con profondità
 *
 * @param u nodo senza profondita
 * @param padre padre (con profondità) di u
 * @param profondita tiene traccia della profondità a cui ci si trova
 * @return radice albero con profondità
 */
pnode_prof build_albero_con_prof_AUX(pnode u, pnode_prof padre, int profondita);

T crea_albero();
/**
 * @brief cerca un nodo (con profondità) con chiave k e lo restituisce
 *
 * @param u nodo di partenza
 * @param k chiave da cercare
 * @return nodo (con profondità) con chiave k se esiste, altrimenti null
 */
pnode_prof find_node(pnode_prof u, int k);

void in_order(pnode u);
void in_order_prof(pnode_prof u);