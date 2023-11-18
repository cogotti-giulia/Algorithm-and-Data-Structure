/**
 * @file header.hpp
 * @author me, myself and I
 * @brief definizione metodi e funzioni
 * @version 1.0
 * @date 2023-11-18
 */
#include "structs_used.hpp"

/**
 * @brief ordina l'array nel seguente modo:
 *  - costruisce un max heap a partire dall'array disordinato
 *  - estrae n-1 volte l'elemento massimo e lo mette come ultimo elemento del
 * vettore
 *  - ogni volta decrementa la heap size
 *  - ogni volta richiama la max heapify alla radice per mantenere vera la
 * proprietà di max heap
 *
 * @param heap array disordinato
 */
void my_heap_sort(p_heap heap);

/**
 * @brief costruisce un max heap a partire da un array disordinato
 *
 * @param heap array
 */
void build_max_heap(p_heap heap);

/**
 * @brief mantiene vera la proprietà di max heap
 * @pre gli alberi binari radicati in left(i) e right(i) sono max heap
 * @param heap array
 * @param i nodo che sto analizzando
 */
void max_heapify(p_heap heap, int i);

int parent(int i);
int left(int i);
int right(int i);

void swap(p_heap heap, int i1, int i2);

void stampa_array(p_heap heap);
