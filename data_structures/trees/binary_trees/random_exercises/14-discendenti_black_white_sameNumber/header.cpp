/**
 * @file header.cpp
 * @author cogotti-giulia (cogotti.giulia.irl@gmail.com)
 * @brief implementazione metodi e funzioni
 * @version 1.1
 * @date 2023-12-02
 */
#include "header.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <unordered_map>

int discendenti_bw_sameNum(pnode u) {
  int totBlack = 0;
  int totWhite = 0;
  return discendenti_bw_sameNum_aux(u, &totBlack, &totWhite);
}

int discendenti_bw_sameNum_aux(pnode u, int *totBlack, int *totWhite) {
  if (u == nullptr) {
    *totBlack = 0;
    *totWhite = 0;
    return 0;
  } else {
    int totBlackSX, totWhiteSX;
    int totBlackDX, totWhiteDX;

    int risSX = discendenti_bw_sameNum_aux(u->left, &totBlackSX, &totWhiteSX);
    int risDX = discendenti_bw_sameNum_aux(u->right, &totBlackDX, &totWhiteDX);

    if (u->color.compare("black") == 0)
      *totBlack = totBlackDX + totBlackSX + 1;
    else
      *totBlack = totBlackDX + totBlackSX;

    if (u->color.compare("white") == 0)
      *totWhite = totWhiteSX + totWhiteDX + 1;
    else
      *totWhite = totWhiteSX + totWhiteDX;

    if (*totWhite == *totBlack)
      return risSX + risDX + 1;
    else
      return risSX + risDX;
  }
}

void post_order(pnode u) {
  if (u != nullptr) {
    post_order(u->left);
    post_order(u->right);

    std::cout << u->color << " ";
  }
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

std::vector<T> get_trees_from_file(std::string file_name) {
  std::vector<parr> v_parent;
  std::vector<T> v_tree;

  std::ifstream my_file(file_name);
  std::string line;

  if (my_file.is_open()) {
    while (!my_file.eof()) {
      std::vector<std::string> info;
      std::vector<int> parent;
      std::vector<char> child_posi;
      for (int i = 0; i < 3; i++) {
        if (getline(my_file, line)) {

          std::string delimiter = ":";
          std::string type = line.substr(0, line.find(delimiter));
          line.erase(0, 2);

          std::stringstream ss(line);

          switch (type.at(0)) {
          case 'i': {
            std::string tmp;
            while (ss >> tmp)
              info.push_back(tmp);
          } break;
          case 'p': {
            int tmp;
            while (ss >> tmp)
              parent.push_back(tmp);
          } break;
          case 'c': {
            char tmp;
            while (ss >> tmp)
              child_posi.push_back(tmp);
          } break;
          default: {
            throw "Ooops, something went wrong! (check your file, maybe you "
                  "write something wrong)";
          }
          }
        } else {
          throw "Ooops, something went wrong! (check your file, maybe you "
                "write something wrong)";
        }
      }
      v_parent.push_back(new vector_parent(parent, info, child_posi));
    }
    my_file.close();
  } else {
    throw "Error: cannot open the file!";
  }

  for (int i = 0; i < v_parent.size(); i++) {
    T t = new tree();
    t->root = crea_albero(v_parent.at(i));
    v_tree.push_back(t);
  }

  return v_tree;
}