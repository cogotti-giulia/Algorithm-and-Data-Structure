## Esercizio

Dato un albero binario con radice r, verificate se è un binary search tree.

### 1. Implementazione utilizzando la definizione di BST

> sia x un nodo in un albero binario di ricerca, allora:
>
> - se y è un nodo nel sotto albero sinistro di x allora y.key <= x.key
> - se y è un nodo nel sotto albero destro di x allora y.key >= x.key

Quindi mi basta controllare che la proprietà sia verificata nei due sotto alberi e verificare che anche la radice rispetti la condizione di BST.

```
    caso 1: u.left == nil
    + ----------------- +
    |                   |
    |         O         |   risSX = true
    |       /   \       |   minSX = u.key
    |     nil   /\      |   maxDX = u.key
    |           ¯¯      |
    + ----------------- +

    caso 2: u.right == nil
    + ----------------- +
    |                   |
    |         O         |   risDX = true
    |       /   \       |   minDX = u.key
    |      /\   nil     |   maxDX = u.key
    |      ¯¯           |
    + ----------------- +

    (1) e (2) coprono anche il caso in cui u sia una foglia

    caso 3: u.left != nil e u.right != nil
    + ----------------- +
    |                   |
    |         O         |   <risSX, minSX, maxSX> = check_BST_DEF_AUX(u.left)
    |       /   \       |   <risDX, minDx, maxDx> = check_BST_DEF_AUX(u.right)
    |      /\   /\      |
    |      ¯¯   ¯¯      |
    + ----------------- +

    Una volta ottenuti i risultati dei due sotto alberi si fa il check sulla radice (il valore di u.key deve rispettare la proprietà di BST)
```

```pseudocode
check_BST_DEF(u)
    if u == NIL
        return true     # albero vuoto è un BST
    else
        <ris, min, max> = check_BST_DEF_AUX(u)

check_BST_DEF_AUX(u)
    if u.left == NIL    # caso 1
        # u.left è vuoto quindi è BST
        risSX = true
        # minimo e massimo sono uguali ad u
        # dato che non esiste un sotto albero sinistro di u
        minSX = u.key
        maxSX = u.key
    else
        # caso 3
        <risSX, minSX, maxSX> = check_BST_DEF_AUX(u.left)


    if u.right == NIL
        risDX = true
        min_DX = u.key
        max_DX = u.key
    else
        <risDX, minDX, maxDX> = check_BST_DEF_AUX(u.right)



    # i sotto alberi non sono BST
    # oppure la radice non rispetta la condizione
    if !risSX or !risDX or u.key > maxSX or u.key > minDX
        return <false, - , - >
    else
        return <true, minSX, maxDX>
```

```c++
bool check_BST_DEF(pnode u){
    if(u == nullptr)
        return true;
    else{
        int min = u.key;
        int max = u.key;

        return check_BST_DEF_AUX(u, &min, &max);
    }
}

bool check_BST_DEF_AUX(pnode u, int *min, int *max){
    bool risSX, risDX;
    int minSX, maxSX, minDX, maxDX;

    if(u->left == nullptr){
        risSX = true;
        minSX = u->key;
        maxSX = u->key;
    }else
        risSX = check_BST_DEF_AUX(u->left, &minSX, &maxSX);

    if(u->right == nullptr){
        risDX = true;
        minDX = u->key;
        maxDX = u->key;
    }else
        risDX = check_BST_DEF_AUX(u->right, &minDX, &maxDX);

    if(!risSX || !risDX || u->key < maxSX || u->key > minDX)
        return false;
    else{
        *min = minSX;
        *max = maxDX;
        return true;
    }
}
```

#### Analisi complessità

```
        --- c                   se n = 0
T(n) = |
        --- T(k) + T(n-k-1) +d  se n > 0

dove k rappresenta i nodi visitati nel sotto albero sinistro
e (n-k-1) quelli visitati nel sotto albero destro
```

Risolvo la ricorrenza tramite il **metodo di sostituzione**

Assumo che T(n) = an + b (generica funzione lineare).
Dimostro che ho ragione tramite induzione su a e b.

_Caso base_<br>
n = 0<br>
T(0) = b<br>
[per definizione] T(0) = c<br>
questo implica che **b = c**

_Passo induttivo_
Assumo che per m < n sia vero che T(m) = am + b e dimostro per n.

[per definizione] T(n) = T(k) + T(n-k-1) + d<br>
[dato che k < n e (n-k-1) < n posso applicare l'ipotesi induttiva]<br>
[per ip. induttiva] T(n) = ak +b + a(n-k-1) + b + d = an + 2b -a +d <br>

ora mi chiedo se è vero che T(n) = an + 2b -a +d **?=** an + b <br>
-a + b + d = 0 ~> a = b + d<br>
[per caso base ] b+d = c+d quindi a = c+d<br>

ma allora **T(n)=(c+d)n + c = Teta(n)** !

<br>

### 2. Implementazione utilizzando la proprietà dell'attraversamento simmetrico

> T è un _BST_ **se e solo** se la visita simmetrica elenca le chiavi in ordine _non decrescente_

```pseudocode
check_BST_NO_DEF(u)
    if u == NIL
        return true
    else
        is_bst = true;  # non ho motivi per supporre che non sia bst
        u = tree_minimum(u);
        while(u != NIL and is_bst)
            succ = tree_successor(u)
            if succ != NIL and succ.key < u.key
                is_bst = false
            else
                u = succ
        return is_bst
```

```c++
bool check_BST_NO_DEF(pnode u) {
    if (u == nullptr)
        return true;
    else {
        bool is_bst = true;
        pnode x = tree_minimum(u);
        pnode y = tree_successor(x);

        if (y->key < x->key) {
            is_bst = false;
        } else {
            x = tree_successor(y);
            while (x != nullptr && is_bst) {
                if (x->key < y->key)
                    is_bst = false;
                y = x;
                x = tree_successor(x);
            }
        }
        return is_bst;
    }
}
```
#### Analisi complessità
La funzione effettua una visita simmetrica nella quale potrei fermarmi prima di visitare tutti i nodi (nel caso in cui sia violata la proprietà), quindi se considero n come il numero di nodi dell'albero la complessità risulta essere **T(n) = O(n)**

#### Dimostrazione proprietà

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
