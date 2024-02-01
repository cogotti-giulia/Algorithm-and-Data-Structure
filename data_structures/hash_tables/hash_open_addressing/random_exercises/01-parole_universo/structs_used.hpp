/**
 * @file structs_used.hpp
 * @author cogotti-giulia (cogotti.giulia.irl@gmail.com)
 * @brief strutture dati utilizzate per implementare la tabella hash
 * @version 1.0
 * @date 2024-02-01
 *
 * @copyright Copyright (c) 2024
 *
 */
#include <string>
#include <vector>

struct hash_table {
  std::vector<std::string> tab;
  int n; // elementi effettivamente memorizzati
  int m; // dimensione tabella

  hash_table(int m, std::vector<std::string> tab, int n = 0)
      : tab{tab}, m{m}, n{n} {};
};
typedef hash_table *T;