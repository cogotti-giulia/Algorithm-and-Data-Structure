## Esame 13/06/2013 (parte II, esercizio I)

Dato un albero binario, i cui nodi contengono chiavi intere, progettare un algoritmo efficiente che stabilisca se le chiavi nei nodi soddisfano la proprietà del max-heap, e analizzarne la complessità.

Per l’esame da 12 CFU, deve essere fornita una funzione C e si deve dichiarare il tipo Node utilizzato per rappresentare l’albero binario. Per l’esame da 9 CFU, è sufficiente specificare lo pseudocodice.

### Idea

Mi sta chiedendo di verificare la proprietà di max heap (non di heap!), quindi per ogni nodo i diverso dalla radice deve valere che il padre di i ha chiave maggiore o uguale a quella del nodo i.
Quindi faccio un visita in pre order perché quando sono sul nodo posso già sapere se la proprietà è violata oppure no. Se non è violata vado in ricorsione sui sottoalberi sinistro e destro.

### Codice c++

Tipo nodo

```c++
struct node {
  int key;
  node *left;
  node *right;

  node(int k, node *sx = nullptr, node *dx = nullptr)
      : key{k}, left{sx}, right{dx} {};
};
typedef node *pnode;
```

Funzione

```c++
bool check_proprieta_max_heap(pnode u) {
  if (u == nullptr)
    return true;
  else {
    if ((u->left != nullptr && u->left->key > u->key) ||
        (u->right != nullptr && u->right->key > u->key))
      return false;

    bool risSX = check_proprieta_max_heap(u->left);
    bool risDX = check_proprieta_max_heap(u->right);

    return risSX && risDX;
  }
}
```


#### Analisi complessità

Dal codice si ottiene la seguente ricorrenza che, se risolta tramite [metodo di sostituzione](../../dimostrazioni.md), permette di concludere che il tempo di esecuzione è **T(n) = Teta(n)**

```
        --- c                   n = 0
T(n) = |
        --- T(k)+T(n-k-1)+d     n > 0

dove
k: nodi visitati in un sottoalbero
n-k-1: nodi visitati nell'altro sottoalbero (-1 per la radice)
d: costo alla radice
```