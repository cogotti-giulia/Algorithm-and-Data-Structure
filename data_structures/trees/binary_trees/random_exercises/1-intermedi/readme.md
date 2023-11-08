## Esercizio

Un albero binario è detto intermedio se la somma delle chiavi contenuta nei nodi del
sotto albero di cui u è radice, è uguale alla somma delle chiavi contenute nei nodi sul
percorso che collega u alla radice dell'albero (u escluso).
Scrivere una funzione efficiente che calcoli il numero di nodi intermedi e calcolarne la complessità.

```
        17 (root)
      /    \
(v) 17     0 (u)
          /   \
         7     9
        /
       1

17 somma chiavi da root (17) a nodo u (u.key=0)
1+7+9+0 = 17 somma nodi nel sotto albero di u (u.key=0)
=> u è intermedio

17 somma chiavi da root (17) a nodo v (v.key=*17)
17 = 17 somma nodi nel sotto albero di v (v.key=1)
=> v è intermedio

~> #intermedi = 2
```

Le informazioni mi arrivano dai discendenti, quindi mi conviene fare un visita in post order!

### Codice funzione

```pseudocode
intermedi(r)
    #ris è il numero di nodi intermedi
    #sumK è la somma delle chiavi nel sotto albero
    <ris, sumK> = intermedi_AUX(r, 0);
    return ris;

#sumpercorso somma lungo il percorso che va dalla radice a u
intermedi_AUX(u, sumPercorso)
    if u == NIL
        return <0, 0>
    else
        <risSX, sumkSX> = intermedi_AUX(u.left, sumPercorso+1);
        <risDX, sumkDX> = intermedi_AUX(u.right, sumPercorso+1);

        sum = sumkSX + sumkDX + u.key;
        if(sum == sumPercorso)
            return <risSX+risDX+1, sum>
        else
            return <risSX+risSX, sum>


```

```c++
int intermedi(pnode r){
    int sumKeys = 0; //somma chiavi sotto albero
    return intermedi_AUX(r, 0, &sumKeys);
}

int intermedi_AUX(pnode u, int sumPercorso, int *sumKeys){
    if(u == nullptr){
        *sumKeys = 0;
        return 0;
    }else{
        int sumKeysSX = *sumKeys;
        int risSX = intermedi_AUX(u->left, sumPercorso + u->key, &sumKeysSX);

        int sumKeysDX = *sumKeys;
        int risDX = intermedi_AUX(u->right, sumPercorso + u->key, &sumKeysDX);

        int sum = sumKeysDX+sumKeysSX+u->key;
        if(sum == sumPercorso){
            *sumKeys = sum;
            return risSX + risDX +1;
        }else{
            *sumKeys = sum;
            return risSX + risDX;
        }
    }
}
```

#### Analisi complessità

```
        --- c                 se n=0
T(n) = |
        --- T(k)+T(n-k-1)+d   se n>0
```

Risolvo la ricorrenza tramite il **metodo della sostituzione**.

Assumo che T(n) = an + b (generica funzione lineare).
Dimostro che ho ragione per induzione su a e b.

_Caso base_<br>
n = 0 <br>
T(0) = b<br>
[per definizione] T(0) = c<br>
questo implica che **b = c**

_Passo induttivo_<br>
Assumo che per m < n sia vero che T(m) = am + b e dimostro per n<br>
[per definizione] T(n) = T(k)+T(n-k-1)+d<br>
[dato che k < m e (n-k-1) < m applico l'ipotesi induttiva]<br>
[per ip. induttiva] T(k)+T(n-k-1)+d = ak+b + a(n-k-1)+b + d = an-a+2b+d<br>

ora mi chiedo se è vero che T(n) = an-a+2b+d ?= an+b<br>
-a+b+d = 0 ~> a = b+d<br>
[per caso base] b+d = c+d quindi a = c+d<br>

ma allora **T(n)=(c+d)n + c = Teta(n)** !
