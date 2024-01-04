## Prima prova intermedia del 13/01/2020 (esercizio II)

Realizzare una funzione efficiente triplo che, dato un array A di n interi, verifica se esiste una coppia di indici i, j tali che A[j] = 3 ∗ A[i]. Restituisce 1 e i corrispondenti indici se la coppia esiste, 0 altrimenti. Analizzare la complessità e scrivere le eventuali funzioni/procedure ausiliarie utilizzate.

### Idea

Modifico il merge sort, quando la procedura di merge fa i confronti vedo se trovo due elementi che rispettano la mia condizione! Utilizzo una struttura dati ausiliaria dove copio valori e indici corrispondenti all'array originale (perché devo restituire gli indici ma se ordino perdo questa informazione), in tempo lineare.

Chiamare il merge sort porterà via al più un tempo pari a n logn. Quindi non troppo male come complessità.

### Codice c++

```c++
struct ii {
  int info;
  int index;

  ii(int info, int index) : info{info}, index{index} {};
};
typedef ii *pii;

bool triplo(const std::vector<int> &A, int *i, int *j) {

  std::vector<pii> a;

  for (int i = 0; i < A.size(); i++) // n
    a.push_back(new ii(A.at(i), i));

  return my_merge_sort(a, 0, a.size() - 1, i, j); // n logn
}

bool my_merge_sort(std::vector<pii> &a, int p, int r, int *i, int *j) {
  if (p < r) {
    int med = std::floor((p + r) / 2);
    bool ris1 = my_merge_sort(a, p, med, i, j);
    bool ris2 = my_merge_sort(a, med + 1, r, i, j);

    if (my_merge(a, p, med, r, i, j))
      return true;
    else {
      return ris1 || ris2;
    }
  } else {
    return false;
  }
}

bool my_merge(std::vector<pii> &a, int p, int q, int r, int *index1,
              int *index2) {
  int n1 = q - p + 1;
  int n2 = r - q;

  std::vector<pii> L;
  std::vector<pii> R;

  for (int i = 0; i < n1; i++)
    L.push_back(a.at(p + i));

  for (int j = 0; j < n2; j++)
    R.push_back(a.at(q + j + 1));

  int k = p;
  int i = 0, j = 0;

  bool is_triplo = false;

  //mi fermo se lo trovo, mi bastano i primi due elementi che trovo
  while (k <= r && !is_triplo) {
    if (i < n1 && j < n2) {
      if ((L.at(i)->info * 3 == R.at(j)->info) ||
          (R.at(j)->info * 3 == L.at(i)->info)) {
        is_triplo = true;

        if (abs(L.at(i)->info) < abs(R.at(j)->info)) {
          *index1 = L.at(i)->index;
          *index2 = R.at(j)->index;
        } else {
          *index1 = R.at(j)->index;
          *index2 = L.at(i)->index;
        }
      }
      if (L.at(i)->info <= R.at(j)->info) {
        a.at(k) = L.at(i);
        i++;
      } else {
        a.at(k) = R.at(j);
        j++;
      }
    } else {
      if (i < n1) {
        a.at(k) = L.at(i);
        i++;
      } else {
        a.at(k) = R.at(j);
        j++;
      }
    }

    k++;
  }

  return is_triplo;
}
```

#### Analisi complessità

Popolare la struttura dati ausiliaria porta via un tempo lineare, il merge sort impiega al più n logn, ma allora **T(n) = Teta(n) + O(n logn) = O(n logn)**. Purtroppo è necessario uno spazio aggiuntivo proporzionale agli elementi dell'array sia per la struttura ausiliaria che per i vettori nel merge. Quindi _S(n) = Teta(n)_