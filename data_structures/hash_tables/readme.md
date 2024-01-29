# Tabelle hash

## Tabelle hash ad accesso/indirizzamento diretto

```
                                 T[0...w-1]
 U__________________               ______
  |                 |           0 |______|
  |                 |      +--> 1 |______| ~> [dati satellite]
  |     K ______    |      |    2 |______|
  |      |   1--|----------+      | ...  |
  |      | 7----|---|--+          |______|
  |      |______|   |  |-------> 7|______|
  |_________________|             | ...  |
                               w-1|______|  

```

- U possibili valori U = {0, 1, .., w-1}
- K chiavi effettive |K| = n < |U|

Idea: utilizzare un array T[0 ... w-1] dove
- se esiste x con chiave k allora T[k] = puntatore a x
- se _non_ esiste x con chiave k allora T[k] = NIL

### Operazioni

```pseudocode
direct_address_search(array T, chiave k)
  return T[k]

direct_address_insert(array T, elem x)
  T[x.key] = x

direct_address_delete(array T, elem x)
  T[x.key] = NIL
```

Il tempo di esecuzione è _costante_ per tutte le operazioni, però **la tabella è proporzionale** a **w** e _NON_ al numero di elementi effettivamente memorizzati! (Inoltre le chiavi devono essere per forza interi in {0...w-1})

## Tabelle hash

Per memorizzare un elemento con chiave _k_, invece di mapparlo nella cella k, viene utilizzata una **funzione h** che memorizza l'elemento nella cella ottenuta applicando la funzione *h(k)**.

```
    U 
  +-----------------+              
  |                 |           0 |¯¯¯¯¯¯|
  |     K           |             | ...  |
  |      +------+   |  h(K1)      |______|
  |      |   .k1| ~~~~~~~~~~~~~> i|  k1  |
  |      |.k2   |   |             |¯¯¯¯¯¯|
  |      +------+   |             | ...  |
  +-----------------+          m-1|______|  

```

- **h** funzione hash
- h : U -> {0, 1, ..., m-1}
- _m_ dimensione della tabella hash, molto più piccolo di |U|
- l'elemento con _chiave k_ è mappato nella cella **h(k)**

> Voglio cercare di ridurre gli indici della mia tabella tramite l'hashing!

## Problema delle collisioni

Una collisione si verifica quando un elemento è mappato in una cella già occupata:
- può accadere quando |U| > m
- accade _sicuramente_ quando |K| > m

Vengono gestite tramite due tecniche:
- [concatenamento](../hash_tables/hash_chaining/readme.md)
- [indirizzamento aperto](../hash_tables/hash_open_addressing/readme.md)

## Costruzione funzioni hash

Nel caso fortunato in cui le chiavi siano _numeri reali k_ casuali e distribuiti in modo **indipendente** e uniforme nell'intervallo _0 <= k < 1_ allora

```
h(k) = | k * m | 
       ¯¯     ¯¯
```

soddisfa la condizione di hashing uniforme semplice!

> Si assume che le chiavi siano numeri **naturali**! (Se non dovessero essere numeri naturali allora si trasformano, vedi esempio sotto)

```
chiave CLRS

ASCII
- C = 67
- L = 76
- R = 82
- S = 83

CLRS = 67 * 128^3 + 76 * 128^2 + 82 * 128^1 + 83 * 128^0
```

### Metodo della divisione

>  h(k) = k mod **m** _(resto della divisione tra k ed m)_

```
esempio:
m = 19
k = 91

h(k) = 91 mod 19 = 15
```

È semplice da realizzare ma bisogna stare attenti alla _scelta di m_:

- evitare le potenza di 2 (2<sup>p</sup>)
  ```
  se m = 2^p allora h(k) rappresenta i p bit meno significativi di k
  sto prendendo solo un pezzo della chiave, non tutta
  ```
- evitare le stringhe interpretate nella base 2<sup>p</sup>
  ```
  colpa delle permutazioni
  h(amor) = h(roma)
  ```
- **numero primo** non troppo vicino a una potenza di 2 o 10 (funziona bene)
  ```
  n = 2000
  sapendo che posso tollerare 3 collisioni (in media ho liste da 3 elementi)

  n/3 = 666,66667 

  allora scelgo m = 701, numero primo vicino a quel valore e lontano dalle potenze di 2 o 10
  ```



### Metodo della moltiplicazione


>  h(k) = floor(**m** \* _k_) _(parte intera inferiore di m \* k, dove k in [0, 1))_

Data una chiave intera k in U, la trasformo in un numero in [0, 1):
1. fisso una costante **A** tale che 0 < A < 1
2. calcolo k \* A
3. estraggo la parte frazionaria (k \* A) mod 1 in [0, 1)
4. **h(k) = floor(m \* (_(k * A) mod 1)_)**

In questo modo **m** non è più un valore critico e funziona bene per tutti i _valori di A_ (specialmente A = (sqrt(5)-1)/2 = 0.6180, inverso del rapporto aureo).


Per _semplificare_ il calcolo della funzione hash:

- w = lunghezza di una parola di memoria
  ```
   ______________
  |              | w
   ¯¯¯¯¯¯¯¯¯¯¯¯¯¯
  ```
- k = entra in una singola parola di memoria
  ```
   ______________
  |              | k
   ¯¯¯¯¯¯¯¯¯¯¯¯¯¯
  ```
- scelgo un intero 0 < q < 2<sup>w</sup>
- scelgo **m = 2<sup>p</sup>**
- scelgo _A = q / 2<sup>w</sup>_

Quindi

1. calcolo k \* A = (k \* q) / 2<sup>w</sup>_
    ```
    ______________ ______________
    |       r1     ,      r0      | k * q = r1*2^w + r0
    ¯¯¯¯¯¯¯¯¯¯¯¯¯¯ ¯¯¯¯¯¯¯¯¯¯¯¯¯¯
    il 2^w mette la virgola tra le due parole di memoria
    ```
2. h(k) = floor(**m** \* (_(k * A) mod 1)_) = floor(**2<sup>p</sup>** \* (_(k * A) mod 1)_) = _p bit più significativi della parola meno significativa di k\*q_
    ```
    2^p sposta la virgola di p posizioni
    ______________ _____ _________
    |       r1     ,  p  ,  r0      | k * q
    ¯¯¯¯¯¯¯¯¯¯¯¯¯¯ ¯¯¯¯¯ ¯¯¯¯¯¯¯¯¯
                    <--->
                funzione hash!
    ```

### Hashing universale

Insieme **H** di funzioni hash opportunamente costruito. Il programma sceglie all'inizio una funzione hash _h in H_ in modo casuale.

> Prestazioni molto buone!

## Metodi di scansione/ispezione (voglio definire h(k, i))

> Ipotesi di **hashing uniforme**: ogni chiave ha la _stessa probabilità_ di avere come _sequenza di ispezione_ una delle **m!** permutazioni di <0, 1, ..., m-1>

h(k, 0) si distribuisce uniformemente sulle m celle<br>
h(k, 1) si distribuisce uniformemente sulle m-1 celle<br>
h(k, 2) si distribuisce uniformemente sulle m-2 celle<br>
...<br>
~> circa un hashing uniforme semplice ad ogni iterazione

### Ispezione lineare

Utilizza una funzione ausiliaria _h' : U -> {0, 1, ..., m-1}_.

> Per i = 0, ..., m-1 : **h(k, i) = (_h'(k)_ + i) mod m**

Quando si arriva alla fine della tabella, riparte dall'inizio.

- È _facile_ da implementare
- Problema dell'**addensamento/agglomerazione primaria**: si formano lunghe file di celle occupate che aumentano il tempo di ricerca.
  ```            _____
             ^  |     |
    i celle  |  |     |
    occupate |  |     |
             v  |_____|
                |_____|

    una cella ha probabilità P = 1/m di essere occupata
    la probabilità di occupare la cella i+1 è (i+1)/m

    ma allora le file tendono a diventare sempre più lunghe :(
    ```

    > Ci sono soltanto **m** sequenze distinte di ispezioni per ogni chiave (una volta che si fissa il punto di partenza, esse sono univocamente determinate), quindi si formano tante collisioni che ovviamente sono un problema.

#### Esempio!

Funzione ausiliaria: h'(k) = k mod 13<br>
Voglio inserire le chiavi: < 69, 4, 31, 43>

> L'ordine di inserimento è importante! Non posso cambiarlo!

Scansione lineare: h(k, i) = (k mod 13 + i) mod 13

```
   _________
 0|_________|   
 1|_________|  
 2|_________|  
 3|_________|  
 4|_________|  
 5|_________|  
 6|_________|  
 7|_________|  
 8|_________|  
 9|_________|  
10|_________|  
11|_________|  
12|_________|  
13|_________|  
  
```

a. h(69, 0) = 69 mod 13 = 4

```
   _________
 0|_________|   
 1|_________|  
 2|_________|  
 3|_________|  
 4|___69____| a
 5|_________|  
 6|_________|  
 7|_________|  
 8|_________|  
 9|_________|  
10|_________|  
11|_________|  
12|_________|  
13|_________|  
  
```

b. h(4, 0) = 4 mod 13 = 4 **collisione**<br>
~> scansione lineare _h(k, i) = (k mod 13 + i) mod 13_<br>
b1. h(4, 1) = 4 + 1 = 5

```
   _________
 0|_________|   
 1|_________|  
 2|_________|  
 3|_________|  
 4|___69____| a b
 5|____4____|   b1
 6|_________|  
 7|_________|  
 8|_________|  
 9|_________|  
10|_________|  
11|_________|  
12|_________|  
13|_________|  
  
```

c. h(31, 0) = 31 mod 13 = 5 **collisione**<br>
~> scansione lineare _h(k, i) = (k mod 13 + i) mod 13_<br>
c1. h(31, 1) = 5 + 1 = 6

```
   _________
 0|_________|   
 1|_________|  
 2|_________|  
 3|_________|  
 4|___69____| a b
 5|____4____|   b1 c
 6|___31____|      c1
 7|_________|  
 8|_________|  
 9|_________|  
10|_________|  
11|_________|  
12|_________|  
13|_________|  
  
```

d. h(43, 0) = 43 mod 13 = 4 **collisione**<br>
~> scansione lineare _h(k, i) = (k mod 13 + i) mod 13_<br>
d1. h(43, 1) = 4 + 1 = 5 **collisione**<br>
d2. h(43, 2) = 4 + 2 = 6 **collisione**<br>
d3. h(43, 3) = 4 + 3 = 7 


```
   _________
 0|_________|   
 1|_________|  
 2|_________|  
 3|_________|  
 4|___69____| a b     d
 5|____4____|   b1 c  d1
 6|___31____|      c1 d2
 7|___43____|         d3
 8|_________|  
 9|_________|  
10|_________|  
11|_________|  
12|_________|  
13|_________|  
  
```


### Ispezione quadratica


> **h(k, i) = (_h'(k)_ + c<sub>1</sub>i + c<sub>2</sub>i<sup>2</sup>) mod m**

- _h'(k)_ funzione hash ausiliaria
- c<sub>1</sub>, c<sub>2</sub> != 0 costanti ausiliarie
- i = 0, ..., m-1

I valori di c<sub>1</sub> e c<sub>2</sub> devono essere scelti _bene_ in modo da generare tutti gli _indici della tabella_. Quindi <h(k, 0), ..., h(k, m-1)> deve essere una permutazione di <0, 1, ..., m-1>. Si è visto che funziona bene con **c<sub>1</sub>=c<sub>2</sub>=1/2 e m = 2<sup>p</sup>**

Anche qua però la prima posizione **h'(k)** determina l'intera sequenza di ispezioni e dunque ad ogni chiave ci sono soltanto _m_ sequenze di ispezioni distinte.

Soffre del problema dell'**addensamento secondario**: se due chiavi distinte k1 e k2 hanno lo stesso valore hash per la funzione ausiliaria h'(k1) = h'(k2) allora hanno la _stessa sequenza di ispezioni_ e dunque sono _indistinguibili_.

### Doppio Hashing

Sono presenti due funzioni ausiliarie:
- h1(k) determina la prima posizione
- h2(k) determina il passo!

Inoltre
- i = 0, ..., m-1 indica il numero di ispezioni fallite

Il valore di **h2(k)** deve essere _relativamente primo (il MCD è uno)_ con la dimensione **m** della tabella hash in modo che possa essere ispezionata l'intera tabella.

1. si sceglie _m come potenza di 2_ e si definisce **h2** in modo che produca sempre _numeri dispari_
    ```
      m = 2^p
      h(2) = 2 * h'(k) + 1
    ```
2. _**m è primo**_ e **h2** genera sempre un numero _**positivo minore di m**_
    ```
    h1(k) = k mod m
    h2(k) = 1 + k mod m'

    con m' < m
    ```


> Assumo `i, i' < m` e `h(k, i) = h(k, i')` allora `i = i'` (_sotto ipotesi di h2 relativamente primo con m)

Il doppio hashing usa **O(m<sup>2</sup>)** sequenze di ispezioni poiché ogni possibile coppia <h1(k), h2(k)> produce una _sequenza distinta_ di ispezioni. Quindi riesco ad ottenere prestazioni migliori _riducendo_ le collisioni ed eliminando il problema dell'addensamento secondario!

#### Esempio!

Funzione ausiliaria: h1(k) = k mod 13<br>
Funzione ausiliaria: h2(k) = 1 + (k mod 11)<br>
Voglio inserire le chiavi: < 69, 4, 31, 43>

> L'ordine di inserimento è importante! Non posso cambiarlo!

Doppio hashing: h(k, i) = (k mod 13 + i*(1+ k mod 11)) mod 13

```
   _________
 0|_________|   
 1|_________|  
 2|_________|  
 3|_________|  
 4|_________|  
 5|_________|  
 6|_________|  
 7|_________|  
 8|_________|  
 9|_________|  
10|_________|  
11|_________|  
12|_________|  
13|_________|  
  
```

a. h(69, 0) = 69 mod 13 = 4

```
   _________
 0|_________|   
 1|_________|  
 2|_________|  
 3|_________|  
 4|___69____| a
 5|_________|  
 6|_________|  
 7|_________|  
 8|_________|  
 9|_________|  
10|_________|  
11|_________|  
12|_________|  
13|_________|  
  
```

b. h(4, 0) = 4 mod 13 = 4 **collisione!**
~> doppio hashing
b1. h(4, 1) = h1(4) + 1*h2(4) = 4 + 5 = 9

```
   _________
 0|_________|   
 1|_________|  
 2|_________|  
 3|_________|  
 4|___69____| a b
 5|_________|  
 6|_________|  
 7|_________|  
 8|_________|  
 9|____4____|   b1
10|_________|  
11|_________|  
12|_________|  
13|_________|  
  
```

c. h(31, 0) = 31 mod 13 = 5

```
   _________
 0|_________|   
 1|_________|  
 2|_________|  
 3|_________|  
 4|___69____| a b
 5|___31____|      c
 6|_________|  
 7|_________|  
 8|_________|  
 9|____4____|   b1
10|_________|  
11|_________|  
12|_________|  
13|_________|  
  
```

d. h(43, 0) = 43 mod 13 = 4 **collisione!**
~> doppio hashing
d1. h(43, 1) = h1(43) + 1*h2(43) = (4 + (1 + 43 mod 11)) mod 13 = 4 + 11 mod 13 = 15 mod 13 = 2

```
   _________
 0|_________|   
 1|_________|  
 2|___43____|        d1
 3|_________|  
 4|___69____| a b    d
 5|___31____|      c
 6|_________|  
 7|_________|  
 8|_________|  
 9|____4____|   b1
10|_________|  
11|_________|  
12|_________|  
13|_________|  
  
```

## Ristrutturazione

Nel caso di [indirizzamento aperto](../hash_tables/hash_open_addressing/readme.md) si raddoppia la dimensione della tabella HASH (reinserendo tutte le chiavi) quando **alfa > 0.5**, un vantaggio è che così vengono eliminate tutte le posizioni deleted!

Nel caso di [concatenamento](../hash_tables/hash_chaining/readme.md) viene fatta la ristrutturazione quando **alfa >= 2**

## Confronto di strutture dati

**Strutture dati**|**Ricerca**|**Successore**|**Costruzione**|**Massimo**
:-----------------|:---------:|:------------:|:-------------:|:----------:
Tabelle hash con [liste di collisione](../hash_tables/hash_chaining/readme.md) (_medio_)| Teta(1+a) | O(m+n) | Teta(n) | Teta(m+n)
Tabelle hash con [liste di collisione](../hash_tables/hash_chaining/readme.md) (**worst**)| O(n) | O(m+n) | Teta(n) | Teta(m+n)
Tabelle hash con [indirizzamento aperto](../hash_tables/hash_open_addressing/readme.md) (_medio_)| O(1/(1-a)) | O(m) | O(n/(1-a)) | Teta(m)
Tabelle hash con [indirizzamento aperto](../hash_tables/hash_open_addressing/readme.md) (**worst**)| O(n) | O(m) | O(n<sup>2</sup>) | Teta(m)
[Max heap](../trees/heap/max_heap/readme.md) (**worst**)| O(n) | O(n) | Teta(n) | Teta(1)
[Alberi binari di ricerca](../trees/binary_trees/binary_search_trees/readme.md) [BST] (**worst**)| O(h) | O(h) | Teta(n logn) | O(h)

dove
- a: il fattore di carico alfa
- m: dimensione della tabella hash
- n: numero di chiavi
- h: altezza dell'albero 