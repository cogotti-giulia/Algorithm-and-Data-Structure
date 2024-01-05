## Esame 12/06/2019 (parte II, esercizio II)

Un collezionista di figurine possiede K figurine, non necessariamente distinte. Le figurine vengono stampate con un numero di serie, impresso dal produttore. I numeri di serie sono tutti gli interi compresi tra 1 e N. La collezione sarebbe completa se ci fosse almeno un esemplare di tutte le N figurine prodotte. Purtroppo la collezione non è completa: sono presenti dei duplicati, mentre alcune figurine mancano del tutto. Il vostro compito è di indicare i numeri di serie delle figurine mancanti.

Scrivere un algoritmo efficiente che dato N e l'array S[1..K], ove S[i] è il numero di serie della i- esima figurina posseduta, stampa l'elenco dei numeri di serie mancanti. L'array S non è ordinato. Ad esempio, se N=10 e S=[1, 4, 2, 7, 10, 2, 1, 4, 3], l'algoritmo deve stampare a video i numeri di serie mancanti 5, 6, 8, 9 (non necessariamente in questo ordine)

Determinare la complessità dell'algoritmo di cui sopra, in funzione di N e K. Attenzione: K potrebbe essere minore, uguale o maggiore di N.


### Idea

Utilizzo un vettore delle occorrenze [0...N+1] dove conto i numeri di serie presenti in S. Questo mi permette poi di scorrerlo e trovare immediatamente le figurine assenti (sarebbero gli indici del vettore delle occorrenze in cui la cella è a zero)

### Codice c++

```c++
void print_missing_numbers(const std::vector<int> &S, int N) {

  std::vector<int> occ(N + 1);

  for (int i = 0; i < occ.size(); i++) // Teta(n)
    occ.at(i) = 0;

  for (int j = 0; j < S.size(); j++) // Teta(k)
    occ.at(S.at(j))++;

  for (int i = 1; i < occ.size(); i++) // Teta(n)
    if (occ.at(i) == 0)
      std::cout << i << " ";

  std::cout << std::endl;
}
```

#### Analisi complessità

Il primo ciclo for è necessario per inizializzare a zero il vettore delle occorrenze e ha tempo pari a Teta(n). Il secondo ciclo for incrementa le posizioni del vettore delle occorrenze corrispondenti ai numeri presenti in S e viene quindi eseguito k volte. Infine per stampare i numeri mancanti si scorre il vettore delle occorrenze trovando le posizioni in cui è presente uno zero, il tutto viene fatto n volte.

Quindi **T(n, k) = T(n) + T(k) + T(n) = T(n+k)**