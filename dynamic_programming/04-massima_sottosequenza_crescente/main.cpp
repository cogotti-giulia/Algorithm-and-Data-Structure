
#include <iostream>
#include <vector>

int massima_sottosequenza_crescente(std::vector<int> num) {

  int n = num.size();
  std::vector<int> L(n);
  L.at(0) = 1;

  int max = L.at(0);

  for (int j = 1; j < n; j++) {
    int max_1_j = 0;
    for (int k = 0; k < j; k++) {
      if (num.at(k) < num.at(j) && L.at(k) > max_1_j)
        max_1_j = L.at(k);
    }

    L.at(j) = 1 + max_1_j;
    if (L.at(j) > max)
      max = L.at(j);
  }

  return max;
}

int main() {

  std::vector<std::vector<int>> num = {{1, 2, 3, 4, 0, 10},
                                       {-1, -3, 2, 7, 4, 1, 12},
                                       {4, 1, -1, 3, 10, 11},
                                       {1},
                                       {9, 8, 7, 6, 10, 5, 11, 3}};

  for (int i = 0; i < num.size(); i++) {
    for (int j = 0; j < num.at(i).size(); j++)
      std::cout << num.at(i).at(j) << " ";

    std::cout << std::endl;
    std::cout << "LIS: " << massima_sottosequenza_crescente(num.at(i));
    std::cout << std::endl;
    std::cout << std::endl;
  }
}