#include <iostream>
#include "header.cpp"
/*
* sia T un albero binario. il LIVELLO di un nodo è la sua distanza dalla radice.
* progettare un algoritmo che, preso in ingresso T e un intero k >= 0, stampa le chiavi
* contenute nei nodi di T a livello k, procedendo da SX verso DX
*/

int main(){
    T t = crea_albero();
    stampa_livello(t->root, 2);
}