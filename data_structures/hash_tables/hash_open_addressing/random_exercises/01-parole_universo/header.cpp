/**
 * @file header.cpp
 * @author cogotti-giulia (cogotti.giulia.irl@gmail.com)
 * @brief implementazione
 * @version 1.0
 * @date 2024-02-01
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "header.hpp"
#include <iostream>

int sum_ascii(std::string w) {
  int sum = 0;
  for (int i = 0; i < w.size(); i++)
    sum += w.at(i);

  return sum;
}

int hash1(std::string w) { return sum_ascii(w) % M; }

int hash_ispezione_lineare(std::string w, int i) {
  int h1_index = hash1(w);
  if (i == 0) {
    std::cout << "h1(" << w << ") = " << h1_index << std::endl;

    return h1_index;
  } else {
    std::cout << ">>> ispezione lineare! >>>" << std::endl;
    int h2_index = (h1_index + i) % M;
    std::cout << "h2(" << w << ", " << i << ") = " << h2_index << std::endl;
    return h2_index;
  }
}

int insert(T hash_table, std::string el) {
  int i = 0; // inizio dall'ispezione zero PER OGNI CHIAVE
  int j;     // posizione calcolata dalla tabella hash;
  bool found = false;

  do {
    j = hash_ispezione_lineare(el, i);
    std::cout << "insert k = " << el << std::endl;
    if (hash_table->tab.at(j).empty()) {
      hash_table->tab.at(j) = el;
      found = true;
    } else {
      i++;
    }
  } while (!found && i != hash_table->m);

  if (found)
    return j;
  else
    throw "ERROR overflow della tabella hash!";
}

void print_hash_table(T hash_table) {
  for (int i = 0; i < hash_table->m; i++)
    std::cout << i << " : " << hash_table->tab.at(i) << std::endl;

  std::cout << std::endl;
}