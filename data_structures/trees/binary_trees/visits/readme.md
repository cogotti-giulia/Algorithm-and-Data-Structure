## Visite alberi binari

### Visita generale

```pseudocode
    visita_generale(r)
        S = {r}
        while S != 0    #insieme vuoto
            estrai un nodo u da S
            visita il nodo u
            S = S U {figli di u}
        
```

#### Analisi complessità

L'algoritmo di visita_generale applicato alla radice di un albero con n nodi termina in **O(n)** iterazioni e richiede uno spazio in memoria di **O(n)**.

_Dimostrazione_

Ipotesi: inserimento e cancellazione da S sono effettuate in tempo **costante**<br>
so che ogni nodo verrà inserito ed estratto da S _una sola volta_ dato che non posso risalire al padre dai figli del nodo, ma allora
- le iterazioni del ciclo _while_ possono essere al più n ~> **T(n) = O(n)**
- dato che ogni nodo compare al più una volta in S ~> **S(n) = O(n)**

### Visite
**Visita in preorder (DFS):** si visita la radice, poi si eseguono le chiamate ricorsive ai figli sinistro e destro.
```pseudocode
visita_preorder_DFS(u)
    if u != NIL
        visita il nodo u
        visita_preorder_DFS(u.left)
        visita_preorder_DFS(u.right)
```

**Visita in order (simmetrica):** si esegue la chiamata ricorsiva al figlio sinistro, si visita la radice e poi si effettua la chiamata ricorsiva al figlio destro.

```pseudocode
vista_in_order(u)
    if u != NIL
        visita_in_order(u.left)
        visita il nodo u
        visita_in_order(u.right)
```

**Visita in postorder:** si eseguono le chiamate ricorsive ai figli sinistro e destro e infine si visita la radice.

```pseudocode
visita_in_postorder(u)
    if u != NIL
        visita_in_postorder(u.left)
        visita_in_postorder(u.right)
        visita il nodo u
```


**Visita in ampiezza/livelli (BFS):** l'insieme S si implementa utilizzando una coda fifo per scorrere i livelli dell'albero.

```pseudocode
visita_BFS(r)
    Queue q
    q = new Queue
    enqueue(q, r) #inserisce il nodo r nella coda
    while notQueueEmpty(q)
        u = dequeue(q) #estrae il nodo u
        if u != NIL
            visita il nodo u
            #inserisce i figli nella code
            enqueue(q, u.left)
            enqueue(q. u.right)
```


#### Esempio
```
            A           ~ pre order     A E R L B O
          /   \         ~ in order      E L R A B O   
         L     B        ~ post order    E R L O B A
        / \     \       ~ livelli       A L B E R O
       E   R     0
```

<br>

### Schema per risolvere problemi decomponibili

```pseudocode
decomponibile(u)
    if u == NIL     #caso base
        < risolvi direttamente >
    else
        risSX = decomponibile(u.left)
        risDX = decomponibile(u.right)
        return ricombina(risSX, risDX, u)
```

#### Analisi complessità

Ogni nodo viene attraversato un numero _costante_ di volte per cui, se l'esecuzione del _caso base_ e di _ricombina_ richiede un tempo costante, l'esecuzione di **decomponibile** richiede un tempo complessivo di **O(n)**. 

Dunque **T(n) = O(n)**.
