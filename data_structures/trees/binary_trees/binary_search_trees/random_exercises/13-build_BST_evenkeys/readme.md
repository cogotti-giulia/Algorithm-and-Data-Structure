## Prima prova intermedia 25/01/2019 (esercizio II)

Sia dato un albero binario di ricerca T con n nodi e chiavi naturali. Si scriva tramite pseudocodice una funzione efficiente che restituisca un albero binario di ricerca T′ contenente tutte e sole le chiavi pari di T.

Qual è la complessità in termini di tempo della funzione proposta? La soluzione proposta è in loco? Giustificare le risposte.

### Idea!

Faccio una visita simmetrica dell'albero (impiega un tempo pari ad n, si può dimostrare) e salvo le chiavi pari in un array (non è in loco quindi). Applico poi la build bst ottimizzata (richiede un array ordinato per funzionare e l'ho ottenuto dato che la visita simmetrica elenca le chiavi in ordina non decrescente) che in tempo Teta(n) costruisce un bst bilanciato contenente le chiavi richieste.

### Codice c++

```c++

T build_BST_even_keys(T t) {
  T tris = new tree();

  if (t != nullptr) {
    std::vector<int> A = get_even_keys_from_T(t);
    tris = build_BST_OTT(A);
  }

  return tris;
}
```

Funzioni ausiliarie

```c++
std::vector<int> get_even_keys_from_T(T t) {
  std::vector<int> A;

  pnode scorri = tree_minimum(t->root);

  while (scorri != nullptr) {
    if (scorri->key % 2 == 0)
      A.push_back(scorri->key);

    pnode tmp = scorri;
    scorri = tree_successor(tmp);
  }

  return A;
}

pnode tree_minimum(pnode x) {
  while (x->left != nullptr)
    x = x->left;

  return x;
}

pnode tree_successor(pnode x) {
  if (x->right != nullptr)
    return tree_minimum(x->right);
  else {
    pnode y = x->p;

    while (y != nullptr && y->left != x) {
      x = y;
      y = y->p;
    }

    return y;
  }
}

T build_BST_OTT(std::vector<int> A) {
  T t = new tree();
  t->root = build_BST_OTT_AUX(A, 0, A.size() - 1, nullptr);
  return t;
}

pnode build_BST_OTT_AUX(std::vector<int> A, int p, int r, pnode padre) {
  if (p > r)
    return nullptr;
  else {
    int med = std::floor((p + r) / 2);
    pnode nuovo = new node(A.at(med));
    nuovo->p = padre;
    nuovo->left = build_BST_OTT_AUX(A, p, med - 1, nuovo);
    nuovo->right = build_BST_OTT_AUX(A, med + 1, r, nuovo);

    return nuovo;
  }
}
```

#### Analisi complessità

La ricerca delle chiavi pari impiega un tempo pari a Teta(n) dato dalla visita simmetrica. La costruzione del bst ottimizzata impiega anch'essa Teta(n).

Quindi **T(n) = Teta(n) + Teta(n) = Teta(n)**

La soluzione proposta _non_ è in loco in quanto utilizza un array che occupa uno spazio in memori pari a S(n) = O(n), perché al più posso avere che tutte le chiavi del bst sono pari e devo duplicarlo!