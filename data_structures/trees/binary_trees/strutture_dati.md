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

```
Alberi binari

            (a)0
            /   \
          (b)1  (c)2
          / \     \
       3(d) (e)4   (f)5
            /
           (g)6

vettore padri ~ tre campi
                    0   1   2   3   4   5   6 
- info            | a | b | c | d | e | f | g |
- parent          |-1 | 0 | 0 | 1 | 1 | 2 | 4 |
- child_position  |'z'|'l'|'r'|'l'|'r'|'r'|'l'|
```


Contiene i seguenti campi

- parent: vettore di interi contente l'indice della posizione in cui si trova il padre del nodo i
- info: vettore contenente le chiavi dei nodi in posizione i (-1: radice, non ha un padre!)
- child_position: vettore di caratteri per rappresentare la posizione del nodo i ('l': figlio sinistro, 'r': figlio destro, 'z': radice che non ha padre)

```c++
struct vector_parent {
  std::vector<int> parent;
  std::vector<int> info;
  std::vector<char> child_position;

  vector_parent(std::vector<int> p, std::vector<int> i,
                std::vector<char> c_posi)
      : parent{p}, info{i}, child_position{c_posi} {};
};
typedef vector_parent *parr;
```

Funzione c++ per costruire un albero binario dato il vettore dei padri

```c++
pnode crea_albero(parr vet_padri) {
  // numero di nodi
  int n = vet_padri->info.size();
  // crea una mappa vuota
  std::unordered_map<int, pnode> map;
  // crea un nuovo nodo per ogni info del padre e la mette nella mappa
  for (int i = 0; i < n; i++) {
    map[i] = new node(vet_padri->info.at(i));
  }
  // radice
  pnode root = nullptr;
  // scorre tutte le celle
  for (int i = 0; i < n; i++) {
    // indice del padre
    int index_parent = vet_padri->parent.at(i);
    // nodo corrente
    pnode nuovo = map.at(i);
    // posizione del nodo corrente ('l': figlio sinistro, 'r': figlio destro,
    // 'z': radice)
    char child_posi = vet_padri->child_position.at(i);

    // se è -1 allora è la radice
    if (index_parent == -1) {
      root = nuovo;
    } else {
      // prende il padre del nodo corrente, tramite la mappa
      pnode padre = map[index_parent];

      // se è 'l' lo attacca come figlio sinistro
      if (child_posi == 'l')
        padre->left = nuovo;
      else if (child_posi == 'r') // altrimenti come figlio destro
        padre->right = nuovo;
    }
  }
  return root;
}
```

Chiamata alla funzione

```c++
  std::vector<int> info = {/*put your values here*/};
  std::vector<int> parent = {/*put your values here*/};
  std::vector<char> child_posi = {/*put your values here*/};
  parr vet_parent = new vector_parent(parent, info, child_posi);

  T t = new tree();
  t->root = crea_albero(vet_parent);

```