## Esercizio

Dato un array non ordinato di n interi, eventualmente ripetuti, e un intero positivo k, progettare un algoritmo efficiente che restituisca 1 se esiste un valore nell’array che occorre esattamente k volte, 0 altrimenti. Analizzarne la complessità in tempo.

L’algoritmo deve utilizzare _spazio aggiuntivo costante_ e devono essere definite esplicitamente eventuali funzioni/procedure ausiliarie.

### Idea

Mi conviene ordinare e, dato che lo spazio aggiuntivo deve essere costante devo usare un algoritmo che ordina in _loco_. La scelta ricade tra insertion sort e quick sort.

L'insertion sort nel caso peggiore ha tempo di esecuzione pari a Teta(n^2) ma dato che per ipotesi l'array non è ordinato non si verificherà mai il caso peggiore, quindi avrei un O(n^2)

Il quick sort ha prestazioni che oscillano tra n logn e n^2. Utilizzando la tripartizione con la randomizzazione del pivot le prestazioni nel caso medio sono più vicine a n logn che ad n^2.

In teoria non mi interessa la stabilità. Potrei avere senza dubbio elementi ripetuti, ma allora mi conviene usare il quick sort direi.

L'ordinamento mi assicura che gli elementi uguali ripetuti esattamente k volte, se esistono, saranno nelle k posizioni adiacenti dell'array, scorrendo l'array (da 0 a n - k) confronto l'elemento in posizione **i** con quello in posizione **i+k-1**, se sono uguali e l'elemento successivo è diverso da loro allora ho trovato ciò che cercavo (se esiste l'elemento successivo, altrimenti sono alla fine dell'array col i+k-1 esimo elemento e confronto soltanto essi).

### Codice funzione

```c++
bool esattamente_k_volte(std::vector<int> *A, int k) {
  if (k > 0 && k <= A->size()) {
    // l'ordinamento mi assicura che gli elementi uguali si troveranno in
    // posizioni adiacenti dell'array
    my_quick_sort_tri(A, 0, A->size() - 1); //! oscilla tra n log n ed n^2
    stampa_array(*A);

    bool found = false;

    int elem = A->at(0);
    int i = 1;

    while (i <= A->size() - k && !found) { //! al più O(n)

      if (A->at(i) != elem) {
        elem = A->at(i);
        int k_elem = i + (k - 1); // posizione k esimo elemento partendo da i

        // se esiste un elemento in posizione i+k
        if ((k_elem + 1) < A->size()) {
          // controllo che ci siano k elementi uguali ad A[i] e che l'elemento
          // successivo a questi k sia diverso dai precedenti
          if (A->at(k_elem) == elem) {
            if (A->at((k_elem + 1)) != elem) {
              found = true;

            } else {

              i = k_elem + 1; // vado al k+1 esimo elemento a partire da i,
                              // perché tanto so già che quei k sono uguali a
                              // qualcosa che ho già controllato
            }
          } else {
            i++;
          }

        } else {
          if (k_elem < A->size()) {
            // se non esiste un elemento in posizione i+k semplicemente
            // controllo che ce ne siano k uguali in quanto il k esimo si trova
            // come ultimo elemento dell'array
            if (A->at(k_elem) == elem)
              found = true;

            i = k_elem + 1; // vado al k+1 esimo elemento

          } else {
            i++;
          }
        }
      }else
        i++;
    }
    return found;
  } else {
    return false;
  }
}
```

```c++
void my_quick_sort_tri(std::vector<int> *A, int p, int r) {
  if (p < r) {
    my_double_index i = my_rand_partition_tri(A, p, r);
    my_quick_sort_tri(A, p, (i->q) - 1);
    my_quick_sort_tri(A, (i->t) + 1, r);
  }
}

my_double_index my_rand_partition_tri(std::vector<int> *A, int p, int r) {
  // int i = rand() % r; // sceglie un elemento random come pivot
  // my_swap(A, i, r); boh non funziona

  return my_partition_tri(A, p, r);
}

my_double_index my_partition_tri(std::vector<int> *A, int p, int r) {
  int x = A->at(r);

  int min = p, eq = p;
  int mag = r;

  while (eq < mag) {
    if (A->at(eq) < x) {
      my_swap(A, min, eq);
      eq++;
      min++;
    } else if (A->at(eq) == x) {
      eq++;
    } else { // A.at(eq) > x
      mag--;
      my_swap(A, mag, eq);
    }
  }

  my_swap(A, mag, r);
  return new double_index(min, mag);
}
```

### Analisi complessità

L'algoritmo di ordinamento quick sort impiega un tempo che oscilla tra n logn ed n^2.

Il ciclo while della funzione principale impiega _al più O(n)_

Quindi purtroppo, nel caso peggiore, avrò un tempo di **T(n) = O(n + n^2) = O(n^2)** dato dal quick sort. Ma, nel caso medio questo n^2 si avvicina sempre più a un **T(n) = O(n logn)**.
