/**
 * @file header.hpp
 * @author me, myself and I
 * @brief definizione metodi e funzioni utilizzate
 * @version 1.0
 * @date 2023-11-25
 */

#include "structs_used.hpp"
#include <cmath>

/**
 * @brief dati due Max-Heap H1 e H2 contenenti rispettivamente n1 e n2 interi
 * (anche ripetuti), ritorna in output un nuovo Max-Heap contenente gli elementi
 * che appartengono a H1 ma non appartengono a H2. In presenza di duplicati se x
 * compare k1 volte in H1 e k2 volte in H2, nel Max-Heap differenza x dovrà
 * comparire max{0, k1-k2}.
 * @param h_diff array che rappresenta il nuovo heap
 * @param h1 array che rappresenta un heap
 * @param h2 array che rappresenta un heap
 */
void differenza(p_heap h_diff, p_heap h1, p_heap h2);

/**
 * @brief rimuove e restituisce l'elemento massimo da un heap
 *
 * @param heap array che rappresenta un heap
 * @return elemento massimo estratto
 */
int max_heap_extract_max(p_heap heap);

/**
 * @brief inserisce la chiave k nell'heap
 *
 * @param heap array che rappresenta un heap
 * @param k chiave da inserire
 */
void max_heap_insert(p_heap heap, int k);

/**
 * @brief estrae l'elemento massimo da un heap (solo lettura)
 *
 * @param heap array che rappresenta un heap
 * @return chiave elemento massimo
 */
int max_heap_maximum(p_heap heap);

/**
 * @brief dato un nodo i (posizione array) fa in modo che l'heap in input
 * risulti essere un max heap
 * @pre i figli left(i) e right(i) sono dei max heap!
 * @param heap array che rappresenta un heap
 * @param i posizione dell'array che rappresenta l'heap 
 */
void max_heapify(p_heap heap, int i);

int parent(int i);
int left(int i);
int right(int i);

void swap(p_heap heap, int i1, int i2);

void build_max_heap(p_heap heap);

void stampa_heap(p_heap heap);