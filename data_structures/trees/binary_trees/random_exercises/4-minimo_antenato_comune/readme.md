Dati due nodi u e v appartenenti a un albero con _profondità_, il **minimo antenato comune(MAC)** è l'antenato comune di u e v che si trova più lontano dalla radice.

```
         1              lvl. 0
       /   \
      2     3           lvl. 1
    /     /   \
   4     5     6        lvl. 2
              /
             7          lvl. 3

~> mac(5, 7) = 3
~> mac(4, 5) = 1
~> mac(4, 2) = 2

La radice è antenato comune a tutti i nodi!
```

Dato che ho la profondità, parto dai due nodi e mi allineo fino a quando non raggiungono la stessa profondità. Se sono lo stesso nodo ho trovato l'antenato comune, altrimenti continuo a salire e al più otterrò la radice come antenato comune!

# Codice funzione

```pseudocode
mac(u, v)
    #mi allineo alla stessa profondità
    while(u.profondita != v.profondita)
        if(u.profondita > v.profondita)
            u = u.p
        else
            v = v.p

    if(u == v)
        return u
    else
        #stessa profondita ma diverso nodo
        #salgo finché non diventano lo stesso nodo
        while(u.p != v.p)
            u = u.p
            v = v.p
        return u.p
```

```c++
pnode mac(pnode u, pnode v){
    //mi allineo alla stessa profondità
    while(u->prof != v->prof){
        if(u->prof > v->prof)
            u = u->p;
        else
            v = v->p;
    }
    //sono lo stesso nodo
    if(u == v)
        return u;
    else{
        while(u->p != v->p){
            u = u->p;
            v = v->p;
        }
        return u.p;
    }
}
```

### Complessità

```
T(n) = O(h)
dove h rappresenta l'altezza dell'albero
```

Seguo un cammino che va dal nodo x alla radice, quindi al più sarà lungo quando l'altezza dell'albero.

Se l'albero fosse bilanciato **h = log(n) ~> T(n) = O(log n)**.
