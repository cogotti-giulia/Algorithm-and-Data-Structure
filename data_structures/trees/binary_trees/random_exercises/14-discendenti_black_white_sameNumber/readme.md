## Esame 23/01/2014 (esercizio I)

Dato un albero binario i cui nodi sono colorati di bianco o di nero, scrivere una funzione C (o c++) efficiente che calcoli il numero di nodi aventi lo stesso numero di discendenti bianchi e neri. (Un nodo è discendente di se stesso.) Inoltre analizzare la complessità di tale algoritmo.

Il tipo Node in c utilizzato per rappresentare l’albero binario è il seguente:

```c
typedef struct node{
  char * colore;
  struct node * left;
  struct node * right;
} * Node;
```

### Idea!

Effettuo una visita in post order per calcolare il numero di discendenti bianchi e neri del nodo. Quindi calcolo i nodi bianchi e neri dei sottoalberi sinistro e destro, se il nodo corrente è nero lo aggiungo al mio contatore di nodi neri, altrimenti a quello dei nodi bianchi. Se il numero di neri e bianchi (compresa la radice del sottoalbero) è uguale allora conto quel nodo, altrimenti no.

```
         (b)
        /   \
      (w)     w
      / \    /
     b   w  (b)
      \    /  \
       b  w    b
              /
             w

~> 3 nodi!
```

### Codice c++

```c++
int discendenti_bw_sameNum(pnode u) {
  int totBlack = 0;
  int totWhite = 0;
  return discendenti_bw_sameNum_aux(u, &totBlack, &totWhite);
}

int discendenti_bw_sameNum_aux(pnode u, int *totBlack, int *totWhite) {
  if (u == nullptr) {
    *totBlack = 0;
    *totWhite = 0;
    return 0;
  } else {
    int totBlackSX, totWhiteSX;
    int totBlackDX, totWhiteDX;

    int risSX = discendenti_bw_sameNum_aux(u->left, &totBlackSX, &totWhiteSX);
    int risDX = discendenti_bw_sameNum_aux(u->right, &totBlackDX, &totWhiteDX);

    if (u->color.compare("black") == 0)
      *totBlack = totBlackDX + totBlackSX + 1;
    else
      *totBlack = totBlackDX + totBlackSX;

    if (u->color.compare("white") == 0)
      *totWhite = totWhiteSX + totWhiteDX + 1;
    else
      *totWhite = totWhiteSX + totWhiteDX;

    if (*totWhite == *totBlack)
      return risSX + risDX + 1;
    else
      return risSX + risDX;
  }
}
```

#### Analisi complessità

Il tempo di esecuzione risulta essere **T(n) = Teta(n)**, dove n rappresenta il numero di nodi dell'albero. In particolare esso si ottiene risolvendo la seguente ricorrenza tramite _metodo di sostituzione_.

```
        --- c                         n = 0
T(n) = |
        --- T(k) + T(n-k-1) + d       n > 0

k: nodi sottoalbero sx
n-k-1: nodi sottoalbero dx
d: costo alla radice
```

Assumo che **T(n) = an+b** (generica funzione lineare) e dimostro che ho ragione per induzione.

_caso base_<br>
n = 0<br>
T(n) = b<br>
[per definizione] T(n) = c<br>
ma allora c = b

_passo induttivo_
assumo che per m < n valga T(m) = am+b e dimostro che allora vale anche per n

[per definizione] T(n) = T(k) + T(n-k-1) + d<br>
[dato che k < n e (n-k-1) < n posso applicare l'ipotesi induttiva]<br>
[per ip. induttiva] T(n) = ak+b+a(n-k-1)+b+d = an+2b+d-a

mi chiedo se è vero che T(n) = an+b ?=? an+2b+d-a<br>
~> an+b = an+2b +d-a ~> a = b+d

[per caso base] so che b = c, ma allora a = c+d

quindi T(n)=(c+d)n + c = Teta(n)