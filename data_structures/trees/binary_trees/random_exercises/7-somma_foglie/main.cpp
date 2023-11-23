/**
 * @file main.cpp
 * @author me, myself and I
 * @brief test somma chiavi su un albero binario
 * @version 1.0
 * @date 2023-11-23
 */
#include "header.cpp"
#include <iostream>

int main() {

  T t = crea_albero();

  std::cout << "Visita a livelli (le foglie hanno una F davanti)" << std::endl;
  visita_in_ampiezza(t->root);
  std::cout << std::endl << std::endl;

  std::cout << "Somma chiavi foglie:" << somma_foglie(t);
}