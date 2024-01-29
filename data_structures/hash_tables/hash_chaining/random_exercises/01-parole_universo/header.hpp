/**
 * @file header.hpp
 * @author cogotti-giulia (cogotti.giulia.irl@gmail.com)
 * @brief definizione
 * @version 1.0
 * @date 2024-01-29
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "structs_used.hpp"

/**
 * @brief somma i valori ascii della parola w
 * @param w stringa
 * @return somma dei valori ascii dei caratteri della stringa
 */
int sum_ascii(std::string w);

/**
 * @brief funzione hash, calcola l'indice sommando i valori ascii delle lettere
 * che compongono la chiave e applica il modulo 5 (dove cinque è la dimensione
 * fissa della tabella)
 * @param w chiave
 * @return intero che rappresenta l'indice della tabella hash in cui inserire la
 * chiave k
 */
int hash(std::string w);

/**
 * @brief inserisce l'elemento elem nella tabella hash
 * @param hash_table tabella hash con concatenamento
 * @param elem elemento da inserire nella tabella
 */
void insert(T hash_table, E elem);

void print_hash_table(T hash_table);