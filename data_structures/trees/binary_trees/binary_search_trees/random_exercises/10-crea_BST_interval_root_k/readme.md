## Esame 05/06/2023 (parte II, esercizio I)

Sia T un BST di dimensione n e sia k una chiave di T tale che T->root->key < k. Si vuole costruire un nuovo BST T' contenente tutte e sole le chiavi di T appartenenti all’intervallo [T->root->key, k].

1. Si scriva una funzione efficiente in C o C++ per risolvere il problema. Il prototipo della funzione è: `PTree creaBSTInterval(PTree t, int k)`
2. Valutare e giustificare la complessità della funzione.
3. Specificare il linguaggio di programmazione scelto e la definizione di PTree.

### Idea


Dato che l'intervallo va da T->root-> a k compresi, posso escludere completamente i nodi a sinistra di T (in quanto le chiavi sono minori di quella alla radice). Allora posso andare a destra e scorro l'albero di successore in successore fino a quando non trovo una chiave > k. Posso farlo perché la visita simmetrica elenca le chiavi in ordine non decrescente in un BST (si può dimostrare!).

In questo modo la complessità risulta essere O(n) dove n rappresenta il numero di nodi dell'albero dell'albero.

L'unico problema è che purtroppo esce un albero completamente sbilanciato, per renderlo bilanciato dovrei probabilmente salvare le chiavi in un array di supporto e costruire l'albero usando una build ottimizzata. Che prende come root l'elemento centrale e attacca in ricorsione i figli sinistro e destro prendendo rispettivamente le chiavi nella porzione sinistra e destra dell'array. Questo porterebbe via un tempo O(n) quindi non impatta sulla complessità temporale. Su quella spaziale si dato che non sarebbe più costante!

> Perché dovrei crearlo bilanciato? Perché poi tutte le operazioni che hanno costo pari ad O(h) posso eseguirle in tempo O(logn) perché l'altezza di un albero bilanciato è logn

```
visita simmetrica!

gli alberi sono tali che u.left.key < u.key <= u.right.key

OLD: -3 -1 4 4 5 5 6 7 10 12 12 13 19 27 29 
ROOT: 5

k =  17

NEW: 5 5 6 7 10 12 12 13 
ROOT: 5

NEW BALANCED: 5 5 6 7 10 12 12 13 
ROOT: 7

```

### Codice c++ (crea un bst NON bilanciato)

```c++
T crea_BST_interval(T t, int k) {
  T new_tree = new tree();

  if (t->root != nullptr) {

    pnode new_root = new node(t->root->key);
    new_tree->root = new_root;

    pnode nuovo = new_tree->root;
    pnode succ = tree_successor(t->root);

    while (succ != nullptr && succ->key <= k) {

      nuovo->right = new node(succ->key);
      nuovo->right->p = nuovo;
      nuovo = nuovo->right;
      

      pnode tmp = succ;
      succ = tree_successor(tmp);
    }
  }

  return new_tree;
}
```

#### Analisi complessità

Sto effettuando una attraversamento simmetrico, passando da successore in successore, dato che inizio dalla radice questo avrà un costo pari a O(n). Dunque la complessità risulta essere **T(n) = O(n) + d = O(n)**


### Codice c++ (crea un bst BILANCIATO)

```c++
T crea_BST_interval_BALANCED(T t, int k) {
  T new_tree = new tree();
  std::vector<int> nuovo_keys;

  pnode scorri = t->root;

  while (scorri != nullptr && scorri->key <= k) {
    nuovo_keys.push_back(scorri->key);

    pnode tmp = scorri;
    scorri = tree_successor(tmp);
  }

  new_tree->root = build_BST_OTT_RIC(nuovo_keys, 0, nuovo_keys.size()-1, nullptr);

  return new_tree;
}
```

#### Analisi complessità

Sto effettuando una attraversamento simmetrico, passando da successore in successore, dato che inizio dalla radice questo avrà un costo pari a O(n).

La procedura build_BST_OTT_RIC porta via un tempo pari a O(n).

Ma allora **T(n) = O(n) + O(n) + d = O(n)**


### Codice c++ (funzioni ausiliarie utilizzate)

**Costruzione bst da un array di n elementi**

```c++
// T(n) = O(n)
pnode build_BST_OTT_RIC(std::vector<int> A, int inf, int sup, pnode padre) {
  if (inf > sup)
    return nullptr;
  else {
    int med = std::floor((inf+sup)/2);
    pnode nuovo = new node(A.at(med));
    nuovo->p = padre;
    nuovo->left = build_BST_OTT_RIC(A, inf, med-1, nuovo);
    nuovo->right = build_BST_OTT_RIC(A, med+1, sup, nuovo);

    return nuovo;
  }
}
```

**Successore**

```c++

//T(n) = O(n)
pnode tree_successor(pnode x) {
  if (x->right != nullptr)
    return tree_minimum(x->right);
  else {
    pnode y = x->p;

    while (y != nullptr && y->right == x) {
      x = y;
      y = y->p;
    }

    return y;
  }
}

//T(n) = O(h)
pnode tree_minimum(pnode x) {
  while (x->left != nullptr)
    x = x->left;

  return x;
}
```