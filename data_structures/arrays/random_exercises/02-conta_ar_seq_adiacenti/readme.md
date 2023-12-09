## Prima prova intermedia 28/01/2015 (esercizio II)

Scrivere un algoritmo efficiente, di tipo divide et impera, che conta il numero di occorrenze della sequenza ‘a’ ‘r’ memorizzata in posizioni adiacenti in un array di caratteri. Analizzare la complessità indicando e risolvendo la corrispondente relazione di ricorrenza.

Esempio: Per l’array ‹a, b, c, r› la risposta sarà 0<br>.
Per l’array ‹b, a, r, c, a, r› la risposta sarà 2.

### Idea

Uso un approccio simile al merge sort, divido l'array in due sottoarray ricorsivamente (prendendo l'elemento centrale ogni volta).

Siano 
- p : inizio porzione del sottoarray
- r : fine porzione del sottoarray

Allora
- med : elemento centrale, è la parte intera inferiore di (p+r)/2

Ogni volta controllo se l'elemento in posizione med è uguale ad 'a' e se quello in posizione med+1 è uguale ad 'r'. Se è così lo conto, altrimenti no.


### Codice c++

```c++
int conta_ar_seq_rec(const std::vector<char> &a, int p, int r) {
  if (p < r) {
    int med = std::floor((p + r) / 2);
    int ris_sx = conta_ar_seq_rec(a, p, med); //? T(n/2)
    int ris_dx = conta_ar_seq_rec(a, med + 1, r); //? T(n/2)

    //? costante!
    if (a.at(med) == 'a' && a.at(med + 1) == 'r') {
      return ris_dx + ris_sx + 1;
    } else {
      return ris_dx + ris_sx;
    }
  } else {
    return 0;
  }
}

int conta_ar_seq(const std::vector<char> &a) {
  return conta_ar_seq_rec(a, 0, a.size() - 1); //! T(n) = Teta(n)
}
```

### Analisi complessità

La funzione ricorsiva impiega un tempo pari a **T(n) = Teta(n)**, ottenuto risolvendo la seguente ricorrenza usando il teorema master.

```
        --- c                 n = 0
T(n) = |
        --- 2*T(n/2) + c      n > 0
```

a = 2<br>
b = 2<br>
f(n) = c = Teta(1)<br>

d = log(b)a = log(2)2 = 1<br>
g(n) = n^d = n^1 = n

f(n) = O(n^(d+epsilon)<br>
c = O(n^(1-epsilon)<br>
fisso epsilon = 1

ma allora c = O(n^0 = 1)

quindi concludo che T(n) = Teta(n);