# Dimostrazioni proprietà utilizzate

## Alberi binari

### Ricorrenza alberi binari (chiamate ricorsive ai sottoalberi SX e DX)

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

## Alberi binari di ricerca (BST)

### Attraversamento simmetrico BST

> L'**attraversamento simmetrico** di un albero binario di ricerca di n nodi può essere implementato trovando l'elemento minore (tree_minimum) nell'albero ed effettuando poi n-1 chiamate di tree_successor.

```
Questo algoritmo viene eseguito in T(n) = Teta(n)
```

_Dimostrazione_

La chiamata a tree*minimum seguita da n-1 chiamate a tree_successor, esegue una \_visita simmetrica (in_order)*, infatti in_order stampa il minimum (tree_minimum) e poi, per definizione, il tree_successor è il prossimo nodo in una visita simmetrica!

L'algoritmo ha tempo di esecuzione Teta(n) perché

- richiede omega(n) per effettuare le n chiamate ricorsive
- attraversa ognuno degli (n-1) archi **al più** due volte, quindi O(n) (\*\*\*)

ma allora **T(n) = Teta(n)**

```
(***)
sia (u,v) un arco generico, allora:
[downward] vado da u a v in tree_minimum
[upward] vado da v a u in tree_successor quando il nodo non ha sotto albero destro
```

### Proprietà molto utile

> T è un _BST_ **se e solo** se la visita simmetrica elenca le chiavi in ordine _non decrescente_

Dimostro tramite induzione su n, numero di nodi dell'albero.

```
Assumo di aver un albero T composto dalla radice (x), sotto albero sinistro (T1) e destro (T2)

               (x)
             /     \
            /\     /\
           /  \   /T2\
          / T1 \  ¯¯¯¯
          ¯¯¯¯¯¯
visita simmetrica:  visita(T1) ~> x ~> visita(T2)
```

> **(<=)** La visita simmetrica elenca le chiavi in ordine _NON_ decrescente => T è un _BST_

_Caso base_
n = 0 ~> albero vuoto, è banale

_Passo induttivo_
n > 0 ~> assumo vera la proprietà per k < n e dimostro per n.

Una visita simmetrica, per definizione, produce _visita(T1) ~> x ~> visita(T2)_.<br>
Per ipotesi le chiavi vengono elencate in ordine non decrescente, ma allora:

1. la visita(T1) è ordinata in modo non decrescente
2. la visita(T2) è ordinata in modo non decrescente
3. x.key >= y.key per ogni y in T1
4. x.key <= y.key per ogni y in T2

Ma allora [per ipotesi induttiva] dato che T1 e T2 hanno entrambi un numero di nodi minore di n e valgono (1) e (2), posso concludere che T1 e T2 sono BST.<br>
Da (3) e (4) concludo che anche **T è un BST**!<br>

> **(=>)** T è un _BST_ => la visita simmetrica elenca le chiavi in ordine _NON_ decrescente

_Caso base_
n = 0 ~> albero vuoto, è banale

_Passo induttivo_
n > 0 ~> assumo vera la proprietà per k < n e dimostro per n.

Una visita simmetrica, per definizione, produce _visita(T1) ~> x ~> visita(T2)_.<br>
Per ipotesi so che:

1. T1 è un BST
2. T2 è un BST
3. per ogni y in T1 y.key <= x.key
4. per ogni y in T2 y.key >= x.key

Ma allora [per ipotesi induttiva] dato che T1 e T2 hanno entrambi un numero di nodi minore di n, la visita simmetrica produce due sequenze di chiavi ordinate in modo non decrescente:

```
    key   <= ... <=  key       <=       x.key      <=        key   <= ... <= key
      i1              im    [per (3)]           [per (4)]      im+2            in
```

Ho quindi enumerato [per (3) e (4)] le chiavi di T in ordine **non** decrescente!
