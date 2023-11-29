/**
 * @file main.cpp
 * @author cogotti-giulia
 * @brief test
 * @version 1.1
 * @date 2023-11-29
 */
#include "header.cpp"

int main() {
  std::vector<int> info = {5, 2, -1, 3, -10, 12, -8, 1};
  std::vector<int> parent = {-1, 0, 0, 1, 1, 2, 2, 5};
  std::vector<char> child_posi = {'z', 'l', 'r', 'l', 'r', 'l', 'r', 'l'};
  parr vet_parent = new vector_parent(parent, info, child_posi);

  T t = new tree();
  t->root = crea_albero(vet_parent);

  std::cout << "DFS: ";
  visita_dfs(t->root);
  std::cout << std::endl;

  std::cout << "... aggiungendo figli ... "<<std::endl;
  aggiungi_figli(t->root);

  std::cout << "DFS: ";
  visita_dfs(t->root);
}