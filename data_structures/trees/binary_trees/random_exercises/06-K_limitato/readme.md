## Esercizio

Sia T un albero binario i cui nodi x hanno i campi left, right, key. L’albero si dice k-limitato, per un certo valore k, se per ogni nodo x la somma delle chiavi lungo ciascun cammino da x ad una foglia è minore o uguale a k.

- Scrivere una funzione efficiente in c++ k-limitato(u,k) che dato in input la radice u di un albero T e un valore k verifica se T è k-limitato e ritorna 1 se T è k-limitato, 0 altrimenti.
- Valutare la complessità della funzione, indicando eventuali relazioni di ricorrenza.

```
k = 7

                      1       <~ sum = 7
               ^    /    \    ^
sumSX = 6      |   2      5   | sumDX = 6
(max subtrees) |  / \    /    | risSX = T
risSX = T      | 4  -2  1     v
               |    /
               V   3

~> l'albero è 7 limitato (k >= 7 ok)
~> non è 6 limitato (k < 6 not ok)
```

L'idea è quella di calcolare la somma dei sotto alberi fino ad arrivare alla radice, al primo valore che viola la condizione ritorna false; altrimenti va avanti a controllare e se è k limitato rende true.

### Codice funzione

```pseudocode
k_limitato(u,k)
       <ris, sum> = k_limitato
       return ris

k_limitato_AUX(u, k)
       if u == NIL
              return <true, 0> # albero vuoto è per forza k limitato dato che la somma è zero
       else
              <risSX, sumSX> = k_limitato(u.left, k);
              <risDX, sumDX> = k_limitato(u.right, k);

              if !risSX or !risDX > k or sumSX > k or sumDX > k
                     return <false, - > # non mi interessa la somma tanto è false

              sum = sumSX+sumDX+u.key
              return <true, sum>
```

```c++
bool k_limitato(pnode u, int k){
       int sum = 0;
       return k_limitato_AUX(u, k, &sum);
}

bool k_limitato_AUX(pnode u, int k, int *sum){
       if(u == nullptr){
              *sum = 0; // la somma è 0 dato che non esiste la chiave
              return true; // vero perché un albero vuoto è k limitato
       }else{
              int sumSX, sumDX;
              bool risSX, risDX;

              risSX = k_limitato_AUX(u->left, k, &sumSX);
              risDX = k_limitato_AUX(u->right, k, &sumDX);

              if(!risSX || !risDX || sumSX > k || sumDX > k)
                     return false; // non mi interessa la somma, tanto è false

              *sum = sumSX+sumDX+u.key;
              return true;
       }
}
```

#### Analisi complessità

```
       --- c                       se n=0
T(n) = |
       --- T(k) + T(n-k-1) + d     se n>=0
```

Risolvo la ricorrenza tramite il **metodo di sostituzione**<br>
Assumo che T(n) = an+b (generica funzione lineare) e dimostro, tramite induzione, che ho ragione.

_Caso base_<br>
n = 0<br>
T(0) = b<br>
[per definizione caso base] so che T(0) = c<br>
ma allora T(0) = b = c che implica **b=c**

_Passo induttivo_<br>
Assumo che, per m < n, valga che T(m) = am+b e dimostro per n.

[per definizione] T(n) = T(k) + T(n-k-1) + d<br>
[dato che k < n e (n-k-1) < n posso applicare l'ipotesi induttiva]<br>
[per ip. induttiva] T(n) = ak+b + a(n-k-1)+b +d = 2b +an -a +d<br>

mi chiedo se è vero che T(n)=2b+an-a+d **?=** an+b<br>
-a+b+d = 0 ~> a = b+d<br>
[per caso base] b+d = c+d, ma allora a = c+d<br>

quindi T(n) = (c+d)n + c, dunque concludo che **T(n) = Teta(n)**<br>
_(potrebbe anche essere un O(n) dato che appena trovo qualcosa che mi contraddice rendo false e basta)_
