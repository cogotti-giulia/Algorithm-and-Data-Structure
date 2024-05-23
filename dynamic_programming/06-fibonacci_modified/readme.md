## Esercizio

Dati A e B, rappresentanti i primi due numeri della serie di fibonacci e un certo N. Determinare l'N-esimo numero di fibonacci.

```
Esempio

Input: A = 2, B = 3, N = 4 
Output: 8 
The series will be 2, 3, 5, 8, 13, 21, … 
And the 4th element is 8.
Input: A = 5, B = 7, N = 10 
Output: 343 

```

### Idea

Utilizzo una variabile sum che conserverà la somma dei due numeri precedenti. All'interno di un ciclo for, eseguito da 2 ad N, calcolo la serie di fibonacci (sum = A+B) e aggiorno le variabili (A = B e B = sum). Alla fine sum conterrà il valore ottimo, quindi l'N-esimo numero di fibonacci a partire da A e B.

### Codice c++

```c++
int fibi_modified(int A, int B, int N){
    int sum = 0;

    for(int i = 2; i < N; i++){
        sum = A+B;

        A = B;
        B = sum;
    }
    return sum;
}
```

### Analisi complessità

Il tempo di esecuzione risulta essere **T(n) = O(n)** e lo spazio in memoria costante.