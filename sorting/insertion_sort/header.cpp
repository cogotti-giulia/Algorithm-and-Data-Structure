/**
 * @file header.cpp
 * @author me, myself and I
 * @brief implementazione metodi e funzioni
 * @version 1.0
 * @date 2023-11-14
 */
#include "header.hpp"
#include <array>
#include <cstddef>
#include <iostream>

//! T(n) = Teta(n^2) nel caso peggiore

template <std::size_t n> void insertion_sort(std::array<my_elem, n> arr) {
  // inizio dall'elemento uno
  // l'elemento in posizione zero si trova già nella porzione ordinata del
  // vettore
  for (int j = 1; j < arr.size(); j++) { //?eseguito n-1 volte
    int key = arr.at(j)->get_key();
    char satellite = arr.at(j)->get_satellite();

    int i = j - 1;
    // sposta i valori lasciando un "buco" nel posto in cui inserire l'elemento
    // con chiave key
    while (i >= 0 && arr.at(i)->get_key() > key) { //?eseguito j-1 volte
      arr.at(i + 1)->set_key(arr.at(i)->get_key());
      arr.at(i + 1)->set_satellite(arr.at(i)->get_satellite());

      i = i - 1;
    }
    arr.at(i + 1)->set_key(key);
    arr.at(i + 1)->set_satellite(satellite);
  }
}

template <std::size_t n> void stampa_array(std::array<my_elem, n> arr) {
  for (int i = 0; i < arr.size(); i++)
    std::cout << arr.at(i)->get_key() << ":" << arr.at(i)->get_satellite()
              << " ";

  std::cout << std::endl;
}