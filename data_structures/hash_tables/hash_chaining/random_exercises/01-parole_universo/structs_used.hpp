/**
 * @file structs_used.hpp
 * @author cogotti-giulia (cogotti.giulia.irl@gmail.com)
 * @brief strutture dati utilizzate
 * @version 1.0
 * @date 2024-01-29
 *
 * @copyright Copyright (c) 2024
 *
 */
#include <string>
#include <vector>

constexpr int M = 5;

// elemento della lista
struct my_elem {
  my_elem *next;
  my_elem *prev;
  std::string info;

  my_elem(std::string info, my_elem *next = nullptr, my_elem *prev = nullptr)
      : info{info}, next{next}, prev{prev} {};
};
typedef my_elem *E;

// tabella hash
struct hash_table {
  std::vector<E> list;
  int n = 0; // elementi effettivamente memorizzati
  int m = M; // dimensione tabella

  hash_table() { 
    for(int i = 0; i < M; i++)
      list.push_back(nullptr);
  };
};

typedef hash_table *T;