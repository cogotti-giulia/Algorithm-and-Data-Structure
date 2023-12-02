## Prima prova intermedia 28/01/2015 (esercizio I)

Un nodo di un albero binario u è detto intermedio se la somma delle chiavi contenute nei nodi del sottoalbero di cui u è radice è uguale alla somma delle chiavi contenute nei nodi sul percorso che collega u alla radice dell’albero (u escluso).

- Scrivere una funzione efficiente in C che restituisca il numero di nodi intermedi. (vedi esercizio 1-intermedi)
- Analizzare la complessità della soluzione trovata, indicando la corrispondente relazione di ricorrenza. (vedi esercizio 1-intermedi)
- Se vogliamo modificare la funzione in modo che restituisca l’insieme dei nodi intermedi che tipo di struttura dati si può utilizzare per rappresentare l’insieme? La complessità dell’algoritmo deve rimanere la stessa che nel caso 1.

### Codice funzione

```c++

std::list<pnode> intermedi(pnode u){
  int sumK = 0;
  std::list<pnode> list_intermedi;
  intermedi_aux(u, list_intermedi, 0, &sumK);
  return list_intermedi;
}

void intermedi_aux(pnode u, std::list<pnode>& list_intermedi, int sumPercorso, int *sumKeysSubtree){
  if(u == nullptr){
    *sumKeysSubtree = 0;
  }else{
    int sum_keys_sx, sum_keys_dx;

    intermedi_aux(u->left, list_intermedi, sumPercorso+u->key, &sum_keys_sx);
    intermedi_aux(u->right, list_intermedi, sumPercorso+u->key, &sum_keys_dx);

    int sum = sum_keys_dx + sum_keys_sx + u->key;

    *sumKeysSubtree = sum;

    if(sum == sumPercorso){
      list_intermedi.push_back(u);
    }
  }
}
```

#### Analisi complessità

L'utilizzo di una lista permette l'inserimento (in coda in questo caso) in tempo costante, dunque la complessità rimane quella del caso uno: **T(n) = Teta(n)** 