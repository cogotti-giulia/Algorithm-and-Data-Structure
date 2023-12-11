/**
 * @file header.hpp
 * @author cogotti-giulia (cogotti.giulia.irl@gmail.com)
 * @brief definizione metodi e funzioni
 * @version 1.0
 * @date 2023-11-30
 */
#include "structs_used.hpp"
#include <vector>

/**
 * @brief stampa l'array di input ordinato costruendo un BST tramite n chiamate
 * a tree_insert ed effettuando una visita simmetrica dell'albero
 * @param A array di input
 */
void sort_BST(std::vector<int> A);

/**
 * @brief inserisce un nodo nell'albero mantenendo vera la proprietà di bst
 * @pre z è un nodo tale che z.p=z.left=z.right=NIL
 * @param t albero bst
 * @param z nodo da inserire
 */
void tree_insert(T t, pnode z);

/**
 * @brief trova il minimo del sottoalbero radicato in x
 * @param x nodo di partenza
 * @return nodo con valore minimo
 */
pnode tree_minimum(pnode x);

/**
 * @brief trova il successero del nodo x
 * @param x nodo di partenza
 * @return nodo successore di x
 */
pnode tree_successor(pnode x);

/**
 * @brief stampa le chiavi dell'albero binario di ricerca radicato in r
 * effettuando una visita simmetrica (trovando l'elemento minimo ed effettuando
 * poi n-1 chiamate a tree successor)
 * @param r nodo radice bst
 */
void visita_simmetrica_BST(pnode r);

void print_array(std::vector<int> A);