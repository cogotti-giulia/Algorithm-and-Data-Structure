/**
 * @file main.cpp
 * @author me, myself and I
 * @brief test contare occorrenze di k nel BST
 * @version 1.0
 * @date 2023-11-09
 */
#include "header.cpp"
#include <iostream>

int main(){
  
  int n = 9;
  int arr[] = {-2, 1, 3, 7, 7, 7, 9, 9, 12};
  T t = build_BST_OTT(arr, n);

  in_order(t->root);

  int k = 7;
  std::cout<<std::endl<<"Occorrenze di k="<<k<<" ~> "<<occorrenze_k(t, k);
}