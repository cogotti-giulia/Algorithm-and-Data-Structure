/**
 * @file main.cpp
 * @author cogotti-giulia (cogotti.giulia.irl@gmail.com)
 * @brief test
 * @version 1.0
 * @date 2024-02-01
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "header.cpp"

int main() {

  T tab = new hash_table();

  std::vector<std::string> words = {"MARTE",   "LUNA", "COMETA",
                                    "PIANETI", "SOLE", "SOLI"};

  for (int i = 0; i < words.size(); i++) {
    int posi = insert(tab, words.at(i));
    print_hash_table(tab);
  }
}