#include <algorithm>
#include <cmath>
#include <iostream>
#include "header.cpp"



int main(){
    T t = crea_albero();

    visita_in_ampiezza_BFS(t->root);

    std::cout<<endl;
    std::cout<<t_bilanciato(t->root);
}