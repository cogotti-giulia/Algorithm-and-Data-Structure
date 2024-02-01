## Seconda prova intermedia 30/05/2013 (esercizio I)

In una tabella Hash di m = 17 posizioni, inizialmente vuota, devono essere inserite le seguenti chiavi numeriche nell’ordine indicato:

```
101, 50, 20, 72, 3, 14, 25, 121, 115, 22, 73
```

La tabella è a indirizzamento aperto e la scansione è eseguita per doppio Hashing:

h(k, i) = (k mod m + i \* 2<sup>k mod 5</sup>) mod m

Indicare per ogni chiave le posizioni scandite nella tabella e la posizione finale dove viene allocata.

### Codice c++

```c++
int hash1(int k) { return k % M; }

int hash_doppio_hashing(int k, int i) {
  int h1_index = hash1(k);
  if (i == 0) {
    std::cout << "h1(" << k << ", " << i << ") = " << h1_index << std::endl;

    return h1_index;
  } else {
    std::cout << ">>> doppio hashing! >>>" << std::endl;
    int h2_index = std::pow(2, k % 5);

    int h = (h1_index + i * h2_index) % M;
    std::cout << "h(" << k << ", " << i << ") = " << h << std::endl;
    return h;
  }
}

int insert(T hash_table, int k) {
  int i = 0; // ordine di ispezione!
  bool found = false;
  int j; // risultato funzione hash

  do {
    j = hash_doppio_hashing(k, i);

    // -1 perché inserisco chiavi tutte >= 0
    if (hash_table->tab.at(j) == -1) {
      hash_table->tab.at(j) = k;
      found = true;
    } else {
      i++;
    }

  } while (!found && i != hash_table->m);

  if (found)
    return j;
  else
    throw "ERROR overflow tabella hash";
}
```

#### Analisi complessità

Considerando che il calcolo della funzione hash risulta essere costante e sotto ipotesi di _hashing uniforme_ (ogni chiave ha la stessa probabilità di avere come sequenza di ispezioni una delle m! permutazioni di <0, 1, ..., m-1>), **in media** l'inserimento richiede **1/(1-alfa)** **ispezioni**, dove alfa rappresenta il fattore di carico della tabella hash (alfa = n/m)

### Simulazione

```
h1(101, 0) = 16

h1(50, 0) = 16
>>> doppio hashing! >>>
h(50, 1) = 0

h1(20, 0) = 3

h1(72, 0) = 4

h1(3, 0) = 3
>>> doppio hashing! >>>
h(3, 1) = 11

h1(14, 0) = 14

h1(25, 0) = 8

h1(121, 0) = 2

h1(115, 0) = 13

h1(22, 0) = 5

h1(73, 0) = 5
>>> doppio hashing! >>>
h(73, 1) = 13
>>> doppio hashing! >>>
h(73, 2) = 4
>>> doppio hashing! >>>
h(73, 3) = 12

tabella finale
0 : 50
1 :
2 : 121
3 : 20
4 : 72
5 : 22
6 :
7 :
8 : 25
9 :
10 :
11 : 3
12 : 73
13 : 115
14 : 14
15 :
16 : 101

```
