/**
 * @file header.cpp
 * @author me, myself and I
 * @brief implementazione funzioni e metodi
 * @version 1.0
 * @date 2023-11-07
 */

#include "header.hpp"
#include <cmath>
#include <iostream>

/********************************************** search
 * *************************************************/
//! T_search(n) = O(log n)
int search(my_array A, int k, size_t size) {
  int i = search_index(A, k, 0, size - 1); //! O(log n)
  if (i == -1)
    return -1;
  else
    return i;
}

/********************************************** search_index
 * *************************************************/
//! T_search_index(n) = O(log n) [master theorem]
int search_index(my_array A, int k, int p, int r) {
  if (p > r) // vettore non vuoto
    return -1;
  else {
    // prendo l'indice al centro dell'array
    int med = std::floor((p + r) / 2);
    // se la chiave in quell'indice corrisponde a k
    if (A[med].key == k)
      return med;
    else {
      // vedo se la chiave di mezzo è maggiore di k
      // se è così vado in ricorsione nella metà precedente
      // altrimenti vado in ricorsione nella metà successiva
      if (A[med].key > k)
        return search_index(A, k, p, med - 1); //? T(n)= T(N/2)
      else
        return search_index(A, k, med + 1, r); //? T(n) = T(n/2)
    }
  }
}

/********************************************** reallocate
 * *************************************************/
// TODO: fare una reallocate efficiente con la tecnica di raddoppiamento e
// dimezzamento
//! T_reallocate(n) = O(n)
void reallocate(my_array A, size_t new_dim, size_t *size) {
  record *tmp_A = new record[new_dim]; // nuovo array

  // copia i valori del vecchio array nel nuovo
  for (int i = 0; i < std::min(new_dim, *size);
       i++) { //? viene eseguito n volte
    /*tmp_A[i].key = A[i].key;
    tmp_A[i].info = A[i].info;*/
    tmp_A[i] = A[i];
  }

  *size = new_dim; // la dimensione sarà quella del nuovo array (potrebbe non
                   // essere +1 anche se qua lo è)

  A = tmp_A; // faccio puntare il vecchio array al nuovo appena creato
}

/********************************************** insert
 * *************************************************/
//! T_insert(n) = Teta(1) + i*d + O(n) + (n-i+1)*d = Teta(1) + (n+1)d + O(n) =
//! O(n) d è il costo dell'assegnamento del corpo del ciclo Teta(1) insieme di
//! tutte le operazioni costanti
void insert(my_array A, int k, int v, size_t *size) {
  int i = 0;
  // scorro fino a trovare la posizione nella quale la chiave è minore di quella
  // da inserire oppure finché non finisco l'array
  while (i <= *size - 1 && A[i].key < k) //? i-volte
    i = i + 1;                           //? costante
  // chiave già presente, aggiorno il valore
  if (i <= *size - 1 && A[i].key == k)
    A[i].info = v;
  else {
    // aumento la dimensione dell'array
    int new_dim = *size + 1;
    // sistemo lo spazio nell'array
    reallocate(A, new_dim, size); //? O(n)

    // shift di una cella di tutti i valori per lasciar spazio al nuovo record
    for (int j = *size - 1; j >= i; j--) //? (n+1)-(i-1)+1 = (n-i+1) volte
      A[j] = A[j - 1];

    // inserisce il nuovo record
    A[i].key = k;
    A[i].info = v;
  }
}

/********************************************** delete
 * *************************************************/
//! T_delete_(n) = O(log n) + (n-i)*d + O(n) = O(log n) + O(n) + O(n) = O(n)
//! d: costo del corpo del ciclo
//! (n-i)*d = O(n) perché se ho fortuna elimino quello in ultima posizione, ma,
//! nel caso peggiore devo scorrere tutto l'array!
void delete_(my_array A, int k, size_t *size) {
  int i = search_index(A, k, 0, *size); //? T(n) = O(log n)

  // shift a sinistra per eliminare la cella
  for (int j = i; j < *size; j++) //? (n-1)-i+1= n-i volte
    A[j] = A[j + 1];

  // sistema le celle in modo che non ne restino vuote alla fine
  int new_dim = *size - 1;
  reallocate(A, new_dim, size); //? T(n) = O(n)
}

/********************************************** print
 * *************************************************/
// scorre l'array e stampa rispettiva chiave e valore di ogni record presente
void print_array(my_array A, size_t size) {
  for (int i = 0; i < size; i++)
    std::cout << "key:" << A[i].key << " info:" << A[i].info << " ; ";

  std::cout << std::endl;
}