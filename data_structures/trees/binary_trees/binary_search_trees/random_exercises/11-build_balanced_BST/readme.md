## Esame 29/05/2012 (parte II, esercizio II)

Dato un array di n interi, progettare un algoritmo efficiente che costruisca un albero binario di ricerca di altezza Θ(log n) che contenga gli interi dell’array come chiavi, e analizzarne la complessità.

Devono essere definite esplicitamente eventuali funzioni/procedure ausiliarie. Si consideri la rappresentazione dell’albero binario che utilizza i campi left, right e key.

### Idea

Per avere altezza log n l'albero binario di ricerca deve essere _bilanciato_ per avere un'altezza pari a _log n_ quindi, ordino l'array utilizzando un algoritmo di sorting che porta via al più O(n logn) (quindi merge sort) poi prendo l'elemento centrale dell'array e ricorsivamente creo i figli sinistro e destro prendendoli dalle rispettive porzioni dell'array (avrà un costo pari ad n).

### Codice c++

```c++

T build_bst_height_logn(std::vector<int> &A) {
  my_merge_sort(A, 0, A.size() - 1);
  T t = new tree();
  t->root = build_bst_height_logn_AUX(A, 0, A.size() - 1);
  return t;
}

pnode build_bst_height_logn_AUX(const std::vector<int> &A, int p, int r) {
  if (p > r)
    return nullptr;
  else {
    int med = std::floor((p + r) / 2);
    pnode nuovo = new node(A.at(med));
    nuovo->left = build_bst_height_logn_AUX(A, p, med - 1);
    nuovo->right = build_bst_height_logn_AUX(A, med + 1, r);
    return nuovo;
  }
}

void my_merge_sort(std::vector<int> &A, int p, int r) {
  if (p < r) {
    int q = std::floor((p + r) / 2);
    my_merge_sort(A, p, q);
    my_merge_sort(A, q + 1, r);
    my_merge(A, p, q, r);
  }
}

void my_merge(std::vector<int> &A, int p, int q, int r) {
  int n1 = q - p + 1;
  int n2 = r - q;

  std::vector<int> L, R;

  for (int i = 0; i < n1; i++)
    L.push_back(A.at(p + i));

  for (int j = 0; j < n2; j++)
    R.push_back(A.at(q + j + 1));

  int k = p;
  int i = 0, j = 0;

  while (k <= r) {
    if (i < n1 && j < n2) {
      if (L.at(i) <= R.at(j)) {
        A.at(k) = L.at(i);
        i++;
      } else {
        A.at(k) = R.at(j);
        j++;
      }
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
}
```

#### Analisi complessità

Ordinamento

```
        --- c             se n = 0
T(n) = |
        -- 2T(n/2) + n    se n > 0

[t. master]

a = 2
b = 2
f(n) = n
g(n) = n^d = n^log(b)a = n^log(2)2 = n

ma allora f(n) = Teta(n^d) ~> T(n) = Teta(n logn)
```

Costruzione BST aux

```
        --- Teta(1)          n = 0
T(n) = |  
        --- 2T(n/2) + c      n > 0

[t. master]

a = 2
b = 2
f(n) = c
g(n) = n^d = n^log(b)a = n^log(2)2 = n


ma allora per epsilon > 0
f(n) = O(n^(1-epsilon)) 

fisso epsilon uguale ad 1

allora f(n) = O(n^0 = 1)

quindi T(n) = Teta(n)
```

La procedura per ordinare costa O(n logn), la costruzione dell'albero ricorsiva costa Teta(n). Dunque la complessità risulta essere **T(n) = Teta(n)** dove n rappresenta il numero degli elementi dell'array di input (nodi dell'albero).