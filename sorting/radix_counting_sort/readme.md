# Algoritmi di ordinamento NON basati su confronti

## Counting sort

Utilizzato quando i numeri da ordinare sono _interi_ in un **intervallo** (insieme limitato) che va da 0 a k (con k appartenente ai numeri interi).

input: A[1...n], dove A[j] in [0...k] per ogni j in{1,..,n}<br>
output: B[1...n] _ordinato_<br>
memoria ausiliaria: C[0...k] _vettore delle occorrenze_

> **Stabile** se scorro dalla fine dell'array!

```pseudocode
counting_sort(array A, array B, int n, int k)
  /*alloca C di k+1 elementi*/
  for(i = 0 to k) 
    C[i] = 0

  /* a */
  for(j = 1 to n)
    C[A[j]]++

  /* b */
  for(i = 1 to k)
    C[i] = c[i] + c[i-1]
  
  /* c */
  for(j = n down to 1)
    B[C[Aj]] = A[j]
    C[A[j]]--
```

### Simulazione counting sort

```
A <3 0 2 3 2>

k = 3

c | 0 | 0 | 0 | 0 | 
```

```
/* a */
C[i] = |{x in {1...n} t.c. A[x] = i}|
C | 1 | 0 | 2 | 2 |
    0   1   2   3
```

```
/* b */
C[i] = |{x in {1...n} t.c. A[x] <= i}|
C | 1 | 1 | 3 | 5 |
    0   1   2   3
```

```
/* c */
C | 1 | 1 | 3 | 5 |
    0   1   2   3
            ^ --- B | | | 2 | | |
                     0 1  2  3 4
          lo mette lì perché ci sono
        3 elementi minori o uguali a 2!

C | 1 | 1 | 2 | 5 |
    0   1   2   3
                ^ - B | | | 2 | | 3 |
                       0 1  2  3  4

C | 1 | 1 | 2 | 5 |
    0   1   2   3
            ^ --- B | | 2 | 2 | | 3 |
                     0  1   2  3  4

C | 1 | 1 | 2 | 5 |
    0   1   2   3
    ^ ----------- B | 0 | 2 | 2 | | 3 |
                      0   1   2  3  4

C | 1 | 1 | 2 | 5 |
    0   1   2   3
                ^ - B | 0 | 2 | 2 | 3 | 3 |
                        0   1   2   3   4
```

### Complessità counting sort

- n dimensione array da ordinare
- k limite superiore intervallo dei numeri dell'array

Il tempo di esecuzione risulta essere **T(n) = Teta(n + k)**. Se _k_ è _costante_ allora il tempo si riduce a _Teta(n)_, ma nello sfortunato caso in cui _k = n^2_ la complessità sale e diventa quadratica (_Teta(n^2)_)

## Radix sort

Ordina elementi con **d** cifre, dove la cifra 1 è la meno significativa e la d la più significativa.

```
   _______ _
  |_______|_|
   d       1
```

```pseudocode
radix_sort(array A, int d)
  for(i = 1 to d)
    /* usa un algoritmo di ordinamento STABILE per ordinare l'array A sulla cifra i, spesso si utilizza il counting sort! */
```

### Correttezza radix sort

Dimostrazione sulla _i-esima_ cifra da ordinare:

- _i = 1:_ ordina la colonna
- _i != 1:_ assumo che le cifre dalla colonna i alla i-1 siano ordinate e dimostro che un **algoritmo stabile** sulla colonna i lascia le colonne 1,2,..,i _ordinate:
  ```
  se due cifre sulla colonna i sono uguali, restano ordinate per stabilità e, per ipotesi induttiva, sono ordinate

  se due cifre sulla colonna i sono diverse, allora l'algoritmo di ordinamento sulla colonna i le ordina e le mette in posizione corretta
  ```

### Complessità radix sort

Dati

- n numeri
- d cifre
- massimo k valori per cifra

Allora, assumendo che l'algoritmo stabile impieghi un tempo pari a Teta(n+k), si ottiene come tempo di esecuzione _T(n) = Teta(**d***(n+k))_ ~> **T(n) = Teta(n+k)**

## Esempi di utilizzo

[Ordinare un insieme di parole](../random_exercises/05-ordina_insieme_parole/readme.md)