## Prima prova intermedia 25/01/2019 (esercizio I)

1. Dato un albero binario T, definire l’altezza di un nodo v.

> L'altezza di un nodo v è la lunghezza del più lungo cammino che scende da v a una foglia

2. Sia T un albero binario i cui nodi x hanno campi left, right e key. Scrivere una funzione in C efficiente altezzaNodi(u, k) che riceve in input la radice u di un albero binario T e un numero naturale k e restituisce il numero di nodi che hanno altezza k.
3. Analizzare la complessità della funzione, indicando eventuali relazioni di ricorrenza.

Non si possono utilizzare strutture dati ausiliarie

### Idea!

Mi calcolo le altezze dei sottoalberi sinistro e destro, vedo l'altezza maggiore, se essa corrisponde a k allora incremento il conteggio dei nodi che hanno altezza k.

Mi serve una funzione ausiliaria per trascinarmi dietro l'altezza dei sottoalberi

```
      4
    /   \
   3     -1
  /      / \
 -2     5   10   ^
  \        /  \  | k = 2 = max => u=10 lo conto
   7      5    1 | hsx = 2 <~ max!
           \     | hdx = 1
            3    v

#nodi altezza k=2 ~> 2 (u=10, u=3)
#nodi altezza k=4 ~> 1 (u=4)
```

### Codice funzione

```c++

int altezza_nodi(pnode r, int k) {
  int h = -1;
  return altezza_nodi_AUX(r, k, &h);
}

int altezza_nodi_AUX(pnode u, int k, int *h) {
  if (u == nullptr) {
    *h = -1;
    return 0;
  } else {
    int hSX, hDX;
    int risSX, risDX;

    risSX = altezza_nodi_AUX(u->left, k, &hSX);
    risDX = altezza_nodi_AUX(u->right, k, &hDX);

    *h = std::max(hSX, hDX) + 1;

    if (*h == k)
      return risSX + risDX + 1;
    else
      return risSX + risDX;
  }
}
```

#### Analisi complessità

Il tempo di esecuzione risulta essere **T(n) = Teta(n)** ottenuto risolvendo la seguente ricorrenza tramite [metodo di sostituzione](../../dimostrazioni.md)

```
        --- c                           n=0
T(n) = |
        ---T(m)+T(n-m-1)+d              n>0

dove
m: nodi presenti in un sottoalbero
n-m-1: nodi nell'altro sottoalbero
d: costo alla radice
```
