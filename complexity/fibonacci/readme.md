## Fibonacci

**Definizione di fibonacci**

```
      --- 1                 n=1,2
Fn = |
      --- F(n-1) + F(n-2)   n>=3
```

### Formula di Binet

```
fi = [1 + sqrt(5)]/2 = 1.618...
fi_cap = [1 - sqrt(5)]/2 = 0.618... = 1 - fi

formula di binet

Fn = [1/sqrt(5)] * (fi^n - fi_cap^n)
```

```c++
const double fi = (1 + std::sqrt(5)) / 2;
const double fi_cap = (1 - std::sqrt(5)) / 2; // 1 - fi

int fib_binet(int n) {
  return (1 / std::sqrt(5)) * (std::pow(fi, n) - std::pow(fi_cap, n));
}
```

Il tempo richiesto risulta essere costante, **T(n) = Teta(1)**.<br>
Lo spazio utilizzato è costante.

> **Non** è corretto! (problemi di ottimizzazione)

### Algoritmo ricorsivo

```c++
int fib_ric(int n) {
  if (n <= 2)
    return 1;
  else
    return fib_ric(n - 1) + fib_ric(n - 2);
}
```

> È corretto (è la definizione)

Lo spazio utilizzato è lineare, _S(n) = n_<br>
Il tempo richiesto è esponenziale, **T(n) = 2^n**

```
albero ricorsioni

n = 5
T(n) = 4(2) + 5(1)

                fib(5)
               /      \
            fib(4)    fib(3)
            / \         /  \ 
      fib(3) fib(2) fib(2) fib(1)
         /  \
   fib(2)  fib(1)

~> T(n) = 2i(Tn) + f(Tn) 

i(Tn) : nodi interni
f(Tn) : nodi foglia
```

T(n) = 2+T(n-1) + T(n-2) =
     = 2i(Tn) + f(Tn) = 2(Fn-1) + Fn = 3Fn-2 ~> **T(n) = Fn = 2^n**

#### Proprietà importanti

1. **f(Tn) = Fn** : Tn è l'albero delle ricorsioni
2. **i(T) = f(T)-1** : T albero binario

### Algoritmo iterativo

```c++
int fib_iter_arr(int n) {
  int fibi[n];
  fibi[0] = 1;
  fibi[1] = 1;

  for (int i = 2; i < n; i++)
    fibi[i] = fibi[i - 1] + fibi[i - 2];

  return fibi[n-1];
}
```

Lo spazio richiesto risulta essere lineare (array): _S(n) = n_<br>
Il tempo complessivo (per n>=3) risulta: T(n) = c + (n-1) + (n-2) = 2n ~> **T(n) = n**

```c++
int fib_iter(int n) {
  int a = 1;
  int b = 1;

  for (int i = 2; i < n; i++) {
    int c = a + b;
    a = b;
    b = c;
  }

  return b;
}
```

Lo spazio richiesto risulta essere costante (tre variabili): _S(n) = Teta(1)_<br>
Il tempo complessivo (per n>=3) risulta: **T(n) = n**
