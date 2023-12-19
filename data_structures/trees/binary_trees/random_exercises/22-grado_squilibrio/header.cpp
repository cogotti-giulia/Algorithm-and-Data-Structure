
#include "header.hpp"
#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <unordered_map>

int grado_squili(pnode u) {
  int max_squili = 0;
  grado_squili_AUX(u, &max_squili);
  return max_squili;
}

int grado_squili_AUX(pnode u, int *max_squili) {
  if (u == nullptr) {
    return 0;
  } else {
    // calcolo la somma delle chiavi contenute nelle foglie dei sottoalberi
    // sinistro e destro
    int sumFSX = grado_squili_AUX(u->left, max_squili);
    int sumFDX = grado_squili_AUX(u->right, max_squili);

    // se mi trovo su una foglia incremento la somma al valore della chiave
    if (u->left == nullptr && u->right == nullptr) {
      return sumFSX + sumFDX + u->key;
    } else {
      // squilibrio del nodo, dato dal valore assoluto della differenza delle
      // somme dei nodi foglia radicati nei sottoalberi sinistro e destro
      int squili_node = std::abs(sumFSX - sumFDX);
      // calcolo il massimo squilibro dato dal massimo tra il grado di
      // squilibrio del nodo corrente e il massimo precedentemente calcolato
      *max_squili = std::max(squili_node, *max_squili);
      // la somma delle foglie sarà data dalla somma dei due sottoalberi del
      // nodo corrente
      return sumFSX + sumFDX;
    }
  }
}

void post_order(pnode u) {
  if (u != nullptr) {
    post_order(u->left);
    post_order(u->right);
    std::cout << u->key << " ";
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