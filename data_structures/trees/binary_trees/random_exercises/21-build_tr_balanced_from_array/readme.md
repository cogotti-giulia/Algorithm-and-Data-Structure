## Esame 13/06/2013 (parte II, esercizio II)

Dato un array A di n elementi, progettare un algoritmo efficiente che costruisca ricorsivamente un albero binario bilanciato tale che A[i] sia l’(i+1)-esimo campo u.key in ordine di visita posticipata (post ordine). 

Discutere la complessità al caso pessimo indicando, e risolvendo, la corrispondente relazione di ricorrenza.

### Idea

```
A[0...n]

A: | 3 | -1 | 4 | 7 | 12 | 0 | 
     0    1   2   3    4   5

visita post order
i = 0   A[0] = 3  ~> (0+1) = 1° nodo
i = 1   A[1] = -1 ~> (1+1) = 2° nodo 
i = 2   A[2] = 4  ~> (2+1) = 3° nodo 
i = 3   A[3] = 7  ~> (3+1) = 4° nodo 
i = 4   A[4] = 12 ~> (4+1) = 5° nodo 
i = 5   A[5] = 0  ~> (5+1) = 6° nodo 

T:

              0
             / \
            4   12
           / \  /
          3 -1 7
```

Costruisco l'albero ricorsivamente, dividendo ogni volta l'array A[p...r] in due porzioni [p...med] e [med+1...r-1], ottenendo sicuramente un albero bilanciato dato che distribuisco metà dei nodi a sinistra e metà di essi a destra!

Inoltre noto che per ottenere la visita in post ordine con i nodi nell'ordine richiesto, la radice di ogni sottoalbero si troverà sempre in posizione r. Ma allora creo il nodo con quel valore e vado in ricorsione per attaccare i figli nelle porzioni [p...med] e [med+1...r-1]. Il -1 è perché il valore di r l'ho appena usato per il nodo corrente.

```


A[p...r] 
r: radice!

p = 0
r = 5
                          root
                           |
                           v
A: | 3 | -1 | 4 | 7 | 12 | 0 | 
     0    1   2   3    4   5

T:       0

divido 

med = 2
      root   root
        |     |
        v |   v
A: 3 -1 4 | 7 12 
   0  1 2 | 3  4

T:       0
        / \
       4  12


continuando così si ottiene

T:       0
        / \
       4   12
      / \  /
     3 -1 7
```

### Codice c++

```c++
pnode build_tree_balanced(const std::vector<int> &A, int p, int r) {
  if (p < r) {
    pnode nuovo = new node(A.at(r));
    int med = std::floor((p + r) / 2);
    
    nuovo->left = build_tree_balanced(A, p, med); // T(n/2)
    nuovo->right = build_tree_balanced(A, med + 1, r-1); // T(n/2)

    return nuovo;
  } else if(p==r){
    //* NON DIMENTICARTI DEL CASO BASE
    pnode nuovo = new node(A.at(r));
    return nuovo;
  }else{
    return nullptr;
  }
}
```

#### Analisi complessità

Ad ogni chiamata ricorsiva divido l'array in due porzioni, quindi il costo di ognuna è T(n/2). Quando mi trovo sull'elemento i faccio delle semplici operazioni costanti. Ma allora si ottiene la seguente ricorrenza:

```
        --- Teta(1)               se n<=1
T(n) = |
        --- 2*T(n/2)+c            se n>1

dove n rappresenta il numero di elementi dell'array di input
```

Si può risolvere tramite _master theorem_ ottenendo che **T(n) = Teta(n)**

```
a = 2
b = 2
f(n) = c

d = log(b)a = log(2)2 = 1
g(n) = n^d = n

[I° caso]
f(n) = O(n^(d-epsilon)) = O(n^(1-epsilon)) con epsilon>0

fisso epsilon = 1
f(n) = O(1)

quindi concludo che T(n) = Teta(n^d) = Teta(n)
```