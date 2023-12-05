/**
 * @file header.cpp
 * @author cogotti-giulia (cogotti.giulia.irl@gmail.com)
 * @brief implementazione metodi e funzioni
 * @version 1.0
 * @date 2023-12-05
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include "header.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <unordered_map>

bool is_binario_completo(pnode r) {
  int pf = -1; //non so se ho nodi, la profondità di un albero vuoto è -1
  return is_binario_completo_AUX(r, 0, &pf);
}

bool is_binario_completo_AUX(pnode u, int profondita, int *prof_foglia) {
  if (u == nullptr) {
    return true; // albero vuoto è binario completo
  } else {
    bool risSX, risDX;
    risSX = is_binario_completo_AUX(u->left, profondita + 1, prof_foglia);
    risDX = is_binario_completo_AUX(u->right, profondita + 1, prof_foglia);

    if (u->left == nullptr && u->right == nullptr) { // sono su una foglia
      if (*prof_foglia == -1) // prima foglia, setto la profondità
        *prof_foglia = profondita;

      // le foglie devono essere tutte alla stessa profondita
      if (*prof_foglia != profondita)
        return false;
    }

    // un solo figlio, grado != 2
    if ((u->left != nullptr && u->right == nullptr) ||
        (u->left == nullptr && u->right != nullptr))
      return false;

    return risSX && risDX;
  }
}

void pre_order(pnode u) {
  if (u != nullptr) {
    std::cout << u->key << " ";
    pre_order(u->left);
    pre_order(u->right);
  }
}

void in_order(pnode u) {
  if (u != nullptr) {
    in_order(u->left);
    std::cout << u->key << " ";
    in_order(u->right);
  }
}

std::vector<T> get_trees_from_file(std::string file_name) {
  std::vector<parr> v_parent;
  std::vector<T> v_tree;

  std::ifstream my_file(file_name);
  std::string line;

  if (my_file.is_open()) {
    while (!my_file.eof()) {
      std::vector<int> info;
      std::vector<int> parent;
      std::vector<char> child_posi;

      int count_correct_lines = 0;
      for (int i = 0; i < 3; i++) {
        if (getline(my_file, line)) {

          std::string delimiter = ":";
          std::string type = line.substr(0, line.find(delimiter));
          line.erase(0, 2);

          std::stringstream ss(line);

          switch (type.at(0)) {
          case 'i': {
            int tmp;
            while (ss >> tmp)
              info.push_back(tmp);
            count_correct_lines++;
          } break;
          case 'p': {
            int tmp;
            while (ss >> tmp)
              parent.push_back(tmp);
            count_correct_lines++;
          } break;
          case 'c': {
            char tmp;
            while (ss >> tmp)
              child_posi.push_back(tmp);
            count_correct_lines++;
          } break;
          default: {
            std::cout
                << "Ooops, something went wrong! (check your file, maybe you "
                   "write something wrong)";
            exit(false);
          }
          }
        } else {
          std::cout
              << "Ooops, something went wrong! (check your file, maybe you "
                 "write something wrong)";
          exit(false);
        }
      }

      if (count_correct_lines < 3) {
        std::cout << "Ooops, something went wrong! (check your file, maybe you "
                     "write something wrong)";
        exit(false);
      }
      v_parent.push_back(new vector_parent(parent, info, child_posi));
    }
    my_file.close();
  } else {
    std::cout << "The file doesn t exist!";
    exit(false);
  }

  for (int i = 0; i < v_parent.size(); i++) {
    T t = new tree();
    t->root = crea_albero(v_parent.at(i));
    v_tree.push_back(t);
  }

  return v_tree;
}

pnode crea_albero(parr vet_padri) {
  // numero di nodi
  int n = vet_padri->info.size();
  // crea una mappa vuota
  std::unordered_map<int, pnode> map;
  // crea un nuovo nodo per ogni info del padre e la mette nella mappa
  for (int i = 0; i < n; i++) {
    map[i] = new node(vet_padri->info.at(i));
  }
  // radice
  pnode root = nullptr;
  // scorre tutte le celle
  for (int i = 0; i < n; i++) {
    // indice del padre
    int index_parent = vet_padri->parent.at(i);
    // nodo corrente
    pnode nuovo = map.at(i);
    // posizione del nodo corrente ('l': figlio sinistro, 'r': figlio destro,
    // 'z': radice)
    char child_posi = vet_padri->child_position.at(i);

    // se è -1 allora è la radice
    if (index_parent == -1) {
      root = nuovo;
    } else {
      // prende il padre del nodo corrente, tramite la mappa
      pnode padre = map[index_parent];

      // se è 'l' lo attacca come figlio sinistro
      if (child_posi == 'l')
        padre->left = nuovo;
      else if (child_posi == 'r') // altrimenti come figlio destro
        padre->right = nuovo;
    }
  }
  return root;
}