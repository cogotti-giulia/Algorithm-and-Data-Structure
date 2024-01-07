/**
 * @file header.cpp
 * @author me, myself and I
 * @brief implementazione metodi e funzioni
 * @version 1.1
 * @date 2023-11-26
 */
#include "header.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

bool esattamente_k_volte(std::vector<int> *A, int k) {
  if (k > 0 && k <= A->size()) {
    // l'ordinamento mi assicura che gli elementi uguali si troveranno in
    // posizioni adiacenti dell'array
    my_quick_sort_tri(A, 0, A->size() - 1); //! oscilla tra n log n ed n^2
    stampa_array(*A);

    bool found = false;

    int elem = A->at(0);
    int i = 1;


    while (i < A->size() && !found) { //! al più O(n)

      if (A->at(i) != elem) {
        elem = A->at(i);
        int k_elem = i + (k - 1); // posizione k esimo elemento partendo da i

        // se esiste un elemento in posizione i+k
        if ((k_elem + 1) < A->size()) {
          // controllo che ci siano k elementi uguali ad A[i] e che l'elemento
          // successivo a questi k sia diverso dai precedenti
          if (A->at(k_elem) == elem) {
            if (A->at((k_elem + 1)) != elem) {
              found = true;

            } else {

              i = k_elem + 1; // vado al k+1 esimo elemento a partire da i,
                              // perché tanto so già che quei k sono uguali a
                              // qualcosa che ho già controllato
            }
          } else {
            i++;
          }

        } else {
          if (k_elem < A->size()) {
            // se non esiste un elemento in posizione i+k semplicemente
            // controllo che ce ne siano k uguali in quanto il k esimo si trova
            // come ultimo elemento dell'array
            if (A->at(k_elem) == elem)
              found = true;

            i = k_elem + 1; // vado al k+1 esimo elemento

          } else {
            i++;
          }
        }
      }else
        i++;
    }
    return found;
  } else {
    return false;
  }
}

void my_quick_sort_tri(std::vector<int> *A, int p, int r) {
  if (p < r) {
    my_double_index i = my_rand_partition_tri(A, p, r);
    my_quick_sort_tri(A, p, (i->q) - 1);
    my_quick_sort_tri(A, (i->t) + 1, r);
  }
}

my_double_index my_rand_partition_tri(std::vector<int> *A, int p, int r) {
  // int i = rand() % r; // sceglie un elemento random come pivot
  // my_swap(A, i, r); boh non funziona

  return my_partition_tri(A, p, r);
}

void my_swap(std::vector<int> *A, int i1, int i2) {
  // iter_swap(A->begin() + i1, A->begin() + i2);
  int tmp = A->at(i1);
  A->at(i1) = A->at(i2);
  A->at(i2) = tmp;
}

my_double_index my_partition_tri(std::vector<int> *A, int p, int r) {
  int x = A->at(r);

  int min = p, eq = p;
  int mag = r;

  while (eq < mag) {
    if (A->at(eq) < x) {
      my_swap(A, min, eq);
      eq++;
      min++;
    } else if (A->at(eq) == x) {
      eq++;
    } else { // A.at(eq) > x
      mag--;
      my_swap(A, mag, eq);
    }
  }

  my_swap(A, mag, r);
  return new double_index(min, mag);
}

void stampa_array(std::vector<int> A) {
  for (int i = 0; i < A.size(); i++)
    std::cout << A.at(i) << " ";

  std::cout << std::endl;
}



std::vector<std::vector<int>> get_arrays_from_file(std::string file_name, std::vector<int>& K) {
  std::string line;

  std::vector<std::vector<int>> arrays;

  std::ifstream my_file(file_name);
  if (my_file.is_open()) {
    while (!my_file.eof()) {
      std::vector<int> arr;

      if (getline(my_file, line)) {
        std::stringstream ss(line);
        int n;

        ss >>n;
        K.push_back(n);
        
        while (ss >> n)
          arr.push_back(n);
      }
      arrays.push_back(arr);
    }

    my_file.close();
  }

  return arrays;
}