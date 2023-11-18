/**
 * @file header.cpp
 * @author me, myself and I
 * @brief implementazione metodi e funzioni
 * @version 1.0
 * @date 2023-11-18
 */
#include "header.hpp"
#include <cstddef>
#include <iostream>

void my_quick_sort(my_elem *arr, int p, int r) {
  if (p < r) { // ho almeno due elementi
    int q = my_partition(arr, p, r);
    // ordina ricorsivamente le due porzioni
    my_quick_sort(arr, p, q - 1);
    my_quick_sort(arr, q + 1, r);
  }
}

int my_partition(my_elem *arr, int p, int r) {
  // pivot, ultimo elemento dell'array
  my_elem x = new elem(arr[r]->get_key(), arr[r]->get_satellite());

  int i = p - 1; // i identifica la fine della porzione di elementi <= x
  for (int j = p; j < r; j++) // j scorre tutti gli elementi non so
    if (arr[j]->get_key() <= x->get_key()) {
      // l'elemento non so è minore o uguale a x?
      // se si scambio e mando avanti i
      i++;
      swap(arr, j, i);
    }

  // scambio il pivot con il primo elemento della porzione degli elementi
  // maggiori
  swap(arr, i + 1, r);
  return i + 1;
}

void my_randomized_quick_sort(my_elem *arr, int p, int r) {
  if (p < r) {
    int q = my_randomized_partition(arr, p, r);
    my_randomized_quick_sort(arr, p, q - 1);
    my_randomized_quick_sort(arr, q + 1, r);
  }
}

int my_randomized_partition(my_elem *arr, int p, int r) {
  int i = rand() % r; // sceglie un elemento a caso dall'array
  swap(arr, i, r);    // lo scambia con l'elemento in ultima posizione
  return my_partition(arr, p, r);
}

void my_quick_sort_tripart(my_elem *arr, int p, int r) {
  if (p < r) {
    my_double_index i = my_partition_tripart(arr, p, r);
    // ordina le porzioni di elementi maggiori e minori del pivot
    my_quick_sort_tripart(arr, p, (i->q) - 1);
    my_quick_sort_tripart(arr, (i->t) + 1, r);
  }
}

my_double_index my_partition_tripart(my_elem *arr, int p, int r) {
  my_elem x = new elem(arr[r]->get_key(), arr[r]->get_satellite()); // pivot

  //! min e mag identificano inizio e fine (compresi) della porzione di elementi
  //! uguali al pivot

  // eq è l'elemento che al momento sto controllando
  int min = p, eq = p;
  int mag = r;

  while (eq < mag) {
    if (arr[eq]->get_key() < x->get_key()) {
      // se l'elemento non so è minore di x, scambia elemento non so con
      // l'elemento in posizione min e mando avanti gli indici
      swap(arr, min, eq);
      eq++;
      min++;
    } else if (arr[eq]->get_key() == x->get_key()) {
      // se l'elemento è uguale ad x semplicemente mando avanti eq perché esso
      // si trova già in posizione corretta
      eq++;
    } else {
      // se l'elemento è maggiore di x, decremento mag aggiungendo uno spazietto
      // per l'elemento e scambio mag con  eq
      mag--;
      swap(arr, mag, eq);
    }
  }

  // infine scambio il pivot A[r] con il primo elemento di quelli maggiori di
  // esso
  swap(arr, mag, r);
  // rendo due indici min e mag che identificano inizio e fine della porzione di
  // elementi uguali al pivot
  return new double_index(min, mag);
}

void my_randomized_quick_sort_tripart(my_elem *arr, int p, int r) {
  if (p < r) {
    my_double_index i = my_randomized_partition_tripart(arr, p, r);
    my_randomized_quick_sort_tripart(arr, p, (i->q) - 1);
    my_randomized_quick_sort_tripart(arr, (i->t) + 1, r);
  }
}

my_double_index my_randomized_partition_tripart(my_elem *arr, int p, int r) {
  int i = rand() % r; // sceglie un elemento random come pivot
  swap(arr, i, r);    // scambia con quello in posizione r
  return my_partition_tripart(arr, p, r);
}

void swap(my_elem *arr, int e1, int e2) {
  my_elem tmp = new elem(arr[e1]->get_key(), arr[e1]->get_satellite());

  arr[e1]->set_key(arr[e2]->get_key());
  arr[e1]->set_satellite(arr[e2]->get_satellite());

  arr[e2]->set_key(tmp->get_key());
  arr[e2]->set_satellite(tmp->get_satellite());
}

void stampa_array(my_elem *arr, int n) {

  for (int i = 0; i < n; i++)
    std::cout << arr[i]->get_key() << ":" << arr[i]->get_satellite() << " ";

  std::cout << std::endl;
}
