
#include <iostream>

int fibi_modified(int A, int B, int N){
    int sum = 0;

    for(int i = 2; i < N; i++){
        sum = A+B;

        A = B;
        B = sum;
    }
    return sum;
}

int main(){
    
    int A = 2, B = 3, N = 4;
    std::cout<<"A: "<<A<<" B: "<<B<<" N: "<<N<<std::endl;
    std::cout<<fibi_modified(A, B, N)<<std::endl;;
    std::cout<<std::endl;

    A = 5, B = 7, N = 10;
    std::cout<<"A: "<<A<<" B: "<<B<<" N: "<<N<<std::endl;
    std::cout<<fibi_modified(A, B, N)<<std::endl;;
}