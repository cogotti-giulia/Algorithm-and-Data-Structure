

#include <iostream>
#include <vector>

/**
 * @brief risoluzione del problema di fibonacci tramite la tecnica di
 * programmazione dinamica, con un approccio bottomup
 * @pre n >= 2
 * @param n numero in input
 * @return n-esimo numero di fibonacci
 */
int fib_bottom_up(int n) {
  std::vector<int> A(n); // memorizza le soluzioni

  A.at(0) = 0;
  A.at(1) = 1;

  for (int i = 2; i < n; i++)
    A.at(i) = A.at(i - 1) + A.at(i - 2);

  return A.at(n-1);
}

int main() {
    int n = 20;
    for(int i = 2; i < 20; i++) 
        std::cout<<"fib("<<i<<") = "<<fib_bottom_up(i)<<std::endl;
}