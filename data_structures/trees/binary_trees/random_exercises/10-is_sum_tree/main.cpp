/**
 * @file main.cpp
 * @author me, myself and I
 * @brief test is sum tree su qualche albero binario
 * @version 1.1
 * @date 2023-11-23
 */
#include "header.cpp"
#include <iostream>
#include <vector>

int main() {

  // test albero normale
  std::vector<int> info = {14, 1, 10, 2, -1, 7, -3};
  std::vector<int> parent = {-1, 0, 0, 1, 1, 2, 5};
  std::vector<char> child_posi = {'z', 'l', 'r', 'l', 'r', 'l', 'r'};
  parr vet_parent = new vector_parent(parent, info, child_posi);

  T t_normal = new tree();
  t_normal->root = crea_albero(vet_parent);

  // test albero con un solo nodo
  info.clear();
  parent.clear();
  child_posi.clear();

  info = {-3};
  parent = {-1};
  child_posi = {'x'};

  parr vet_parent_root = new vector_parent(parent, info, child_posi);

  T t_root = new tree();
  t_root->root = crea_albero(vet_parent_root);

  // test albero vuoto
  T t_empty = new tree();

  std::vector<T> trees_test = {t_normal, t_root, t_empty};

  for (int i = 0; i < trees_test.size(); i++) {
    std::cout << "in-order: ";
    visita_in_order_simmetrica(trees_test.at(i)->root);
    std::cout << std::endl;

    if (is_sum_tree(trees_test.at(i)->root))
      std::cout << "l'albero è sum tree" << std::endl;
    else
      std::cout << "l'albero non è sum tree" << std::endl;
    std::cout << std::endl;
  }
}