## Dizionario

Relazione univoca R:D->C, associazione univoca chiave-valore

**Dati:** insieme S di coppie (k, val)

**Operazioni:**

- search(S, k); <br>
  _POST: rende il valore associato a k se presente in S, NIL altrimenti_
- insert(S, k, v); <br>
  _POST: associa il valore v alla chiave k_
- delete(S, k); <br>
  _PRE: k è presente in S_ <br>
  _POST: cancella da S la coppia con chiave k_

### Realizzazione con array ordinati

**Dati:** un array A di dimensione n, contenete record con due campi (key, info) _ordinati_ in base al campo key.

```
S(n) = Teta(n)
```

**Operazioni:**

- search(A, k) <br>

```
~> T(n) = O(log n)
```

- search*index(A, k, p, r) <br>
  \_PRE: A[p ... r] porzione su cui vado a cercare la chiave k*<br>

```
~> T(n) = O(log n)
```

- reallocate(A, new*dim) <br>
  \_POST: crea un nuovo array con dimensione new_dim e copia il contenuto del vecchio array nel nuovo*<br>

```
~> T(n)=O(n)
```

- insert(A, k, v)<br>

```
~> T(n)=O(n)
```

- delete(A, k)<br>

```
~> T(n)=O(n)
```

### Realizzazione con strutture collegate

**Dati:** collezione L di n record contente (key, info, next, prev) dove next e prev sono puntatori al successivo e precedente record della collezione. Un attributi L.head mantiene il puntatore al primo elemento della lista, se vuota L.head=null;

```
S(n) = Teta(n)
```

**Operazioni:**

- insert(L, v, k) <br>

```
~> T(n) = Teta(1)
```

- search(L, k) ~> **T(n) = O(n)**<br>

```
~> T(n) = O(n)
```

- delete(L, k) <br>

```
~> T(n) = Teta(n)
```
