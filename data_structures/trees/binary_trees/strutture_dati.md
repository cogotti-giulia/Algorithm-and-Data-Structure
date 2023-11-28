# Strutture dati utilizzate per rappresentare un albero binario

## Nodo 

Contiene i seguenti campi

- key: contenuto informativo del nodo
- left: puntatore al figlio sinistro
- right: puntatore al figlio destro

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

## Albero

Contiene i seguenti campi

- root: punta alla radice dell'albero

```c++
struct tree {
  node *root;

  tree() : root{nullptr} {};
};
typedef tree *T;
```

## Vettore padri

Struttura utilizzata per la costruzione degli alberi binari. 
Contiene i seguenti campi

- parent: vettore di interi contente l'indice della posizione in cui si trova il padre del nodo i
- info: vettore contenente le chiavi dei nodi in posizione i (-1: radice, non ha un padre!)
- child_position: vettore di caratteri per rappresentare la posizione del nodo i ('l': figlio sinistro, 'r': figlio destro, 'x': radice che non ha padre)
- size: dimensione dei vettori (numero di nodi dell'albero)

```c++
struct vector_parent {
  int *parent;
  int *info;
  char *child_position;
  int size;

  vector_parent(int *p, int *i, char *c_posi, int s) : parent{p}, info{i}, child_position{c_posi}, size{s} {};
};
typedef vector_parent *parr;
```