/**
 * @file header.cpp
 * @author cogotti-giulia (cogotti.giulia.irl@gmail.com)
 * @brief implementazione metodi e funzioni
 * @version 1.0
 * @date 2023-12-01
 */
#include "header.hpp"
#include <iostream>
#include <map>
#include <vector>

pnode ricostruisci_AUX(const std::vector<int> &va, const std::vector<int> &vs,
                       int p, int r, int *index_va,
                       std::map<int, int> map_elem_index) {

  if (p > r) // non ho elementi
    return nullptr;
  else {
    // nuovo elemento avrà come chiave l'elemento in posizione index_va della
    // visita anticipata, poi mando avanti l'indice
    pnode nuovo = new node{va.at(*index_va)};
    *index_va = *index_va + 1;

    // non ha figli
    if (p == r)
      return nuovo;

    // indice dell'elemento appena creato, lo prendo dalla mappa
    // so per certo che gli elementi alla sua destra saranno nel  suo
    // sottoalbero destro e quelli alla sua sinistra saranno nel suo sottoalbero
    // sinistro perché è una visita simmetrica!
    int index_vs = map_elem_index.at(nuovo->key);

    // vado in ricorsione a costruire il resto dell'albero

    // per i nodi a sinistra vado nella porzione sinistra dell'array vs
    // per i nodi a destra vado nella porzione a destra dell'array vs
    nuovo->left =
        ricostruisci_AUX(va, vs, p, index_vs - 1, index_va, map_elem_index);
    nuovo->right =
        ricostruisci_AUX(va, vs, index_vs + 1, r, index_va, map_elem_index);

    return nuovo;
  }
}

pnode ricostruisci(const std::vector<int> &va, const std::vector<int> &vs) {
  int n = va.size();
  if (n > 0) {
    // mappa che contiene chiavi e valori
    // chiave: elemento del vettore vs
    // valore: indice cella dove si trova quell'elemento
    std::map<int, int> map_elem_index;

    //? T(n) = Teta(n)
    for (int i = 0; i < n; i++) {
      map_elem_index[vs.at(i)] = i;
    }

    int index_va = 0; // indice per scorrere l'array va
    //?T(n) = O(n)
    return ricostruisci_AUX(va, vs, 0, n - 1, &index_va, map_elem_index);

  } else
    return nullptr;
}

void in_order(pnode u) {
  if (u != nullptr) {
    in_order(u->left);
    std::cout << u->key << " ";
    in_order(u->right);
  }
}

void pre_order(pnode u) {
  if (u != nullptr) {
    std::cout << u->key << " ";
    in_order(u->left);
    in_order(u->right);
  }
}

void print_vector(const std::vector<int> &v) {
  for (int i = 0; i < v.size(); i++)
    std::cout << v.at(i) << " ";

  std::cout << std::endl;
}