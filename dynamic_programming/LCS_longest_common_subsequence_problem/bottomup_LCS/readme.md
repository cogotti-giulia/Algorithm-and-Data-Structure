# Bottom up LCS

Approccio bottom up per risolvere il problema della LCS. Utilizza il [teorema della sotto struttura ottima per la LCS](/dynamic_programming/LCS_longest_common_subsequence_problem/readme.md).

## Codice c++ (non ottimizzato)

Versione non ottimizzata (utilizza una matrice b ausiliaria per ricostruire la soluzione)

Stuttura dati ausiliaria (per implementare le freccette)
```
struct MyStruct {
  char LEFT = 'L';
  char TOP = 'T';
  char OBLI = 'O';
  char EMPTY = 'E'; //per inizializzare la matrice
};
MyStruct arrows;
```

- c[i, j] = lunghezza della LCS(X<sup>i</sup>, Y<sup>j</sup>)
- b[i, j] = informazioni utili per recuperare la soluzione
    - 'O' = se x<sub>i</sub>=y<sub>j</sub> ~> LCS(X<sup>i</sup>, Y<sup>j</sup>) ridotto a LCS(X<sup>i-1</sup>, Y<sup>j-1</sup>) _spostamento in diagonale_
    - 'T' = se x<sub>i</sub>!=y<sub>j</sub> ~> LCS(X<sup>i</sup>, Y<sup>j</sup>) ridotto a LCS(X<sup>i-1</sup>, Y<sup>j</sup>) _spostamento sulla riga precedente_
    - 'L' = se x<sub>i</sub>!=y<sub>j</sub> ~> LCS(X<sup>i</sup>, Y<sup>j</sup>) ridotto a LCS(X<sup>i</sup>, Y<sup>j-1</sup>) _spostamento sulla colonna precedente_

Il valore ottimo è contenuto in c[m, n].

```c++
void bottomup_LCS(std::string X, std::string Y,
                  std::vector<std::vector<int>> &c,
                  std::vector<std::vector<char>> &b) {
  int m = X.size();
  int n = Y.size();

  /* riempe prima riga e prima colonna con zero (confronta una lettera con la
   * stringa vuota, non hanno nulla in comune) */
  for (int i = 0; i <= m; i++)
    c.at(i).at(0) = 0;

  for (int j = 0; j <= n; j++)
    c.at(0).at(j) = 0;

  for (int i = 1; i <= m; i++)
    for (int j = 1; j <= n; j++)
      if (X.at(i - 1) == Y.at(j - 1)) {
        c.at(i).at(j) = c.at(i - 1).at(j - 1) + 1;
        b.at(i).at(j) = arrows.OBLI;
      } else {
        if (c.at(i - 1).at(j) >= c.at(i).at(j - 1)) {
          // l'uguale da precedenza alla riga
          c.at(i).at(j) = c.at(i - 1).at(j);
          b.at(i).at(j) = arrows.TOP;
        } else {
          c.at(i).at(j) = c.at(i).at(j - 1);
          b.at(i).at(j) = arrows.LEFT;
        }
      }
}

void print_LCS(std::string X, std::string Y, std::vector<std::vector<int>> &c,
               std::vector<std::vector<char>> &b) {
  bottomup_LCS(X, Y, c, b);
  print_LCS_REC(X, b, X.size(), Y.size());
}

void print_LCS_REC(std::string X, std::vector<std::vector<char>> b, int i,
                   int j) {
  if (i > 0 && j > 0) {
    if (b.at(i).at(j) == arrows.OBLI) {
      print_LCS_REC(X, b, i - 1, j - 1);
      std::cout << X.at(i - 1);
    } else {
      if (b.at(i).at(j) == arrows.TOP)
        print_LCS_REC(X, b, i - 1, j);
      else
        print_LCS_REC(X, b, i, j - 1);
    }
  }
}
```

### Analisi complessità

- bottomup_LCS: **T(m, n)** = Teta(m) + Teta(n) = Teta(m\*n) = **Teta(m\*n)**

- print_LCS: **T(m, n)** = Teta(m\*n) + Teta(m+n) = **Teta(m\*n)**

- print_LCS_REC: **T(i, j)** = **O(i+j)** _(perché ad ogni chiamata decremento uno tra i e j)_

## Codice c++ (versione ottimizzata)

La tabella b non è fondamentale, infatti l'informazione è derivabile da c in modo _locale_, generando tre celle di c.

c[i, j] dipende infatti da
- c[i-1, j-1]
- c[i-1, j]
- c[i, j-1]

```c++
void bottomup_LCS_OTT(std::string X, std::string Y,
                      std::vector<std::vector<int>> &c) {
  int m = X.size();
  int n = Y.size();

  /* riempe prima riga e prima colonna con zero (confronta una lettera con la
   * stringa vuota, non hanno nulla in comune) */
  for (int i = 0; i <= m; i++)
    c.at(i).at(0) = 0;

  for (int j = 0; j <= n; j++)
    c.at(0).at(j) = 0;

  for (int i = 1; i <= m; i++)
    for (int j = 1; j <= n; j++)
      if (X.at(i - 1) == Y.at(j - 1)) {
        c.at(i).at(j) = c.at(i - 1).at(j - 1) + 1;
      } else {
        if (c.at(i - 1).at(j) >= c.at(i).at(j - 1)) {
          // l'uguale da precedenza alla riga
          c.at(i).at(j) = c.at(i - 1).at(j);
        } else {
          c.at(i).at(j) = c.at(i).at(j - 1);
        }
      }
}

void print_LCS_OTT(std::string X, std::string Y,
                   std::vector<std::vector<int>> &c) {
  bottomup_LCS_OTT(X, Y, c);
  print_LCS_REC_OTT(X, c, X.size(), Y.size());
}

void print_LCS_REC_OTT(std::string X, std::vector<std::vector<int>> c, int i,
                       int j) {
  // L'ORDINE DEI TEST È FONDAMENTALE
  if (i > 0 && j > 0) {
    if (c.at(i).at(j) == c.at(i - 1).at(j)) {
      print_LCS_REC_OTT(X, c, i - 1, j);
    } else {
      if (c.at(i).at(j) == c.at(i).at(j - 1))
        print_LCS_REC_OTT(X, c, i, j - 1);
      else {
        print_LCS_REC_OTT(X, c, i - 1, j - 1);
        std::cout << X.at(i);
      }
    }
  }
}
```

### Analisi complessità

La complessità temporale rimane invariata:

- bottomup_LCS_OTT: **T(m, n)** = Teta(m) + Teta(n) = Teta(m\*n) = **Teta(m\*n)**

- print_LCS_OTT: **T(m, n)** = Teta(m\*n) + Teta(m+n) = **Teta(m\*n)**

- print_LCS_REC_OTT: **T(i, j)** = **O(i+j)** _(perché ad ogni chiamata decremento uno tra i e j)_

La complessità spaziale invece diventa **O(m\*n)** dato che ho eliminato una matrice.

## Altre ottimizzazioni

Se mi interessa soltanto la lunghezza della LCS (senza ricostruire la soluzione) posso evitare di mantenere tutta la tabella c[i, j] calcolando la riga i+1 tramite i. In questo modo lo spazio si riduce a **O(n)**