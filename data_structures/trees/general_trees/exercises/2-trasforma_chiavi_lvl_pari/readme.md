## Esercizio

Sia T un albero generale i cui nodi hanno chiave intera e i campi key, left_child e right_sibling. Scrivere una procedura ricorsiva che trasforma T dimezzando i valori di tutte le chiavi sui livelli pari dell'albero.

```
livello
   0                50           <~ trasformo
                /         \
   1           8          2      <~ lo salto
             / | \      / | \
   2        20 12 4   -12 18 80  <~ trasformo

trasforma(u = 50)

   0                25
                /         \
   1           8          2
             / | \      / | \
   2        10 6 2    -6  9 40
```

### Codice funzione

```pseudocode
# @pre: u.key != 0
trasforma(u)
  if u != NIL
    u.key = u.key/2
    trasforma(u.right_sibling) #anche i fratelli di u sono a livello pari
    iter = u.left_child
    while(iter!=nullptr)
      trasforma(u.left_child) #i figli sono a livello pari
      iter = iter.right_sibling
```

```c++
/*@pre: u.key != 0*/
void trasforma(pnode u){
  if(u != nullptr){
    u.key = u.key/2;
    trasforma(u.right_sibling);

    pnode iter = u.left_child;
    while(iter != nullptr){
      trasforma(iter.left_child);
      iter = iter.right_sibling;
    }
  }
}
```

#### Analisi complessità

Ogni nodo è visitato _esattamente_ una volta quindi il tempo richiesto risulta essere **T(n) = Teta(n)**