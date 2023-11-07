Un albero si dice T bilanciato se per ogni nodo vale la seguente proprietà: _"le altezze dei sotto alberi radicati nei suoi due figli differiscono per al più T unità"_.<br>
Dato un albero binario, scrivere una funzione efficiente che restituisca il minimo valore t per cui l'albero risulti t bilanciato.

```
                 3  ---- h=max{0+1, 2+1} = 3
          +1 ~ /   \ ~ +1
        ^     5     7     ^
hSX     |         /       |
risSX=0 v        1        | hDX
               /   \      | risDX=2
              4     9     v

~> t = 2
```

Prendo le **altezze** dei sotto alberi, calcolo l'altezza dell'albero (massimo tra sotto albero sinistro e destro, più uno che sarebbe l'arco che collega i sotto alberi alla radice). Poi prendo il massimo tra i sotto alberi (risSX e risDX), la differenza delle altezze al nodo radice (valore assoluto di hSX - hDX), e infine calcolo il massimo tra i due valore (che è il t che sto cercando).

### Codice funzione

```pseudocode
t_bilanciato(u)
    if u == NIL
        return <0, -1>
    else
        <risSX, hSX> = t_bilanciato(u.left)
        <risDX, hDX> = t_bilanciato(u.right)
        h_tree = max{hSX, hDX}+1;
        diff_root = abs|hSX, hDX|;
        t = max{diff_root, max{risSX, risDX}};
        return <t, h_tree>
```

```c++
int t_bilanciato(pnode u){
    int h = -1;
    return t_bilanciato_AUX(u, &h);
}

int t_bilanciato_AUX(pnode u, int *h){
    if(u == nullptr){
        *h = -1
        return 0;
    }else{
        int hSX = *h;
        int risSX = t_bilanciato_AUX(u->left, &hSX);
        int hDX = *h;
        int risDX = t_bilanciato_AUX(u->right, &hDX);

        *h = max(hSX, hDX)+1;//altezza albero
        int diff_root = abs(hSX, hDX); //differenza al nodo radice

        int t = max(diff_root, max(risSX, risDX));
        return t;
    }
}
```

### Complessità

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
