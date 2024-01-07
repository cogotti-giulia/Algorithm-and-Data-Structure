/**
 * @file main.cpp
 * @author me, myself and I
 * @brief test anagrammi
 * @version 1.0
 * @date 2023-11-28
 */
#include "header.cpp"
#include <vector>

int main() {
  std::vector<char> a = {'m', 'o', 'r', 't', 'e'};
  std::vector<char> b = {'m', 'e', 't', 'r', 'o'};
  std::vector<char> c = {'t', 'e', 't', 't', 'o'};

  std::cout << "A: ";
  print_string(a);
  std::cout << "B: ";
  print_string(b);
  std::cout << "C: ";
  print_string(c);

  if (anagramma(&a, &b))
    std::cout << "B è anagramma di A" << std::endl;
  else
    std::cout << "B NON è anagramma di A" << std::endl;

  if (anagramma(&a, &c))
    std::cout << "C è anagramma di A" << std::endl;
  else
    std::cout << "C NON è anagramma di A" << std::endl;
}