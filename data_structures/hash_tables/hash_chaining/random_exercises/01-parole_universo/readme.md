## Esercizio

Considerare la realizzazione di un dizionario tramite tavole hash con risoluzione delle collisioni tramite concatenamento. Supporre che le chiavi del dizionario siano stringhe di lettere e che la seguente funzione hash sia stata definita per una tavola di dimensione m = 5: sommare i codici ASCII delle lettere, dividere il risultato della somma per 5 e prendere il resto della divisione.

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

int hash(std::string w) {
  int s = sum_ascii(w);

  return s % M;
}

void insert(T hash_table, E elem) {
  int h = hash(elem->info);
  hash_table->n++;

  std::cout << "insert k = " << elem->info << std::endl;
  std::cout << "h(k) = " << h << std::endl;
  if (hash_table->list.at(h) == nullptr)
    hash_table->list.at(h) = elem;
  else {
    elem->next = hash_table->list.at(h);
    hash_table->list.at(h)->prev = elem;
    hash_table->list.at(h) = elem;
  }
}
```

### Simulazione

> Inserisce in testa!

```
insert k = MARTE
h(k) = 2
0 :
1 :
2 : MARTE -
3 :
4 :

insert k = LUNA
h(k) = 4
0 :
1 :
2 : MARTE -
3 :
4 : LUNA -

insert k = COMETA
h(k) = 1
0 :
1 : COMETA -
2 : MARTE -
3 :
4 : LUNA -

insert k = PIANETI
h(k) = 2
0 :
1 : COMETA -
2 : PIANETI - MARTE -
3 :
4 : LUNA -

insert k = SOLE
h(k) = 2
0 :
1 : COMETA -
2 : SOLE - PIANETI - MARTE -
3 :
4 : LUNA -

insert k = SOLI
h(k) = 1
0 :
1 : SOLI - COMETA -
2 : SOLE - PIANETI - MARTE -
3 :
4 : LUNA -
```
