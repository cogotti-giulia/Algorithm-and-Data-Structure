

#include <algorithm>
#include <iostream>
#include <vector>
/**
 * @brief funzione che calcola il ricavo massimo data la lunghezza dell'asta e
 * il costo di ogni taglio (vettore dei prezzi)
 *
 * @param p vettore dei prezzi p[0...n-1]
 * @param n lunghezza asta da tagliare
 * @return ricavo massimo
 */
int cutrod(std::vector<int> p, int n) {
  if (n == 0) // non posso più tagliare
    return 0;
  else {
    int q = -1; // massimo dei prezzi fino ad ora, posso usare -1 dato che so
                // per certo che tutti i prezzi sono positivi
    for (int i = 0; i < n; i++) {
      // std::cout<<i<< " "<<n<<std::endl;
      q = std::max(q, p.at(i) + cutrod(p, (n - 1) - i));
    }
    return q;
  }
}

int main() {

  int n = 4;
  std::vector<int> p = {0, 1, 5, 8};

  int r = cutrod(p, n);
  std::cout << "ricavo massimo: " << r;
}