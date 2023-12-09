## Esercizio random

Si consideri una stringa memorizzata in un array S[1..n] di n ≥ 1 caratteri. La stringa S si dice palindroma se è uguale alla sua versione letta a rovescio. Ad esempio, l'array ['B', 'A', 'N', 'A', 'B'] rappresenta una stringa palindroma, mentre ['A', 'N', N', 'I'] no.

Scrivere un algoritmo ricorsivo che, dato in input un array di caratteri S[1..n], restituisce true se e solo se la stringa S è palindroma. Scrivere l'equazione di ricorrenza per il tempo di esecuzione T(n) dell'algoritmo in funzione di n.

### Codice

```c++
bool is_palindroma_ric(std::vector<char> s, int p, int r) {
  if (p >= r) // quando ho un elemento (p = r) oppure p supera r (stringa ha n
              // pari caratteri)
    return true;
  else {
    return s.at(p) == s.at(r) && is_palindroma_ric(s, p + 1, r - 1);
  }
}
```

#### Analisi complessità

```
        --- c                   n<=1
T(n) = |
        --- T(n-2) + d          n>1
```

La ricorrenza si risolve tramite metodo di sostituzione ottenendo che **T(n) = O(n)**