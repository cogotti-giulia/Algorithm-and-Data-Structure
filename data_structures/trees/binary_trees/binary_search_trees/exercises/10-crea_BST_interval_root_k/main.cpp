
#include "header.cpp"
#include <vector>

int main() {

  std::vector<int> A = {5, 5, 7, -1, 4, 6, 19, 12, 27, 10, 13, 12, 29, -3, 4};

  T t = new tree();
  for (int i = 0; i < A.size(); i++)
    tree_insert(t, new node(A.at(i)));

  std::cout << "OLD: ";
  visita_simmetrica(t);
  std::cout << "ROOT: " << t->root->key<<std::endl<<std::endl;

  int k = 17;
  std::cout << "k =  " << k<<std::endl<<std::endl;

  T nuovo = crea_BST_interval(t, k);

  std::cout << "NEW: ";
  visita_simmetrica(nuovo);
  std::cout << "ROOT: " << nuovo->root->key<<std::endl<<std::endl;


  T nuovo_BAL = crea_BST_interval_BALANCED(t, k);

  std::cout << "NEW BALANCED: ";
  visita_simmetrica(nuovo_BAL);
  std::cout << "ROOT: " << nuovo_BAL->root->key<<std::endl;
}