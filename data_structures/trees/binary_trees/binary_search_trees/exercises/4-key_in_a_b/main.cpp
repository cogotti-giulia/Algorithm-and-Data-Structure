/**
 * @file main.cpp
 * @author me, myself and I
 * @brief test controllo se l'albero binario è un bst con chiavi comprese
 * nell'intervallo [a, b]
 * @version 1.0
 * @date 2023-11-23
 */
#include "header.cpp"
#include <iostream>

int main() {
  int arr_ordinato[] = {-1, 3, 6, 9, 15, 17};
  T t1 = build_BST_OTT(arr_ordinato, 6);
  std::cout << "[ T1 ]  ";
  in_order(t1->root);
  std::cout << std::endl;

  int arr[] = {5, 4, 7, -2, 12, 41, 3, 1, 0};
  T t2 = build_BST_OTT(arr, 9);
  std::cout << "[ T2 ] ";
  in_order(t2->root);
  std::cout << std::endl;

  int arr_ordinato_2[] = {-5, -2, 4, 7, 11, 21};
  T t3 = build_BST_OTT(arr_ordinato_2, 6);
  std::cout << "[ T3 ]  ";
  in_order(t3->root);

  std::cout << std::endl << std::endl;

  int a = -3;
  int b = 24;
  if (is_bst_in_a_b(t1, a, b))
    std::cout << "t1 è un bst con chiavi in [" << a << ";" << b << "]"
              << std::endl;
  else
    std::cout << "t1 non è un bst con chiavi in [" << a << ";" << b << "]"
              << std::endl;

  if (is_bst_in_a_b(t2, a, b))
    std::cout << "t2 è un bst con chiavi in [" << a << ";" << b << "]"
              << std::endl;
  else
    std::cout << "t2 non è un bst con chiavi in [" << a << ";" << b << "]"
              << std::endl;

  if (is_bst_in_a_b(t3, a, b))
    std::cout << "t3 è un bst con chiavi in [" << a << ";" << b << "]"
              << std::endl;
  else
    std::cout << "t3 non è un bst con chiavi in [" << a << ";" << b << "]"
              << std::endl;
}