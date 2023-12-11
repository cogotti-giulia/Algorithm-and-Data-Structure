/**
 * @file header.hpp
 * @author me, myself and I
 * @brief definizione metodi
 * @version 1.0
 * @date 2023-11-08
 */
#include "structs_used.hpp"
#include <cstddef>
#include <iostream>

/**
 * @brief verifica se l'albero binario radicato in u e un BST usando la
 * definizione di BST
 *
 * @param u radice albero binario
 * @return true se l'albero binario radicato in u è un bst, false altrimenti
 */
bool check_BST_DEF(pnode u);

/**
 * @brief controlla i sotto alberi SX e DX in ricorsione e vede se sono BST
 *
 * @param u nodo
 * @param min minimo valore nell'albero
 * @param max massimo valore nell'albero
 * @return true se l'albero binario radicato in u è un bst, false altrimenti
 */
bool check_BST_DEF_AUX(pnode u, int *min, int *max);

/**
 * @brief verifica se l'albero binario radicato in u è un bst usando la
 * proprietà: "T è un BST se e solo se la visita simmetrica elenca le chiavi in
 * ordine non decrescente" (vedi dimostrazione nel file readme.md)
 *
 * @param u radice albero binario
 * @return true se l'albero binario radicato in u è un bst, false altrimenti
 */
bool check_BST_NO_DEF(pnode u);
pnode tree_minimum(pnode x);
pnode tree_successor(pnode x);

T build_BST_OTT(int *A, std::size_t n);
pnode build_BST_OTT_AUX(int *A, int inf, int sup, pnode padre);
void in_order(pnode u);
