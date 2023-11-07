#include "header.hpp"
#include <iostream>
#include <queue>

using namespace std;

T crea_albero(){
    T t = new tree();
    pnode n4 = new node(4, nullptr, nullptr);
    pnode n9 = new node(9, nullptr, nullptr);
    pnode n1 = new node(1, n4, n9);
    pnode n7 = new node(7, n1, nullptr);
    pnode n5 = new node(5, nullptr, nullptr);
    pnode n3= new node(3, n5, n7);

    t->root = n3;
    return t;
}

int t_bilanciato(pnode u){
    int h = -1; //altezza ALBERO vuoto
    return t_bilanciato_AUX(u, &h);
}

//rende il minimo T
int t_bilanciato_AUX(pnode u, int* h){
    if(u == nullptr){
        *h = -1;
        return 0;
    }else{
        int hSX = *h;
        int hDX = *h;
        int risSX = t_bilanciato_AUX(u->left, &hSX);
        int risDX = t_bilanciato_AUX(u->right, &hDX);

        int h_tmp = max(hSX, hDX)+1; //altezza albero
        int diff = abs(hSX - hDX); // differenza al nodo radice

        *h = h_tmp;
        return max(diff, max(risSX, risDX));
    }
    
}

void visita_in_ampiezza_BFS(pnode u){
    std::queue<pnode> q;
    q.push(u);
    while(!q.empty()){
        pnode tmp = q.front();
        q.pop();

        if(tmp != nullptr){
            std::cout<<tmp->key<<" ";

            q.push(tmp->left);
            q.push(tmp->right);
        }
    }
}