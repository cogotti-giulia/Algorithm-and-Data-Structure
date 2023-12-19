#include "structs_used.hpp"
#include <string>

/**
 * @brief calcola il grado di squilibrio dell'albero radicato in u
 * @return grado di squilibrio albero
 */
int grado_squili(pnode u);
/**
 * @brief funzione ausiliaria utilizzata per calcolare il grado di squilibrio di
 * ogni nodo e trovarne il massimo
 * @param u nodo
 * @param max_squili massimo grado di squilibro (alla fine sarà quello
 * dell'albero)
 * @return somma foglie sottoalberi sinistro e destro
 */
int grado_squili_AUX(pnode u, int *max_squili);

void post_order(pnode u);
std::vector<T> get_trees_from_file(std::string file_name);
pnode crea_albero(parr vet_padri);