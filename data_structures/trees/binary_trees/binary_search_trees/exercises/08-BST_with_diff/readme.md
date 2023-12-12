## Prima prova intermedia 16/01/2018 (esercizio II)

Sia BST+ la struttura dati che si ottiene aggiungendo ad ogni nodo x di un albero binario di ricerca un nuovo attributo diff che contiene la differenza fra il numero di nodi nel sottoalbero sinistro e quelli nel sottoalbero destro di x.

Modificando la procedura Tree-insert si definisca una procedura BST+-insert per l’inserimento di una nuova chiave in un BST+.

Il prototipo della procedura è: `BST+-insert(TreeConSum t, NodeConSum z)`

Si assuma che il nodo z sia così inizializzato:

```
z.p = z.left = z.right = NULL
z.key = k (nuova chiave)
z.diff = 0
```

### Idea

Inizialmente inserisco z nell'albero, scorrendo verso il basso (quindi al più avrà un costo pari all'altezza dell'albero). Una volta che trovo il punto in cui inserire z risalgo da z alla radice perché l'eventuale anomalia di differenza del numero di nodi si trova nel cammino che collega z alla radice dato che ho aggiunto un nodo!

Quindi scorro tenendomi figlio (z all'inizio) e rispettivo padre. Mi calcolo i nodi presenti nei sottoalberi sinistro e destro (se figlio sta a sinistra so già il numero e trovo il numero di destra usando il numero dei nodi a sinistra e la differenza presente nel padre e viceversa se figlio sta a destra). Poi mi calcolo la differenza tra il numero dei nodi del sottoalbero sinistro e destro e la inserisco nel campo diff di padre.

### Codice

```c++
void tree_insert_diff(T_d t, pnode_d z) {
  pnode_d scorri_down = t->root;
  pnode_d padre_z = nullptr;

  //! O(h)
  while (scorri_down != nullptr) {
    padre_z = scorri_down;
    if (z->key <= scorri_down->key)
      scorri_down = scorri_down->left;
    else
      scorri_down = scorri_down->right;
  }

  z->p = padre_z;
  if (z->p == nullptr)
    t->root = z;
  else {
    if (z->key <= z->p->key)
      z->p->left = z;
    else
      z->p->right = z;
  }

  // scorro dal padre del nodo che ho aggiunto fino alla radice
  // tenendomi figlio perché devo sapere se è destro o sinistro
  pnode_d padre = z->p;
  pnode_d figlio = z;

  // conta i nodi nei sottoalberi di padre
  int nodi_SX = 0;
  int nodi_DX = 0;

  //! O(h)
  while (padre != nullptr) {
    // se il figlio sta nel sottoalbero sinistro, significa che la somma dei
    // nodi dei sottoalberi sinistro e destro precedentemente calcolata è la
    // somma dei nodi del sottoalbero sinistro corrente
    // ma allora al momento io il numero lo conosco ma non conosco quello
    // dell'altro sottoalbero che mi calcolo

    // vedo se ha anche un figlio destro, in caso positivo, con la differenza e
    // il numero di nodi a sinistra (prima di aggiungere z) mi trovo il numero
    // dei nodi di quel sottoalbero (MI HA FATTA DANNARE RIUSCIRE A CALCOLARE IL
    // NUMERO AAAAAAAAAAA)

    // alla fine incremento il numero di nodi nel sottoalbero sinistro perché in
    // quel cammino io ho aggiunto z
    if (padre->left == figlio) {
      nodi_SX = nodi_DX + nodi_SX;
      nodi_DX = 0;
      if (padre->right != nullptr) {
        if (nodi_SX <= padre->diff)
          nodi_DX = (padre->diff) + nodi_SX;
        else
          nodi_DX = nodi_SX - padre->diff;
      }
      nodi_SX++;
    } else if (padre->right == figlio) {
      nodi_DX = nodi_DX + nodi_SX;
      nodi_SX = 0;
      if (padre->left != nullptr) {
        if (nodi_DX <= padre->diff)
          nodi_SX = (padre->diff + nodi_DX);
        else
          nodi_SX = nodi_DX - padre->diff;
      }
      nodi_DX++;
    }

    // la differenza sarà il valore assoluto tra la differenza dei sottoalberi
    // (esclusa la radice)
    int new_diff = abs(nodi_DX - nodi_SX);
    padre->diff = new_diff;

    figlio = padre;
    padre = padre->p;
  }
}
```

#### Analisi complessità

Il ciclo while per inserire z nell'albero ha costo pari a *O(h)* dove h rappresenta l'altezza dell'albero, dato che si segue un percorso che va dalla radice a una foglia. Anche il secondo ciclo ha costo *O(h)* in quanto si segue il cammino opposto (da una foglia alla radice).

Ma allora ho che *T(n) = O(h) + O(h) + d* e concludo che **T(n) = O(h)** dove h rappresenta l'altezza dell'albero.