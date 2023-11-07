/**
 * @file main.cpp
 * @author me, myself and I
 * @brief test operazioni sui BST
 * @version 1.0
 * @date 2023-11-07
 */
#include "header.cpp"

int main() {

  std::size_t n = 9;
  int arr[] = {27, 12, 16, 32, 60, 91, 78, 46, 49};
  T t1 = build_BST(arr, n);
  std::cout << "BST T1: ";
  in_order(t1->root);
  std::cout << std::endl;

  int arr_ordinato[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  T t2 = build_BST_OTT(arr_ordinato, n);
  std::cout << "BST T2: ";
  in_order(t2->root);
  std::cout << "(ottimizzato)" << std::endl << std::endl;

  int k_search = 32;
  pnode my_node = tree_search(t1->root, k_search);
  if (my_node != nullptr)
    std::cout << "[ T1 ] nodo con chiave " << k_search << " trovato :)"
              << std::endl
              << std::endl;
  else
    std::cout << "[ T1 ] nodo con chiave " << k_search
              << " non presente nell'albero :(" << std::endl
              << std::endl;

  std::cout << "[ T2 ] MINIMO valore nell'albero "
            << " ~> " << tree_minimum(t2->root)->key << std::endl;
  std::cout << "[ T2 ] MASSIMO valore nell'albero "
            << " ~> " << tree_maximum(t2->root)->key << std::endl
            << std::endl;

  pnode x = my_node;
  if (tree_successor(x) != nullptr)
    std::cout << "[ T1 ] SUCCESSORE di " << x->key << " ~> "
              << tree_successor(x)->key << std::endl;
  else
    std::cout << x->key << "[ T1 ] NON ha un successore" << std::endl;

  if (tree_predecessor(x) != nullptr)
    std::cout << "[ T1 ] PREDECESSORE di " << x->key << " ~> "
              << tree_predecessor(x)->key << std::endl;
  else
    std::cout << x->key << "[ T1 ] NON ha un predecessore" << std::endl;
}