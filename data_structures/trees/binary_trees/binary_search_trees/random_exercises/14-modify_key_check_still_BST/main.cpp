/**
 * @file main.cpp
 * @author cogotti-giulia (cogotti.giulia.irl@gmail.com)
 * @brief test
 * @version 1.0
 * @date 2024-01-03
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "header.cpp"
#include <ostream>
#include <vector>

int main() {

  std::vector<int> A = {-1, 3, 5, 6, 12, 13, 15, 16, 17, 18, 21, 29, 24};

  ptree t = build_BST_OTT(A);

  std::vector<int> x_keys = {3, 13, 16, -1};
  std::vector<int> new_keys = {4, 14, 21, -5};

  int i = 0;
  bool is_still_bst = true;

  while (i < x_keys.size() && is_still_bst) {

    pnode x = find_node_by_key(t->root, x_keys.at(i));
    in_order(t->root, x);

    ptree t_copy = t;
    ptree t_edited = modify_key(t_copy, x, new_keys.at(i));

    if (t_edited)
      in_order(t_edited->root, find_node_by_key(t->root, new_keys.at(i)));
    else {
      std::cout << "Modificando la chiave di x (" << x_keys.at(i)
                << ") al valore " << new_keys.at(i)
                << " l'albero NON è più un BST\n";
      is_still_bst = false;
    }

    std::cout << std::endl;

    i++;
  }
}