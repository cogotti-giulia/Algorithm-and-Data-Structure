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

  std::vector<int> keys = {101, 50, 20, 72, 3, 14, 25, 121, 115, 22, 73};

  for (int i = 0; i < keys.size(); i++) {
    int index = insert(tab, keys.at(i));
    print_hash_table(tab);
  }
}