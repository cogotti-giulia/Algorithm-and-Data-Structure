## Esame 11/06/2015 (parte II, esercizio II)

Dati due alberi binari di ricerca T1 e T2 tali che le chiavi in T1 sono tutte minori delle chiavi in T2, scrivere una procedura che restituisce un albero di ricerca contenente tutte le chiavi in tempo O(h), dove h è l’altezza massima dei due alberi. Quale è l’altezza dell’albero risultante?

### Idea

Dato che le chiavi in T1 sono tutte minori delle chiavi in T2 prendo il minimo di T2 che sarà la radice del nuovo albero. Elimino il minimo da T2 e sistemo l'albero (tree_delete che ha tempo O(h)).

Poi uso il minimo come radice del nuovo albero, il figlio sinistro sarà t1.root mentre il figlio destro t2.root.

```
T1
      1
    /   \
   -3   3
    \   /
    -1 2

T2
      10
     /  \
    8   13
   / \
  5  9
   \
   7
  /
 6

~> min(T2) = 5
~> tree_delete (mette 6 al posto di 5)

T3
      5
     / \
    1   10
  ...    ...

visita simmetrica!

T1: -3 -1 1 2 3 
T2: 5 6 7 8 9 10 13 
T3: -3 -1 1 2 3 5 6 7 8 9 10 13 

```

### Codice

```c++
T build_new_tree(T t1, T t2) {
  T new_tree = new tree();

  if (t2->root == nullptr)
    new_tree->root = t1->root;
  else {
    pnode min_t2 = tree_minimum(t2->root);
    pnode r = new node(min_t2->key);

    tree_delete(t2, min_t2);

    r->left = t1->root;
    r->right = t2->root;
    r->right->p = r;
    r->left->p = r;

    new_tree->root = r;
  }

  return new_tree;
}
```

#### Analisi complessità

Siano
- h2 : altezza albero T2
- h1 : altezza albero T1

La funzione tree_minimum costa O(h2) in quando segue un cammino che va al più dalla radice a una foglia La funzione tree_delete costa anch'essa O(h2).

Ma allora il tempo complessivo risulta essere **O(h)** dove h è l'altezza massima tra h1 e h2.


L'albero risultante avrà altezza al più *h* perché per esempio, se T2 è vuoto allora il nuovo albero è uguale a T1 e l'altezza è il massimo tra le due quindi h1 = h.

Ma se invece non esiste T1 ma esiste T2, prendendo il minimo elimino un nodo e l'altezza del nuovo albero sarà h2 - 1 = h-1