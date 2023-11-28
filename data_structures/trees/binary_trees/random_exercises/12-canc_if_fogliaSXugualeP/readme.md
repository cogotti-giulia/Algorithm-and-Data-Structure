## Esame 08/09/2014 (esercizio I, parte II)

Dato un albero binario, scrivere un procedura efficiente che cancelli il figlio sinistro di ogni nodo se è una foglia e contiene la stessa chiave del nodo padre. Calcolare la complessità al caso pessimo della funzione indicando la corrispondente relazione di ricorrenza. La rappresentazione dell’albero binario utilizza esclusivamente i campi left, right e key e il prototipo della procedura è: void cancella(Node u)

### Idea

Effettuo una visita in post order ma, ad ogni chiamata ai sottoalberi sx e dx tengo traccia del padre del nodo, quindi quando arrivo ad un nodo foglia posso verificare se la foglia è il figlio sinistro del padre e se le loro chiavi sono uguali (ed eventualmente cancellarlo se le condizioni sono rispettate).

### Codice c++

```c++
void cancella(pnode u) {
  cancella_aux(u, nullptr); // radice, non ha un padre!
}

void cancella_aux(pnode u, pnode padre) {
  if (u != nullptr) {
    // il nodo corrente è il padre
    cancella_aux(u->left, u);
    cancella_aux(u->right, u);

    if (u->left == nullptr && u->right == nullptr) // è una foglia
      if (padre->left == u && padre->key == u->key)
        // è figlio sinistro con chiave uguale al padre
        padre->left = nullptr;
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
