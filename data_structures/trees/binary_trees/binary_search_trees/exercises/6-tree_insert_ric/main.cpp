
#include "header.cpp"
#include <iostream>
#include <vector>

int main() {

  std::vector<int> A = {-3, 2, 1, 8, 4, 11, 17, -5};

  T t = new tree();
  for (int i = 0; i < A.size(); i++) {
    pnode z = new node(A.at(i));
    tree_insert_ric(t, z);
    std::cout << "insert z = " << z->key << std::endl;

    visita_simmetrica(t->root);
    std::cout << std::endl;
  }
}