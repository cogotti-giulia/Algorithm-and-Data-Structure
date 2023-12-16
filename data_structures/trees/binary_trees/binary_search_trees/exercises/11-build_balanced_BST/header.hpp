/**
 * @file header.hpp
 * @author cogotti-giulia (cogotti.giulia.irl@gmail.com)
 * @brief definizione metodi e funzioni utilizzate
 * @version 1.0
 * @date 2023-12-16
 *
 * @copyright Copyright (c) 2023
 *
 */
#include "structs_used.hpp"
#include <vector>

/**
 * @brief crea un bst di altezza logn a partire da un array di n elementi
 * @param A array di n elementi A[0...n-1]
 * @return albero binario di ricerca
 */
T build_bst_height_logn(const std::vector<int> &A);
/**
 * @brief funzione ausiliaria utilizzata per creare l'albero ricorsivamente
 * prendendo l'elemento centrale dell'array come chiave del nodo corrente e
 * attaccando in ricorsione i figli sinistro e destro andandoli a cercare nelle
 * porzioni dell'array rispettivamente sinistra e destra
 * @param A array di n elementi A[0...n-1]
 * @param p inizio porzione dell'array su cui sto lavorando
 * @param r fine porzione dell'array su cui sto lavorando
 * @return nodo radice dell'albero binario di ricerca che ho costruito
 */
pnode build_bst_height_logn_AUX(const std::vector<int> &A, int p, int r);

/**
 * @brief ordina ricorsivamente il vettore di input
 * @param A vettore da ordinare
 * @param p inizio porzione da ordinare
 * @param r fine porzione da ordinare
 */
void my_merge_sort(std::vector<int> &A, int p, int r);
/**
 * @brief dati due array L[p...q] e R[q+1...r] ordinati, ordina ottenendo un
 * vettore A[p...r] ordinati
 * @param A vettore da ordinare
 * @param p inizio porzione da ordinare
 * @param q indice che divide l'array in due sottoarray ordinati
 * @param r fine porzione da ordinare
 */
void my_merge(std::vector<int> &A, int p, int q, int r);

void in_order(pnode u);
void stampa_array(const std::vector<int> &A);