# Bottom up cut rod

## Metodo bottom up
Si ordinano i problemi in base alla dimensione e partendo dai più piccoli si risolvono memorizzando le soluzioni ottenute (risolve tutto).

## Codice 

```c++
/**
 * @brief dato il vettore dei prezzi e la dimensione dell'asta calcola il
 * guadagno massimo con un approccio di tipo bottom up
 *
 * @param p vettore dei prezzi p[0...n-1], dove p[i] è il prezzo del taglio di
 * dimensione i (con i = 0,...,n-1)
 * @param n dimensione asta
 * @return ricavo massimo
 */
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
```

### Analisi complessità

```
        n
T(n) = sum j*Teta(1) = Teta((n*(n+1)/2)) = Teta(n^2)
       j=1
```

Quindi **T(n) = Teta(n<sup>2</sup>)**

## Codice (stampa soluzione!)

```c++
/**
 * @brief salva la posizione dei tagli in modo da poter ricostruire la soluzione
 *
 * @param p vettore dei prezzi p[0...n-1], dove p[i] è il prezzo del taglio di
 * dimensione i (con i = 0,...,n-1)
 * @param n dimensione asta
 * @param r vettore ricavi massimi
 * @param s vettore degli indici della posizione dei tagli
 */
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

/**
 * @brief dato il vettore dei prezzi e la dimensione dell'asta chiama la
 * ext_bottomup_cutrod e stampa la posizione dei tagli e il vettore dei
 * guadagni, rendendo possibile la ricostruzione della soluzione
 *
 * @param p vettore dei prezzi p[0...n-1], dove p[i] è il prezzo del taglio di
 * dimensione i (con i = 0,...,n-1)
 * @param n dimensione asta
 */
void print_bottomup_cutrod_solution(std::vector<int> p, int n) {
  std::vector<int> r(n);
  std::vector<int> s(n);
  ext_bottomup_cutrod(p, n, r, s);

  n = n - 1;
  std::cout << "posizione dei tagli: ";

  while (n > 0) {
    std::cout << s.at(n) << " ";
    n = n - s.at(n);
  }
}
```

### Analisi complessità

La `ext_bottomup_cutrod` porta via un tempo pari a _Teta(n<sup>2</sup>)_, mentre la `print_bottomup_cutrod_solution` al più costa _n_ (caso peggiore quando taglio l'asta in pezzettini da uno!). Quindi **T(n) = Teta(n<sup>2</sup>) + O(n) = Teta(n<sup>2</sup>)**


