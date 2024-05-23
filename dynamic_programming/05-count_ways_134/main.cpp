

#include <iostream>
#include <vector>

int count_ways_O1space(int n){
    int c1, c2, c3, c4; //i-1 i-2 i-3 i-4
    int c_i;

    if(n == 0 || n == 1 || n == 2)
        return 1;
    if(n == 3)  
        return 2;

    c4 = c3 = c2 = 1; 
    c1 = 2; 

    for(int i = 4; i <=n ; i++){
        c_i = c1 + c3 + c4;

        c4 = c3;
        c3 = c2;
        c2 = c1;
        c1 = c_i;
    }

    return c_i;
}

int count_ways(int n) {
  std::vector<int> c(n + 1);

  c.at(0) = 1;
  // perché 1a+3b+4c se metto a=b=c=0 ho un solo modo (unico tra
  // l'altro) di esprimere 0 come somma di 1 3 e 4!
  c.at(1) = c.at(2) = 1;
  c.at(3) = 2;

  for (int i = 4; i <= n; i++)
    c.at(i) = c.at(i - 1) + c.at(i - 3) + c.at(i - 4);

  for (int i = 0; i <= n; i++) {
    std::cout << c.at(i) << " ";
  }
  std::cout << std::endl;
  return c.at(n);
}

int main() {
  int n = 20;
  for (int i = 3; i < 20; i++) {
    std::cout << "n = " << i << std::endl;
    std::cout << count_ways(i);
    std::cout << std::endl;
    std::cout << count_ways_O1space(i);
    std::cout << std::endl;
  }
}