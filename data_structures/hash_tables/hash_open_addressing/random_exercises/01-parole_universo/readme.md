## Esercizio

Considerare la realizzazione di un dizionario tramite tavole hash con risoluzione delle collisioni tramite indirizzamento aperto. Supporre che le chiavi del dizionario siano stringhe di lettere e che la seguente funzione hash sia stata definita per una tavola di dimensione m = 5: sommare i codici ASCII delle lettere, dividere il risultato della somma per 5 e prendere il resto della divisione.

Mostrare il contenuto della tavola dopo l'inserimento delle stringhe:

```
MARTE
LUNA
COMETA
PIANETI
SOLE
SOLI
```

### Codice c++

```c++

int sum_ascii(std::string w) {
  int sum = 0;
  for (int i = 0; i < w.size(); i++)
    sum += w.at(i);

  return sum;
}

int hash1(std::string w) { return sum_ascii(w) % 5; }

int hash_ispezione_lineare(std::string w, int i) {
  int h1_index = hash1(w);
  if (i == 0) {
    std::cout << "h1(" << w << ") = " << h1_index << std::endl;

    return h1_index;
  } else {
    std::cout << ">>> ispezione lineare! >>>" << std::endl;
    int h2_index = (h1_index + i) % 5;
    std::cout << "h2(" << w << ", " << i << ") = " << h2_index << std::endl;
    return h2_index;
  }
}

int insert(T hash_table, std::string el) {
  int i = 0; // inizio dall'ispezione zero PER OGNI CHIAVE
  int j;     // posizione calcolata dalla tabella hash;
  bool found = false;

  do {
    j = hash_ispezione_lineare(el, i);
    std::cout << "insert k = " << el << std::endl;
    if (hash_table->tab.at(j).empty()) {
      hash_table->tab.at(j) = el;
      found = true;
    } else {
      i++;
    }
  } while (!found && i != hash_table->m);

  if (found)
    return j;
  else
    throw "ERROR overflow della tabella hash!";
}
```

#### Analisi complessità

Considerando che il calcolo della funzione hash risulta essere costante e sotto ipotesi di _hashing uniforme_ (ogni chiave ha la stessa probabilità di avere come sequenza di ispezioni una delle m! permutazioni di <0, 1, ..., m-1>), **in media** l'inserimento richiede **1/(1-alfa)** **ispezioni**, dove alfa rappresenta il fattore di carico della tabella hash (alfa = n/m)

### Simulazione

```
h1(MARTE) = 2
insert k = MARTE
0 : 
1 : 
2 : MARTE
3 : 
4 : 

h1(LUNA) = 4
insert k = LUNA
0 : 
1 : 
2 : MARTE
3 : 
4 : LUNA

h1(COMETA) = 1
insert k = COMETA
0 : 
1 : COMETA
2 : MARTE
3 : 
4 : LUNA

h1(PIANETI) = 2
insert k = PIANETI
>>> ispezione lineare! >>>
h2(PIANETI, 1) = 3
insert k = PIANETI
0 : 
1 : COMETA
2 : MARTE
3 : PIANETI
4 : LUNA

h1(SOLE) = 2
insert k = SOLE
>>> ispezione lineare! >>>
h2(SOLE, 1) = 3
insert k = SOLE
>>> ispezione lineare! >>>
h2(SOLE, 2) = 4
insert k = SOLE
>>> ispezione lineare! >>>
h2(SOLE, 3) = 0
insert k = SOLE
0 : SOLE
1 : COMETA
2 : MARTE
3 : PIANETI
4 : LUNA

h1(SOLI) = 1
insert k = SOLI
>>> ispezione lineare! >>>
h2(SOLI, 1) = 2
insert k = SOLI
>>> ispezione lineare! >>>
h2(SOLI, 2) = 3
insert k = SOLI
>>> ispezione lineare! >>>
h2(SOLI, 3) = 4
insert k = SOLI
>>> ispezione lineare! >>>
h2(SOLI, 4) = 0
insert k = SOLI
terminate called after throwing an instance of 'char const*'
```

