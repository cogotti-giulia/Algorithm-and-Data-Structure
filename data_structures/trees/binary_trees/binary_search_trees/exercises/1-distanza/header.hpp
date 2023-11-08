/**
 * @file header.hpp
 * @author me, myself and I
 * @brief implementazione funzioni e metodi
 * @version 1.0
 * @date 2023-11-08
 */
#include "structs_used.hpp"
#include <cstddef>
/**
 * @brief restituisce la minima distanza fra le chiavi dei nodi dell'albero t
 * @pre l'albero t ha almeno due nodi
 * @param t bst
 * @return int
 */
int min_distance(T t);

pnode tree_minimum(pnode x);
pnode tree_successor(pnode x);

T build_BST_OTT(int *A, std::size_t n);
pnode build_BST_OTT_AUX(int *A, int inf, int sup, pnode padre);

void in_order(pnode u);