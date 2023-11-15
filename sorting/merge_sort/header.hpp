/**
 * @file header.hpp
 * @author me, myself and I
 * @brief definizione metodi e funzioni
 * @version 1.0
 * @date 2023-11-15
 */
#include "structs_used.hpp"
#include <array>
#include <cstddef>

/**
 * @brief utilizza la tecnica del divide et impera per ordinare in loco l'array
 * di input mantenendo l'ordine di eventuali duplicati (metodo stabile). divide
 * l'array in due sottoarray L[p..q] e R[q11...r], li ordina ricorsivamente e
 * richiama la funzione di merge per fonderli insieme ottenendo un unico array
 * ordinato
 *
 * @param arr array da ordinare di dimensione n
 * @param p inizio della porzione da ordinare (alla prima chiamata p = 0)
 * @param r fine della porzione da ordinare (alla prima chiamata r = n-1, dove n
 * è la size dell'array)
 */
void my_merge_sort(my_elem *arr, int p, int r);

/**
 * @brief presi due sottoarray ordinati L[p...q] e R[q+1...r] li fonde insieme
 * ottenendo un'array A[p...r] ordinato
 *
 * @param arr array da ordinare
 * @param p inizio porzione da ordinare
 * @param q indice che divide l'array in due sottoarray ordinati
 * @param r fine della porzione da ordinare
 */
void my_merge(my_elem *arr, int p, int q, int r);

void stampa_array(my_elem *arr, int n);