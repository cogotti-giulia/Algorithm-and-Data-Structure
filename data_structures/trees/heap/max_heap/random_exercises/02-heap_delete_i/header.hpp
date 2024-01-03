/**
 * @file header.hpp
 * @author cogotti-giulia (cogotti.giulia.irl@gmail.com)
 * @brief definizione metodi e funzioni 
 * @version 1.0
 * @date 2024-01-03
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "structs_used.hpp"

void heap_delete(p_heap &A, int i);

void max_heapify(p_heap &A, int i);

void stampa_heap(p_heap A);

int parent(int i);
int left(int i);
int right(int i);

void my_swap(p_heap &A, int i1, int i2);