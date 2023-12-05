## Prima prova intermedia 28/01/2013 (esercizio I)

Dare la definizione di albero binario completo.

> Un albero binario si dice completo se ogni nodo interno ha esattamente grado 2 e tutte le foglie si trovano alla stessa profondità

Scrivere in C un programma efficiente per stabilire se un albero binario è completo e calcolarne la complessità al caso pessimo indicando, e risolvendo, la corrispondente relazione di ricorrenza.

### Idea

Niente, applico la definizione di albero binario completo.

Quando arrivo a una foglia (se è la prima mi salvo la sua profondità), controllo la sua profondità e se è diversa da quella delle altre foglie rendo false.
Se invece mi trovo su un nodo interno che ha un solo figlio (sinistro o destro) allora anche qua la risposta è false perché il grado non risulta essere 2.

### Codice c++

```c++
bool is_binario_completo(pnode r) {
  int pf = -1; //non so se ho nodi, la profondità di un albero vuoto è -1
  return is_binario_completo_AUX(r, 0, &pf);
}

bool is_binario_completo_AUX(pnode u, int profondita, int *prof_foglia) {
  if (u == nullptr) {
    return true; // albero vuoto è binario completo
  } else {
    bool risSX, risDX;
    risSX = is_binario_completo_AUX(u->left, profondita + 1, prof_foglia);
    risDX = is_binario_completo_AUX(u->right, profondita + 1, prof_foglia);

    if (u->left == nullptr && u->right == nullptr) { // sono su una foglia
      if (*prof_foglia == -1) // prima foglia, setto la profondità
        *prof_foglia = profondita;

      // le foglie devono essere tutte alla stessa profondita
      if (*prof_foglia != profondita)
        return false;
    }

    // un solo figlio, grado != 2
    if ((u->left != nullptr && u->right == nullptr) ||
        (u->left == nullptr && u->right != nullptr))
      return false;

    return risSX && risDX;
  }
}
```

#### Analisi complessità

Il tempo di esecuzione risulta essere **T(n) = Teta(n)** ottenuto risolvendo la seguente ricorrenza tramite [metodo di sostituzione](../../dimostrazioni.md)

```
        --- c                         n=0
T(n) = |
        --- T(k) + T(n-k-1) + d       n>0
dove
k: nodi in un sottoalbero
n-k-1: nodi nell'altro sottoalbero
d: costo alla radice
```