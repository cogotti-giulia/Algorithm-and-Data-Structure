/**
 * @file header.hpp
 * @author me, myself and I
 * @brief definizione metodi e funzioni
 * @version 1.0
 * @date 2023-11-08
 */
#include "structs_used.hpp"

/**
 * @brief data la radice di un albero generale verifica se è k ario completo
 * 
 * @param u nodo radice dell'albero generale
 * @param k grado dei nodi
 * @return true se l'albero è k ario completo, false altrimenti
 */
bool is_k_ario(pnodeG u, int k);

/**
 * @brief funzione ausiliaria per verificare se l'albero ì k ario completo
 * 
 * @param u nodo dell'albero
 * @param k grado
 * @param h altezza albero
 * @return true se l'albero è k ario completo, false altrimenti
 */
bool is_k_ario_AUX(pnodeG u, int k, int *h);

T crea_albero();