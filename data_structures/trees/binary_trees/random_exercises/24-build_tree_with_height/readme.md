## Esame 17/05/2016 (parte II, esercizio I)

Dato un albero binario T

1. progettare una funzione efficiente che restituisca una copia T’ di T, che contenga anche, in ogni nodo, la differenza fra l’altezza del suo sottoalbero sinistro e quella del suo sottoalbero destro.
2. Fornire la chiamata della funzione dal programma principale.
3. Modificare in modo adeguato il tipo dell’albero T per ottenere il tipo dell’albero T’.
4. Analizzare la complessità di tale funzione.

### Idea

Utilizzo una funzione ausiliaria che calcola ricorsivamente l'[altezza](../../../definizioni.md) (visita post order) di tutti i nodi dell'albero T e per ogni nodo crea un nuovo nodo di T' e ricorsivamente attacca i figli sx e dx. L'altezza la ricavo come il massimo tra le altezze dei sottoalberi sinistro e destro più uno perché devo considerare l'arco che collega il nodo ai sottoalberi. L'altezza di un albero vuoto è -1!!!

### Codice c++

```c++
T_h build_tree_with_height(T t) {
  T_h tree = new tree_h();
  int h = -1; // altezza albero vuoto
  tree->root = build_tree_with_height_AUX(t->root, &h);
  return tree;
}

pnode_h build_tree_with_height_AUX(pnode u, int *h) {
  if (u == nullptr) {
    *h = -1;
    return nullptr;
  } else {
    pnode_h nuovo = new node_h(u->key);
    int hSX, hDX;
    nuovo->left = build_tree_with_height_AUX(u->left, &hSX);
    nuovo->right = build_tree_with_height_AUX(u->right, &hDX);
    nuovo->height = std::max(hSX, hDX) + 1;
    *h = std::max(hSX, hDX) + 1;

    return nuovo;
  }
}
```

Strutture dati per il nuovo albero

```c++
struct node_h {
  int key;
  int height;
  node_h *left;
  node_h *right;

  node_h(int k, int h = -1, node_h *sx = nullptr, node_h *dx = nullptr)
      : key{k}, height{h}, left{sx}, right{dx} {};
};
typedef node_h *pnode_h;

struct tree_h {
  node_h *root;

  tree_h() : root{nullptr} {};
};
typedef tree_h *T_h;
```

#### Analisi complessità

Si ottiene la seguente ricorrenza che, se risolta tramite [metodo di sostituzione](../../dimostrazioni.md), permette di concludere che **T(n) = Teta(n)**.

```
        --- c                     n = 0
T(n) = |
        --- T(k) + T(n-k-1) + d   n > 0

dove
k: nodi in un sottoalbero
n-k-1: nodi nell'altro sottoalbero
d: costo alla radice
```