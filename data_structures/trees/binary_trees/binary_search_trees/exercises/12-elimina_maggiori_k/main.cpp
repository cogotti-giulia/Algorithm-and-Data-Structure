/**
 * @file main.cpp
 * @author cogotti-giulia (cogotti.giulia.irl@gmail.com)
 * @brief test
 * @version 1.0
 * @date 2023-12-18
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include "header.cpp"
#include <vector>

int main() {
  std::vector<int> A = {-3, 1, 7, 9, 11, 13, 12, 15, 27};

  T t = build_BST_OTT(A);

  int k = 27;
  std::cout << "\nk = " << k << std::endl;
  reverse_in_order(t, k);
  elimina_maggiori_k(t, k);
  reverse_in_order(t, k);

  k = 7;
  std::cout << "\nk = " << k << std::endl;
  reverse_in_order(t, k);
  elimina_maggiori_k(t, k);
  reverse_in_order(t, k);
}