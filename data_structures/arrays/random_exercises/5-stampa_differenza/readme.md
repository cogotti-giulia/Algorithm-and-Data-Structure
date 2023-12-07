## Esercizio a caso

Si considerino due array A[1..n] e B[1..m], contenenti n ed m valori interi, rispettivamente. Entrambi gli array sono ordinati in senso crescente, e ciascuno dei due contiene elementi distinti. È però possibile che lo stesso valore sia presente sia in A che in B.

1. Scrivere un algoritmo di complessità ottima per stampare i valori di A che non sono presenti in B. Ad esempio, se A=[1, 3, 4, 7, 8] e B=[2, 3, 5, 7], l'algoritmo deve stampare 1, 4, 8 (infatti i rimanenti valori di A, 3 e 7, sono presenti anche in B quindi NON devono essere stampati).
2. Analizzare il costo computazionale dell'algoritmo di cui al punto 1.

### Idea

Seguo il ragionamento del merge_sort  nella procedura merge, scorro i due array partendo da i = 0 per A e j = 0 per B e confronto gli elementi nelle posizioni. Se A[i] < B[j] stampo A[i] e incremento i, se sono uguali incremento i e j, altrimenti vado avanti solo in B.

Ovviamente se finisco prima gli elementi di B, finisco di stampare quelli che rimangono in A.

### Codice c++

```c++
void differenza(const std::vector<int>& A, std::vector<int> B) {
  int i = 0;
  int j = 0;

  while (i < A.size()) {
    if (j < B.size()) {
      if (A.at(i) < B.at(j)) {
        std::cout << A.at(i) << " ";
        i++;
      } else if (A.at(i) == B.at(j)) {
        i++;
        j++;
      } else {
        j++;
      }
    } else {
      std::cout << A.at(i) << " ";
      i++;
    }
  }
}
```

#### Analisi complessità

Assumendo che
- n = numero di elementi di A
- m = numero di elementi di B

Il tempo di esecuzione risulta essere **T(n, m) = O(n+m)**.