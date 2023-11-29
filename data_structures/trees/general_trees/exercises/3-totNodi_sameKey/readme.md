## Prima prova intermedia 20/01/2016 (esercizio I)

Dato un albero generico i cui nodi hanno attributi key, left-child, right-sib, scrivere una funzione c++ che restituisce il numero di nodi interni i cui figli hanno tutti la stessa chiave.
Qual è la complessità della funzione?

### Idea

Scorro l'albero scendendo di figlio in figlio in ricorsione e usando un ciclo while per scorrere i fratelli di ogni figlio. Se sono sul primo figlio mi salvo la sua chiave, scorro poi e conto grado e numero di fratelli che hanno la sua stessa chiave. Se grado e numero di fratelli con chiave uguale coincidono e mi trovo sull'ultimo figlio (non ha un fratello destro) allora ho un nodo che rispetta la proprietà, quindi incremento il risultato. Procedo poi a visitare tutto l'albero in questo modo.

```
              (2)
              /
             1 -> 1 -> 1
            /          /
           3 -> 4    (5) -> 6
                     /     /
                    4     7 -> -7

~> 2 nodi interni in cui i figli hanno la stessa chiave!
```

### Codice c++

```c++
int node_childrenSameKey(pnodeG u) {
  int ris = 0;
  node_childrenSameKey_AUX(u, &ris);
  return ris;
}

void node_childrenSameKey_AUX(pnodeG u, int *ris) {
  if (u == nullptr) {
    // i figli non hanno la stessa chiave perché non esistono quindi ris è zero
    *ris = 0;
  } else {
    bool is_first_key =
        true;         // mi serve a capire se mi trovo nel primo child oppure no
    int key = 0;      // conta i fratelli con la stessa chiave
    int grado = 0;    // conta il grado del nodo, quindi il numero di figli
    int k_left_child; // chiave del figlio più a sinistra

    pnodeG figlio = u->left_child;

    // scorro i figli andando da figlio a right sibling
    // all'interno vado in ricorsione per calcolare il risultato dei figli del
    // nodo che sto scorrendo
    while (figlio != nullptr) {

      // se è il primo figlio allora setto la chiave
      if (is_first_key) {
        is_first_key = false;
        k_left_child = figlio->key;
      }
      grado++; // ho un figlio in più

      // se la chiave è uguale a quella del primo figlio incremento key
      if (figlio->key == k_left_child)
        key++;

      // vado in ricorsione sul figlio più a sinistra
      node_childrenSameKey_AUX(figlio, ris);

      // se il grado coincide con key, quindi se tutti i figli hanno la stessa
      // chiave e mi trovo sul figlio più a destra (ultimo, non ha un fratello)
      if (grado == key && figlio->right_sibling == nullptr)
        *ris = *ris + 1; // incremento ris

      // mi sposto al fratello
      figlio = figlio->right_sibling;
    }
  }
}
```

### Analisi complessità

Ogni nodo viene visitato _esattamente_ una volta, dunque il tempo di esecuzione risulta essere **T(n) = Teta(n)**.