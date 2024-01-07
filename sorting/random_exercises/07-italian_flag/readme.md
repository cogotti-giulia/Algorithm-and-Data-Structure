## Esercizio

Il problema seguente fu inizialmente proposto da Edsger W. Dijkstra come Dutch National Flag Problem; ne proponiamo una rivisitazione in chiave italiana. Sia A[1..n] un array di caratteri, i cui elementi assumono valori nell'insieme {'B', 'R', 'V'} (“bianco”, “rosso” e “verde”). Scrivere un algoritmo efficiente che permuta gli elementi di A in modo tale che tutti i valori 'V' precedano tutti i valori 'B', i quali a loro volta precedano tutti i valori 'R'. L'algoritmo dovrebbe richiedere spazio aggiuntivo O(1), quindi dovrebbe limitarsi a permutare tra loro gli elementi di A senza usare un secondo array di appoggio.

### Idea

Utilizzo l'idea della tripartizione utilizzata dal quick sort, in modo che A sia suddiviso nel seguente modo:

- gli elementi in A[1...i-1] sono tutti uguali a V
- gli elementi in A[i...j] sono tutti uguali a B
- gli elementi in A[j+1...n] sono tutti uguali a R

### Codice c++

```c++

void italian_flag(std::vector<char> &A) {
  int i = 0, j = 0;
  int k = A.size() - 1;

  while (j <= k) {
    if (A.at(j) == 'V') {
      my_swap(A, i, j);
      i++;
      j++;
    } else if (A.at(j) == 'B') {
      j++;
    } else {
      my_swap(A, j, k);
      k--;
    }
  }
}

void my_swap(std::vector<char> &A, int i1, int i2) {
  char tmp = A.at(i1);
  A.at(i1) = A.at(i2);
  A.at(i2) = tmp;
}
```

#### Analisi complessità

Ad ogni iterazione viene decrementato l'indice k o incrementato j, quindi si arriverà al punto in cui j > k e il ciclo termina in n iterazioni.

Dunque **T(n) = Teta(n)**