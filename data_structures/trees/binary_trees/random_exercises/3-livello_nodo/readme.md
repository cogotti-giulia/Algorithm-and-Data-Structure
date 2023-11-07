Sia T un albero binario. Il **livello** di un nodo è la sua distanza dalla radice.<br>
Dato k>=0, scrivere una funzione efficiente che stampa le chiavi contenute nei nodi a livello k.

```
        1           lvl. 0
       / \
      2   3         lvl. 1
         / \
        4   5       lvl. 2
       /
      6             lvl. 3

se k = 2 ~> print 4 5
```

### Codice funzione

```pseudocode
#@pre: k>=0
void stampa_livello(u, k)
    if u != NIL
        if k == 0
            print u.key;
        else
            stampa_livello(u.left, k-1)
            stampa_livello(u.right, k-1)
```

```c++
/* @pre: k>=0 */
void stampa_livello(pnode u, int k){
    if(u != nullptr){
        if(k == 0)
            std::cout<<u->key<<" ";
        else{
            stampa_livello(u->left, k-1);
            stampa_livello(u->right, k-1);
        }
    }
}
```

### Complessità

#### Rispetto a n = numero nodi nell'albero

```
        --- c                   n = 0
T(n) = |
        --- T(m)+T(n-m-1)+d     n > 0
dove m rappresenta i nodi visitati nel sotto albero sinistro

~> T(n) = O(n)
```

Risolvo la ricorrenza tramite il **metodo di sostituzione**

Assumo che T(n) = an + b (generica funzione lineare).
Dimostro che ho ragione tramite induzione su a e b.

_Caso base_<br>
n=0<br>
T(0) = b<br>
[per definizione] T(0) = c<br>
questo implica che **b = c**

_Passo induttivo_<br>
Assumo che per r < n sia vero che T(r) = ar + b e dimostro per n<br>
[per definizione] T(n) = T(m)+T(n-m-1)+d <br>
[dato che m < n e (n-m-1) < n posso applicare l'ipotesi induttiva]<br>
[per ip. induttiva] T(m)+T(n-m-1)+d = am+b + a(n-m-1)+b + d = an-a+2b+d

ora mi chiedo se è vero che T(n) = an-a+2b+d **?=** an+b<br>
-a+b+d = 0 ~> a = b+d <br>
[per caso base] b+d = c+d quindi a = c+d

ma allora **T(n) = (c+d)n + c = Teta(n)**

In questo caso potrei non dover visitare tutti i nodi ma fermarmi prima, quindi **T(n) = O(n)**

#### Rispetto a k = livelli nell'albero

```
        --- c           n = 0
T(k) = |
        ---2T(k-1)+d    n > 0

~> T(n) = Teta(2^k)
```

Purtroppo non posso usare il master theorem :(, quindi userò l'**albero delle ricorsioni**

```
        d                          d
      /   \         ~>           /   \     
  T(k-1)  T(k-1)            d             d
                          /   \         /   \
                      T(k-1) T(k-1)  T(k-1) T(k-1) 


continuando ad espandere l'albero avrò

                                        costo livello
                d                       ~ d
              /   \
             d     d                    ~ 2d
           /  \  /  \
          d   d d    d                  ~ 2^2d
               ...
               ...
    d    ...    d     ...   d           ~ 2^(k-1)d -> T(k-(k-1))
  /   \       /   \       /   \
T(0) T(0)   T(0) T(0)   T(0) T(0)       ~ T(1)
  |    |      |    |      |    |  
  c    c      c    c      c    c        ~ 2*2^(k-1)c = 2^c

      k-1                    k-1
T(k) = E (2^i)*d + (2^k)*c = d* E 2^i + (2^k)*c = 
      i=0                    i=0
     = d((2^(k-1+1)-1)/2-1) + (2^k)*c = d*(2^k -1)+(2^k)*c = 
     = Teta(2^k)
```