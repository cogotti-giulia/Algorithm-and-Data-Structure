#include <iostream>
#include "header.cpp"

int main(){

    std::cout<<"*** LEFT CHILD and RIGHT SIBLING IMPLEMENTATION ***"<<std::endl<<std::endl;

    T t = new tree();
    t = crea_albero_lc_rsib();
    std::cout<<"pre order (DFS):\t\t";
    visita_preorder_DFS(t->root);
    std::cout<<std::endl;
    std::cout<<"post order:\t\t\t\t\t";
    visita_post_order(t->root);
    std::cout<<std::endl;
    std::cout<<"ampiezza (BFS):\t\t\t";
    visita_in_ampiezza_BFS(t->root);
    std::cout<<std::endl;
    std::cout<<std::endl;

}