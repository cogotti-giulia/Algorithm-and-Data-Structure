## Esame 30/06/2021 (esercizio I, parte II)

Dato un albero binario i cui nodi contengono interi, si vuole aggiungere ad ogni foglia un figlio contenente la somma dei valori che appaiono nel cammino dalla radice a tale foglia. Se la somma di tali valori è positiva sarà aggiunto come figlio sinistro, altrimenti come figlio destro.

- Scrivere una procedura efficiente in C aggiungiFigli(Node u) che dato in input la radice u di un albero T aggiunge alle foglie i figli come sopra specificato.
- Valutarne la complessità, indicando eventuali relazioni di ricorrenza.
- Scrivere il tipo Node in C.

### Codice c++

```c++

void aggiungi_figli(pnode u) {
  int sumP = 0;
  // sumP tiene traccia della somma lungo il percorso
  aggiungi_figli_aux(u, &sumP);
}

void aggiungi_figli_aux(pnode u, int *sumP) {
  // se l'albero è vuoto non ho nodi a cui aggiungere figli
  if (u != nullptr) {
    // somma mentre scendo nell'albero
    int sumPK = *sumP + u->key;

    aggiungi_figli_aux(u->left, &sumPK);
    aggiungi_figli_aux(u->right, &sumPK);

    // quando arrivo a una foglia
    if (u->left == nullptr && u->right == nullptr) {
      // la somma nel percorso viene incrementata del valore della chiave della
      // foglia, creo un nuovo nodo con chiave la somma del percorso dalla
      // radice alla foglia, se è maggiore di zero attacco a sinistra altrimenti
      // a destra
      int value = *sumP + u->key;
      pnode nuovo = new node(value);
      if (*sumP >= 0)
        u->left = nuovo;
      else
        u->right = nuovo;
    }
  }
}
```

#### Analisi complessità

La funzione ha un costo di **T(n) = Teta(n)** in quanto ogni nodo viene visitato esattamente una volta.

Ricorrenza ottenuta risolvibile tramite _metodo di sostituzione_

```
        --- c                   n = 0
T(n) = |
        --- T(k)+T(k-n-1)+d     n > 0
```