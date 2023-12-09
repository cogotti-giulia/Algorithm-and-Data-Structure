## Esercizio

Sia T un albero generale i cui nodi hanno campi: key, left-child e right-sib. Si scriva una funzione EFFICIENTE che verifichi la seguente proprietà: per ogni nodo u, le chiavi dei figli del nodo u devono avere valori non decrescenti considerando i figli di u da sinistra verso destra.

Il prototipo della funzione è: `bool isNonDec(PNodeG r)`

Restituisce true se la proprietà è verificata altrimenti false.

Analizzare e motivare in modo chiaro, preciso ed approfondito la complessità della funzione.

Il tipo PNodeG è così definito:

```c++
struct NodeG{  
  int key;
  NodeG* left_child;
  NodeG* right_sib;
};

typedef NodeG* PNodeG;
```

## Idea

scorro l'albero utilizzando un while per scorrere i right sibling e vado in ricorsione sul left child, in questo modo ogni nodo è visitato al più una volta.

mi salvo il valore del left child e confronto a coppie di fratelli, se la condizione è violata rendo false

```
      4
     /
    2 ~> 3 ~> 3
   /          /
 -1 ~> 1      7

true

      4
     /
    2 ~> 18 ~> 3
   /          /
 -1 ~> 1     7

false!

```

## Codice funzione

```c++
bool is_not_decr(pnodeG r) {
  if (r == nullptr)
    return true;
  else {
    pnodeG left = r->left_child;
    bool ris = true;
    bool ris_prev = true;

    while (left != nullptr && ris) {
      int prev_val = left->key;
      ris_prev = is_not_decr(left);

      left = left->right_sibling;

      if (left != nullptr && prev_val > left->key)
        ris = false;
      else
        ris = true && ris_prev;
    }

    return ris;
  }
}
```

#### Analisi complessità

Ogni nodo è visitato **al più** una volta, dunque la complessità risulta essere **T(n) = O(n)**, non è esattamente n volte perché la condizione potrebbe essere violata prima di aver visitato tutti i nodi e, dato che deve valere per ogni nodo, se accade ciò esco dal ciclo while e rendo false.