## Esame 11/06/2015 (esercizio I, parte II)

Scrivere un algoritmo efficiente che date in input due stringhe di lunghezza n i cui caratteri variano in {a, b, ..., x, y, z} rappresentate mediante due array di caratteri A[1..n] e B[1..n], restituisce true se e solo se le due stringhe sono una l’anagramma dell’altra. Analizzare la complessità dell’algoritmo.

Per esempio:
A = [‘s’, ‘a’, ‘r’, ‘a’] e B = [‘r’, ‘a’ ,‘s’, ‘a’] sono anagrammi.<br>
A = [‘c’, ‘a’, ‘r’, ‘a’] e B = [‘r’, ‘a’ ,‘n’, ‘a’] NON sono anagrammi.

### Idea

Ordino tramite merge sort (che ha costo O(n logn)) le due stringhe. Una volta che le ho ordinate confronto le stringhe carattere per carattere, se trovo che due lettere nella stessa posizione non corrispondono allora non può essere un anagramma!

### Codice c++

```c++
//! T(n) = O(n logn)
bool anagramma(std::vector<char> *A, std::vector<char> *B) {
  int n = A->size();
  my_merge_sort(A, 0, n - 1); //? T(n) = O(n logn)
  my_merge_sort(B, 0, n - 1); //? T(n) = O(n logn)

  bool is_anagramma = true;
  int i = 0;

  while (i < n && is_anagramma) { //? T(n) = O(n)
    if (A->at(i) != B->at(i))
      is_anagramma = false;
    i++;
  }
  return is_anagramma;
}
```

#### Analisi complessità

L'ordinamento tramite merge sort porta via un tempo pari a **n logn** per ognuna delle due stringhe. Il ciclo while per il confronto dei caratteri viene eseguito al più n volte. Dove n è la lunghezza delle stringhe.

Quindi si ottiene che **T(n)** = O(n) + O(n logn) + O(n logn) = **O(n logn)**
