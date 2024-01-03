## Esame 15/05/2012 (parte II, esercizio I)

Un nodo di un albero binario è detto pari se il numero di foglie del sottoalbero di cui è radice è pari.

1. Progettare un algoritmo efficiente che dato un albero binario restituisca il numero di nodi pari.
2. Discutere brevemente la complessità della soluzione trovata.

La rappresentazione dell’albero binario utilizza esclusivamente i campi left, right e key.

### Idea

Faccio un visita in post order perché le informazioni mi arrivano dalle foglie. Conto il numero di foglie dei sottoalberi sinistro e destro, se questo numero è pari allora ho un nodo che rispetta la mia condizione e vado avanti per tutti i nodi.

### Codice c++

```c++

int nodi_pari(pnode u) {
  int foglie = 0;
  return nodi_pari_AUX(u, &foglie);
}

int nodi_pari_AUX(pnode u, int *foglie) {
  if (u == nullptr) {
    *foglie = 0;
    return 0;
  } else {
    int risSX = nodi_pari_AUX(u->left, foglie);
    int risDX = nodi_pari_AUX(u->right, foglie);

    if (u->left == nullptr && u->right == nullptr) {
      *foglie += 1;
      return 0; // non lo so, non ha foglie la foglia
    } else {

      if ((*foglie) % 2 == 0)
        return risSX + risDX + 1;
      else
        return risSX + risDX;
    }
  }
}
```

#### Analisi complessità

Si ottiene la seguente ricorrenza

```
        --- c                    n = 0
T(n) = |
        --- T(k) + T(n-k-1) + d  n > 0
```

che, se risolta tramite [metodo di sostituzione](../../dimostrazioni.md) permette di concludere che **T(n) = Teta(n)**