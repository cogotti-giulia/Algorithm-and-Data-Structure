## Esame 03/06/2019 (parte II, esercizio I)

Sia dato un albero binario i cui nodi contengono una chiave intera x.key, oltre ai campi x.left, x.right che rappresentano rispettivamente il figlio sinistro e il figlio destro. Si definisce grado di squilibrio di un nodo il valore assoluto della differenza tra la somma delle chiavi nei nodi foglia del sottoalbero sinistro e la somma delle chiavi dei nodi foglia del sottoalbero destro. Il grado di squilibrio di un albero è il massimo grado di squilibrio dei suoi nodi.

Scrivere una funzione efficiente in C, di nome gradosquil(u), che data la radice di un albero binario, calcola il grado di squilibrio dell’albero.

Analizzare la complessità della funzione, indicando eventuali relazioni di ricorrenza.

### Idea

Devo fare una visita in post order perché le informazioni mi arrivano dai discendenti. Uso una funzione ausiliaria che mi permette di portarmi dietro la somma delle chiavi nei nodi foglia dei sottoalberi sinistro e destro e per ogni nodo interno calcolo il suo grado di squilibrio (valore assoluto della differenza tra la somma delle chiavi nei nodi foglia dei sottoalberi sx e dx) e me la salvo se rappresenta il massimo corrente. Alla fine ciò che avrò sarà lo squilibrio dell'albero dato dal massimo grado di squilibrio dei nodi.

### Codice c++

```c++

int grado_squili(pnode u) {
  int max_squili = 0;
  grado_squili_AUX(u, &max_squili);
  return max_squili;
}

int grado_squili_AUX(pnode u, int *max_squili) {
  if (u == nullptr) {
    return 0;
  } else {
    // calcolo la somma delle chiavi contenute nelle foglie dei sottoalberi
    // sinistro e destro
    int sumFSX = grado_squili_AUX(u->left, max_squili);
    int sumFDX = grado_squili_AUX(u->right, max_squili);

    // se mi trovo su una foglia incremento la somma al valore della chiave
    if (u->left == nullptr && u->right == nullptr) {
      return sumFSX + sumFDX + u->key;
    } else {
      // squilibrio del nodo, dato dal valore assoluto della differenza delle
      // somme dei nodi foglia radicati nei sottoalberi sinistro e destro
      int squili_node = std::abs(sumFSX - sumFDX);
      // calcolo il massimo squilibro dato dal massimo tra il grado di
      // squilibrio del nodo corrente e il massimo precedentemente calcolato
      *max_squili = std::max(squili_node, *max_squili);
      // la somma delle foglie sarà data dalla somma dei due sottoalberi del
      // nodo corrente
      return sumFSX + sumFDX;
    }
  }
}
```

#### Analisi complessità

Analizzando il codice si ottiene la seguente ricorrenza che, se risolta tramite [metodo di sostituzione](../../dimostrazioni.md), permette di affermare che il tempo di esecuzione è **T(n) = Teta(n)**

```
        --- c                       n = 0
T(n) = |
        --- T(k) + T(n-k-1) + d     n > 0
dove
k = numero di nodi presenti in un sottoalbero
n-k-1 = numero di nodi presenti nell'altro sottoalbero
d = costo alla radice
```
