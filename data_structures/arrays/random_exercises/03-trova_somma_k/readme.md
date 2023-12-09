## Esercizio 

Scrivere un algoritmo che dati in input un array A[1..n] di n interi positivi restituisce true se e solo se esistono due elementi in A la cui somma sia esattamente uguale a 21 (restituire opzionalmente anche i due numeri) e analizzarne la complessità.

### Idea

Utilizzo un vettore delle occorrenze occ[0...21] (se non ti piace 21 cambia numero, è lo stesso ragionamento) e lo inizializzo a zero! 

Poi scorro A[0...n-1], se l'elemento in posizione A[i] è minore o uguale a 21 allora controllo cosa ho salvato nel vettore delle occorrenze in posizione occ[21 - A[i]], se è maggiore di zero allora restituisco vero, altrimenti incremento occ[A[i]].

```
esempio!
faccio somma 5 per non dover riempire 21 celle

A: 2 7 3 2 1 2
   0 1 2 3 4 5

occ: 0 0 0 0 0 0
     0 1 2 3 4 5

i = 0
A[i] = 2 < 5
occ[5-2 = 3] = 0 allora occ[2] ++

occ: 0 0 1 0 0 0
     0 1 2 3 4 5
     
i = 1
A[i] = 7 > 5 non faccio nulla

occ: 0 0 1 0 0 0
     0 1 2 3 4 5

i = 2
A[i] = 3 < 5
occ[5-3 = 2] = 1 allora ho trovato due numeri che sommano 5!

occ: 0 0 1 0 0 0
     0 1 2 3 4 5
```

### Codice

```c++
bool somma_21(std::vector<int> A, int *n1, int *n2) {
  std::vector<int> occ(22);

  for (int i = 0; i < occ.size(); i++) //eseguito 21 volte
    occ.at(i) = 0;

  bool found = false;
  int i = 0;
  while (i < A.size() && !found) { // O(n)
    if (A.at(i) <= 21) {
      if (occ.at(21 - A.at(i)) > 0) {
        found = true;
        *n1 = A.at(i);
        *n2 = 21 - A.at(i);
      } else
        occ.at(A.at(i))++;

      i++;
    }
  }

  return found;
}
```

#### Analisi complessità

Il ciclo for per riempire il vettore delle occorrente viene eseguito un numero costante di volte (in questo caso 21 ma poco importa, tanto è costante).

Il ciclo while invece scorre A per al più il numero dei suoi elementi.

Ma allora la complessità risulta essere **T(n) = O(n)**

