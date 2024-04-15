#include "header.hpp"
#include <algorithm>
#include <iostream>
#include <vector>

int memoized_cutrod(std::vector<int> p, int n) {
  std::vector<int> r(n);

  for (int i = 0; i < n; i++)
    r.at(i) = -1; // so che i prezzi sono tutti maggiori o uguali a zero

  return memoized_cutrod_AUX(p, n - 1, r);
}

int memoized_cutrod_AUX(std::vector<int> p, int j, std::vector<int> r) {
  if (r.at(j) < 0) { // non ho ancora calcolato il valore
    if (j == 0)      // ricavo per un'asta di lunghezza zero è sempre zero
      r.at(j) = 0;
    else { // viene eseguito UNA VOLTA per ogni problema
      int q = -1;
      for (int i = 1; i <= j; i++) {
        // std::cout<<i<<" "<<j<<std::endl;
        q = std::max(q, p.at(i) + memoized_cutrod_AUX(p, j - i, r));
      }
      r.at(j) = q; // memorizzo il valore massimo
    }
  }
  return r.at(j); // se r[j]>=0 il problema è già risolto
}

void ext_memoized_cutrod(std::vector<int> p, int n, std::vector<int> &r,
                         std::vector<int> &s) {
  for (int i = 0; i < n; i++)
    r.at(i) = -1; // so che i prezzi sono tutti maggiori o uguali a zero

  ext_memoized_cutrod_AUX(p, n - 1, r, s);
}

void ext_memoized_cutrod_AUX(std::vector<int> p, int j, std::vector<int> &r,
                             std::vector<int> &s) {
  if (r.at(j) < 0) { // non ho ancora calcolato il valore
    if (j == 0)      // ricavo per un'asta di lunghezza zero è sempre zero
      r.at(j) = 0;
    else { // viene eseguito UNA VOLTA per ogni problema
      int q = -1;
      for (int i = 1; i <= j; i++) {
        ext_memoized_cutrod_AUX(p, j - i, r, s);
        if (q < p.at(i) + r.at(j - i)) {
          q = p.at(i) + r.at(j - i);
          s.at(j) = i;
        }
      }
      r.at(j) = q; // memorizzo il valore massimo
    }
  }
}

void print_memoized_cutrod_solution(std::vector<int> p, int n) {
  std::vector<int> r(n);
  std::vector<int> s(n);

  ext_memoized_cutrod(p, n, r, s);
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

  int j = n - 1;
  std::cout << "posizione dei tagli: ";

  while (j > 0 && s.at(j) != 0) {
    std::cout << s.at(j) << " ";
    j = j - s.at(j);
  }
}