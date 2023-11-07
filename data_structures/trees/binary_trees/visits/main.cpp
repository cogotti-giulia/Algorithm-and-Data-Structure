#include <iostream>
#include "header.cpp"

int main(){

    T tree = crea_albero_sx_dx();   
    
    std::cout<<"*** LEFT and RIGHT IMPLEMENTATION ***"<<std::endl;
    std::cout<<"pre order (DFS):\t\t";
    visita_preorder_DFS(tree->root);
    std::cout<<std::endl;
    std::cout<<"in order (simmetrica):\t";
    visita_in_order_simmetrica(tree->root);
    std::cout<<std::endl;
    std::cout<<"post order:\t\t\t\t";
    visita_post_order(tree->root);
    std::cout<<std::endl;
    std::cout<<"ampiezza (BFS):\t\t\t";
    visita_in_ampiezza_BFS(tree->root);
    std::cout<<std::endl;
    std::cout<<std::endl;

}
