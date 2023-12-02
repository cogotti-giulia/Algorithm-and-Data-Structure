/**
 * @file main.cpp
 * @author cogotti-giulia (cogotti.giulia.irl@gmail.com)
 * @brief test
 * @version 1.0
 * @date 2023-11-29
 */
#include "header.cpp"
#include <vector>

int main() {

  std::vector<T> v_tree = get_trees_from_file("test.txt");

  for (int i = 0; i < v_tree.size(); i++) {
    pnode root = v_tree.at(i)->root;
    std::cout << "preorder visit: ";
    pre_order(root);
    std::cout << std::endl;
    stampaK_nodeSX_mag_nodeDX(root);
    std::cout << std::endl;
  }
}