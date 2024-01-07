/**
 * @file header.hpp
 * @author me, myself and I
 * @brief definizione metodi e funzioni
 * @version 1.0
 * @date 2023-11-28
 */

#include <vector>

/**
 * @brief verifica se le stringhe sono una l'anagramma dell'altra
 * 
 * @param A vettore di caratteri
 * @param B vettore di caratteri
 * @return true se le stringhe sono una l'anagramma dell'altra, false altrimenti
 */
bool anagramma(std::vector<char> *A, std::vector<char> *B);

/**
 * @brief ordina ricorsivamente il vettore A[p...r]
 * 
 * @param A array da ordinare
 * @param p indice inizio porzione da ordinare
 * @param r fine porzione da ordinare
 */
void my_merge_sort(std::vector<char> *A, int p, int r);

/**
 * @brief dati due array L[p...q] r R[q+1...r] ordinati, costruisce A[p...r] ordinato
 * 
 * @param A array da ordinare
 * @param p indice inizio
 * @param q indice che divide l'array in due sottoarray
 * @param r indice fine
 */
void my_merge(std::vector<char> *A, int p, int q, int r);

void print_string(std::vector<char> A);