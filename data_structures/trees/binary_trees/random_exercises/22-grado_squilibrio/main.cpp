
#include "header.cpp"
#include <vector>

int main() {

  std::vector<T> trees = get_trees_from_file("test.txt");

  for (int i = 0; i < trees.size(); i++) {
    T t = trees.at(i);
    std::cout<<"T <post order>: ";
    post_order(t->root);
    std::cout << "\ngrado squilibrio albero: " << grado_squili(t->root)<<std::endl;
  }
}