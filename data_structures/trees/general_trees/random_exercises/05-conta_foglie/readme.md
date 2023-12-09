## Esame 12/09/2022 (parte II, esercizio I)

Sia T un albero generale i cui nodi hanno campi: key, left-child e right-sib. Scrivere una funzione efficiente in C o C++ che calcoli il numero di foglie di T e analizzarne la complessità. Specificare quale linguaggio è stato utilizzato.

### Idea

Quando sono sul nodo so già se è una foglia (non ha il left child) oppure no. Scorro l'albero tramite un ciclo while che scorre i fratelli e va in ricorsione su ogni left child. Quando incontro un nodo senza left child incremento il mio contatore e alla fine rendo il risultato che sarà il numero di nodi foglia.

### Codice c++

```c++

//! T(n) = Teta(n) ogni nodo viene visitato esattamente una volta
int conta_foglie(pnodeG u) {
  if (u == nullptr)
    return 0; // albero vuoto non ha foglie
  else {
    pnodeG left = u->left_child;
    int ris = 0;

    // se il nodo non ha un left child allora è una foglia
    if (left == nullptr)
      ris++;

    while (left != nullptr) {
      ris += conta_foglie(left);  // vado in ricorsione sul figlio sinistro
      left = left->right_sibling; // per tutti i fratelli
    }

    return ris;
  }
}
```

#### Analisi complessità

Il tempo di esecuzione risulta essere **T(n)=Teta(n)** in quanto ogni nodo viene visitato esattamente una volta.