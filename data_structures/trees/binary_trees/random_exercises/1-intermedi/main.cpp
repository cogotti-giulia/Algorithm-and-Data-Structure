#include <iostream>
#include "header.cpp"


int main(){
    T tree = crea_albero();
    
    visita_in_ampiezza_BFS(tree->root);
    std::cout<<std::endl;
    std::cout<<"numero di nodi intermedi: "<<intermedi(tree->root);
}
