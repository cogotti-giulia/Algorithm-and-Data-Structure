/**
 * @file header.hpp
 * @author cogotti-giulia (cogotti.giulia.irl@gmail.com)
 * @brief definizione metodi e funzioni
 * @version 1.0
 * @date 2023-12-12
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include "structs_used.hpp"

T build_new_tree(T t1, T t2);

pnode tree_minimum(pnode x);

pnode tree_successor(pnode x);

void transplant(T tree, pnode old, pnode neww);

void tree_delete(T tree, pnode z);

void visita_simmetrica(T t);

void tree_insert(T tree, pnode z);