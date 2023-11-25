## Esercizio

Nella lingua italiana non esistono parole che hanno più di due lettere uguali consecutive. Scrivere un algoritmo efficiente che, dato in input un array A[1..n] di n ≥ 1 caratteri, restituisce true se e solo se A **non** contiene più di due caratteri uguali consecutivi. 

Ad esempio, se A = ['m', 'a', 'm', 'm', 'a', 'a'] l'algoritmo restituisce true; se A = ['a', 'l', 'b', 'b', 'b', 'e'] l'algoritmo restituisce false. 

Analizzare il costo asintotico dell'algoritmo nel caso pessimo e nel caso ottimo; indicare quando si verificano.

### Codice

```c++
bool max_due_lettere_consecutive(std::vector<char> A) {
  bool is_italian = true;
  int i = 0;

  //esco alla prima violazione!
  while (i < A.size() - 2 && is_italian) {
    if (A.at(i + 1) == A.at(i) && A.at(i + 2) == A.at(i))
      is_italian = false;

    i++;
  }

  return is_italian;
}
```

#### Analisi complessità

La funzione esegue un ciclo while al più **n** volte, dunque la complessità risulta essere **T(n) = O(n)** dove n rappresenta il numero di elementi presenti nell'array di input.

Il ciclo potrebbe interrompersi anche eseguendo una sola iterazione (caso migliore, T(n) = Teta(1)), questo si verifica quando la condizione viene violata nelle prime 3 lettere della parola.

Ovviamente se la parola è corretta o se la violazione di trova alla fine della parola, il costo risulta essere proporzionale al numero di elementi dell'array (caso peggiore, T(n) = Teta(n)).