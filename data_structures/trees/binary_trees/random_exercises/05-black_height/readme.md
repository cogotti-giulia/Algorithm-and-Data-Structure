## Esercizio

Scrivere una funzione EFFICIENTE blackHeight(u) che dato in input la radice u di un albero binario, i cui nodi x hanno, oltre ai campi key, left e right, un campo col che può essere ’B’ (per “black”) oppure ’R’ (per “red”), verifica se per ogni nodo, il cammino da quel nodo a qualsiasi foglia contiene lo stesso numero di nodi neri (altezza nera del nodo x). In caso negativo, restituisce -1, altrimenti restituisce l’altezza nera della radice.

Il prototipo della funzione è:

```c++
int blackHeight(PNode u)
```

Valutare la complessità della funzione, indicando eventuali relazioni di ricorrenza.

Il tipo PNode è così definito:

```c++
struct Node {
  int key;
  char col;
  Node* left;
  Node* right;

  Node(int k, char c, Node* sx = nullptr, Node* dx = nullptr)
  : key{k}, col{c}, left{sx}, right{dx} {}
};
typedef Node* PNode;
```

```
            R
          /   \
         R     R
        / \     \
       B   B     B

altezza nera radice: 1
```

> mmh, non sono certa di aver capito bene cosa intende nel testo ma spero abbia senso ciò che ho fatto

### Codice funzione

```pseudocode
blackHeight(u)
  if u == NIL
    return 0
  else
    risSX = blackHeight(u.left)
    risDX = blackHeight(u.right)

    # condizione violata
    if risSX == -1 or risDX == -1 
      or (u.left != nullptr and u.right != nullptr and risSx != risDX)
      return -1
    else
      # perché se non esiste il sotto albero ha come altezza nera zero credo
      ris = max(risSX, risDX)

      if u.col == 'B'
        ris++
      
      return ris
```

```c++
int blackHeight(PNode u){
  if(u == nullptr)
    return 0;
  else{
    int risSX, risDX, ris;

    risSX = blackHeight(u->left);
    risDX = blackHeight(u->right);

    if(risSX == -1 || risDX == -1
      || (u->left != nullptr && u->right != nullptr && risSX != risDX))
      return -1;
    
    //so per certo che se entrambi esistono risSx = risDX
    //quindi credo funzioni dato che se uno non esiste avrà altezza nera zero
    ris = std::max(risSX, risDX);

    if(u->col == 'B')
      ris++;

    return ris;
  }
}
```

#### Analisi complessità

```
        --- c                     se n = 0
T(n) = |
        --- T(k) + T(n-k-1) + d   se n > 0
```

Risolvo la ricorrenza tramite il **metodo di sostituzione**.

Assumo che T(n) = an + b (generica funzione lineare).<br>
Dimostro che ho ragione tramite induzione su a e b.

_Caso base_<br>
n = 0<br>
T(0) = b<br>
[per caso base] T(0) = c<br>
ma allora **b = c**

_Passo induttivo_<br>
Assumo che per m < n sia vero che T(m) = am + b e dimostro per n.

[per definizione] T(n) = T(k) + T(n-k-1) + d<br>
[dato che k<n e (n-k-1)< n vale l'ipotesi induttiva]<br>
[per ip. induttiva] T(n) = ak + b + a(n-k-1) + b + d = an +2b -a +d<br>

mi chiedo se è vero che T(n) = an+2b-a+d **?=** an + b<br>
-a+b+d = 0 ~> a = b+d<br>
[per caso base] b+d = c+d ~> a = c+d

quindi **T(n) = (c+d)n + c = Teta(n)**