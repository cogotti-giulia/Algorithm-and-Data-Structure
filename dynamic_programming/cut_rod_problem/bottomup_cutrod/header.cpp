
#include "header.hpp"
#include <algorithm>
#include <iostream>
#include <vector>

int bottomup_cutrod(std::vector<int> p, int n) {
  std::vector<int> r(n);
  r.at(0) = 0;
  for (int j = 1; j < n; j++) {
    int q = -1;
    for (int i = 1; i <= j; i++)
      q = std::max(q, p.at(i) + r.at(j - i)); // r[j-i] è già stato calcolato
                                              // dato che è minore di r[j]

    r.at(j) = q;
  }

  return r.at(n - 1);
}

void ext_bottomup_cutrod(std::vector<int> p, int n, std::vector<int> &r,
                         std::vector<int> &s) {

  r.at(0) = 0;
  for (int j = 1; j < n; j++) {
    int q = -1;
    for (int i = 1; i <= j; i++) {
      if (q < p.at(i) + r.at(j - i)) {
        q = p.at(i) + r.at(j - i);
        s.at(j) = i;
      }

      r.at(j) = q;
    }
  }
}

void print_bottomup_cutrod_solution(std::vector<int> p, int n) {
  std::vector<int> r(n);
  std::vector<int> s(n);
  ext_bottomup_cutrod(p, n, r, s);

  std::cout << "i   : ";
  for (int i = 0; i < n; i++)
    std::cout << i << " ";

  std::cout << std::endl;

  std::cout << "r[i]: ";
  for (int i = 0; i < r.size(); i++)
    std::cout << r.at(i) << " ";

  std::cout << std::endl;

  std::cout << "s[i]: ";
  for (int i = 0; i < s.size(); i++)
    std::cout << s.at(i) << " ";

  std::cout << std::endl;

  n = n - 1;
  std::cout << "posizione dei tagli: ";

  while (n > 0) {
    std::cout << s.at(n) << " ";
    n = n - s.at(n);
  }
}