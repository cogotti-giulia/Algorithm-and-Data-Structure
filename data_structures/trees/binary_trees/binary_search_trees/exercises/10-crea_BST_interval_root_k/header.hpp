
#include "structs_used.hpp"
#include <vector>

/**
 * @brief crea un nuovo BST formato dalle chiavi del BST t appartenenti
 * all'intervallo [t->root->key, k]
 * @pre t->root->key < k
 * @pre u->left->key < u->key <= u->right->key
 * @param t bst tale che t->root->key < k
 * @param k intero, rappresenta la fine dell'intervallo
 * @return un nuovo BST che rispetta la condizione imposta
 */
T crea_BST_interval(T t, int k);

/**
 * @brief crea un nuovo BST BILANCIATO formato dalle chiavi del BST t
 * appartenenti all'intervallo [t->root->key, k]
 * @pre t->root->key < k
 * @pre u->left->key < u->key <= u->right->key
 * @param t bst tale che t->root->key < k
 * @param k intero, rappresenta la fine dell'intervallo
 * @return un nuovo BST che rispetta la condizione imposta
 */
T crea_BST_interval_BALANCED(T t, int k);

void visita_simmetrica(T t);

pnode tree_successor(pnode x);

pnode tree_minimum(pnode x);

void tree_insert(T tree, pnode z);

pnode build_BST_OTT_RIC(std::vector<int> A, int inf, int sup, pnode padre);