# Definizioni importanti

## Alberi binari

### Definizione di albero binario

Caso base: un albero _vuoto_ è un albero binario (altezza -1)<br>
Passo induttivo: un albero costituito da un nodo _radice_, un albero binario (sottoalbero _sinistro_ della radice) e un albero binario (sottoalbero _destro_ della radice) è un **albero binario**.

```
               (r)
             /     \
            /\     /\
           /  \   /DX\
          / SX \  ¯¯¯¯
          ¯¯¯¯¯¯
```

## Alberi binari di ricerca (BST)

### Definizione di bst

sia x un nodo in un albero binario di ricerca:<br>
~ se y è un nodo nel sotto albero _sinistro_ di x allora **y.key <= x.key** <br>
~ se y è un nodo nel sotto albero _destro_ di x allora **y.key >= x.key**

```
        3
      /   \
    -1     7    ~> è un BST !
          / \
         5   9
```