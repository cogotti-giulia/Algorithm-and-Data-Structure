## Esercizio

Sia T un albero binario di ricerca contenente n chiavi intere distinte. Sia k una chiave di T. Si consideri il problema di eliminare da T tutte le chiavi maggiori di k.

1. Si scriva una procedura in C efficiente per risolvere il problema proposto.
2. Calcolarne la complessità.
3. Scrivere i tipi in C Tree e Node.

Il prototipo della procedura è void `eliminaMaggioriK(Tree t, int k)`

### Idea

Scorro l'albero partendo dal massimo e vado di predecessore in predecessore (opposto di una visita simmetrica), in questo modo elenco le chiavi in ordine non crescente. Elimino i nodi utilizzando la tree delete finché non arrivo al nodo con chiave k.

### Codice c++

```c++
void elimina_maggiori_k(T t, int k) {
  if (t->root != nullptr) {
    pnode scorri = tree_maximum(t->root);

    while (scorri != nullptr && scorri->key > k) {
      pnode tmp = scorri;
      scorri = tree_predecessor(scorri);
      tree_delete(t, tmp);
    }
  }
}
```

#### Analisi complessità

Se h è l'altezza dell'albero allora la funzione tree_maximum impiega O(h). Il ciclo while viene eseguito al più n volte e al suo interno la tree_predecessor costa al più O(h) e anche la tree_delete.

Quindi si ha **T(n) = O(h) + O(n * (h+h)) = O(h) + O(n\*h) = (n\*h).**

### Proprietà utilizzata

> T è un BST allora la visita simmetrica inversa ordina le chiavi in senso non crescente 

La visita simmetrica inversa si ottiene trovando l'elemento massimo nell'albero ed effettuando n-1 chiamate a tree_predecessor.

_Dimostrazione_

_caso base [ n = 0 ]:_ ovvio

_passo induttivo [ n > 0 ]:_
```
  T
      (x)
     /   \
    /\    /\
   /t1\  /  \
   ¯¯¯¯ / t2 \
        ¯¯¯¯¯¯
```

Una visita simmetrica inversa produce _visita(t2)_ ~> _x_ ~> _visita(t1)_.

Assumo che la proprietà sia vera per un k < n e dimostro per n

Ipotesi:

1. t2 è un BST
2. t1 è un BST
3. per ogni y in t2 y.key >= x.key
4. per ogni y in t1 y-key <= x.key

Allora, dato che il numero di nodi in t1 e in t2 sono entrambi minori di n si ha che la visita simmetrica inversa produce

```
    chiave    >= ... >= chiave       >=   x.key   >=   chiave        >=  ...   >= chiave
          i_n                 i_m  (ip.3)       (ip.4)       i_m+2                      i_1
```

Quindi per ipotesi 3 e 4 anche x è ordinata in senso non crescente, ma allora ho finito la dimostrazione!