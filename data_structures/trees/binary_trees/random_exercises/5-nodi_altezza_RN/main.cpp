
#include "header.cpp"
#include <iostream>

int main(){
  T t = crea_albero();

  std::cout<<"altezza nera radice:"<< blackHeight(t->root);
}