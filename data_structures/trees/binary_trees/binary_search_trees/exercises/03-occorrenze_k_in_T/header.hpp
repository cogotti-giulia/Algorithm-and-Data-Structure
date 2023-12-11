/**
 * @file header.hpp
 * @author me, myself and I
 * @brief definizione metodi e funzioni
 * @version 1.0
 * @date 2023-11-09
 */
#include "structs_used.hpp"
#include <cstddef>

/**
 * @brief dato un BST conta le occorrenze di k contenute nell'albero
 * 
 * @param t albero (BST)
 * @param k valore delle chiavi da contare
 * @return numero di occorrenze di k presenti in t 
 */
int occorrenze_k(T t, int k);

pnode tree_minimum(pnode x);
pnode tree_successor(pnode x);

T build_BST_OTT(int *A, std::size_t n);
pnode build_BST_OTT_AUX(int *A, int inf, int sup, pnode padre);

