/**
 * @file main.cpp
 * @author cogotti-giulia (cogotti.giulia.irl@gmail.com)
 * @brief test e implementazione procedure
 * @version 1.0
 * @date 2023-12-14
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <iostream>
#include <string>
#include <vector>

constexpr int alphabet = 26;
constexpr int ascii_code_a = 97;
constexpr int d = 4;

// T(n) = Teta(n)
void my_counting_sort(std::string &letters_posi, std::vector<int> &prev_posi) {
  std::vector<int> c(alphabet);

  int n = letters_posi.size();

  // k volte !
  for (int i = 0; i < alphabet; i++)
    c.at(i) = 0;

  // Teta(n)
  for (int j = 0; j < n; j++)
    c.at((letters_posi.at(j) - ascii_code_a))++;

  // k volte !
  for (int i = 1; i < alphabet; i++)
    c.at(i) = c.at(i) + c.at(i - 1);

  // Teta(n)
  for (int j = n - 1; j >= 0; j--) {
    int index = (letters_posi.at(j) - ascii_code_a);
    prev_posi[c.at(index) - 1] = j;
    c.at(index)--;
  }
}
void my_radix_sort(std::vector<std::string> &A) {

  int n = A.size();

  // eseguito d volte
  for (int i = d - 1; i >= 0; i--) {
    std::string letters_posi;
    std::vector<int> prev_posi(n);

    // Teta(n)
    for (int j = 0; j < n; j++)
      letters_posi.push_back(A.at(j).at(i));

    // Teta(n)
    my_counting_sort(letters_posi, prev_posi);

    std::vector<std::string> cpy_A = A; // Teta(n)

    // Teta(n)
    for (int k = 0; k < prev_posi.size(); k++)
      A.at(k) = cpy_A.at(prev_posi.at(k));
  }
}

int main() {

  std::vector<std::string> words = {"hand", "busy", "lamp", "arms",
                                    "zoom", "ring", "last"};

  for (int i = 0; i < words.size(); i++)
    std::cout << words.at(i) << std::endl;
  
  std::cout << "<<< sorting >>>" << std::endl;

  my_radix_sort(words);
  for (int i = 0; i < words.size(); i++)
    std::cout << words.at(i) << std::endl;
}