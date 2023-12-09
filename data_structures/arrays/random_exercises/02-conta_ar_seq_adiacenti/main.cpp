/**
 * @file main.cpp
 * @author cogotti-giulia (cogotti.giulia.irl@gmail.com)
 * @brief test su array presi da un file
 * @version 1.0
 * @date 2023-12-02
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <cmath>
#include <fstream>
#include <iostream>
#include <vector>

/**
 * @brief divide ricorsivamente l'array in due porzioni L[p...med] e R[med+1...r] (tipo merge sort)
 * controlla se L[med] = 'a' e R[med] = 'r', se si incrementa il conteggio degli ar trovati
 * @param a array
 * @param p inizio porzione sottoarray
 * @param r fine porzione sottoarray
 */
int conta_ar_seq_rec(const std::vector<char> &a, int p, int r) {
  if (p < r) {
    int med = std::floor((p + r) / 2);
    int ris_sx = conta_ar_seq_rec(a, p, med); //? T(n/2)
    int ris_dx = conta_ar_seq_rec(a, med + 1, r); //? T(n/2)

    //? costante!
    if (a.at(med) == 'a' && a.at(med + 1) == 'r') {
      return ris_dx + ris_sx + 1;
    } else {
      return ris_dx + ris_sx;
    }
  } else {
    return 0;
  }
}

/**
 * @brief conta le sequenze di ar presenti nell'array di input
 * @param a array
 */
int conta_ar_seq(const std::vector<char> &a) {
  return conta_ar_seq_rec(a, 0, a.size() - 1); //! T(n) = Teta(n)
}

void stampa_array(const std::vector<char> &a) {
  for (int i = 0; i < a.size(); i++) {
    std::cout << a.at(i) << " ";
  }
  std::cout << std::endl;
}

int main() {
  std::string line;

  std::vector<std::vector<char>> a;

  std::ifstream my_file("words.txt");
  if (my_file.is_open()) {
    while (getline(my_file, line)) {

      std::vector<char> v_row;
      v_row.assign(line.begin(), line.end());

      a.push_back(v_row);
    }
    my_file.close();
  }

  for (int i = 0; i < a.size(); i++) {
    std::cout << conta_ar_seq(a.at(i)) << " : ";
    stampa_array(a.at(i));
  }
}