## Prima prova intermedia 28/21/2013 (esercizio II)

Dato l’insieme delle chiavi {1,4,5,10,16,17,21}, quale è l’altezza minima hmin di un albero binario di ricerca che contenga esattamente queste chiavi? E l’altezza massima hmax?

Disegnare 3 alberi binari di ricerca con le chiavi dell’insieme specificato rispettivamente di altezza hmin, hmax e di un’altezza h tale che hmin < h < hmax.

Infine scrivere una versione ricorsiva della procedura Tree-Insert per gli alberi binari di ricerca. La procedura ha come input un albero binario di ricerca T e un nodo z da inserire in tale albero. Discutere la complessità al caso pessimo di tale procedura.

### BST con chiavi {1,4,5,10,16,17,21}

```
min = floor(n/2)

       10
     /    \
    4     17
   / \   /  \
  1   5 16  21

      
hmax = n = 7

 1
  \
   4
    \
     5
      \
       10
        \
         16
          \
           17
            \
            21

hmin < h < hmax
h = floor(n/2)+1

       16
     /    \
    10     21
   / \     /
  4  16   17 
 / \    
1   5
```

### Idea

Vado in ricorsione di padre in figlio (sinistro o destro dipende dal valore della chiave), trascinandomi dietro il padre. Quando raggiungo nullptr (il padre è quindi una foglia), attacco il nuovo nodo in base al valore del campo key. 
Ovviamente se l'albero è vuoto semplicemente metto il nuovo nodo come radice dell'albero

### Codice c++

```c++

void tree_insert_ric(T t, pnode z) {
  if (t->root == nullptr) // albero vuoto
    t->root = z;
  else
    tree_insert_ric_AUX(t->root, z, nullptr);
}

void tree_insert_ric_AUX(pnode u, pnode z, pnode padre) {
  if (u != nullptr) {
    // scendo di padre in figlio (conservandomi il padre)
    // in base alla proprietà delle chiavi del bst
    // finché non raggiungo il punto in cui attaccare z
    if (u->key > z->key) {
      tree_insert_ric_AUX(u->left, z, u);
    } else {
      tree_insert_ric_AUX(u->right, z, u);
    }

  } else {
    // so che padre esiste per forza (ho almeno un nodo, altrimenti non viene
    // chiamata questa procedura)
    z->p = padre;
    // attacco z in base alla chiave
    if (padre->key > z->key)
      padre->left = z;
    else
      padre->right = z;
  }
}
```

#### Analisi complessità

La tree insert ricorsiva richiede un tempo di esecuzione pari a **O(h)** dove h rappresenta l'altezza dell'albero. Questo perché si segue un cammino che va dalla radice a una foglia.

Nel caso peggiore in cui l'albero sia completamente sbilanciato questa h è uguale al numero di nodi, quindi il tempo di esecuzione risulta essere **T(n) = O(n)**, avviene quando do in input una serie di chiavi da inserire ordinate!