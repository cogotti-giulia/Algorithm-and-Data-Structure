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

constexpr int M = 5;

struct hash_table {
  std::vector<std::string> tab;
  int n = 0; // elementi effettivamente memorizzati
  int m = M; // dimensione tabella

  hash_table(){
    for(int i = 0; i < M; i++){
      tab.push_back("");
    }
  };
};
typedef hash_table *T;