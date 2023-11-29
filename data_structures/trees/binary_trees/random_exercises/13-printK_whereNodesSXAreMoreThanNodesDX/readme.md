## Esame 06/06/2022

Sia T un albero binario. Si vogliono stampare le chiavi di T memorizzate in nodi il cui sottoalbero radicato nel figlio sinistro contiene più chiavi del sottoalbero radicato nel figlio destro.

1. Si rappresenti un albero binario di ricerca la cui visita in pre ordine ha come risultato 30, 25, 21, 40, 35, 45. Si mostri quali chiavi verrebbero stampate in base alla condizione sopra descritta.
2. Scrivere una procedura efficiente in C o C++ per risolvere il problema proposto.
3. Valutarne la complessità.

```
visita pre order
30 ~> 25 ~> 21 ~> 40 ~> 35 ~> 45 

BST
            30
           /  \
         25    40
         /    /  \
       21    35  45

La procedura stamperebbe 25 perché i nodi del sottoalbero radicato nel figlio sinistro sono maggiori dei nodi radicati nel sottoalbero destro(che è NIL)
```

## Idea

Tramite una visita in post order vado in ricorsione sui sottoalberi sinistro e destro, conto i nodi in ciascuno e, se i nodi a sinistra sono di più rispetto a quelli a destra allora stampo la chiave del nodo corrente. 

## Codice c++

```c++
void stampaK_nodeSX_mag_nodeDX(pnode u) { 
  stampaK_nodeSX_mag_nodeDX_AUX(u); 
}

int stampaK_nodeSX_mag_nodeDX_AUX(pnode u) {
  if (u == nullptr)
    return 0;
  else {
    int totSX, totDX;
    totSX = stampaK_nodeSX_mag_nodeDX_AUX(u->left);
    totDX = stampaK_nodeSX_mag_nodeDX_AUX(u->right);

    if (totSX > totDX)
      std::cout << u->key << " ";

    int tot = totSX + totDX + 1;
    return tot;
  }
}
```

#### Analisi complessità

Il tempo di esecuzione risulta essere **T(n) = Teta(n)**, dove n rappresenta il numero di nodi dell'albero, ottenuto risolvendo la seguente ricorrenza tramite _metodo di sostituzione_.

```
        --- c                     n = 0
T(n) = |
        --- T(k) + T(n-k-1) + d   n > 0
```