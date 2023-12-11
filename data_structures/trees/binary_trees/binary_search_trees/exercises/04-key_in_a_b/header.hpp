/**
 * @file header.hpp
 * @author me, myself and I
 * @brief definizione metodi e funzioni
 * @version 1.0
 * @date 2023-11-23
 */
#include "structs_used.hpp"
#include <cstddef>

/**
 * @brief verifica se l'albero binario radicato in t è un BST nel quale tutte le
 * chiavi sono comprese nell'intervallo [a, b]
 * @pre le chiavi sono distinte
 * @pre a < b
 * @param tree albero binario
 * @param a estremo sinistro intervallo (compreso)
 * @param b estremo destro intervallo (compreso)
 * @return true se l'albero è un bst, false altrimenti
 */
bool is_bst_in_a_b(T tree, int a, int b);

pnode tree_minimum(pnode x);
pnode tree_successor(pnode x);

T build_BST_OTT(int *A, std::size_t n);
pnode build_BST_OTT_AUX(int *A, int inf, int sup, pnode padre);
void in_order(pnode u);