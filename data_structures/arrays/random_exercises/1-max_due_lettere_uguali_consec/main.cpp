/**
 * @file main.cpp
 * @author me, myself and I
 * @brief esercizio su array (test e funzioni)
 * @version 1.0
 * @date 2023-11-24 
 */
#include <iostream>
#include <vector>

/**
 * @brief verifica se la parola contenuta nell'array ha al più due lettere uguali consecutive
 * 
 * @param A array di caratteri contenenti la parola
 * @return true se la parola non ha più di due lettere uguali consecutive, false altrimenti
 */
bool max_due_lettere_consecutive(std::vector<char> A) {
  bool is_italian = true;
  int i = 0;

  //! esco alla prima violazione! ~> T(n) = O(n)
  while (i < A.size() - 2 && is_italian) {
    if (A.at(i + 1) == A.at(i) && A.at(i + 2) == A.at(i))
      is_italian = false;

    i++;
  }

  return is_italian;
}

void stampa_array(std::vector<char> A) {
  for (int i = 0; i < A.size(); i++)
    std::cout << A.at(i) << " ";

  std::cout << std::endl;
}

int main() {

  std::vector<char> a1 = {'m', 'a', 'm', 'm', 'a'};
  std::vector<char> a2 = {'a', 'l', 'b', 'b', 'b', 'e'};
  std::vector<char> a3 = {'c', 'c', 'c', 'i', 'a', 'o'};
  std::vector<char> a4 = {'i', 'p', 'p', 'o', 'p', 'o', 't', 'a', 'm', 'o'};
  std::vector<char> a5 = {'a', 'p', 'p', 'u', 'n', 't', 'i'};
  std::vector<char> a6 = {'a', 'i', 'u', 't', 'o', 'o', 'o'};

  std::vector<std::vector<char>> A = {a1, a2, a3, a4, a5, a6};

  for (int i = 0; i < A.size(); i++) {
    stampa_array(A.at(i));
    std::cout << max_due_lettere_consecutive(A.at(i));
    std::cout << std::endl;
  }
}