## Prima prova intermedia 16/01/2018 (esercizio I)

Scrivere una funzione C efficiente, di nome simmetrico, che, dato un albero binario, ritorna 1 se l'albero è speculare, sia dal punto di vista strutturale che nel contenuto dei nodi, altrimenti ritorna 0.

Specificare la chiamata della funzione nel main.<br>
Analizzare la complessità della funzione.

### Cerco di capire cosa mi sta chiedendo

```
      5
     / \
    1   1
~> è simmetrico

      3
     / \
   -1  -1
   /     \
  8       8
~> è simmetrico credo

      3
     / \
   -1   5
   /    /
  8    8
~> no, -1 e 5 non hanno la stessa chiave
~> e anche nell'ultimo livello i nodi non sono specchiati

      3
     / \
    2   2
   /\   /\
  7 -1  7 -1
~> yep
```

### Idea

Quando sono su un nodo, posso vedere se i figli esistono entrambi e hanno stessa chiave.

Poi vado in ricorsione confrontando via via i figli dei figli

### Codice

```c++

bool is_simmetrico(pnode u) {
  if (u == nullptr) {
    return true;
  }

  return is_simmetrico_AUX(u->left, u->right);
}

bool is_simmetrico_AUX(pnode left, pnode right) {
  if (left == nullptr && right == nullptr) {
    return true;
  } else if ((left != nullptr && right == nullptr) ||
             (left == nullptr && right != nullptr)) {
    return false; // non sono speculari se uno esiste e l'altro no!
  } else {
    bool ris;
    if (left->key == right->key)
      ris = true;
    else
      ris = false;

    // vado in ricorsione
    //  a sinistra confronto il left del nodo a sinistra con il right del nodo
    //  destro a destra faccio il contrario
    bool risSX = is_simmetrico_AUX(left->left, right->right);
    bool risDX = is_simmetrico_AUX(left->right, right->left);

    return ris && risSX && risDX;
  }
}
```

#### Analisi complessità

La funzione risulta avere una complessità pari a **T(n) = Teta(n)**, dove n sono il numero di nodi dell'albero, ottenuta risolvendo la seguente ricorrenza tramite [metodo di sostituzione](../../dimostrazioni.md).

```
        --- c                       n = 0
T(n) = |
        --- T(k)+T(n-k-1)+d         n > 0
``` 