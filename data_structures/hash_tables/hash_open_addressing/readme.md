# Tabelle hash con risoluzione delle collisioni tramite _indirizzamento aperto_

Tutti gli elementi sono memorizzati nella tabella hash (non sono quindi presenti strutture esterne). Ogni cella della _tabella_ contiene un elemento dell'insieme dinamico, oppure NIL.

Per _cercare_ un elemento con chiave k:
- calcolo **h(k)** ed esamino la cella <<ispezione>>
  - se h(k) contiene la chiave k => **successo**
  - se h(k) contiene NIL => **insuccesso**
  - se h(k) contiene una chiave che _non è k_ calcolo un **nuovo indice** di un'altra cella in base a k e all'**ordine di ispezione (0, 1, ..., m-1)**
  - continuo a scansionare la tabella fino a trovare k (_successo_) o trovo una cella con NIL (_insuccesso_) oppure quando ho fatto **m** ispezioni!

> L'ordine di ispezione indica il numero di ispezioni già fatte e ovviamente fallite

## Funzione hash
```
h : U x {0, 1, ..., m-1} -> {0, 1, ..., m-1}
      ordine di ispezione   indice cella
```

**h(k, i)** : posizione della _chiave k_ dopo **i** ispezioni fallite (_celle occupate da una chiave diversa da k_).

> Per ogni chiave k, la _sequenza di ispezioni_ <h(k, 0), h(k, 1), ..., h(k, m-1)> deve essere una **permutazione** di <0, 1, ..., m-1> **indici** della tabella hash, in modo che ogni posizione della tabella hash possa essere considerata come una possibile cella in cui vado ad inserire una chiave.

## Operazioni

> SI INIZIA SEMPRE DALL'ISPEZIONE I = 0 PER OGNI CHIAVE!

### Insert

```pseudocode
hash_insert(T, k)
  i = 0
  trovato = false
  repeat
    j = h(k, i)
    if T[j] == NIL OR T[j] == DELETED /*vedi delete*/
      T[j] = k
      trovato = true
    else
      i = i + 1
  until trovato OR i == m /*m ispezioni fallite!*/
  if trovato
    return j
  else
    ERROR overflow della tabella hash /*tabella piena, anche se in realtà viene raddoppiato quando è quasi piena, con ricalcolo ovviamente di tutti gli hash*/
```



### Search

```pseudocode
hash_search(T, k)
  i = 0
  trovato = false
  repeat
    j = h(k, i)
    if T[j] == k
      trovato = true
    else
      i = i + 1     
  until trovato OR T[j] == NIL OR i == m /*doveva esserci la mia chiave ma è nil, oppure ho fallito m ispezioni*/ 
  if trovato
    return j
  else
    return NIL
```

### Delete

```
supponendo di avere già le chiavi 15, 25, 39 e 73 nella tabella, faccio le seguenti operazioni

   _________
 0|_________|   a. insert k = 118
 1|___ 15 __|      h(118, 0) = collisione
 2|___ 25 __|      h(118, 1) = collisione
 3|__ 118 __|      h(118, 3) = successo e inserisce 118
  |         |
  |   ...   |  
  |_________|
 7|___ 39 __|
  |         |
  |   ...   |
  |___ 73 __|



  _________
 0|_________|   b. delete k = 39
 1|___ 15 __|  
 2|___ 25 __|  
 3|__ 118 __|  
  |         |
  |   ...   |  
  |_________|
 7|__ NIL __|
  |         |
  |   ...   |
  |___ 73 __|

  _________
 0|_________|   c. search k = 118
 1|___ 15 __|      h(118, 0) = 2 != 118
 2|___ 25 __|      h(118, 1) = 7
 3|__ 118 __|         TROVA NIL E MI DICE CHE 118 
  |         |         NON È PRESENTE NELLA TABELLA :(
  |   ...   |  
  |_________|
 7|__ NIL __|
  |         |
  |   ...   |
  |___ 73 __|

```

**SOLUZIONE**: usare una costante **DELETED** al posto di NIL per marcare una cella vuota a causa di un'operazione di cancellazione

```
  _________
 0|_________|   b. delete k = 39
 1|___ 15 __|  
 2|___ 25 __|  
 3|__ 118 __|  
  |         |
  |   ...   |  
  |_________|
 7| DELETED |
  |         |
  |   ...   |
  |___ 73 __|

```

Però in questo modo il _tempo di ricerca_ dipende dalle chiavi presenti e da quelle cancellate, non dal fattore di carico alfa! Questo porta a un degrado delle prestazioni :(

> In caso di molte cancellazioni è meglio usare il [concatenamento](../hash_chaining/readme.md)!

### Analisi complessità delle operazioni di search e insert

Nell'ipotesi di **hashing uniforme** (_ogni chiave ha la stessa probabilità di avere come sequenza di ispezione una delle **m!** permutazioni di <0, 1, ..., m-1>_) e ipotizzando che **non** ci siano cancellazioni viene fatta un'analisi in termini del fattore di carico **alfa**.

```
        n
alfa = ---
        m

0 <= alfa <= 1

non ho strutture esterne, quindi alfa = 1 quando ho tutte le celle occupate
```

#### Ricerca senza successo

Nell'ipotesi di hashing uniforme, data una tabella hash ad indirizzamento aperto con un fattore di carico `alfa = n/m < 1` _(minore di uno perché se è senza successo vuol dire che ci sono celle libere, ma allora mi fermerò alla prima libera)_, il **numero atteso (medio) di ispezioni** in una _ricerca senza successo_ è al massimo **1/(1-alfa)**.

> È il fattore di carico che conta!

```
dimostrazione circa

ispezione | probabilità
----------|------------
  1       | 1
          |
  2       | n/m = alfa : prob. che la cella della prima ispezione fosse occupata
          |   
  3       | n/m * (n-1)/(m-1) 
          |
  4       | n/m * (n-1)/(m-1) * (n-2)/(m-2)

allora il valore atteso di ispezioni è
                                    inf         
1 + alfa + alfa^2 + ... + ... <=     E alfa^i = 1 / (1-alfa) 
                                    i=0

|alfa| < 1
```

- alfa costante => il tempo **_medio_** di una ricerca senza successo è **Teta(1)**
- alfa = 0.5 => _(tabella piena al 50%)_ numero _medio_ di ispezioni è 1/(1-0.5) = **2** (in media dopo 2 ispezioni so che il valore non è presente!)
- alfa = 0.9 =>  _(tabella piena al 90%)_ numero _medio_ di ispezioni è 1/(1-0.9) = **10** 

> Le prestazioni di degradano al diminuire delle celle libere :(

#### Inserimento

L'inserimento di un elemento in una tabella hash a indirizzamento aperto con un fattore di carico `alfa` richiede **_in media_** **1/(1-alfa)** ispezioni nell'ipotesi di hashing uniforme.

```
dimostrazione
Un elemento è inserito solo se c'è spazio, quindi alfa < 1. L'inserimento richiede una ricerca senza successo (trovare una posizione vuota) seguita dall'inserimento della chiave nella prima cella vuota che viene trovata.

Ma allora il numero medio di ispezioni è al massimo 1/(1-alfa)
```

#### Ricerca con successo

Data una tabella hash a indirizzamento aperto con fattore di carico `alfa < 1`, il **numero atteso (medio) di ispezioni** in una ricerca _con_ successo è **al più (1/alfa)ln(1/(1-alfa))** sotto ipotesi di hashing uniforme e che ogni chiave abbia la stessa probabilità di essere cercata.

- alfa costante => il tempo **_medio_** di una ricerca CON successo è **Teta(1)**
- alfa = 0.5 => _(tabella piena al 50%)_ numero _medio_ di ispezioni è  **<= 1.387**
- alfa = 0.9 =>  _(tabella piena al 90%)_ numero _medio_ di ispezioni è **<= 2.559**

<hr>

> In generale il **concatenamento** ha prestazioni migliori!