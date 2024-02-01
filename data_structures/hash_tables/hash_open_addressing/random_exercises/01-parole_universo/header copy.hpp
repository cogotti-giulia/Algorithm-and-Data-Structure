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
 * @brief funzione hash, esegue una scansione lineare con funzione hash
 * h(k, i)=(h1(k)+i)mod m
 * @param w chiave
 * @param i indice per l'ispezione lineare
 * @return intero che rappresenta l'indice della tabella hash in cui inserire la
 * chiave k
 */
int hash_ispezione_lineare(std::string w, int i);
/**
 * @brief funzione hash, calcola l'indice sommando i valori ascii delle lettere
 * che compongono la chiave e applica il modulo 5 (dove cinque è la dimensione
 * fissa della tabella)
 * @param w chiave
 * @return intero che rappresenta l'indice della tabella hash in cui inserire la
 * chiave k
 */
int hash1(std::string w);
/**
 * @brief inserisce l'elemento elem nella tabella hash
 * @param hash_table tabella hash con indirizzamento aperto
 * @param el stringa da inserire nella tabella
 */
int insert(T hash_table, std::string el);

void print_hash_table(T hash_table);