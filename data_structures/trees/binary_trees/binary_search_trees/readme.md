### Binary Search Tree [ BST ]

sia x un nodo in un albero binario di ricerca:<br>
~ se y è un nodo nel sotto albero _sinistro_ di x allora **y.key <= x.key** <br>
~ se y è un nodo nel sotto albero _destro_ di x allora **y.key >= x.key**

```
        3
      /   \
    -1     7    ~> è un BST !
          / \
         5   9
```

#### Analisi complessità

Le operazioni sugli _insiemi dinamici_:

- tree_search
- tree_minimum
- tree_maximum
- tree_successor
- tree_predecessor
- tree_insert
- tree_delete

posso essere essere realizzate nel tempo **O(h)** su un albero _binario di ricerca_ di **altezza h**.

Se l'albero si mantiene **bilanciato** allora il tempo diventa **O(log n)**.

#### Insert

```
              15
            /    \
          10      20
         /  \    /  \
        7   12  16   23

tree_insert ~> z.key = 9
tree_insert ~> z.key = 22
              15
            /    \
          10      20
         /  \    /  \
        7   12  16   23
         \          /
         (9)      (22)
```

#### Delete

ho tre possibili casi:<br>
i. se z è una _foglia_ allora cambio z.p eliminando il riferimento al figlio (z = NIL);<br>
ii. se z ha _un solo figlio_ allora stacco z e creo un collegamento fra il figlio di z e il padre di z;<br>
iii. se z ha **due figli**: trovo il successore di z (y) e metto y nella posizione che era occupata da z nell'albero

```

              15
            /    \
           7      18
         /  \      \
        3   10      21
                   /  \
                  19  23
                   \
                   20

tree_delete ~> z.key = 10 (caso i)
              15
            /    \
           7      18
         /          \
        3           21
                   /  \
                  19  23
                   \
                   20

tree_delete ~> z.key = 18 (caso ii)
              15
            /    \
           7     21
          /     /  \
         3     19  23
                 \
                 20

tree_delete ~> z.key = 15 (caso iii)
              19
            /    \
           7     21
          /     /  \
         3     20  23
```
