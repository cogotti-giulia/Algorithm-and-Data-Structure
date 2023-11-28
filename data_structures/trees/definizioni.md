# Definizioni importanti

## Albero radicato

Un albero radicato è una coppia T=(N, A) dove
- N: insieme finito di nodi fra cui si distingue un nodo r (radice!)
- A: insieme di archi ~ [A c NxN: insieme di coppie di nodi (archi)]

ogni nodo v != r ha esattamente un padre tale che (u, v) appartiene ad A

**GRADO:** numero di figli di un nodo<br>
**FOGLIA:** un nodo senza figli<br>
**NODO INTERNO:** un nodo non foglia<br>
**FRATELLO:** se due nodi hanno lo stesso padre

<br>

**CAMMINO** da un nodo u a un nodo u\' in T è una _sequenza di nodi_ \<n0, n1, ..., nk> tale che
- u = n0
- u' = nk
- \<n_i-1, n_i> appartiene ad A per ogni i=1,..,k

**LUNGHEZZA CAMMINO:** numero di archi nel cammino (o numero di nodi che formano il cammino meno uno)

> esiste _sempre_ un cammino di lunghezza **zero** che va da u a se stesso!

<br>

```
   (r)
    :
    :
   (y) <~ antenato di x
    :
    :
   (x) <~ discendente di y
```

Un qualsiasi nodo **y** in un cammino da r a _x_ è **ANTENATO** di _x_.<br>
Se _y_ è _antenato_ di x allora **x** è **DISCENDENTE** di _y_. 

Se _y_ è _antenato_ di _x_ e **x!=y** allora y è antenato proprio di x e x è discendente proprio di y

> ogni nodo è _antenato_ e _discendente_ di **se stesso**!

<br>

**SOTTOALBERO _con radice in x:_** albero indotto dai _discendenti di x con radice in x

**PROFONDITÀ _di un nodo x:_** la _lunghezza del cammino_ dalla **radice ad x**<br>
**LIVELLO ALBERO:** costituito da tutti i nodi che si trovano alla _stessa profondità_

```
    (r)         
    / \   <~ cammino da r a x
  ..   ..
        |
       (x)
       / \ 
      .. ..
``` 

**ALTEZZA _di un nodo x:_** la lunghezza del _più lungo cammino_ che va **da x a una foglia**<br>
**ALTEZZA ALBERO:** altezza della radice

```
      ...
      / \
    (x)
    / \
  (f) ... 
       /
      (f) <~ cammino più lungo
             da x a f
```