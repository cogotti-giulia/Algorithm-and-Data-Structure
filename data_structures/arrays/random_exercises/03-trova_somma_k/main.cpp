/**
 * @file main.cpp
 * @author cogotti-giulia (cogotti.giulia.irl@gmail.com)
 * @brief test e funzione esercizio (utilizzo il vettore delle occorrenze!)
 * @version 1.0
 * @date 2023-12-06
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <iostream>
#include <vector>

bool somma_21(std::vector<int> A, int k, int *n1, int *n2) {
  std::vector<int> occ(k+1);

  for (int i = 0; i < occ.size(); i++)
    occ.at(i) = 0;

  bool found = false;
  int i = 0;
  while (i < A.size() && !found) {
    if (A.at(i) <= k) {
      if (occ.at(k - A.at(i)) > 0) {
        found = true;
        *n1 = A.at(i);
        *n2 = k - A.at(i);
      } else
        occ.at(A.at(i))++;

      i++;
    }
  }

  return found;
}

int main() {

  std::vector<int> A = {3, 7, 3, 2, 1, 2, 19};
  int n1 = -1;
  int n2 = -1;

  int k = 21;

  if (somma_21(A, k, &n1, &n2))
    std::cout << "esistono n1=" << n1 << " e n2=" << n2 << " in A tali che "
              << n1 << " + " << n2 << " = "<<k<<"!";
  else
    std::cout << "non esistono due elementi in A tali che la loro somma sia "<<k<<" :(";
}