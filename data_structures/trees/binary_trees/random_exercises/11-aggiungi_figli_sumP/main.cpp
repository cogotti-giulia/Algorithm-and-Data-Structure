/**
 * @file main.cpp
 * @author me, myself and I
 * @brief test
 * @version 1.0
 * @date 2023-11-28
 */
#include "header.cpp"

int main() {
  int info[8] = {5, 2, -1, 3, -10, 12, -8, 1};
  int parent[8] = {-1, 0, 0, 1, 1, 2, 2, 5};
  char child_posi[8] = {'x', 'l', 'r', 'l', 'r', 'l', 'r', 'l'};
  parr vet_parent = new vector_parent(parent, info, child_posi, 8);

  T t_normal = new tree();
  t_normal->root = crea_albero(vet_parent);

  std::cout << "DFS: ";
  visita_dfs(t_normal->root);
  std::cout << std::endl;

  std::cout << "... aggiungendo figli ... "<<std::endl;
  aggiungi_figli(t_normal->root);

  std::cout << "DFS: ";
  visita_dfs(t_normal->root);
}