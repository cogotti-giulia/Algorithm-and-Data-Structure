/**
 * @file main.cpp
 * @author me, myself and I
 * @brief test su array generati in numero e valori random
 * @version 1.0
 * @date 2023-11-26
 */
#include "header.cpp"
#include <cstdlib>
#include <iostream>
#include <vector>

int main() {

  // test importante sul vettore con quasi tutti i numeri uguali, o comunque per
  // fare test personalizzati e non random
  std::vector<int> vet = {9, 2, 2, 2, 2, 2, 2, 1};
  stampa_array(vet);
  int k = 3;

  std::cout << "~> k = " << k << std::endl;
  if (esattamente_k_volte(&vet, k))
    std::cout << "true" << std::endl << std::endl;
  else
    std::cout << "false" << std::endl << std::endl;

  int how_many_tests_do_you_need = 10;

  for (int i = 0; i < how_many_tests_do_you_need; i++) {
    int random_size = rand() % 21 + 1;

    std::vector<int> vet;

    for (int j = 0; j < random_size; j++) {
      int random_elem = rand() % 21 - 5;
      vet.push_back(random_elem);
    }

    stampa_array(vet);
    int k = rand() % 3 + 1;

    std::cout << "~> k = " << k << std::endl;
    if (esattamente_k_volte(&vet, k))
      std::cout << "true" << std::endl << std::endl;
    else
      std::cout << "false" << std::endl << std::endl;
  }

  /**
   *! qualche output di esempio
   *
   * -1 4 14 3 5 5 4 10 5
   *  ~> k = 3
   *  -1 3 4 4 5 5 5 10 14
   *  true
   *
   * 10 11 11 12 9 7 4 -3 0 0 8 -4 14 0 -5 -2
   * ~> k = 4
   * -5 -4 -3 -2 0 0 0 4 7 8 9 10 11 11 12 14
   * false
   */
}