/**
 * @file main.cpp
 * @author me, myself and I
 * @brief funzioni per calcolare l'n-esimo numero di fibonacci
 * @version 1.0
 * @date 2023-11-22
 */
#include <cmath>
#include <iostream>

const double fi = (1 + std::sqrt(5)) / 2;
const double fi_cap = (1 - std::sqrt(5)) / 2;

int fib_binet(int n) {
  return (1 / std::sqrt(5)) * (std::pow(fi, n) - std::pow(fi_cap, n));
}

int fib_ric(int n) {
  if (n <= 2)
    return 1;
  else
    return fib_ric(n - 1) + fib_ric(n - 2);
}

int fib_iter_arr(int n) {
  int fibi[n];
  fibi[0] = 1;
  fibi[1] = 1;

  for (int i = 2; i < n; i++)
    fibi[i] = fibi[i - 1] + fibi[i - 2];

  return fibi[n-1];
}

int fib_iter(int n) {
  int a = 1;
  int b = 1;

  for (int i = 2; i < n; i++) {
    int c = a + b;
    a = b;
    b = c;
  }

  return b;
}

int main() {
  int n = 7;
  std::cout << "formula di binet ~ fib(" << n << ") = " << fib_binet(n)
            << std::endl;

  std::cout << "formula ricorsiva ~ fib(" << n << ") = " << fib_ric(n)
            << std::endl;

  std::cout << "formula iterativa (array) ~ fib(" << n << ") = " << fib_iter_arr(n)
            << std::endl;

  std::cout << "formula iterativa costante ~ fib(" << n << ") = " << fib_iter(n)
            << std::endl;
}