# Massima sotto sequenza comune (LCS)

## Esempio

Il DNA è composto da sequenze di molecole base (A G C T). Per capire se due organismi sono simili si confrontano le loro sequenze di DNA e si cerca di trovane la massima sotto sequenza in comune.

```
S1 : A C T A C C T G
S2 : A T C A C C

LCS : A T A C C
```

La LCS non per forza ha i caratteri consecutivi.

## Definizione sotto sequenza

Una _sotto sequenza_ di X=x<sub>1</sub>...x<sub>m</sub> è x<sub>i<sub>1</sub></sub>...x<sub>i<sub>k</sub></sub> con
- i<sub>1</sub>...i<sub>k</sub> in {1...m}  _(indici)_
- i<sub>1</sub> \< i<sub>2</sub> \< ... \< i<sub>k</sub>    _(indici consecutivi)_

## Problema LCS

Date due _sequenze_ X=x<sub>1</sub>...x<sub>m</sub> e Y=y<sub>1</sub>...y<sub>n</sub> trovare una **sequenza W** tale che:
- sia una _sottosequenza_ di X e Y
- sia di lunghezza massima

> ATTENZIONE!<br>
> La LCS _non_ è unica!<br>
> **LCS(X, Y): insieme delle LCS di X e Y**

## Definizione prefisso

Data X=x<sub>1</sub>...x<sub>m</sub>, per k <= m, indico con **X<sup>k</sup>** il **prefisso** di lunghezza k di X.

**X<sup>k</sup>=x<sub>1</sub>...x<sub>k</sub>**


> X = ACG<br>
> X<sup>0</sup> = epsilon<br>
> X<sup>1</sup> = A<br>
> X<sup>2</sup> = AC<br>
> X<sup>3</sup> = ACG<br>

In generale X=x<sub>1</sub>...x<sub>m</sub> ha **m+1 prefissi**. Ridurre il problema della LCS sui prefissi permette di ottenere **O(m\*n)** sotto problemi, dove  _X=x<sub>1</sub>...x<sub>m</sub>_ e _Y=y<sub>1</sub>...y<sub>n</sub>_.

Decisamente meglio rispetto a un approccio _brute force_ che (generando tutte le sotto sequenze di X e verificando se sono sotto sequenze di Y, memorizza la più lunga) porta via un tempo **esponenziale**, con X=x<sub>1</sub>...x<sub>m</sub> si hanno a 2<sup>m</sup> sotto sequenze (ogni carattere può appartenere o meno alla sequenza)! 

## Sotto struttura OTTIMA per la LCS

Date X=x<sub>1</sub>...x<sub>m</sub> e Y=y<sub>1</sub>...y<sub>n</sub> sequenza e W=w<sub>1</sub>...w<sub>k</sub> in LCS(X, Y), allora:
1. se x<sub>m</sub> = y<sub>n</sub> => w<sub>k</sub>=x<sub>m</sub>=y<sub>n</sub> e W<sup>k-1</sup> in LCS(X<sup>m-1</sup>, Y<sup>n-1</sup>)
2. se x<sub>m</sub> != y<sub>n</sub>
    - (a) se w<sub>k</sub>!=x<sub>m</sub> => W in LCS(X<sup>m-1</sup>, Y)
    - (b) se w<sub>k</sub>!=y<sub>n</sub> => W in LCS(X, Y<sup>n-1</sup>)


_Dimostrazione_

1. so che w<sub>k</sub>=x<sub>m</sub>=y<sub>n</sub> altrimenti (per assurdo) potrei costruire una sequenza W<sub>X<sub>m</sub></sub> (a W concatena X<sub>m</sub>) che sarebbe una sotto sequenza di X e Y. Ma, avrebbe lunghezza maggiore di |W|, assurdi perché W in LCS(X<sup>m-1</sup>, Y<sup>n-1</sup>)<br>
W<sup>k-1</sup> è sotto sequenza di X<sup>m-1</sup> e Y<sup>n-1</sup> e, voglio dimostrare che W<sup>k-1</sup> in LCS(X<sup>m-1</sup>, Y<sup>n-1</sup>). Se per assurdo non fosse così allora esisterebbe W<sup>'</sup> in LCS(X<sup>m-1</sup>, Y<sup>n-1</sup>) e avrei che |W<sup>'</sup>| > |W<sup>k-1</sup>| = k-1<br>
dato che w<sub>k</sub>=x<sub>m</sub>=y<sub>n</sub> ho che |W<sub>w<sub>k</sub></sub><sup>k-1</sup>| \< |W<sub>w<sub>k</sub></sub><sup>'</sup>| sono sotto sequenze di X e Y1. <br>
La prima è proprio |W|, quindi |W| < |W<sub>w<sub>k</sub></sub><sup>'</sup>|, il che è assurdo! (dato che W non sarebbe più ottimale)

2. (a) se <sub>m</sub> != y<sub>n</sub> allora W è sotto sequenza di X<sup>m-1</sup> e Y (_per ipotesi_). ora voglio dimostrare che W in LCS(X<sup>m-1</sup>, Y).<br>
Suppongo per assurdo che ci sia una sotto sequenza comune di X<sup>m-1</sup> e Y più lunga di W, chiamata W<sup>'</sup>. Allora |W<sup>'</sup>| > |W|<br>
Essendo W<sup>'</sup> una sotto sequenza comune di X<sup>m-1</sup> e Y lo è anche di X e Y, ma questo contraddice il fatto che W è di lunghezza massima in LCS(X, Y)

## Soluzione ricorsiva

Date X=x<sub>1</sub>...x<sub>m</sub> e Y=y<sub>1</sub>...y<sub>n</sub>, indico con c[i, j] la lunghezza della LCS(X<sup>i</sup>, Y<sup>i</sup>) con 0<=i<=m e 0<=j<=n

        
c[i, j] = 
- 0 se i=0 OR j=0 (_una stringa è vuota_)
- c[i-1, j-1]+1 (_ho un carattere in comune_) se i>0 AND j>0 AND x<sub>i</sub>=y<sub>i</sub>
- max(c[i-1, j], c[i, j-1]) se i>0 AND j>0 AND x<sub>i</sub>!=y<sub>i</sub>

Tempo di esecuzione: **Teta(m\*n)**

> Viene utilizzato un approccio di tipo bottom up!