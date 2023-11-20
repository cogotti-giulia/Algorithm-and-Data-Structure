## Code di priorità

Le code di priorità sono una struttura dati che mantiene un insieme dinamico S di elementi con valore chiave (o peso).

#### Code di massima priorità - operazioni

- **insert(S, x)**: inserisce l'elemento  in S in modo tale che S = S U {x}
- **maximum(S)**: restituisce l'elemento di S con la chiave più grande (sola lettura)
- **extract_max(S)**: elimina e restituisce l'elemento di S con la chiave più grande
- **increase_key(S, x, k)**: aumenta il valore della chiave di x al nuovo valore k, dove k >= chiave di x

#### Code di minima priorità - operazioni

- **insert(S, x)**: inserisce l'elemento  in S in modo tale che S = S U {x}
- **minimum(S)**: restituisce l'elemento di S con la chiave più piccola (sola lettura)
- **extract_main(S)**: elimina e restituisce l'elemento di S con la chiave più piccola
- **decrease_key(S, x, k)**: decrementa il valore della chiave di x al nuovo valore k, dove k <= chiave di x

### Implementazione

L'implementazione verrà effettuata utilizzando gli heap (max o min a seconda del tipo di coda utilizzata. Questo perché un _heap_ può svolgere ciascuna operazione con le **code di priorità** nel tempo **O(logn)** su un inseme dinamico di n elementi!