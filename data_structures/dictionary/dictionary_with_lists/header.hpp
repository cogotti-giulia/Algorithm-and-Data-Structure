/**
 * @file header.hpp
 * @author me, myself and I
 * @brief descrizione funzioni e metodi
 * @version 1.0
 * @date 2023-11-07
 */
#include "structs_used.hpp"
#include <list>

/**
 * @brief inserisce un nuovo elemento all'interno della lista, in testa!
 *
 * @post associa il valore v alla chiave k
 * @param list lista di record con puntatore alla testa
 * @param k nuova chiave da inserire in L, associata al valore v
 * @param v nuovo valore da inserire in L, associato alla chiave k
 */
void insert(L list, int k, int v);

/**
 * @brief cerca un particolare record riferito dalla chiave k
          l'inserimento in testa mi assicura che il primo elemento che trovo è
 il più aggiornato (nonostante i duplicato)
 * @post rende il valore associato a k se presente in L, altrimenti null
 *
 * @param list lista di record con puntatore alla testa
 * @param k chiave da cercare
 * @return elem associato alla chiave record se esiste, null altrimenti
 *
 */
elem search(L list, int k);

/**
 * @brief elimina il record con chiave k
 *
 * @pre il parametro k appartiene alla lista L
 * @param list lista con puntatore alla testa
 * @param k chiave dell'elemento da eliminare
 */
void delete_(L list, int k);

/**
 * @brief stampa il contenuto di ogni cella dell'array
 *
 * @param list lista di record con puntatore alla testa
 */
void print_list(L list);