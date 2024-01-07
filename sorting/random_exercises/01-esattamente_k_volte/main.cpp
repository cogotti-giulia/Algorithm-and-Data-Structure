/**
 * @file main.cpp
 * @author me, myself and I
 * @brief test su array generati in numero e valori random
 * @version 1.0
 * @date 2023-11-26
 */
#include "header.cpp"
#include <iostream>
#include <vector>

int main() {

  std::vector<int> K;
  std::vector<std::vector<int>> arrays = get_arrays_from_file("test.txt", K);

  for (int i = 0; i < arrays.size(); i++) {

    std::vector<int> vet = arrays.at(i);

    stampa_array(vet);
    std::cout << "~> k = " << K.at(i) << std::endl;
    if (esattamente_k_volte(&vet, K.at(i)))
      std::cout << "true" << std::endl << std::endl;
    else
      std::cout << "false" << std::endl << std::endl;
  }
}