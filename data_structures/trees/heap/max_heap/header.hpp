/**
 * @file header.hpp
 * @author me, myself and I
 * @brief definizione metodi e funzioni
 * @version 1.0
 * @date 2023-11-18
 */
#include "structs_used.hpp"

/**
 * @brief dato un nodo rende l'indice del padre
 *
 * @param i indice del nodo
 * @return int indice del padre del nodo i
 */
int parent(int i);

/**
 * @brief dato un nodo rende l'indice del figlio sinistro
 *
 * @param i indice del nodo
 * @return int indice del figlio sinistro di i
 */
int left(int i);

/**
 * @brief dato un nodo rende l'indice del figlio destro
 *
 * @param i indice del nodo
 * @return int indice del figlio destro di i
 */
int right(int i);

/**
 * @brief mantiene vera la proprietà dei max heap
 * @pre gli alberi binari con radice left(i) e right(i) sono dei max heap!
 * @param heap array da controllare
 * @param i padre dell'albero in cui verificare la proprietà
 */
void max_heapify(p_heap heap, int i);

/**
 * @brief dato un array disordinato, costruisce un heap
 *
 * @param heap array disordinato
 */
void build_max_heap(p_heap heap);

/**
 * @brief funzione di utilità per scambiare due elementi dell'array
 *
 * @param heap array
 * @param i1 posizione primo elemento
 * @param i2 posizione secondo elemento
 */
void swap(p_heap heap, int i1, int i2);

/**
 * @brief visualizza gli elementi dell'heap, arr[0...arr.heap_size]
 * 
 * @param heap array
 */
void stampa_heap(p_heap heap);