/**
 * @file main.cpp
 * @author me, myself and I
 * @brief test altezza nera
 * @version 1.0
 * @date 2023-11-08
 */
#include "header.cpp"
#include <iostream>

int main(){
  T t = crea_albero();

  std::cout<<"altezza nera radice:"<< blackHeight(t->root);
}