# Strutture dati per rappresentare un albero binario di ricerca (BST)

## Nodo

Contiene quattro campi:
- key: contenuto informativo del nodo
- p: puntatore al padre
- left: puntatore al figlio sinistro
- right: puntatore al figlio destro

```c++
struct node {
  int key;
  node *p;
  node *left;
  node *right;

  node(int k, node *padre = nullptr, node *sx = nullptr, node *dx = nullptr)
      : key{k}, p{padre}, left{sx}, right{dx} {};
};

typedef node *pnode;
```

## Albero

Contiene un campo root che punta alla radice dell'albero

```c++
struct tree {
  pnode root;

  tree() : root{nullptr} {};
};

typedef tree *T;
```