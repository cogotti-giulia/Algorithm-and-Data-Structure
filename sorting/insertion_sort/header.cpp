/**
 * @file header.cpp
 * @author me, myself and I
 * @brief implementazione metodi e funzioni
 * @version 1.0
 * @date 2023-11-14
 */
#include "header.hpp"
#include <iostream>

//! T(n) = Teta(n^2) nel caso peggiore
void insertion_sort(my_array arr) {
  // inizio dall'elemento uno
  // l'elemento in posizione zero si trova già nella porzione ordinata del
  // vettore
  for (int j = 1; j < arr->size; j++) { //?eseguito n-1 volte
    int key = arr->key[j];
    int i = j - 1;
    // sposta i valori lasciando un "buco" nel posto in cui inserire l'elemento
    // con chiave key
    while (i >= 0 && arr->key[i] > key) { //?eseguito j-1 volte
      arr->key[i + 1] = arr->key[i];
      i = i - 1;
    }
    arr->key[i + 1] = key;
  }
}

void stampa_array(my_array arr) {
  for (int i = 0; i < arr->size; i++)
    std::cout << arr->key[i] << " ";

  std::cout << std::endl;
}