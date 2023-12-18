/**
 * @file main.cpp
 * @author me, myself and I
 * @brief test check BST
 * @version 1.0
 * @date 2023-11-08
 */
#include "header.cpp"
#include <iostream>

int main() {

  int arr_ordinato[] = {-1, 3, 6, 9, 15, 17};
  T t1 = build_BST_OTT(arr_ordinato, 6);
  std::cout << "[ T1 ]  ";
  in_order(t1->root);
  std::cout << std::endl;

  int arr[] = {27, 12, 16, 32, 60, 91, 78, 46, 49};
  T t2 = build_BST_OTT(arr, 9);
  std::cout << "[ T2 ] ";
  in_order(t2->root);
  std::cout << std::endl << std::endl;


  //! utilizzando la definizione di BST
  if (check_BST_DEF(t1->root))
    std::cout << "[ DEF ] T1 è un BST" << std::endl;
  else
    std::cout << "[ DEF ] T1 NON è un BST" << std::endl;

  if (check_BST_DEF(t2->root))
    std::cout << "[ DEF ] T2 è un BST" << std::endl;
  else
    std::cout << "[ DEF ] T2 NON è un BST" << std::endl;

  std::cout << std::endl;

  //! utilizzando la proprietà
  if (check_BST_NO_DEF(t1->root))
    std::cout << "[ NO DEF ] T1 è un BST" << std::endl;
  else
    std::cout << "[ NO DEF ] T1 NON è un BST" << std::endl;

  if (check_BST_NO_DEF(t2->root))
    std::cout << "[ NO DEF ] T2 è un BST" << std::endl;
  else
    std::cout << "[ NO DEF ] T2 NON è un BST" << std::endl;
}