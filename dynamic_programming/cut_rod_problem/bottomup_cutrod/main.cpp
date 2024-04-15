
#include "header.cpp"

int main() {
  int n = 8;
  std::vector<int> p = {0, 1, 5, 8, 10, 13, 17, 18};

  std::cout << "ricavo massimo: " << bottomup_cutrod(p, n) << std::endl
            << std::endl;
  print_bottomup_cutrod_solution(p, n);
}