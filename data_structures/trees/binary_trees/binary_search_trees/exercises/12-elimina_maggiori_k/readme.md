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


