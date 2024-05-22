## Esercizio massima sottosequenza crescente (LIS)

Si consideri un array A[1..n] composto da n numeri reali distinti, non ordinato. Si vuole determinare la massima lunghezza di una sottosequenza di A composta da elementi in ordine crescente. Non è richiesto che la sottosequenza sia composta da elementi contigui. Ad esempio, supponendo che A = [4, 1, -1, 3, 10, 11], possibili sottosequenze composte da valori crescenti sono [1, 3, 11], oppure [4, 10, 11], oppure [1, 3, 10, 11] (si noti che i valori vanno considerati nell'ordine in cui compaiono in A). Nel caso dell'array di esempio, l'algoritmo deve restituire il valore 4 in quanto la più lunga sottosequenza di valori crescenti ha lunghezza 4 (in particolare [1, 3, 10, 11] oppure [-1, 3, 10, 11] sono due sottosequenze di lunghezza massima).

1. Scrivere un algoritmo basato sulla programmazione dinamica per calcolare la massima lunghezza di una sottosequenza crescente. (Suggerimento: sia L[j] la massima lunghezza di una sottosequenza crescente di A[1..j] avente A[j] come ultimo elemento)
2. Calcolare il costo computazionale dell'algoritmo di cui al punto precedente.

### Idea

Si nota subito che L[1] = 1 perché la sottosequenza composta da un singolo elemento è crescente e ha lunghezza 1. Per calcolare il valore di L[j], avendo precedentemente calcolato L[1]...L[j-1] devo trovare la più grande sottosequenza crescente di A[1...j] che termina in A[j], quindi essa avrà un penultimo elemento A[k] con 1 <= k < j. Quindi L[j] = L[k] + 1. Solo che non so quale sia il k corretto, allora per tutti i k < j vedo se A[k] < A[j] (crescente) e tra questi elementi vedo quale è il massimo.

(Utilizzo un approccio bottom up)

### Caratterizzazione ricorsiva

```

       +-- 1                se j == 1
L[j] = |
       +-- 1+max L[k]       altrimenti
         1<=k<j, A[k]<A[j]

```

### Codice c++

```c++
    int massima_sottosequenza_crescente(std::vector<int> num) {

        int n = num.size();
        std::vector<int> L(n);
        L.at(0) = 1;

        int max = L.at(0);

        for (int j = 1; j < n; j++) {
            int max_1_j = 0;
            for (int k = 0; k < j; k++) {
            if (num.at(k) < num.at(j) && L.at(k) > max_1_j)
                max_1_j = L.at(k);
            }

            L.at(j) = 1 + max_1_j;
            if (L.at(j) > max)
            max = L.at(j);
        }

        return max;
    }
```

### Analisi complessità

Il ciclo for interno effettua un'operazione costante ed è eseguito 1+2+...+(n-2)+(n-1) volte. Il ciclo esterno è eseguito n volte. Dunque in totale si avrà **T(n) = T(n<sup>2</sup>)**
