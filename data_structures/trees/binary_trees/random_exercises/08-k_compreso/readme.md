## Esercizio

Sia T un albero binario i cui nodi x hanno i campi left, right e key, dove key è un numero intero. L’albero si dice k-compreso, per un certo numero naturale k, se per ogni nodo x la somma delle chiavi dei nodi dell’albero radicato in x è compresa tra -k e k.

1. Scrivere una funzione efficiente in C o C++ k_compreso(u,k) che dato in input la radice u di un albero T e un valore k verifica se T è k-compreso e ritorna 1 se T è k-compreso, 0 altrimenti.
2. Valutare la complessità della funzione, indicando eventuali relazioni di ricorrenza e la loro risoluzione tramite il metodo di sostituzione.

```
            5
          /   \
         4    -2
        / \
       0   7
          / \
        -3   1

è 12 compreso
non è 11 compreso
```

L'idea è quella di calcolare le somme contenute nei sotto alberi sx e dx e vedere se le somme più la key alla radice hanno un valore compreso tra -k e k.

### Codice

```c++
bool k_compreso(pnode u, int k) {
  int sum = 0;
  return k_compreso_aux(u, k, &sum);
}

bool k_compreso_aux(pnode u, int k, int *sum) {
  if (u == nullptr) {
    *sum = 0;
    return true;
  } else {
    int sumSX, sumDX;

    k_compreso_aux(u->left, k, &sumSX);
    k_compreso_aux(u->right, k, &sumDX);

    *sum = sumSX + sumDX + u->key;

    if (*sum >= -k && *sum <= k)
      return true;
    else
      return false;
  }
}
```

#### Analisi complessità

Ogni nodo viene visitato al più una volta, dunque la complessità risulta essere **T(n) = Teta(n)**

Analizzando il codice si ottiene la seguente ricorrenza

```
        --- c                     se n=0
T(n) = |
        --- T(k) + T(n-k-1) + d   se n>0

dove
k : nodi presenti nel sotto albero sx
n-k-1 : nodi presenti nel sotto albero dx
```

Si risolve tramite il _metodo di sostituzione_.

Assumo che **T(n) = an + b** (generica funzione lineare) e dimostro che ho ragione tramite induzione.

_caso base_<br>
n=0<br>
T(0) = b<br>
[per ipotesi, vedi ricorrenza] T(0) = c<br>
ma allora **b=c**

_passo induttivo_<br>
assumo che per m < n vale che T(m) = am + b e dimostro che allora è vero anche per n.

[per definizione] T(n) = T(k) + T(n-k-1) + d<br>
[dato che k < n e (n-k-1) < n posso applicare l'ipotesi induttiva]<br>
[per ip.induttiva] T(n) = ak+b + a(n-k-1)+b + d = an -a +2b +d

mi chiedo se è vero che an-a+2b+d ???=??? an+b<br>
an-a+2b-an-b +d= 0<br>
-a+b+d = 0 ~> a = b + d

[dal caso base] b + d = c + d

ma allora T(n) = (c+d)n + c e quindi **T(n) = Teta(n)**
