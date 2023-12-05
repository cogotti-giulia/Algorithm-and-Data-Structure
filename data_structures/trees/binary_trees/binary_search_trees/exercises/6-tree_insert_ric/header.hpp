/**
 * @file header.hpp
 * @author cogotti-giulia (cogotti.giulia.irl@gmail.com)
 * @brief definizione metodi e funzioni usate
 * @version 1.0
 * @date 2023-12-05
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include "structs_used.hpp"

void tree_insert_ric(T t, pnode z);

void tree_insert_ric_AUX(pnode u, pnode z, pnode padre);

void visita_simmetrica(pnode u);

pnode tree_minimum(pnode u);
pnode tree_successor(pnode u);