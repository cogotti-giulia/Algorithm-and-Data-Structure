/**
 * @file main.cpp
 * @author me, myself and I
 * @brief test del dizionario implementato tramite array ordinati (in base al campo key)
 * @version 0.1
 * @date 2023-11-07
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <algorithm>
#include <cstddef>
#include <iostream>
#include <cmath>
#include <vector>

#include "header.cpp"


int main(){
    size_t N = 4; //size dell'array

    std::cout<<"[INSERT] inserendo elementi nell'array"<<" ..."<<std::endl<<"~> ";
    my_array A = new record[N]
        {{1, 5},
        {3, 7},
        {7, -3},
        {12, 0}};
    
    print_array(A, N);
    std::cout<<std::endl;

    int k_seach = 3;
    std::cout<<"[SEARCH] cercando elemento con chiave "<<k_seach<<" ..."<<std::endl;
    int ris = search(A, k_seach, sizeof(*A));
    if(ris != -1)
        std::cout<<"~> Elemento trovato! k: "<<k_seach<<" v: "<<A[ris].info<<std::endl<<std::endl;
    else
        std::cout<<"~> Nessun elemento contenete la chiave cercata"<<std::endl<<std::endl;

    

    int new_key = -7;
    int new_value = 29;
    std::cout<<"[INSERT] inserendo elemento con k="<<new_key<<" e v="<<new_value<<" nell'array"<<" ..."<<std::endl<<"~> ";
    insert(A, new_key, new_value, &N);
    print_array(A, N);
    std::cout<<std::endl;

    new_key = 7;
    new_value = 999;
    std::cout<<"[INSERT] inserendo elemento con k="<<new_key<<" e v="<<new_value<<" nell'array"<<" ..."<<std::endl<<"~> ";
    insert(A, new_key, new_value, &N);
    print_array(A, N);
    std::cout<<std::endl;

    int k_del = 7;
    std::cout<<"[DELETE] eliminando elementi con chiave "<<k_del<<" ..."<<std::endl<<"~> ";
    delete_(A, k_del, &N);
    print_array(A, N);
}

