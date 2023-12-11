## Esercizio

Sia BST+ la struttura dati che si ottiene aggiungendo ad ogni nodo x di un albero binario di ricerca un nuovo attributo sum che contiene la somma fra il numero di nodi nel sottoalbero sinistro e quelli nel sottoalbero destro di x.

Modificando la procedura Tree-insert si definisca una procedura BST++insert per l’inserimento di una nuova chiave in un BST+.

Il prototipo della procedura è: `BST++insert(TreeConSum t, NodeConSum z)`

Si assuma che il nodo z sia così inizializzato:

```
z.p = z.left = z.right = NULL
z.key = k (nuova chiave)
z.sum = 0
```

### Idea

Inserisco l'elemento nell'albero, poi scorro verso l'alto e sistemo la somma dato che l'eventuale anomalia può trovarsi solo nel percorso che collega z alla radice

### Codice

```c++
void tree_insert_sum(T_s t, pnode_s z) {
  pnode_s scorri_down = t->root;
  pnode_s padre = nullptr;
  while (scorri_down != nullptr) {
    padre = scorri_down;
    if (z->key <= scorri_down->key)
      scorri_down = scorri_down->left;
    else
      scorri_down = scorri_down->right;
  }

  z->p = padre;
  if (z->p == nullptr)
    t->root = z;
  else {
    if (z->key <= z->p->key)
      z->p->left = z;
    else
      z->p->right = z;
  }

  pnode_s scorri_up = z->p;

  int nodi_SX = 0;
  int nodi_DX = 0;

  while (scorri_up != nullptr) {

    if (scorri_up->left == z) {
      nodi_DX = abs(scorri_up->sum - nodi_SX);
      nodi_SX++;
    } else {
      nodi_SX = abs(scorri_up->sum - nodi_DX);

      nodi_DX++;
    }

    int new_sum = nodi_DX + nodi_SX;

    scorri_up->sum = new_sum;
    z = scorri_up;
    scorri_up = scorri_up->p;
  }
}
```

#### Analisi complessità 

L'algoritmo risulta avere costo O(h) dove h rappresenta l'altezza dell'albero. Questo perché entrambi i cicli hanno costo h dato che seguono un cammino che va rispettivamente dalla radice a una foglia e viceversa.