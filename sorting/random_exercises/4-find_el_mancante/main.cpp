/**
 * @file main.cpp
 * @author cogotti-giulia (cogotti.giulia.irl@gmail.com)
 * @brief test trova elemento mancante
 * @version 1.0
 * @date 2023-12-06
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <cmath>
#include <iostream>
#include <vector>

int find_elemento_mancante(std::vector<int> a, int p, int r) {
  if (p < r) {
    int med = std::floor((p + r) / 2);

    // se l'elemento a metà non coincide col suo indice
    // cerco a sinistra fino a trovare il primo elemento mancante che sfasa gli
    // indici
    //  altrimenti si troverà a destra se fino ad ora ho tutti gli indici a
    //  posto
    if (a.at(med) != med)
      return find_elemento_mancante(a, p, med);
    else
      return find_elemento_mancante(a, med + 1, r);

  } else {
    // quando p == r ho trovato l'elemento
    return p;
  }
}

int main() {
  std::vector<int> a = {0, 1, 2, 3, 5, 6};

  for (int i = 0; i < a.size(); i++)
    std::cout << a.at(i) << " ";

  std::cout << std::endl;
  int ris = find_elemento_mancante(a, 0, a.size() - 1);
  std::cout << "elemento mancante: " << ris;
}