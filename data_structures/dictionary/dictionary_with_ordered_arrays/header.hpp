/**
 * @file header.hpp
 * @author me, myself and I
 * @brief descrizione funzioni e metodi
 * @version 1.0
 * @date 2023-11-07
 */
#include "structs_used.hpp"
#include <cstddef>

/**
 * @brief cerca un particolare record riferito dalla chiave k
 * @post rende il valore associato a k se presente in A, altrimenti -1
 *
 * @param A array
 * @param k chiave da cercare
 * @param size dimensione dell'array
 * @return indice dell'array associato al valore k se esiste, altrimenti -1
 */
int search(my_array A, int k, size_t size);

/**
 * @brief ricerca binaria
 * @pre A[p...r] porzione su cui sto andando a cercare la chiave k
 *
 * @param A array
 * @param k chiave da cercare
 * @param p inizio porzione dell'array nella quale cercare la chiave k
 * @param r fine porzione dell'array nella quale cercare la chiave k
 * @return indice (int) in cui si trova la chiave k se esiste, -1 altrimenti
 */
int search_index(my_array A, int k, int p, int r);

/**
 * @brief aumentare (o diminuire) la dimensione di un array
 * @post crea un array con dimensione new_dim e copia il contenuto delle celle
 * del vecchio array A al nuovo array A punterà poi a quel nuovo array
 *
 * @param A array
 * @param new_dim dimensione del nuovo array
 * @param size dimensione del vecchio array A
 */
void reallocate(my_array A, size_t new_dim, size_t *size);

/**
 * @brief inserisce un nuovo record all'interno dell'array
 *
 * @post associa il valore v alla chiave k
 * @param A array
 * @param k nuova chiave da inserire in A, associata al valore v
 * @param v nuovo valore da inserire in A, associato alla chiave k
 * @param size puntatore alla dimensione dell'array
 */
void insert(my_array A, int k, int v, size_t *size);

/**
 * @brief elimina il record con chiave k
 * @pre k appartiene ad A
 * @param A array
 * @param k chiave del record da eliminare
 * @param size dimensione array A
 */
void delete_(my_array A, int k, size_t *size);

/**
 * @brief stampa il contenuto di ogni cella dell'array
 *
 * @pre
 * @param A
 * @param size
 */
void print_array(my_array A, size_t size);
