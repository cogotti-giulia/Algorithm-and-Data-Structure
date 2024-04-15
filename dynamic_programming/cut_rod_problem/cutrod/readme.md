# Cut rod

## Proprietà della struttura ottima

La soluzione ottima è esprimibile come combinazione di soluzioni ottime di sotto problemi. Invece di tagliare in due parti che saranno ulteriormente divise, posso tagliare un pezzo in modo definitivo e suddividere la parte che resta.

- r<sub>0</sub> = 0
- r<sub>n</sub> = max<sub>1<=i<=n</sub>{ p<sub>i</sub> + r<sub>n-1</sub> }

dove i è la _posizione_ del taglio (se i = n allora non ho fatto alcun taglio).

## Codice

```c++
/**
 * @brief funzione che calcola il ricavo massimo data la lunghezza dell'asta e
 * il costo di ogni taglio (vettore dei prezzi)
 *
 * @param p vettore dei prezzi p[0...n-1]
 * @param n lunghezza asta da tagliare
 * @return ricavo massimo
 */
int cutrod(std::vector<int> p, int n) {
  if (n == 0) // non posso più tagliare
    return 0;
  else {
    int q = -1; // massimo dei prezzi fino ad ora, posso usare -1 dato che so
                // per certo che tutti i prezzi sono positivi
    for (int i = 0; i < n; i++) {
      // std::cout<<i<< " "<<n<<std::endl;
      q = std::max(q, p.at(i) + cutrod(p, (n - 1) - i));
    }
    return q;
  }
}
```

```pseudocode
- p[1...n] : vettore prezzi
- p[i] : prezzo asta lunghezza i
- n : lunghezza asta da tagliare

cutrod(p, n)
    if n = 0
        return 0
    else
        q = -1
        for i = 1 to n
            q = max(q, p[i]+cutrod(p, n-i))
        return q
```

### Analisi complessità

```
        -- 1                            se n=0
T(n) = |
       |        n
        -- 1 + sum T(n-i)     se n>0
               i=1

dove 1 è il costo della chiamata al programma principale

             n                  n-1
T(n ) = 1 + sum T(n-i)   =  1 + sum T(j) = 2^n => T(n) = Teta(2^n)
            i=1        j=n-1    j=0

```

Quindi **T(n) = Teta(2<sup>n</sup>)**.

```
Dimostrazione per induzione su n

- n=0
[per definzione] T(0) = 1 = 2^0

- n>0
assumo che la proprietà sia vera per n e dimostro per n+1
              n
T(n+1) = 1 + sum T(j) [per definizione]
             j=0
             n-1
       = 1 + sum + T(n) [ho spezzato la sommatoria]
             j=0

       = T(n) + T(n) [1+sum ecc. è proprio T(n)]
       = 2T(n)
       = 2*2^n [per ip.induttiva]
       = 2^(n+1)
```

## Esempio albero di ricorsione

```
n = 4
                    4
        +-----+-----|-----+-----+
        |     |           |     |
        3     2           1     0
       /|\    /\          |
      2 1 0  1 0          0
     /\ |
    1 0 0
    |
    0
```

**Osservazioni**

Sono presenti tante foglie quanti sono i possibili modi di tagliare le aste: 2<sup>n-1</sup>=2<sup>4-1</sup>=2<sup>3</sup>=8.

Ogni cammino è un possibile modo di tagliare l'asta.

_Uno stesso sottoproblema viene risolto più volte!_ Infatti ci sono solo n=4 sottoproblemi distinti. Converrebbe dunque memorizzare la soluzione invece di calcolarla di nuovo.
