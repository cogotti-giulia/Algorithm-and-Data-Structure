## Esercizio

Dato un intero n, progettare ed analizzare un algoritmo di programmazione dinamica che conti il numero di modi di esprimere n come somma degli interi 1, 3, 4. Ad esempio, se n = 5, la risposta è 6, in quanto 5=1+1+1+1+1=1+1+3=1+3+1=3+1+1=1+4=4+1

### Idea

Posso esprimere 1 in un solo modo, anche 2 = 1+1, 3 lo posso esprimere in due modi 3=1+1+1=3. 4 sarà esprimibile come la somma dei modi in cui calcolo 3 ed 1 ~> 4=1+1+1+1=3+1=1+3, e così via.

Sia c[0...n] array, dove c[i] indica il numero di modi di scrivere i come somma di 1, 3, 4. Allora c[n] conterrà i modi di scrivere n (soluzione ottima)

```

       +-- 1                         se i==0 or i==1 or i==2
c[i] = |-- 2                         se i==3
       +-- c[i-1]+c[i-3]+c[i-4]      se i>=4
```

Intuitivamente ci sarebbero zero modi per scrivere n=0 con 1 3 e 4. Considerando invece n=1a+3b+4c allora impostando a=b=c=0 si ha esattamente un modo (unico tra l'altro) di scrivere zero. Questo caso base semplifica il modo di risolvere il problema!

Questa soluzione viene risolta in O(n) iterazioni e richiede uno spazio in memoria lineare.

In realtà si nota che per calcolare il valore i-esimo del vettore sono necessari solamente i 4 elementi precedenti, si può
quindi ridurre lo spazio in memoria ottenendo un valore costante!

### Codice c++

```c++
int count_ways(int n) {
  std::vector<int> c(n + 1);

  c.at(0) = 1;
  // perché 1a+3b+4c se metto a=b=c=0 ho un solo modo (unico tra
  // l'altro) di esprimere 0 come somma di 1 3 e 4!
  c.at(1) = c.at(2) = 1;
  c.at(3) = 2;

  for (int i = 4; i <= n; i++)
    c.at(i) = c.at(i - 1) + c.at(i - 3) + c.at(i - 4);

  return c.at(n);
}
```

Ottimizzazione spazio in memoria

```c++
int count_ways_O1space(int n){
    int c1, c2, c3, c4; //i-1 i-2 i-3 i-4
    int c_i;

    if(n == 0 || n == 1 || n == 2)
        return 1;
    if(n == 3)
        return 2;

    c4 = c3 = c2 = 1;
    c1 = 2;

    for(int i = 4; i <=n ; i++){
        c_i = c1 + c3 + c4;

        c4 = c3;
        c3 = c2;
        c2 = c1;
        c1 = c_i;
    }

    return c_i;
}
```

### Analisi complessità

Il tempo di esecuzione risulta essere **T(n) = O(n)**. Lo spazio in memoria è lineare, ma può essere ridotto a un tempo costante.