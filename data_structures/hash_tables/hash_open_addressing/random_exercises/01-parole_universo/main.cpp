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
  int m = 5;
  std::vector<std::string> vet(m);
  for (int i = 0; i < vet.size(); i++)
    vet.at(i) = "";

  T tab = new hash_table(m, vet);

  std::vector<std::string> words = {"MARTE",   "LUNA", "COMETA",
                                    "PIANETI", "SOLE", "SOLI"};

  for (int i = 0; i < words.size(); i++) {
    int posi = insert(tab, words.at(i));
    print_hash_table(tab);
  }
}