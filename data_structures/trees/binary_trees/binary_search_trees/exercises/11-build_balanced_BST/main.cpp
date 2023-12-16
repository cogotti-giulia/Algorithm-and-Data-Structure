/**
 * @file main.cpp
 * @author cogotti-giulia (cogotti.giulia.irl@gmail.com)
 * @brief test
 * @version 1.0
 * @date 2023-12-16
 *
 * @copyright Copyright (c) 2023
 *
 */
#include "header.cpp"
#include <vector>

int main() {
  std::vector<int> A = {-1, 5, 12, -3, 0, 17, 4, 3, 1};

  stampa_array(A);
  std::cout << "<<< ordina array >>>" << std::endl;

  my_merge_sort(A, 0, A.size() - 1);
  stampa_array(A);

  T t = build_bst_height_logn(A);

  if (t != nullptr)
    std::cout << "root: " << t->root->key << std::endl;

  std::cout << "in order: ";
  in_order(t->root);
}