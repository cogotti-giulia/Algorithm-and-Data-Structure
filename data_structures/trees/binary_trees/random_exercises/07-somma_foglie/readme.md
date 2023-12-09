## Esercizio

Si consideri un albero binario T, avente struttura arbitraria, in cui ciascun nodo t contenga un numero reale t.key;

1. Scrivere un algoritmo efficiente che, dato in input T, restituisca la somma dei valori contenuti in tutte le foglie; se l'albero è vuoto l'algoritmo restituisce zero.
2. Analizzare la complessità.

```
            9
          /  \
         1    -8
        / \     \
       4   3     10
      / \        / \
     -2  1      5   2

~> somma è 9
```

Effettuo una visita in pre order perché quando mi trovo nel nodo so già se è una foglia oppure no. Se è una foglia incremento la somma del valore del nodo corrente.

### Implementazione

```pseudocode
somma_foglie(T)
  return somma_foglia_aux(T.root)

somma_foglie_aux(u)
  if(u == nullptr)
    return 0;
  else
    if(u.left == NIL and u.right == NIL)
      return sum + u.key;
    else
      return somma_foglie_aux(u.left) + somma_foglie_aux(u.right)
```

```c++
int somma_foglie(T tree) {
  int sum = 0;
  somma_foglie_aux(tree->root, &sum);
  return sum;
}

int somma_foglie_aux(pnode u, int *sum) {
  if (u == nullptr) {
    *sum = 0;
    return 0;
  } else {

    // u è una foglia
    if (u->left == nullptr && u->right == nullptr) {
      *sum = *sum + u->key;
    } else {
      int sumSX = *sum, sumDX = *sum;

      somma_foglie_aux(u->left, &sumSX);
      somma_foglie_aux(u->right, &sumDX);
      *sum = sumSX + sumDX;
    }

    return *sum;
  }
}
```

```c++
/*versione minimale*/
int somma_foglie_minimal(T tree){
  return somma_foglie_minimal_aux(tree->root);
}

int somma_foglie_minimal_aux(pnode u) {
  if (u == nullptr) {
    return 0;
  } else {
    // u è una foglia
    if (u->left == nullptr && u->right == nullptr)
      return u->key;
    else
      return somma_foglie_minimal_aux(u->left) + somma_foglie_minimal_aux(u->right);
  }
}
```

#### Analisi complessità

La visita del'albero richiede un tempo pari a **T(n) = Teta(n)** in quanto ogni nodo viene visitato esattamente una volta.

La ricorrenza risulta essere

```
        --- c                     se n = 0
T(n) = |
        --- T(k) + T(n-k-1) + d   se n > 0

dove 
k: nodi visitati nel sotto albero sinistro
n-k-1: nodi visitato nel sotto albero destro (-1 è la radice)
```

Si risolve tramite il metodo di sostituzione. 

Intuisco che il costo sia lineare quindi T(n) = an + b, tramite induzione dimostro che ho ragione.

_dimostrazione_<br>

_caso base_
n=0<br>
T(0) = b<br>
[per definizione] T(0) = c, ma allora **b = c**


_passo induttivo_<br>
Assumo che per un m < n valga che T(m) = am+b e dimostro che allora vale anche per n.

[per definizione] T(n) = T(k) + T(n-k+1) + d <br>
[dato che k < m e (n-k-1) < m posso applicare l'ipotesi induttiva]<br>
[per ip. induttiva] T(n) = ak+b + a(n-k-1)+b + d = 2b +an -a +d

mi chiedo se è vero che T(n) = 2b +an -a +d ???=??? an+b<br>
-a +b +d = 0 ~> a = b+d<br>
[per il caso base] so che b = c, ma allora a = c+d

quindi T(n) = (c+d)n + c e concludo che **T(n) = Teta(n)**

