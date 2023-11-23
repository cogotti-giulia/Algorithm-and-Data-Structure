## Esercizio

Si consideri un albero binario T in cui a ciascun nodo v è associato un numero reale t.val. Dato un qualsiasi cammino che porta dalla radice ad una foglia, definiamo il costo del cammino come la somma dei valori associati a tutti i nodi attraversati (inclusa la radice e la foglia di destinazione)

1. Scrivere un algoritmo che, dato in input l'albero T, restituisce il costo massimo tra tutti i cammini radice-foglia. Nel caso di albero vuoto, l'algoritmo restituisce 0.
2. Analizzare il costo computazionale dell'algoritmo di cui al punto 1.


L'idea è quella di visitare l'albero in post order, calcolando quindi la somma di ciascun cammino e prendendo il massimo tra la somma del sotto albero sx e la somma del sotto albero dx unito alla chiave della radice.

### Codice

```c++
int costo_max_cammino(pnode u) {
  if (u == nullptr)
    return 0;
  else {
    return std::max(costo_max_cammino(u->left), costo_max_cammino(u->right)) +
           u->key;
  }
}
```

#### Analisi complessità

Dal codice si ricava la seguente ricorrenza

```
        --- c                       se n=0
T(n) = |
        --- T(k) + T(n-k-1) + d     se n>0
dove
k : nodi visitati nel sotto albero sx
n-k-1 : nodi visitati nel sotto albero dx
```

Tramite metodo di sostituzione si risolve la ricorrenza e si può dimostrare (non ho voglia di farlo ora) che **T(n) = Teta(n)**