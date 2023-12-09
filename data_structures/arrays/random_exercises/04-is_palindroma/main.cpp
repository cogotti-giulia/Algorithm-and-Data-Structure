/**
 * @file main.cpp
 * @author cogotti-giulia (cogotti.giulia.irl@gmail.com)
 * @brief test palindroma
 * @version 1.0
 * @date 2023-12-06
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

bool is_palindroma_ric(std::vector<char> s, int p, int r) {
  if (p >= r) // quando ho un elemento (p = r) oppure p supera r (stringa ha n
              // pari caratteri)
    return true;
  else {
    return s.at(p) == s.at(r) && is_palindroma_ric(s, p + 1, r - 1);
  }
}

void print_string(std::vector<char> s) {
  for (int i = 0; i < s.size(); i++)
    std::cout << s.at(i);

  std::cout << std::endl;
}

int main() {
  std::string line;

  std::vector<std::vector<char>> strings;

  std::ifstream my_file("words.txt");
  if (my_file.is_open()) {
    while (getline(my_file, line)) {

      std::vector<char> v_row;
      v_row.assign(line.begin(), line.end());

      strings.push_back(v_row);
    }
    my_file.close();
  }

  for (int i = 0; i < strings.size(); i++) {
    std::vector<char> s = strings.at(i);
    print_string(s);
    if (is_palindroma_ric(s, 0, s.size() - 1))
      std::cout << "yep, è palindroma!" << std::endl;
    else
      std::cout << "NON è palindroma :(" << std::endl;

    std::cout << std::endl;
  }
}