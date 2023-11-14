/**
 * @file header.hpp
 * @author me, myself and I
 * @brief definizione metodi e funzioni
 * @version 1.0
 * @date 2023-11-14
 */
#include "structs_used.hpp"

/**
 * @brief ordina il vettore utilizzando l'algoritmo di insertion sort, mantiene
 * una porzione di k elementi già ordinati ed estende la soluzione al k+1 esimo
 * elemento
 * @post ordina arr[0 ... arr.size-1]
 * @param arr array da ordinare
 */
void insertion_sort(my_array arr);

void stampa_array(my_array arr);