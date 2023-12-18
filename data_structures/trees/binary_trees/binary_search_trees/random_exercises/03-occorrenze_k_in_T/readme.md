## Esercizio

Sia T un albero binario di ricerca di altezza h e avente n nodi con chiavi intere eventualmente ripetute. Si progetti un algoritmo efficiente che, ricevuto in ingresso T e un intero k, conta il numero di occorrenze di k in T.
Analizzare la complessità dell’algoritmo.

```
              7
           /    \
          1      9
         / \    / \
       -2  3   7   9
            \       \
             7      12

k = 3 ~> 1 occorrenza di k
k = 5 ~> 0 occorrenze di k
k = 7 ~> 3 occorrenze di k
k = 9 ~> 2 occorrenze di k
```

Utilizzo una proprietà utile dei BST

> se T è BST => la visita simmetrica elenca le chiavi in ordine NON decrescente

Quindi, effettuando una visita simmetrica, trovo la prima occorrenza di k (se esiste). Una volta trovata continuo a visitare l'albero allo stesso modo (incrementando le occorrenze che per forza saranno in posizioni successive) e mi fermo quando la chiave del nodo che sto analizzando risulta diversa da k

### Codice funzione

```pseudocode

occorrenze_k(T, n)
  if(T.root == NIL)
    return 0 # se l'albero è vuoto non ci sono occorrenze di k
  else
    # sono certa di avere almeno un nodo
    min = tree_minimum(T.root)
    succ = tree_successor(min)

    ris_k = 0
    found_k = false

    # se la chiave di min è uguale a k ho già trovato la prima occorrenza!
    if min.key == k
      ris_k++;
      found_k = true
    else
      # mi tocca effettuare una visita simmetrica fino a trovare la prima occorrenza di k (se esiste)
      while succ != nullptr && NOT found_k
        if succ.key == k
          found_k = true
        else
          y = succ
          succ = tree_successor(y)

    # se ho trovato la prima occorrenza di k
    if found_k
      # conto le successive occorrenze (se esistono)
      while(succ != nullptr && succ.key == k)
        ris_k++
        y = succ
        succ = tree_successor(y)

    return ris_k
```

```c++
int occorrenze_k(T t, int k) {
  if (t->root == nullptr)
    return 0;
  else {
    // esiste almeno un nodo
    pnode min = tree_minimum(t->root); /*O(h)*/
    pnode succ = tree_successor(min);  /*O(h)*/

    int ris_k = 0;
    bool found_k = false;

    // se key = k si trova nel minimo, posso già andare a scorrere e contare
    if (min->key == k) {
      ris_k++;
      found_k = true;
    } else {
      // trovo il primo nodo con chiave k se esiste e setto found_k a true
      while (succ != nullptr && !found_k) { /*O(n)*/
        if (succ->key == k)
          found_k = true;
        else {
          pnode y = succ;
          succ = tree_successor(y);
        }
      }
    }

    // se esiste almeno un nodo con chiave k, scorro i successori e conto finché
    // hanno chiave uguale a k
    if (found_k) {
      while (succ != nullptr && succ->key == k) { /*O(n)*/
        ris_k++;
        pnode y = succ;
        succ = tree_successor(y);
      }
    }

    return ris_k;
  }
}
```

#### Analisi complessità

L'attraversamento simmetrico su un BST richiede normalmente un tempo **T(n) = Teta(n)**.

Nel caso peggiore non esistono occorrenze di k, oppure esistono solo occorrenze di k. In ogni caso andrebbe effettuata una visita simmetrica completa, la quale richiederebbe un tempo di Teta(n).

Posso quindi concludere che, nel caso peggiore **T(n) = Teta(n)**, dove n rappresenta il numero di nodi dell'albero.

#### Dimostrazione della proprietà che ho usato

> se T è BST => la visita simmetrica elenca le chiavi in ordine NON decrescente

Sia T un BST con n nodi formato da x radice e due sotto alberi T1 e T2.<br>
Una visita simmetrica produce visita(T1) ~> x ~> visita(T2)

```
       (x)
     /     \ 
    /\     /\
   /T1\   /  \
   ¯¯¯¯  / T2 \
         ¯¯¯¯¯¯
```

_Caso base_<br>
T è vuoto ~> è banale

_Passo induttivo_<br>
Assumo che la proprietà sia vera per T1 e T2, entrambi aventi un numero di nodi < n e dimostro che vale anche per T.

Per ipotesi, posso affermare che:

1. T1 è un BST
2. T2 è un BST
3. per ogni y in T1 ~> y.key <= x.key
4. per ogni y in T2 ~> y.key >= x.key

ma allora, da (1) e (2) so che la visita simmetrica produrrà due sequenze di chiavi ordinate in modo non decrescente:

```
              T1                    x                   T2

      key <= ... <= key     <=    x.key   <=    key <= ... <= key
        i1            im    (3)           (4)     im+2          in
```

quindi, da (3) e (4) so che x.key è compreso tra queste due sequenze, ma allora ho finito perché le chiavi sono ordinate in modo non decrescente!