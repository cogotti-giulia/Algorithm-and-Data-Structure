## Esame 11/09/2018 (esercizio I, parte II)

Sia T un albero binario i cui nodi x hanno i campi left, right e key. L’albero si dice un Sum-Tree se per ogni nodo x, la chiave di x è maggiore o uguale sia alla somma delle chiavi nel sottoalbero sinistro che alla somma delle chiavi nel sottoalbero destro Scrivere una funzione in C efficiente IsSumTree(u) che riceve in input la radice u di un albero T e verifica se T è un Sum-Tree, ritornando 1 se la condizione è verificata e 0 altrimenti.

Analizzare la complessità della soluzione trovata, indicando eventuali relazioni di ricorrenza.

### Idea

Tramite una visita in post order vado in ricorsione nei sottoalberi sinistro e destro, vedo la somma di ognuno di essi e la confronto con la radice. Se la condizione è rispettata per ogni nodo ritorno true, altrimenti false. Devo fare attenzione al caso in cui u sia una foglia con chiave negativa, in questo caso la condizione è verificata in quanto non esistono sottoalberi!

### Codice c++

```c++
bool is_sum_tree(pnode u) {
  int sum = 0;
  return is_sum_tree_AUX(u, &sum);
}

bool is_sum_tree_AUX(pnode u, int *sum) {
  if (u == nullptr) {
    *sum = 0;
    return true;
  } else {
    int sumSX, sumDX;
    bool risSX = is_sum_tree_AUX(u->left, &sumSX);
    bool risDX = is_sum_tree_AUX(u->right, &sumDX);

    *sum = u->key + sumSX + sumDX;
    bool ris;

    // ATTENZIONE caso in cui u è una foglia con u.key < 0, dato che i figli non
    // esistono la proprietà è banalmente verificata
    if (u->key < 0 && u->left == nullptr && u->right == nullptr) {
      ris = true;
    } else {
      if (u->key >= sumSX && u->key >= sumDX)
        ris = true;
      else
        ris = false;
    }

    return ris && risSX && risDX;
  }
}
```

#### Analisi complessità

Il tempo di esecuzione risulta essere **T(n) = O(n)**, ottenuto risolvendo la seguente ricorrenza tramite _metodo di sostituzione_.

```
        --- c                   n=0
T(n) = |
        --- T(k)+T(n-k-1)+d     n>0

dove
k: nodi visitati nel sottoalbero sx
n-k-1: nodi visitati nel sottoalbero dx (-1 esclude la radice)
d: costo alla radice
```
