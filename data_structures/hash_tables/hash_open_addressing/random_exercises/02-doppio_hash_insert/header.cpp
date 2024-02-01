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
#include <cmath>
#include <iostream>

int hash1(int k) { return k % M; }

int hash_doppio_hashing(int k, int i) {
  int h1_index = hash1(k);
  if (i == 0) {
    std::cout << "h1(" << k << ", " << i << ") = " << h1_index << std::endl;

    return h1_index;
  } else {
    std::cout << ">>> doppio hashing! >>>" << std::endl;
    int h2_index = std::pow(2, k % 5);

    int h = (h1_index + i * h2_index) % M;
    std::cout << "h(" << k << ", " << i << ") = " << h << std::endl;
    return h;
  }
}

int insert(T hash_table, int k) {
  int i = 0; // ordine di ispezione!
  bool found = false;
  int j; // risultato funzione hash

  do {
    j = hash_doppio_hashing(k, i);

    // -1 perché inserisco chiavi tutte >= 0
    if (hash_table->tab.at(j) == -1) {
      hash_table->tab.at(j) = k;
      found = true;
    } else {
      i++;
    }

  } while (!found && i != hash_table->m);

  if (found)
    return j;
  else
    throw "ERROR overflow tabella hash";
}

void print_hash_table(T hash_table) {
  for (int i = 0; i < hash_table->m; i++) {
    std::cout << i << " : ";
    if (hash_table->tab.at(i) != -1)
      std::cout << hash_table->tab.at(i);

    std::cout << std::endl;
  }
  std::cout << std::endl;
}