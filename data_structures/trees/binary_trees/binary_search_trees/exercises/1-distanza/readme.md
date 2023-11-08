## Esercizio

Dati due numeri x e y si definisce la distanza tra x e y come `d(x, y) = |x-y|`.<br>
Sia T un binary search tree le cui chiavi sono numeri interi e avente almeno due nodi. Scrivere una funzione efficiente che restituisca la distanza MINIMA fra le chiavi di due nodi di T.

```
            9
          /   \
         3     15
        / \      \
      -1   6      17
    
~> dist_min = 2

La distanza minima si trova tra le coppie successive nella visita simmetrica!
```

Sfrutto l'ipotesi che T abbia almeno due nodi trovando il minimo e il suo successore e procedo effettuando una visita simmetrica andando di successore in successore.

### Codice funzione

```pseudocode
    distanza_minima(T)
        x = tree_minimum(T.root)
        y = tree_successor(x)
        min_distance = abs|y.key - x.key |
        x = tree_successor(y)
        while x != NIL
            diff = abs|x.key - y.key|
            if(diff < min_distance)
                min_distance = diff
            y = x
            x = tree_successor(y)
        return min_distance
```

```c++
    int distanza_minima(T t){
        pnode x = tree_minimum(t.root);
        pnode y = tree_successor(x);
        
        int min_distance = abs(y.key - x.key);
        x = tree_successor(y);

        while(x != nullptr){
            int diff = abs(x.key - y.key);
            if(diff < min_distance)
                min_distance = diff;
            y = x;
            x = tree_successor(y);
        }
        return min_distance;
    }
```

#### Analisi complessità

L'**attraversamento simmetrico** di un albero binario di ricerca di n nodi può essere implementato 
trovando l'elemento minore (tree_minimum) nell'albero ed effettuando poi n-1 chiamate di tree_successor.

```
Questo algoritmo viene eseguito in T(n) = Teta(n)
```

_Dimostrazione_

La chiamata a tree_minimum seguita da n-1 chiamate a tree_successor, esegue una _visita simmetrica (in\_order)_, infatti in\_order stampa il minimum (tree\_minimum) e poi, per definizione, il tree\_successor è il prossimo nodo in una visita simmetrica!

L'algoritmo ha tempo di esecuzione Teta(n) perché
- richiede omega(n) per effettuare le n chiamate ricorsive
- attraversa ognuno degli (n-1) archi **al più** due volte, quindi O(n) (\*\*\*)

ma allora **T(n) = Teta(n)**

```
(***)
sia (u,v) un arco generico, allora:
[downward] vado da u a v in tree_minimum
[upward] vado da v a u in tree_successor quando il nodo non ha sotto albero destro
```
