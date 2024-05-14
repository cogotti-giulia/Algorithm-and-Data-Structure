# Grafi

Un grafo è una relazione _binaria_ tra due vertici.

## Grafo (orientato)

Coppia **G=(V, E)** dove _V={1,...,n} insieme di nodi/vertici_ e _E sottoinsieme VxV_

```
G = ({1, 2, 3, 4}, {(1,2), (2,1), (1,3), (3,4), (3,3), (4,2)})

(3,3) rappresenta un cappio/self-loop
```

## Grafo (NON orientato)

Relazione riflessiva _aRb => bRa_. Quindi non possono essere presenti i cappi. Un grafo G=(V, E) è non orientato se vale la seguente proprietà: esiste un arco (u, v) nell'insieme E degli archi se e solo se esiste anche (v, u).

> **G=(V, E) se (u, v) in E <=> (v, u) in E**

```
G = (V, E)
V = {1, 2, 3, 4}
E = {{1,2}, {1,3}, {2,3}, {3,4}}
```

## Proprietà

- G grafo _orientato_ con |V| = n vertici, allora il massimo numero di archi: **E = VxV =n<sup>2</sup>**
- G grado _NON orientato_ con |V| = n vertici, allora il massimo numero di archi: **E=(n 2)=n(n-1)/2=n<sup>2</sup>**
- Due vertici sono **adiacenti** se esiste un arco che li collega
- L'arco (u,v) è **incidente** ai vertici u e v

- Grafo _sparso_: (pochi archi) numero di archi << n<sup>2</sup> (~n)
- Grafo _denso_: (molto archi) numero di archi ~n<sup>2</sup>

```
( u ) ----------- ( v )

u e v sono vertici adiacenti
l'arco (u,v) è incidente ai vertici u e v
```

## Come rappresentare i grafi (strutture dati)

### (i) Lista di adiacenza