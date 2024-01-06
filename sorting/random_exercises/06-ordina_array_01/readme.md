## Esercizio

Si consideri un array A[1..n] di interi in cui ciascun valore può essere esclusivamente 0 oppure 1. I valori sono presenti senza alcun ordine; è anche possibile che tutti i valori siano uguali.

1. Scrivere un algoritmo avente complessità ottima che ordini l'array A spostando tutti i valori 0 prima di tutti i valori 1. Verrà assegnato punteggio pieno ad algoritmi che scambiano elementi in A, che richiedono memoria ulteriore O(1) (quindi che non sfruttano array ausiliari), e che non sono basati sul conteggio del numero di 0 e 1 presenti.
2. Determinare il costo computazionale dell'algoritmo di cui al punto 1.

### Idea

Mantengo due indici i e j che identificano due porzioni dell'array separate. L'invariante mantenuto vero durante l'esecuzione del ciclo è che la porzione A[1...i] contiene gli elementi di A uguali a 0, mentre la porzione A[j+1...] contiene la porzione di elementi uguali a 1. Ad ogni iterazione incremento o decremento j facendo gli opportuni scambi per ristabilire l'ordine quindi scorrerò l'array una sola volta!

### Codice c++

```c++
void ordina_01(std::vector<int>& A){
  int i = 0;
  int j = A.size()-1;

  while(i < j){
    if(A.at(i) == 0)
      i++;
    else{
      if(A.at(j) == 0){
        //scambio
        int tmp = A.at(i);
        A.at(i) = A.at(j);
        A.at(j) = tmp;
        i++;
        j--;
      }else
        j--;
    }
  }
}
```

#### Analisi complessità

Ad ogni iterazione del ciclo while gli almeno uno dei due indici viene sicuramente incrementato/decrementato. Quindi prima o poi si arriva per forza al momento in cui essi diventano uguali senza sovrapporsi prima. 

In conclusione **T(n) = O(n)**