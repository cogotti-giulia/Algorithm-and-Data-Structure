## Esame 20/06/2023 (esercizio I, parte II)

Sia T un albero binario di ricerca (BST) avente n nodi.

1. Si scriva una funzione efficiente in C o C++ PTree Modify_key(PTree t, PNode x, int key) che modifica x.key con key e ritorna t se t è ancora un BST, nullptr altrimenti.
2. Valutare e giustificare la complessità della funzione.
3. Specificare il linguaggio di programmazione scelto e la definizione di PTree e PNode.

### Idea

Modifico x.key, cerco il suo predecessore e successore, se esistono confronto i valori con la nuova chiave, se non rispettano la condizione dell'attraversamento simmetrico allora rendo nullptr (si può dimostrare che la visita simmetrica in un BST ordina le chiavi in modo non decrescente, quindi l'eventuale anomalia la troverò confrontando la nuova chiave con il valore immediatamente precedente e quello immediatamente successivo!)

### Codice c++

```c++
ptree modify_key(ptree t, pnode x, int key) {
  if (x != nullptr) {
    x->key = key;

    pnode prev = tree_predecessor(x);
    pnode succ = tree_successor(x);

    if (prev != nullptr && prev->key > x->key)
      return nullptr;

    if (succ != nullptr && succ->key < x->key)
      return nullptr;
  }

  return t;
}
```

Strutture dati per nodo e albero

```c++
struct node {
  int key;
  node *p;
  node *left;
  node *right;

  node(int k, node *padre = nullptr, node *sx = nullptr, node *dx = nullptr)
      : key{k}, p{padre}, left{sx}, right{dx} {};
};

typedef node *pnode;

struct tree {
  pnode root;

  tree() : root{nullptr} {};
};

typedef tree *ptree;
```

#### Analisi complessità

Le funzioni tree_successor e tree_predecessor costano entrambe O(h) dove h rappresenta l'altezza dell'albero, questo perché si segue un cammino che va dal nodo a una foglia ( o dal nodo alla radice ).

Quindi **T(n) = O(h) + O(h) = O(h)**. Se l'albero fosse bilanciato _h = log_ e _T(n) = O(log n)_