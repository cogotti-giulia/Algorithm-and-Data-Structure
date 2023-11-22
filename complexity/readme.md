## Complessità 

> Capire il comportamento di T(n) per n sufficientemente grande ~ "asintoticamente"

1. f(n) = O(g(n)) <=> _esiste_ c>0, esiste n0 in N tale che per ogni n >=n0 : f(n) **<=** c\*g(n)
2. f(n) = Omega(g(n)) <=> _esiste_ c>0, esiste n0 in N tale che per ogni n >=n0 : f(n) **>=** c\*g(n)
3. f(n) = Teta(g(n)) <=> esiste c1>0 e c2>0, esiste n0 in N tale che per ogni n >=n0 : c1\*g(n) <= f(n) <= c2\*g(n)
4. f(n) = o(g(n)) <=> **per ogni** c>0, esiste n0 in N tale che per ogni n >=n0 : f(n) **<** c\*g(n) 
4. f(n) = w(g(n)) <=> **per ogni** c>0, esiste n0 in N tale che per ogni n >=n0 : f(n) **>** c\*g(n) 


**Complessità in ordine dalla migliore alla peggiore**

> 1 ; log\*logn ; logn ; sqrt(n) ; n ; n\*logn ; n*sqrt(n) ; n^2 ; n^2\*logn ; n^2\*sqrt(n) ; n^3 ; b^n ; n! ; n^n

_le ultime tre (b^n ; n! ; n^n) sono il male assoluto_

### Complessità temporale

T(n) = complessità temporale dell'algoritmo (mi interessa il caso peggiore), dove n è la dimensione dell'istanza in ingresso.

```
esempio!

A |a1|a2|...|an| vettore

voglio vedere se dato un x, esso appartiene ad A
my_algorithm(A, x) 
allora

- T_best(n) = c ~> costante! x è in prima posizione
- T_worst(n) = n ~> x è l'ultimo elemento oppure non appartiene ad A
- T_avg(n) = n/2
```

#### Come calcolare la complessità di un codice?

1. sequenza

    ```
    block_1   :   O(f(n))
    block_2   :   O(g(n))

    ~> T(n) = O(f(n) + g(n))
    ```

2. if then else

    ```
            |-----------------> O(f(n))
    if <condizione> then
      ramo_then   :   O(g(n))
    else
      ramo_else   :   O(h(n))

    ~> T(n) = O(f(n) + max{g(n), h(n)})
    ```

3. cicli

    ```
    for i = 1 to k do
      block_for   :   O(f(n))
    
    ~> T(n) = O(k * f(n))
    ```

    ```
    for i = 1 to k do
      for i = 1 to z do
        block_for_for   :   O(f(n))
    
    ~> T(n) = O(k * z * f(n))
    ```

    ```
                |-----------------> O(f(n))
    while <condizione> do
      block_while  :   O(g(n))
    
    ~> T(n) = O(N(n) * (f(n) + g(n)))
                  |
            max numero di iterazioni
    ```

4. ciclo interno che dipende da quello esterno

    ```  
    for i = 1 to k do
      for i = 1 to m_i do
        block   :   O(f(n))
    
    ~> T(n) = m_1*f(n) + ... + m_k*f(n) =
                  k
            = O[  E m_i * f(n)]
                 i=1
    ```

### Metodi per risolvere le ricorrenze

#### Albero delle ricorsioni

Per algoritmi semplici.

#### Metodo dell'iterazione

Si srotola la ricorsione per cercare di capire come va.

#### Metodo di sostituzione

Si intuisce magicamente l'ordine di grandezza e si dimostra tramite induzione.

#### Master theorem 

È il teorema fondamentale delle ricorrenze, utilizza la tecnica del divide-et-impera. 

1. split: scomporre il problema in sotto problemi
2. risoluzione: risolvere indipendentemente i sotto problemi
3. merge: comporre la soluzione finale

Si assume che ci siano **a** sotto problemi di dimensione **n/b** _ad ogni_ chiamata ricorsiva.


```
        --- c                     se n <= 1
T(n) = |
        --- a T(n/b) + f(n)       se n > 1

dove f(n) = T_split(n) + T_merge(n)
```

Devono essere valide alcune condizioni:

1. a >= 1
2. b > 1
3. f(n) >= 0 _per n sufficientemente grande_
4. n > 1

inoltre _d = log(b)a_

Voglio confrontare _asintoticamente_ **f(n)** e **g(n)=n^d**-

5. epsilon > 0 _deve esistere_


> f(n) = **O(n^(d-epsilon))**   =>    T(n) = Teta(**n^d**)<br>
> _f(n) cresce meno velocemente di n^d_


> f(n) = **Teta(n^d)**    =>    T(n) = Teta(**n^d * logn**)<br>
> _f(n) e g(n) crescono in modo simile


> f(n) = **Omega(n^(d+epsilon))** + **condizione ausiliaria**   =>    T(n) = Teta(**f(n)**)<br>
> _condizione ausiliaria : esiste c<1 t.c. p.n.s.g. a\*f(n/b) <= c\*f(n)_<br>
> _f(n) cresce più velocemente di g(n)_
