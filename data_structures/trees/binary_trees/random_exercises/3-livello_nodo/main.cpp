/**
 * @file main.cpp
 * @author me, myself and I
 * @brief test stampa livello nodo
 * @version 1.0
 * @date 2023-11-07
 */

#include "header.cpp"
#include <iostream>

int main() {
  T t = crea_albero();
  stampa_livello(t->root, 2);
}