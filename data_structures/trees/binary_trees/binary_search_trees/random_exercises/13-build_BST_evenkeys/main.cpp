/**
 * @file main.cpp
 * @author cogotti-giulia (cogotti.giulia.irl@gmail.com)
 * @brief test su un bst
 * @version 1.0
 * @date 2024-01-03
 *
 * @copyright Copyright (c) 2024
 *
 */
#include "header.cpp"
#include <vector>

int main() {
  std::vector<int> A = {-4, 2, 3, 5, 7, 10, 13, 16, 20, 21};

  std::cout << "BST all keys: ";
  T t = build_BST_OTT(A);
  in_order(t);

  std::cout << "BST even keys: ";
  T t_even_keys = build_BST_even_keys(t);
  in_order(t_even_keys);
}