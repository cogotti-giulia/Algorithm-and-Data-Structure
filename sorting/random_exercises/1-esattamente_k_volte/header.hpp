/**
 * @file header.hpp
 * @author me, myself and I
 * @brief definizione metodi e funzioni
 * @version 1.0
 * @date 2023-11-26
 */
#include "structs_used.hpp"
#include <vector>

/**
 * @brief verifica se nell'array di input esiste un elemento ripetuto
 * esattamente k volte
 *
 * @param A array disordinato
 * @param k intero positivo
 * @return true se esiste l'elemento, false altrimenti
 */
bool esattamente_k_volte(std::vector<int> *A, int k);

/**
 * @brief ordina ricorsivamente l'array
 *
 * @param A array da ordinare
 * @param p inizio porzione da ordinare
 * @param r fine porzione da ordinare
 */
void my_quick_sort_tri(std::vector<int> *A, int p, int r);

/**
 * @brief divide l'array in tre sottoarray tali che
 * - A[p...q-1] contiene gli elementi minori di x
 * - A[q...t] contiene gli elementi uguali ad x
 * - A[t+1...r] contiene gli elementi maggiori di x
 * dove x è il pivot scelto dalla randomized partition
 * @param A array da ordinare
 * @param p inizio porzione da ordinare
 * @param r fine porzione da ordinare
 * @return my_double_index, due indici q e t che delimitano la porzione di
 * elementi uguali ad x (pivot)
 */
my_double_index my_partition_tri(std::vector<int> *A, int p, int r);

/**
 * @brief sceglie un elemento a caso dell'array e lo scambia con l'elemento in
 * ultima posizione. infine chiama la partition vera e propria
 *
 * @param A array da ordinare
 * @param p inizio porzione da ordinare
 * @param r fine porzione da ordinare
 * @return risultato della partition
 */
my_double_index my_rand_partition_tri(std::vector<int> *A, int p, int r);

void my_swap(std::vector<int> *A, int i1, int i2);
void stampa_array(std::vector<int> A);