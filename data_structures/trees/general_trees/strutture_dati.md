# Strutture dati utilizzate per rappresentare una albero generale

## Nodo

Contiene i seguenti campi

- key: contenuto informativo del nodo
- left_child: puntatore al figlio più a sinistra
- right_sibling: puntatore al fratello destro

```c++
struct node {
  int key;
  node *left_child;
  node *right_sibling;

  node(int k, node *lc = nullptr, node *rs = nullptr)
      : key{k}, left_child{lc}, right_sibling{rs} {};
};
typedef node *pnodeG;
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

Struttura utilizzata per la costruzione degli alberi generali.

```
Alberi generali

            (a)0
          /   |  \
      (b)1  (c)2 (d)3
      /  \        /
   (e)4 (f)5   (g)6
              /   \
            (h)7 (i)8

vettore padri ~ due campi
                    0   1   2   3   4   5   6   7   8
- info            | a | b | c | d | e | f | g | h | i |
- parent          |-1 | 0 | 0 | 0 | 1 | 1 | 3 | 6 | 6 |

```

Contiene i seguenti campi

- parent: vettore di interi contente l'indice della posizione in cui si trova il padre del nodo i
- info: vettore contenente le chiavi dei nodi in posizione i (-1: radice, non ha un padre!)
- is_left_child: vettore di boolean, true se il nodo è un left child, false se non lo è (quindi per radice e right siblings)

```c++
struct vector_parent {
  std::vector<int> parent;
  std::vector<int> info; 
  std::vector<bool> is_left_child;

  vector_parent(const std::vector<int> &p, const std::vector<int> &i,
                const std::vector<bool> &is_lfc)
      : parent{p}, info{i}, is_left_child{is_lfc} {};
};
typedef vector_parent *parrG;
```

Funzione per creare l'albero (restituisce il nodo radice)

```c++
pnodeG crea_albero(parrG vet_padri) {
  // numero di nodi
  int n = vet_padri->info.size();
  // crea una mappa vuota
  std::unordered_map<int, pnodeG> map;
  // crea un nuovo nodo per ogni info del padre e la mette nella mappa
  for (int i = 0; i < n; i++) {
    map[i] = new node(vet_padri->info.at(i));
  }
  // radice
  pnodeG root = nullptr;

  // figlio sinistro
  pnodeG left_child = nullptr;
  // ultimo fratello
  pnodeG last_sib = nullptr;

  for (int i = 0; i < n; i++) {

    // indice del padre
    int index_parent = vet_padri->parent.at(i);
    // nodo corrente
    pnodeG nuovo = map.at(i);

    // radice!
    if (index_parent == -1) {
      root = nuovo;
    } else {
      // prende il padre del nodo corrente, tramite la mappa
      pnodeG padre = map[index_parent];
      bool is_lfc = vet_padri->is_left_child.at(i);

      // se è un left child
      if (is_lfc) {
        // attacco il left child al padre e me lo salvo come last sibling
        left_child = nuovo;
        last_sib = left_child;
        padre->left_child = left_child;
      } else {
        // altrimenti se è un fratello attacco il nuovo nodo all'ultimo fratello
        // e mando avanti last sib dato che ne ho aggiunto uno
        last_sib->right_sibling = nuovo;
        last_sib = nuovo;
      }
    }
  }
  return root;
}
```

Chiamata alla funzione

```c++
  std::vector<int> info = {/*put your values here*/};
  std::vector<int> parent = {/*put your values here*/};
  std::vector<bool> is_left_child = {/*put your values here*/};

  parrG vet_parent = new vector_parent(parent, info, is_left_child);

  T t = new tree();
  t->root = crea_albero(vet_parent);
```