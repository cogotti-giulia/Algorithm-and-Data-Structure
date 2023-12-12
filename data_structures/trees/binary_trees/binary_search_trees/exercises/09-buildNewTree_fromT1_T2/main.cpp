/**
 * @file main.cpp
 * @author cogotti-giulia (cogotti.giulia.irl@gmail.com)
 * @brief test
 * @version 1.0
 * @date 2023-12-12
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include "header.cpp"
#include <vector>

int main() {

  std::vector<int> t1_keys = {1, -3, 3, -1, 2};
  std::vector<int> t2_keys = {10, 8, 13, 9, 5, 7, 6};

  T t1 = new tree();
  for (int i = 0; i < t1_keys.size(); i++)
    tree_insert(t1, new node(t1_keys.at(i)));

  T t2 = new tree();
  for (int i = 0; i < t2_keys.size(); i++)
    tree_insert(t2, new node(t2_keys.at(i)));

  std::cout << "T1: ";
  visita_simmetrica(t1);
  std::cout << "T2: ";
  visita_simmetrica(t2);

  T t3 = build_new_tree(t1, t2);
  std::cout << "T3: ";
  visita_simmetrica(t3);
}