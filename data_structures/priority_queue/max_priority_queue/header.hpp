/**
 * @file header.hpp
 * @author me, myself and I
 * @brief definizione metodi e funzioni
 * @version 1.0
 * @date 2023-11-20
 */
#include "structs_used.hpp"

/**
 * @brief restituisce l'elemento dell'heap con chiave più grande
 *
 * @param heap array
 * @return int elemento massimo
 */
int q_heap_maximum(p_heap heap);

/**
 * @brief elimina e restituisce l'elemento con la chiave più grande
 *
 * @param heap array
 * @return int elemento massimo
 */
int q_max_heap_extract_max(p_heap heap);

/**
 * @brief aumenta il valore della chiave di x al nuovo valore k
 * @pre k >= chiave di x
 * @param heap array
 * @param i indice che identifica la posizione dell'elemento nel vettore
 * @param key nuovo valore della chiave da assegnare ad i
 */
void q_max_heap_increase_key(p_heap heap, int i, int key);

/**
 * @brief inserisce l'elemento key in heap
 *
 * @param heap heap in cui inserire l'elemento
 * @param key nuovo elemento
 */
void q_max_heap_insert(p_heap heap, int key);

void max_heapify(p_heap heap, int i);
void swap(p_heap heap, int i1, int i2);

int left(int i);
int right(int i);
int parent(int i);

void stampa_heap(p_heap heap);