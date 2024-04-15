# Problema del taglio delle aste

Un'azienda produce delle aste d'acciaio e le vende a pezzi:

- le aste prodotte hanno una certa lunghezza n
- sul mercato i pezzi hanno un _prezzo_ che dipende dalla lunghezza

Trovare il modo di tagliare le aste che **massimizzi** il guadagno (assumendo che il costo del taglio sia irrilevante).

**n**: lunghezza asta<br>
**p<sub>i</sub>**: tabella dei prezzi i = 1...n ~> p<sub>i</sub> è il prezzo di un pezzo di lunghezza <br>
**r<sub>n</sub>**: ricavo massimo per un'asta di lunghezza n (è quello che devo calcolare!)

## Esempio

asta di lunghezza n = 7

```
tagli     1 | 2 | 3 | 4 | 5  | 6  | 7
prezzi    1 | 5 | 8 | 9 | 10 | 17 | 17
```

posso tagliarla in vari modi

```
 1 1 1 1 1 1 1
|-|-|-|-|-|-|-| ~> guadagno: 7

  2 1 1 1 1 1
|--|-|-|-|-|-|  ~> guadagno: 10

  2  2  3
|--|--|---|     ~> guadagno: 18

  3   2  2
|---|--|--|     ~> guadagno: 18

 1    6
|-|------|      ~> guadagno: 18

    6   1
|------|-|      ~> guadagno: 18
```

La soluzione ottima _non_ è unica!

## In quanti modi posso tagliare un asta di lunghezza n?

In ogni posizione ho due possibili scelte, taglio o non taglio. Ma allora ho 2\*2\*...\*2 = 2<sup>n-1</sup>.

> Se analizzassi tutti i possibili tagli otterrei un algoritmo esponenziale!

## Guadagno massimo espresso in forma ricorsiva

- r<sub>0</sub> = 0
- r<sub>n</sub> = max{p<sub>n</sub>, r<sub>1</sub> + r<sub>n-1</sub>, r<sub>2</sub> + r<sub>n-2</sub>, ... }

dove:

- p<sub>n</sub> indica l'assenza di taglio
- r<sub>1</sub> + r<sub>n-1</sub> divido in due pezzi che a loro volta saranno ulteriormente divisi

### Proprietà della struttura ottima

La soluzione ottima è esprimibile come combinazione di soluzioni ottime di sotto problemi. Invece di tagliare in due parti che saranno ulteriormente divise, posso tagliare un pezzo in modo definitivo e suddividere la parte che resta.

- r<sub>0</sub> = 0
- r<sub>n</sub> = max<sub>1<=i<=n</sub>{ p<sub>i</sub> + r<sub>n-1</sub> }

dove i è la _posizione_ del taglio (se i = n allora non ho fatto alcun taglio).

## Quando usare la programmazione dinamica?

La programmazione dinamica è utile quando i sottoproblemi distinti sono in _numero polinomiale_ e ognuno si risolve in _tempo polinomiale_. La **memorizzazione** delle soluzioni evita il costo dovuto a calcolare nuovamente ottenendo dunque un **algoritmo polinomiale**.

> Si tratta di un compromesso fra tempo di esecuzione e spazio di memoria.

## Tecniche di costruzione di algoritmi

Esistono due tecniche: top down e bottom up. Una è ricorsiva, l'altra no. In ogni caso _asintoticamente_ il costo è lo stesso per entrambi i metodi.

### Top down (n -> ... -> 1)

All'interno di una tabella (vettore, hash) si salvano le soluzioni dei problemi già risolti (_memoization_). Si utilizza la ricorsione (che è costosa) ma riesce comunque a prendere solo le cose interessanti.

### Bottom up (1 -> ... -> n)

Si ordinano i problemi in base alla dimensione e partendo dai più piccoli si risolvono memorizzando le soluzioni ottenute (risolve tutto).
