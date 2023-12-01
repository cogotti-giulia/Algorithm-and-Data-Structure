/**
 * @file header.hpp
 * @author cogotti-giulia (cogotti.giulia.irl@gmail.com)
 * @brief definizione metodi e funzioni
 * @version 1.0
 * @date 2023-12-01
 */
#include "structs_used.hpp"
#include <map>
#include <vector>

/**
 * @brief funzione ausiliaria, ricostruisce ricorsivamente l'albero andando a
 * operare su sotto porzioni [p...r]
 * @param va vettore visita anticipata (pre order)
 * @param vs vettore visita simmetrica (in order)
 * @param p inizio porzione su cui sto lavorando
 * @param r fine porzione su cui sto lavorando
 * @param index_va indice dell'elemento nel vettore va (nodo corrente)
 * @param map_elem_index mappa contenente associazioni <elemento_vs, indice>
 */
pnode ricostruisci_AUX(const std::vector<int> &va, const std::vector<int> &vs,
                       int p, int r, int *index_va,
                       std::map<int, int> map_elem_index);

/**
 * @brief dati due vettori contenenti rispettivamente i valori dei nodi tutti
 * DISTINTI ottenuti da una visita in ordine anticipato e da una visita in
 * ordine simmetrico di un albero binario, ricostruisce l’albero binario
 * @param va vettore visita anticipata (pre order)
 * @param vs vettore visita simmetrica (in order)
 */
pnode ricostruisci(const std::vector<int> &va, const std::vector<int> &vs);

void in_order(pnode u);
void pre_order(pnode u);

void print_vector(const std::vector<int> &v);