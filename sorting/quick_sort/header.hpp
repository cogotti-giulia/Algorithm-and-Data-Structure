/**
 * @file header.hpp
 * @author me, myself and I
 * @brief definizione metodi e funzioni
 * @version 1.0
 * @date 2023-11-18
 */
#include "structs_used.hpp"

/**
 * @brief ordina il vettore A[p...r] partizionandolo in due sottoarray
 *
 * @param arr array da ordinare
 * @param p inizio porzione da ordinare
 * @param r fine porzione da ordinare
 */
void my_quick_sort(my_elem *arr, int p, int r);

/**
 * @brief ordina i sottoarray in modo tale che sia partizionato nel seguente
 * modo:
 *      - A[q] = x è il pivot
 *      - A[p...q-1] contiene gli elementi <= x
 *      -A[q+1...r] contiene gli elementi > x
 * @param arr array da ordinare
 * @param p inizio porzione array da ordinare
 * @param r fine porzione array da ordinare
 * @return int indice pivot
 */
int my_partition(my_elem *arr, int p, int r);

/**
 * @brief ordina il vettore A[p...r] partizionandolo in due sottoarray e
 * aggiunge la randomizzazione
 *
 * @param arr array da ordinare
 * @param p inizio porzione da ordinare
 * @param r fine porzione da ordinare
 */
void my_randomized_quick_sort(my_elem *arr, int p, int r);

/**
 * @brief sceglie un elemento a caso come pivot tra gli elementi dell'array, lo
 * scambia con l'elemento in posizione A[r] e chiama la my_partition
 * @param arr array da ordinare
 * @param p inizio porzione array da ordinare
 * @param r fine porzione array da ordinare
 * @return int indice pivot
 */
int my_randomized_partition(my_elem *arr, int p, int r);

/**
 * @brief ordina A[p...r] tripartendo il vettore
 *
 * @param arr array da ordinare
 * @param p inizio porzione da ordinare
 * @param r fine porzione da ordinare
 */
void my_quick_sort_tripart(my_elem *arr, int p, int r);

/**
 * @brief permuta gli elementi di A[p...r] in modo  tale che:
 *  - gli elementi di A[q...t] sono uguali
 *  - ogni elemento di A[p...q-1] è minore di A[q]
 *  - ogni elemento di A[t+1...r] è maggiore di A[q]
 * @param arr array da ordinare
 * @param p inizio porzione da ordinare
 * @param r fine porzione da ordinare
 * @return  due indici q e t con p<=q<=t<=r
 */
my_double_index my_partition_tripart(my_elem *arr, int p, int r);

/**
 * @brief ordina A[p...r] tripartendo il vettore e aggiungendo la
 * randomizzazione
 *
 * @param arr array da ordinare
 * @param p inizio porzione da ordinare
 * @param r fine porzione da ordinare
 */
void my_randomized_quick_sort_tripart(my_elem *arr, int p, int r);

/**
 * @brief sceglie a caso un elemento da A[p...r], lo scambia con A[r] e chiama
 * la my_partition_tripart
 *
 * @param arr array da ordinare
 * @param p inizio porzione da ordinare
 * @param r fine porzione da ordinare
 * @return  due indici q e t con p<=q<=t<=r
 */
my_double_index my_randomized_partition_tripart(my_elem *arr, int p, int r);

/**
 * @brief funzione di utilità per scambiare due elementi dell'array
 *
 * @param arr array su cui lavorare
 * @param e1 indice primo elemento
 * @param e2 indice secondo elemento
 */
void swap(my_elem *arr, int e1, int e2);

void stampa_array(my_elem *arr, int n);