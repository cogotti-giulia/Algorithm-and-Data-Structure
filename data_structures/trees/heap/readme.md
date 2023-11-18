## Heap

Un heap è un albero binario quasi completo, dove _tutti_ i livelli dell'albero sono completamente riempiti tranne eventualmente l'ultimo in cui **tutte** le foglie sono addossate a sinistra. Questo permette di rappresentarlo utilizzando un _vettore posizionale_ senza lasciare posizioni vuote all'interno dell'array.

L'array A contiene due attributi:

- A.length: numero di elementi dell'array;
- A.heap_size: numero di elementi dell'heap memorizzati in A

Inoltre A[1] identifica la radice dell'albero e, se **i** è la radice di un nodo, allora:

```pseudocode
parent(i)
  return floor(i/2) # parte intera inferiore

left(i)
  return i*2

right(i)
  return i*2+1
```

```c++
int parent(int i) {
  return std::floor(i / 2);
}

//aggiungo il +1 perché parto da zero!
int left(int i) {
  return i * 2+1;
}

//aggiungo il +1 perché parto da zero!
int right(int i) {
  return i * 2 + 2;
}
```
