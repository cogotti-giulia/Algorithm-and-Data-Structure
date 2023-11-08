## Alberi generali

Rappresentazione basata su strutture collegate dove ogni nodo x contiene la chiave (contenuto informativo del nodo) e un puntatore a figlio sinistro e fratello destro (opzionale anche il puntatore al padre).

```
            A
          /   \
         L     B
        / \     \
       E   R     O

~ lc: p. left_child
~ rs: p. right_sibling
~ ^ : p. null

             +---[lc: A :^]                    
             |                            
             v                                      
    +---[lc: L :rs]--->[lc: B :^]               
    |                   |                          
    |                   +-------+
    |                           |
    v                           v
[^: E :rs]--->[^: R :^]     [^: O :^]
```

