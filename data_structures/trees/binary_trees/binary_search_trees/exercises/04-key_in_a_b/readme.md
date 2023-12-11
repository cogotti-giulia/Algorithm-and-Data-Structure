## Esercizio

Si consideri un albero binario B in cui a ciascun nodo t è associata una chiave numerica (reale) t.key. Non ci sono chiavi ripetute.

1. Scrivere un algoritmo efficiente che dato in input l'albero B e due valori reali a e b, con a < b, restituisce true se e solo se B rappresenta un albero binario di ricerca le cui chiavi siano tutte comprese nell'intervallo [a, b]. Si noti che è necessario controllare esplicitamente che i valori delle chiavi appartengano all'intervallo dato, poiché in generale l'albero B puo' contenere chiavi arbitrarie.

2. Analizzare la complessità.


```
            6
          /  \
         3    7
        / \
      -1   5

è un bst
[-1, 7] ~> true
[-5, 7] ~> true
[-3, 11] ~> true

[5, 11] ~> false!

            6
          /  \
         13    7
        / \
       8   5

NON è un bst, basta questo a violare la condizione
```

Quindi, oltre a controllare che ogni singola chiave sia compresa nell'intervallo [a, b], devo anche verificare che l'albero risulti essere un bst.

### Implementazione sfruttando la proprietà della visita simmetrica

> Se T è un BST <=> la visita simmetrica elenca le chiavi in ordine non decrescente


```pseudocode

# pre: a < b
# T è un albero binario
is_bst_in_a_b(T, a, b)
  if u == nullptr
    return true   # un albero vuoto è bst e le chiavi sono comprese in [a, b] dato che non ci sono
  else
    min = tree_minimum(T.root)

    bool is_ok = true;

    if(min.key >= a AND min.key <= b)
      succ = tree_successor(min)
      prev = min;

      while(succ != nullptr && is_ok)
        # t non è un bst (prev > succ), oppure key non è in [a, b]
        if(prev.key > succ.key OR succ.key < a OR succ.key > b )
          is_ok = false;
        
        prev = succ;
        succ = tree_successor(prev);

    else
      is_ok = false;

    return is_ok;
```

```c++
bool is_bst_in_a_b(T tree, int a, int b) {
  if (tree->root == nullptr)
    return true; // un albero vuoto è bst e le chiavi sono comprese in [a, b]
  else {
    pnode min = tree_minimum(tree->root);

    bool is_ok = true;

    if (min->key >= a && min->key <= b) {
      pnode succ = tree_successor(min);
      pnode prev = min;

      while (succ != nullptr && is_ok) {
        if (prev->key > succ->key || succ->key < a || succ->key > b)
          is_ok = false;

        prev = succ;
        succ = tree_successor(prev);
      }
    } else
      is_ok = false;

    return is_ok;
  }
}
```

#### Analisi complessità

Il codice esegue una visita simmetrica, di conseguenza ogni nodo viene visitato _al più_ una volta, dunque la complessità risulta essere **T(n) = O(n)** dove n rappresenta il numero di nodi dell'albero. Non è detto che i nodi vengano visitati tutti, infatti alla prima violazione della condizione si esce dal ciclo while.

#### Dimostrazione proprietà utilizzata

Se T è un BST <=> la visita simmetrica elenca le chiavi in ordine non decrescente

(<=)

> La visita simmetrica elenca le chiavi in ordine non decrescente => T è un bst

Assumo di avere un albero binario T così composto

```
   T       (x) 
         /     \
        /\      /\
       /  \    /T2\
      / T1 \   ----  
      ------
```

allora una visita simmetrica produce _visita(T1) ~> x.key ~> visita(T2)_

dunque per ipotesi so che

1. visita(T1) elenca le chiavi in ordine non decrescente
2. visita(T2) elenca le chiavi in ordine non decrescente
3. per ogni y in T1 : y.key <= x.key
4. per ogni y in T2 : y.key >= x.key

quindi le visite T1 e T2 (da ipotesi 1 e 2) producono una sequenza di chiavi del tipo

```
    key  <= ... <= key      <=  x.key <=   key    <= ...  <= key
      1               i_m    |         |      i_m+2             i_n
                            (3)       (4)
```

posso concludere che (per ipotesi 3 e 4) anche x.key è ordinata in modo non decrescente, ma allora ho finito perché T risulta essere un BST
