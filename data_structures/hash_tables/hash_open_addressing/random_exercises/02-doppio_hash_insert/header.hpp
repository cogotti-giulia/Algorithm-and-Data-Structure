/**
 * @file header.hpp
 * @author cogotti-giulia (cogotti.giulia.irl@gmail.com)
 * @brief definizione funzioni
 * @version 1.0
 * @date 2024-02-01
 *
 * @copyright Copyright (c) 2024
 *
 */
#include "structs_used.hpp"

/**
 * @brief funzione hash, esegue un doppio hashing con funzione hash
 * h(k, i) = (k mod m + i * 2^(k mod 5)) mod m
 * dove
 * h1 = k mod m cella prima posizione
 * h2 = 2^(k mod 5) determina il passo!
 * i ordine di ispezione (numero di ispezioni fallite)
 * @param k chiave
 * @param i ordine di ispezione
 * @return intero che rappresenta l'indice della tabella hash in cui inserire la
 * chiave k
 */
int hash_doppio_hashing(int k, int i);
/**
 * @brief funzione hash h1 = k mod m cella prima posizione
 * @param k chiave
 * @return intero che rappresenta l'indice della tabella hash in cui inserire la
 * chiave k
 */
int hash1(int k);
/**
 * @brief inserisce la chiave nella tabella hash
 * @param hash_table tabella hash con indirizzamento aperto
 * @param k stringa da inserire nella tabella
 */
int insert(T hash_table, int k);

void print_hash_table(T hash_table);