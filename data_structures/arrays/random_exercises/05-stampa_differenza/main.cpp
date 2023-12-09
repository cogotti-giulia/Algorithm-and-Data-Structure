/**
 * @file main.cpp
 * @author cogotti-giulia (cogotti.giulia.irl@gmail.com)
 * @brief test differenza tra array
 * @version 1.0
 * @date 2023-12-07
 */
#include <iostream>
#include <vector>

//! T(n, m) = T(n+m)
void differenza(const std::vector<int>& A, std::vector<int> B) {
  int i = 0;
  int j = 0;

  while (i < A.size()) {
    if (j < B.size()) {
      if (A.at(i) < B.at(j)) {
        std::cout << A.at(i) << " ";
        i++;
      } else if (A.at(i) == B.at(j)) {
        i++;
        j++;
      } else {
        j++;
      }
    } else {
      std::cout << A.at(i) << " ";
      i++;
    }
  }
}

void stampa_array(const std::vector<int>& A) {
  for (int i = 0; i < A.size(); i++)
    std::cout << A.at(i) << " ";

  std::cout << std::endl;
}

int main() {

  std::vector<int> A = {-3, 1, 5, 7, 8, 11};
  std::vector<int> B = {5, 6, 8, 14};

  std::cout<<"A: ";
  stampa_array(A);
  std::cout<<"B: ";
  stampa_array(B);

  std::cout<<"differenza (A-B): ";
  differenza(A, B);
  std::cout<<std::endl;

  std::cout<<"differenza (B-A): ";
  differenza(B, A);
}