## Seconda prova intermedia 14/06/2021

I numeri di Fibonacci sono definiti dalla seguente ricorrenza: 
- F0 = 0 
- F1 = 1 
- Fi = Fi-1+Fi-2 per i>=2 

Scrivere un algoritmo di programmazione dinamica con tempo O(n) per calcolare n-esimo numero di Fibonacci. Quale schema è stato utilizzato (top-down o bottom-up)? Giustificare il calcolo della complessità

### Idea

1. caratterizzazione della struttura ottima: posso esprimere l'n-esimo numero di fibonacci come somma dei due valori precedenti, utilizzando un array per memorizzarne le soluzioni
2. definizione ricorsiva: viene già data dal testo
3. calcolo del valore di una soluzione ottima: algoritmo tramite approccio bottom up
4. individuazione di una soluzione ottima: la soluzione ottima si trova nell'ultima posizione dell'array


### Codice (c++)

```c++
/**
 * @brief risoluzione del problema di fibonacci tramite la tecnica di
 * programmazione dinamica, con un approccio bottomup
 * @pre n >= 2
 * @param n numero in input
 * @return n-esimo numero di fibonacci
 */
int fib_bottom_up(int n) {
  std::vector<int> A(n); // memorizza le soluzioni

  A.at(0) = 0;
  A.at(1) = 1;

  for (int i = 2; i < n; i++)
    A.at(i) = A.at(i - 1) + A.at(i - 2);

  return A.at(n-1);
}
```

### Analisi complessità

Vengono svolte operazioni costanti, se i>2 si entra nel ciclo for che è eseguito al più n volte. Quindi il tempo di esecuzione risulta essere **T(n) = O(n)**.