# Memoized (top down) cut rod

## Metodo top down

All'interno di una tabella (vettore, hash) si salvano le soluzioni dei problemi già risolti (_memoization_). Si utilizza la ricorsione (che è costosa) ma riesce comunque a prendere solo le cose interessanti.

## Codice

```c++
/**
 * @brief data la lunghezza dell'asta e il vettore dei prezzi calcola il ricavo
 * massimo tramite metodo top down
 *
 * @param p vettore dei prezzi p[0...n-1], dove p[i] è il prezzo del taglio di
 * dimensione i (con i = 0,...,n-1)
 * @param n dimensione asta
 * @return ricavo massimo
 */
int memoized_cutrod(std::vector<int> p, int n) {
  std::vector<int> r(n);

  for (int i = 0; i < n; i++)
    r.at(i) = -1; // so che i prezzi sono tutti maggiori o uguali a zero

  return memoized_cutrod_AUX(p, n - 1, r);
}

/**
 * @brief funzione ausiliaria per il ricavo massimo
 *
 * @param p vettore dei prezzi p[0...n-1], dove p[i] è il prezzo del taglio di
 * dimensione i (con i = 0,...,n-1)
 * @param j taglio (????)
 * @param r vettore che memorizza i ricavi massimi, dove r[i] rappresenta il
 * ricavo ottimo per aste di lunghezza i (con i = 0,...,n-1)
 * @return int
 */
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
```

### Analisi complessità

Una chiamata ricorsiva per risolvere un problema precedentemente risolto termina immediatamente in tempo _Teta(1)_, si arriva al ramo else (in memoized_cutrod_AUX) **una sola volta per ogni problema** i=1,...,n.

La risoluzione di un sottoproblema di dimensione n effettua n iterazioni.

```
 n
sum = (n(n+1))/2 = Teta(n^2)
j=1
```

Quindi **T(n) = Teta(n<sup>2</sup>)**

## Codice (stampa soluzione!)

Oltre a calcolare il guadagno massimo sono salvare, nel vettore s[0...n-1], anche le posizioni in cui effettuare il taglio in modo da poter ricostruire la soluzione.

Quindi, oltre al vettore r[0...n-1] in cui salvare i ricavi massimi, si utilizza s[0...n-1] che memorizza le posizioni che mi consentono di fare il taglio migliore.

```c++
/**
 * @brief salva la posizione dei tagli in modo da poter ricostruire la soluzione
 *
 * @param p p[0...n-1], dove p[i] è il prezzo del taglio di
 * dimensione i (con i = 0,...,n-1)
 * @param n dimensione asta
 * @param r vettore ricavi massimi
 * @param s vettore degli indici della posizione dei tagli
 */
void ext_memoized_cutrod(std::vector<int> p, int n, std::vector<int> &r,
                         std::vector<int> &s) {
  for (int i = 0; i < n; i++)
    r.at(i) = -1; // so che i prezzi sono tutti maggiori o uguali a zero

  ext_memoized_cutrod_AUX(p, n - 1, r, s);
}

/**
 * @brief funzione ausiliaria di ext_memoized_cutrod
 *
 * @param p p[0...n-1], dove p[i] è il prezzo del taglio di
 * dimensione i (con i = 0,...,n-1)
 * @param j tagli
 * @param r vettore ricavi massimi
 * @param s vettore degli indici della posizione dei tagli
 */
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

/**
 * @brief chiama la ext_memoized_cutrod per ricavare il vettore dei guadagni
 * massimi e il vettore degli indici. Da quest'ultimo ricava le posizioni dei
 * tagli rendendo possibile la ricostruzione della soluzione.
 *
 * @param p vettore prezzi
 * @param n dimensione asta
 */
void print_memoized_cutrod_solution(std::vector<int> p, int n) {
  std::vector<int> r(n);
  std::vector<int> s(n);

  ext_memoized_cutrod(p, n, r, s);

  int j = n - 1;
  std::cout << "posizione dei tagli: ";

  while (j > 0 && s.at(j) != 0) {
    std::cout << s.at(j) << " ";
    j = j - s.at(j);
  }
}
```

### Analisi complessità

La `ext_memoized_cutrod` porta via un tempo pari a _Teta(n<sup>2</sup>)_, mentre la `print_memoized_cutrod_solution` al più costa _n_ (caso peggiore quando taglio l'asta in pezzettini da uno!). Quindi **T(n) = Teta(n<sup>2</sup>) + O(n) = Teta(n<sup>2</sup>)**
