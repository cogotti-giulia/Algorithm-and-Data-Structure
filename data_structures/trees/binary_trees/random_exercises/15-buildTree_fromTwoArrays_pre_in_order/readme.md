## Esercizio

Dati due vettori contenenti rispettivamente i valori dei nodi tutti DISTINTI ottenuti da una visita in ordine anticipato e da una visita in ordine simmetrico di un albero binario, si ricostruisca l’albero binario.

Il prototipo della funzione è:

PNode ricostruisci(const vector<int>& va, const vector<int>& vs)

Analizzare e motivare in modo chiaro, preciso ed approfondito la complessità della funzione.

### Io che cerco di capire cosa devo fare

```
albero
        1
      /  \
    2     3
   / \     \
  4   5     6

va : 1 2 4 5 3 6
vs : 4 2 5 1 3 6
     0 1 2 3 4 5 <~ indici vettore
```

prendendo un nodo u dalla visita anticipata, guardando il vettore della visita simmetrica so che 
in quel vettore (vs) gli elementi a sinistra faranno parte del suo sottoalbero sinistro 
e quelli a destri del suo sottoalbero destro.

```
u = 1 
index_vs = 3
vs : 4 2 5 | 1 | 3 6
     0 1 2   3   4 5 <~ indici vettore

u = 2
nella porzione vs[0...index_vs]
vs : 4 | 2 | 5
     0   1   2
     
```

e così via per tutti i nodi

### Idea!

uso una mappa <\chiave, valore> per salvarmi l'indice dell'elemento u nel vettore vs
(mantengo un tempo lineare senza dover scorrere ogni volta per trovarlo)

nell'esempio di sopra avrò<br>
map<elem_vs> = index 

map<4> = 0<br>
map<2> = 1<br>
map<5> = 2<br>
map<1> = 3<br>
map<3> = 4<br>
map<6> = 5<br>

uso una funzione ausiliaria perché devo ricordarmi la porzione \[p...r] su cui sto lavorando e devo
portarmi dietro l'indice di va, perché ogni volta prendo un elemento da li

inizialmente<br>
index_va = 0<br>
p = 0<br>
r = 0<br>

creo il mio elemento con chiave presa da va.at(0)<br>
~> key = 1

poi incremento index_va  (index_va = 1)

ho elementi in \[p...r]<br>
allora prendo l'indice del nodo appena creato (1) dalla mappa<br>
~> map<1> = 3<br>
quindi ho che index_vs = 3

ora vado in ricorsione ad aggiungere figlio sinistro e destro

ma, come ho detto prima per farlo mi basta andare nelle porzioni sinistra e destra di vs

infatti a sinistra vado nella porzione \[p...index_vs-1]<br>
e a destra vado in \[index_vs+1...r]

e così via fino a quando non ho finito i nodi


### Codice funzione

```c++
pnode ricostruisci_AUX(const std::vector<int> &va, const std::vector<int> &vs,
                       int p, int r, int *index_va,
                       std::map<int, int> map_elem_index) {

  if (p > r) // non ho elementi
    return nullptr;
  else {
    // nuovo elemento avrà come chiave l'elemento in posizione index_va della
    // visita anticipata, poi mando avanti l'indice
    pnode nuovo = new node{va.at(*index_va)};
    *index_va = *index_va + 1;

    // non ha figli
    if (p == r)
      return nuovo;

    // indice dell'elemento appena creato, lo prendo dalla mappa
    // so per certo che gli elementi alla sua destra saranno nel  suo
    // sottoalbero destro e quelli alla sua sinistra saranno nel suo sottoalbero
    // sinistro perché è una visita simmetrica!
    int index_vs = map_elem_index.at(nuovo->key);

    // vado in ricorsione a costruire il resto dell'albero

    // per i nodi a sinistra vado nella porzione sinistra dell'array vs
    // per i nodi a destra vado nella porzione a destra dell'array vs
    nuovo->left =
        ricostruisci_AUX(va, vs, p, index_vs - 1, index_va, map_elem_index);
    nuovo->right =
        ricostruisci_AUX(va, vs, index_vs + 1, r, index_va, map_elem_index);

    return nuovo;
  }
}

pnode ricostruisci(const std::vector<int> &va, const std::vector<int> &vs) {
  int n = va.size();
  if (n > 0) {
    // mappa che contiene chiavi e valori
    // chiave: elemento del vettore vs
    // valore: indice cella dove si trova quell'elemento
    std::map<int, int> map_elem_index;

    //? T(n) = Teta(n)
    for (int i = 0; i < n; i++) {
      map_elem_index[vs.at(i)] = i;
    }

    int index_va = 0; // indice per scorrere l'array va
    //?T(n) = O(n)
    return ricostruisci_AUX(va, vs, 0, n - 1, &index_va, map_elem_index);

  } else
    return nullptr;
}
```

#### Analisi complessità

il ciclo for per riempire la mappa è eseguito n volte

la funzione ausiliaria ricostruisci_AUX divide l'array vs in porzioni sempre più piccole
siano<br>
n : elementi totali dell'array vs<br>
k : elementi nel sottoarray sx<br>
n-k-1 : elementi nel sottoarray di destra (-1 è l'elemento "centrale")<br>
d : costo per eseguire le operazioni sull'elemento "centrale", perché non faccio altro che operazioni costanti

allora ottengo la ricorrenza

```
        --- c                           n = 0
T(n) = |
        --- T(k) + T(n-k-1) + d         n > 0

```

che si risolve tramite metodo di sostituzione ottenendo che T(n) = O(n)


Assumo che T(n) = an + b (generica funzione lineare) e dimostro che ho ragione tramite induzione.<br>
caso base<br>
n=0<br>
T(0) = b<br>
[per ipotesi, vedi ricorrenza] T(0) = c<br>
ma allora b=c<br>

passo induttivo<br>
assumo che per m < n vale che T(m) = am + b e dimostro che allora è vero anche per n.

[per definizione] T(n) = T(k) + T(n-k-1) + d<br>
[dato che k < n e (n-k-1) < n posso applicare l'ipotesi induttiva]<br>
[per ip.induttiva] T(n) = ak+b + a(n-k-1)+b + d = an -a +2b +d

mi chiedo se è vero che an-a+2b+d ???=??? an+b<br>
an-a+2b-an-b +d= 0<br>
-a+b+d = 0 ~> a = b + d<br>
[dal caso base] b + d = c + d<br>
ma allora T(n) = (c+d)n + c e quindi T(n) = O(n)



IN CONCLUSIONE

> **T(n) = Teta(n) + O(n) = Teta(n)**

OSSERVAZIONI<br>
L'utilizzo della mappa mi risparmia il dover scorrere l'array vs ogni volta per trovare l'elemento e suddividere.<br>
Se non l'avessi utilizzata il tempo sarebbe diventato T(n) = Teta(n^2)
*/