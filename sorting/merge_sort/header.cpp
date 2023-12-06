/**
 * @file main.cpp
 * @author me, myself and I
 * @brief implementazione metodi e funzioni
 * @version 1.0
 * @date 2023-11-15
 */
#include "header.hpp"
#include <cmath>
#include <iostream>

//! T(n) = Teta(n logn)
void my_merge_sort(my_elem *arr, int p, int r) {
  if (p < r) { // ho almeno due elementi
    int q = std::floor((p + r) / 2);
    my_merge_sort(arr, p, q);     //? T(n/2)
    my_merge_sort(arr, q + 1, r); //? T(n/2)

    my_merge(arr, p, q, r); //? Teta(n)
  }
}

//! T(n) = Teta(n)
void my_merge(my_elem *arr, int p, int q, int r) {
  int n1 = q - p + 1;
  int n2 = r - q;

  my_elem left[n1];  // L[p...q]
  my_elem right[n2]; // R[q+1...r]

  // copia gli elementi di sinistra nell'array L
  for (int i = 0; i < n1; i++) //! n1 = q-p+1 volte
    left[i] = arr[p + i]; 

  // copia gli elementi di destra nell'array R
  for (int j = 0; j < n2; j++) //! n2 = r-q volte
    right[j] = arr[q + 1 + j];

  int i = 0;
  int j = 0;
  int k = p;

  while (k < r) { //! r-p+1 volte ~> n volte
    if (i < n1 && j < n2) {
      // prende il più piccolo elemento tra i due sottoarray e lo mette nella
      // giusta posizione di A
      if (left[i]->get_key() <= right[j]->get_key()) {
        arr[k] = left[i];
        i++;
      } else {
        arr[k] = right[j];
        j++;
      }
    } else if (i < n1) {
      // ho finito gli elementi in R, finisco di aggiungere quelli di L
      arr[k] = left[i];
      i++;
    } else {
      // ho finito gli elementi in L, finisco di aggiungere quelli di R
      arr[k] = right[j];
      j++;
    }
    k++;
  }
}

void stampa_array(my_elem *arr, int n) {

  for (int i = 0; i < n; i++)
    std::cout << arr[i]->get_key() << ":" << arr[i]->get_satellite() << " ";

  std::cout << std::endl;
}
