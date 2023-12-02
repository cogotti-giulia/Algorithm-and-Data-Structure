/**
 * @file main.cpp
 * @author cogotti-giulia (cogotti.giulia.irl@gmail.com)
 * @brief test
 * @version 1.1
 * @date 2023-12-02
 */
#include "header.cpp"
#include <string>
#include <vector>

int main() {

  std::vector<T> v_tree = get_trees_from_file("test.txt");

  for (int i = 0; i < v_tree.size(); i++) {
    pnode root = v_tree.at(i)->root;
    std::cout << "post order visit" << std::endl;
    post_order(root);
    std::cout << std::endl;

    std::cout << "Numero nodi: " << discendenti_bw_sameNum(root);
  }
}