/**
 * @file header.cpp
 * @author cogotti-giulia (cogotti.giulia.irl@gmail.com)
 * @brief implementazione
 * @version 1.0
 * @date 2024-01-29
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

int hash(std::string w) {
  int s = sum_ascii(w);

  return s % 5;
}

void insert(T hash_table, E elem) {
  int h = hash(elem->info);
  hash_table->n++;

  std::cout << "insert k = " << elem->info << std::endl;
  std::cout << "h(k) = " << h << std::endl;
  if (hash_table->list.at(h) == nullptr)
    hash_table->list.at(h) = elem;
  else {
    elem->next = hash_table->list.at(h);
    hash_table->list.at(h)->prev = elem;
    hash_table->list.at(h) = elem;
  }
}

void print_hash_table(T hash_table) {
  for (int i = 0; i < hash_table->list.size(); i++) {
    std::cout << i << " : ";
    E scorri = hash_table->list.at(i);
    while (scorri != nullptr) {
      std::cout << scorri->info << " - ";
      scorri = scorri->next;
    }

    std::cout << std::endl;
  }

  std::cout << std::endl;
}