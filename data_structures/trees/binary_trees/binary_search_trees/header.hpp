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
 * @brief cerca un nodo con chiave k a partire dal nodo x e lo restituisce
 * @post restituisce nodo con chiave k se esiste, altrimenti null
 * @param x nodo di partenza da cui cercare
 * @param k chiave da cercare
 * @return pnode
 */
pnode tree_search(pnode x, int k);

/**
 * @brief restituisce il nodo col minimo valore nell'albero a partire dalla
 * radice, essendo un BST esso si troverà seguendo il cammino più a sinistra
 * dalla radice alla foglia
 *
 * @param x radice dell'albero
 * @return pnode
 */
pnode tree_minimum(pnode x);

/**
 * @brief restituisce il nodo col massimo valore nell'albero a partire dalla
 * radice, essendo un BST esso si troverà seguendo il cammino più a destra dalla
 * radice alla foglia
 *
 * @param x radice dell'albero
 * @return pnode
 */
pnode tree_maximum(pnode x);

/**
 * @brief trova il successore di un nodo
 *        i. se x ha un figlio DX => tree_successor(x) è il minimo del sotto
 * albero DX ii. se x NON ha un figlio DX => tree_successor(x) se esiste è
 * l'antenato più prossimo di x il cui figlio è anche antenato di x (si trova
 * risalendo da x verso la radice fino ad incontrare la prima svolta a DX)
 * @post restituisce il successore di x in una visita simmetrica se esiste, null
 * altrimenti
 *
 * @param x nodo appartenente a T
 * @return pnode
 */
pnode tree_successor(pnode x);

/**
 * @brief trova il predecessore di un nodo
 *        i. se x ha un figlio SX => tree_successor(x) è il massimo del sotto
 * albero SX ii. se x NON ha un figlio SX => tree_successor(x) se esiste è
 * l'antenato più prossimo di x il cui figlio è anche antenato di x (si trova
 * risalendo da x verso la radice fino ad incontrare la prima svolta a SX)
 * @post restituisce il predecessore di x in una visita simmetrica se esiste,
 * null altrimenti
 *
 * @param x nodo appartenente a T
 * @return pnode
 */
pnode tree_predecessor(pnode x);

/**
 * @brief inserisce un nodo nell'albero mantenendo vera la proprietà di BST
 * @pre z è un nodo tale x.key = v e z.left = z.right = null
 * @post inserisce il nodo z in tree
 *
 * @param tree albero con campo root che punta alla radice
 * @param z nodo da inserire
 */
void tree_insert(T tree, pnode z);

/**
 * @brief sposta il sotto albero con radice in v nella posizione del sotto
 * albero con radice in u
 *
 * @param tree albero
 * @param u radice del sotto albero in cui inserire v
 * @param v sotto albero da inserire
 */
void transplant(T tree, pnode u, pnode v);

/**
 * @brief elimina un nodo dall'albero
 * @pre z appartiene a tree
 * @param tree albero da modificare
 * @param z nodo da eliminare
 */
void tree_delete(T tree, pnode z);

/**
 * @brief costruzione di un BST molto poco efficiente T(n) = Teta(n^2)
 *
 * @param A array contenente le chiavi da inserire
 * @param n dimensione dell'array A
 * @return T
 */
T build_BST(int *A, std::size_t n);

/**
 * @brief costruisce un BST, abbastanza efficiente T(n) = Teta(n) rispetto
 * all'altro metodo
 *
 * @param A array contente le chiavi da inserire
 * @param n dimensione dell'array A
 * @return T
 */
T build_BST_OTT(int *A, std::size_t n);

/**
 * @brief funzione ausiliaria per costruire un BST ottimizzato, rende la radice
 * dell'albero
 * @pre A È ORDINATO
 *
 * @param A array contenente le chiavi da inserire
 * @param inf limite inferiore della porzione dell'array su cui sto lavorando
 * @param sup limite superiore della porzione dell'array su cui sto lavorando
 * @param padre padre del nodo che sto andando ad inserire
 * @return pnode
 */
pnode build_BST_OTT_AUX(int *A, int inf, int sup, pnode padre);

/**
 * @brief visita simmetrica
 * @param p nodo quando la procedura viene chiamata p è la radice dell'albero
 */
void in_order(pnode p);