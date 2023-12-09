## Esercizio

Dato un albero generale verificare se è **K-ARIO completo**.

> Un albero si dice k-ario completo se:
>
> - ogni nodo ha k figli
> - tutte le foglie si trovano alla stessa profondità

```
k = 3
              O             <~ ha grado k
           /  |  \
         /    |    \
       /      |      \
      O       O       O     <~ tutti i nodi hanno grado k
    / | \   / | \   / | \
   O  O  O O  O  O O  O  O  <~ foglie alla stessa profondità
```

### Codice funzione

```pseudocode
k_ario(u, k)
  <ris, h> = k_ario_AUX(u, k)
  return ris

k_ario_AUX(u, k)
  if u == NIL
    return <false, -1>
  else
    hf = -1    # non so ancora niente
    figlio = u.left_child
    grado = 0   # numero di figli del nodo
    ris = true  # assumo che sia k-ario completo
    while(figlio != NIL and ris)
      grado++   # ho un figlio sicuro
      # vado in ricorsione sul figlio
      <risF, h_SubTreeFiglio> = k_ario_AUX(figlio, k)
      if(hf == -1) #sono al primo figlio
        hf = h_SubTree_figlio #tutte le altezze dovranno essere le stesse

      ris = ris and risF and grado <= k and h_SubTreeFiglio == hf
      figlio = figlio.right_sibling

    return ris and (grado == k or grado == 0), hf+1>
```

```c++
bool is_k_ario(pnode u, int k){
  int h = -1;
  return is_k_ario_AUX(u, k, &h);
}

bool is_k_ario_AUX(pnode u, int k, int *h){
  if(u == nullptr){
    *h = -1;
    return true;
  }else{
    int hF = -1; //non so ancora nulla
    int grado = 0; //figli del nodo
    pnode figlio = u->left_child;
    ris = true; //assumo sia k ario completo

    while(figlio != nullptr && ris){
      grado++; //ho un figlio
      int h_subTreeF;
      bool risF = is_k_ario_AUX(figlio, k, h_subTreeF);

      if(hF == -1)
        hF = h_subTreeF; //setto l'altezza che deve essere uguale per tutti i figli

      ris = ris && risF && grado <= k && hF == h_subTreeF;
      figlio = figlio->right_sibling;
    }
    *h = hF;
    //grado k nodo interno, oppure grado 0 se è una foglia
    return ris && (grado == k || grado == 0);
  }
}

```

#### Analisi complessità

Ogni nodo è visitato _al più_ una volta, quindi il tempo richiesto risulta essere **T(n) = O(n)**
