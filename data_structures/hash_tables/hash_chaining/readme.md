# Tabelle Hash con risoluzione delle collisioni tramite _concatenamento_

La cella i contiene un _puntatore_ alla testa della lista di **tutti** gli elementi che sono mappati in i (tramite la funzione **hash**). Se non ci sono elementi è presente il valore _nil_.

```
    +-------+
  0 |       | ~> [k2| ] <~> [k9| ] <~> ^
    +-------+     h(k2) = h(k9)
    |  ...  |
    +-------+
  i |       | ~> [k1| ] <~> [k3| ] <~> [k5| ] <~> ^
    +-------+     h(k1) = h(k3) = h(k5)
    |  ...  |
    +-------+
m-1 |  NIL  |
    +-------+

```

## Operazioni

### Insert

```pseudocode
chained_hash_insert(T, x)
  inserisce x in testa alla lista T[h(x.key)]
```

Il tempo di esecuzione è **costante** assumendo che
- il calcolo della funzione hash sia costante
- l'elemento da inserire non sia presente (altrimenti corrisponderebbe al tempo di una ricerca, quindi O(n))

### Search

```pseudocode
chained_hash_search(T, k)
  ricerca un elemento con chiave k nella lista T(h(k))
```

Il tempo di esecuzione è **proporzionale** alla _lunghezza_ della lista contenuta in **h(h)**


> ATTENZIONE! Nel caso peggiore in cui **tutte** le chiavi sono mappate nella stessa cella e assumendo che la lunghezza della corrispondente lista sia _n_, allora il tempo di ricerca è pari ad **Teta(n)** più il tempo per calcolare la funzione hash!

> Il caso medio dipende dal modo in cui la funzione hash _distribuisce_ mediamente le chiavi fra le **m** celle!

### Delete

```pseudocode
chained_hash_delete(T, x) /*x è il puntatore all'elemento*/
  cancella l'elemento x dalla lista T(h(x.key))
```

Se la lista è doppiamente concatenata il tempo di esecuzione è **costante**.


## Hashing uniforme semplice

L'ipotesi di hashing uniforme semplice afferma che qualsiasi elemento ha la _stessa probabilità_ di essere mandato in una delle qualsiasi delle _m_ celle **indipendentemente** dalle celle in cui sono mandati gli altri elementi.

```
Per ogni i in [0...m-1], la probabilità che una chiave qualsiasi finisca nella cella i è
          1
  Q[i] = ---
          m
```

### Fattore di carico

Il fattore di carico di una _tabella hash_ con **n chiavi** ed **m celle** è 

```
            n
    alfa = ---
            m
```

- alfa < 1 : ci sono meno chiavi rispetto alla dimensione della tabella
- alfa = 1 : tante chiavi quante le celle
- alfa > 1 : potrebbe accadere in quanto le chiavi stanno in strutture esterne!

```
                  [lunghezza lista]
    +-------+
  0 |       | ~> ...   n_0
    +-------+     
    |  ...  |
    +-------+
  j |       | ~> ...   n_j
    +-------+     
    |  ...  |
    +-------+
m-1 |       | ~> ...   n_m-1
    +-------+
```

La lunghezza della lista nella cella j è T[j] = n<sub>j</sub>. 

Allora posso calcolarmi il valore medio di n<sub>j</sub>: (n<sub>0</sub> + ... + n<sub>m-1</sub>) / (m) = n / m = alfa

> Quindi **alfa** è il _numero medio di elementi memorizzati in una lista_.

Assumendo che la funzione hash sia calcolata in tempo costante si ha che la **ricerca** di un elemento con chiave k dipende dalla lunghezza **n<sub>h(k)</sub>** della lista _T[h(k)]_.

#### Tempo ricerca considerando il fattore di carico

In una tabella hash in cui le collisioni sono risolte con il _concatenamento_, una **ricerca senza successo**, richiede un tempo **Teta(1 + alfa)** nel caso medio e sotto _ipotesi di hashing uniforme semplice_.

1. calcolo j = h(k) ~> Teta(1)
2. accedo a T[j]    ~> Teta(1)
3. scorro la lista T[j] ~> Teta(alfa) in media e considerando che _devo_ scorrerla tutta essendo senza successo

In una tabella hash in cui le collisioni sono risolte con il _concatenamento_, una **ricerca con successo** richiede un tempo **Teta(1 + alfa)** nel caso medio e sotto _ipotesi di hashing uniforme semplice_.

1. calcolo j = h(k) ~> Teta(1)
2. accedo a T[j]    ~> Teta(1)
3. scorro la lista T[j] ~> Teta(alfa / 2) perché mediamente lo trovo a metà

> ATTENZIONE! se n = O(m) allora alfa = n/m = O(m)/m = O(1), operazioni svolte _mediamente_ in tempo costante!

