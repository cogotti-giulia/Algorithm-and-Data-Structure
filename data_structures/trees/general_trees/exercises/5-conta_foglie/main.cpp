

#include "header.cpp"
#include <vector>

int main() {

  std::vector<T> trees = get_trees_from_file("test.txt");

  for (int i = 0; i < trees.size(); i++) {
    T t = trees.at(i);

    std::cout << "T: ";

    visita_post_order(t->root);

    std::cout << std::endl;
    std::cout << "numero di foglie: " << conta_foglie(t->root) << std::endl;
  }
}