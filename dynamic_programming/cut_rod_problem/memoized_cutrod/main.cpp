
#include "header.cpp"
#include <iostream>
#include <vector>

int main() {
  int n = 8;
  std::vector<int> p = {0, 1, 5, 8, 10, 13, 17, 18};

  int r = memoized_cutrod(p, n);
  std::cout << "ricavo massimo: " << r << std::endl << std::endl;

  print_memoized_cutrod_solution(p, n);
}