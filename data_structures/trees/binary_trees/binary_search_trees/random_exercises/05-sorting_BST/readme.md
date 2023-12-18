## Prima prova intermedia 23/01/2014 (esercizio II)

Si può ordinare un dato insieme di n numeri costruendo un albero binario di ricerca che contiene questi numeri (usando ripetutamente Tree-Insert per inserire i numeri uno alla volta) e stampando poi i numeri utilizzando un certo tipo di visita. Scrivere l’algoritmo che realizza questo ordinamento e specificare il tipo di visita effettuata e il relativo algoritmo.

Quali sono i tempi di esecuzione nel caso peggiore e nel caso migliore per questo algoritmo
di ordinamento?

### Esempio

```
A : -1 7 3 4 11 0 -2 5 3 

BST:
          -1
         /  \
       -2    7
            / \
           3   11
          / \
         0   4
          \   \
           3   5

caso peggiore h = n
A: -2 1 3 5 8

            -2
              \
               1
                \
                 3
completamente     \
sbilanciato !      5
                    \
                     8

caso miglior h = logn
A: 5 1 7 -2 6

albero       5
bilanciato  / \
           1   7
          /    /
        -2   6

```

### Codice c++

```c++
void sort_BST(std::vector<int> A) {
  T t = new tree();

  for (int i = 0; i < A.size(); i++) {
    pnode nuovo = new node(A.at(i)); // crea un nodo con p=left=right=nullptr
    tree_insert(t, nuovo);
  }

  visita_simmetrica_BST(t->root);
}

void tree_insert(T t, pnode z) {
  pnode padre = nullptr;
  pnode scorri = t->root;

  while (scorri != nullptr) {
    padre = scorri;
    if (z->key > scorri->key)
      scorri = scorri->right;
    else
      scorri = scorri->left;
  }

  z->p = padre;
  if (padre == nullptr) // albero vuoto
    t->root = z;
  else {
    if (z->key <= padre->key)
      padre->left = z;
    else
      padre->right = z;
  }
}

void visita_simmetrica_BST(pnode r) {
  std::cout << "BST: ";

  if (r != nullptr) {
    pnode min = tree_minimum(r);
    pnode succ = tree_successor(min);

    while (succ != nullptr) {
      std::cout << succ->key << " ";
      pnode tmp = succ;
      succ = tree_successor(tmp);
    }

    std::cout << std::endl;
  }
}
```

### Analisi complessità

Il tempo di esecuzione risulta essere _T(n)=Teta(n)+O(n\*h)_ dove n rappresenta il numero di nodi dell'albero e h l'altezza.

Nel caso migliore l'albero è _bilanciato_, ma allora l'altezza _h = logn_ e la funzione richiede un tempo di **T(n)=Teta(n logn)**.

Nel caso peggiore l'albero risulta essere _completamente sbilanciato_ (con input un array già ordinato in senso crescente o decrescente) e l'altezza _h = n_, questo fa in modo che la complessità diventi **T(n)=Teta(n^2)**.