/**
 * @file main.cpp
 * @author me, myself and I
 * @brief test
 * @version 1.0
 * @date 2023-11-28
 */
#include "header.cpp"

int main() {
  int info[12] = {7, 12, -3, 1, 1, 5, 4, 1, 3, 5, 4, 4};
  int parent[12] = {-1, 0, 0, 1, 1, 2, 2, 3, 5, 5, 6, 6};
  char child_posi[12] = {'x', 'l', 'r', 'l', 'r', 'l',
                         'r', 'l', 'l', 'r', 'l', 'r'};
  parr vet_parent = new vector_parent(parent, info, child_posi, 12);

  T t = new tree();
  t->root = crea_albero(vet_parent);

  std::cout << "DFS: ";
  visita_dfs(t->root);
  std::cout << std::endl;

  cancella(t->root);
  std::cout << "DFS: ";
  visita_dfs(t->root);
  std::cout << std::endl;
}