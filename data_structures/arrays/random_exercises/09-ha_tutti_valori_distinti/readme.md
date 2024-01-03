## Esame 29/05/2014 (parte II, esercizio II)

Progettare un algoritmo efficiente di tipo divide et impera che dato un vettore di interi restituisce true se tutti i valori sono distinti, false altrimenti. Analizzare la complessità dell’algoritmo proposto.

### Idea

Posso modificare il merge sort in modo che quando trova un duplicato restituisce false, ottenendo un algoritmo che impiega al più n logn

### Codice c++

```c++

bool kind_of_merge(std::vector<int> &A, int p, int q, int r) {
  int n1 = q - p + 1;
  int n2 = r - q;

  std::vector<int> L;
  std::vector<int> R;

  for (int i = 0; i < n1; i++)
    L.push_back(A.at(p + i));

  for (int j = 0; j < n2; j++)
    R.push_back(A.at(q + j + 1));

  int k = p;
  int i = 0, j = 0;

  bool ris = true;

  while (k <= r && ris) {
    if (i < n1 && j < n2) {
      if (L.at(i) < R.at(j)) {
        A.at(k) = L.at(i);
        i++;
      } else if (L.at(i) > R.at(j)) {
        A.at(k) = R.at(j);
        j++;
      } else
        ris = false;
    } else {
      if (i < n1) {
        A.at(k) = L.at(i);
        i++;
      } else {
        A.at(k) = R.at(j);
        j++;
      }
    }
    k++;
  }

  return ris;
}

bool has_valori_distinti(std::vector<int> &A, int p, int r) {
  if (p < r) {

    int q = std::floor((p + r) / 2);
    has_valori_distinti(A, p, q);
    has_valori_distinti(A, q + 1, r);

    return kind_of_merge(A, p, q, r);
  }else {
    return true;
  }
}
```

#### Analisi complessità

La funzione has_valori_distinti è chiamata due volte su metà array, quindi ogni chiamata impiega T(n/2), dove n rappresenta il numero degli elementi dell'array di input.

La funzione kind_of_merge è eseguita al più n volte quindi

T(n) = 2T(n/2) + O(n)

_teorema master_

```
a = 2
b = 2

d = log(b)a = 1
g(n) = n^d = n

f(n) = n

ma allora f(n) = Teta(n^1)
quindi T(n) = Teta(n logn)
```

in conclusione **T(n) = Teta(n logn)**