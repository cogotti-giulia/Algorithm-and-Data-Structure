/**
 * @file header.cpp
 * @author me, myself and I
 * @brief implementazione metodi e funzioni
 * @version 1.0
 * @date 2023-11-08
 */
#include "header.hpp"
#include <algorithm>

int blackHeight(PNode u) {
  if (u == nullptr)
    return 0;
  else {
    int risSX, risDX, ris;

    //
    risSX = blackHeight(u->left);
    risDX = blackHeight(u->right);

    // ritorna -1 se la condizione è violata
    //in particolare quando uno dei sotto alberi ha restituito -1
    //oppure quando esistono entrambi i figli ma le loro altezze black sono diverse 
    if (risSX == -1 || risDX == -1 ||
        (u->left != nullptr && u->right != nullptr && risSX != risDX))
      return -1;
    else{
      //a questo punto risSx e risDX sono uguali e assegno a ris il giusto valore 
      //prendo il massimo tra i due perché se non esiste il sotto albero l'altezza è zero
      ris = std::max(risSX, risDX);
 
      //se il nodo corrente è black incremento ris
      if(u->col == 'B')
        ris++;
    
      return ris;
    }
  }
}

T crea_albero() {

  T tr = new tree();

  PNode q = new Node(1, 'B');
  PNode w = new Node(1, 'R', nullptr, q);
  PNode e = new Node(1, 'B');
  PNode t = new Node(1, 'B');

  PNode r = new Node(1, 'R', t, e);
  
  PNode i = new Node(1, 'R', r, w);

  tr->root = i;
  return tr;
}