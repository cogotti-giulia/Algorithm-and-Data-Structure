

#include <iostream>
#include <vector>

void counting_sort_descending(std::vector<int> A, std::vector<int> &B, int n,
                              int k) {

  std::vector<int> C(k + 1);

  for (int i = 0; i <= k; i++)
    C.at(i) = 0;

  for (int j = 0; j < n; j++)
    C.at(k - A.at(j))++;

  for (int i = 1; i <= k; i++)
    C.at(i) = C.at(i) + C.at(i - 1);

  for (int j = n - 1; j >= 0; j--) {
    C.at(k - A.at(j))--;
    B.at(C.at(k - A.at(j))) = A.at(j);
  }
}

void counting_sort(std::vector<int> A, std::vector<int> &B, int n, int k) {

  std::vector<int> C(k + 1);

  for (int i = 0; i <= k; i++)
    C.at(i) = 0;

  for (int j = 0; j < n; j++)
    C.at(A.at(j))++;

  for (int i = 1; i <= k; i++)
    C.at(i) = C.at(i) + C.at(i - 1);

  for (int j = n - 1; j >= 0; j--) {
    C.at(A.at(j))--;
    B.at(C.at(A.at(j))) = A.at(j);
  }
}

int main() {
  std::vector<int> A = {3, 0, 2, 3, 2, 10, 7, 7, 0};

  std::vector<int> B(A.size());

  std::cout << "A: ";

  for (int i = 0; i < A.size(); i++)
    std::cout << A.at(i) << " ";
  std::cout << std::endl;
  std::cout << std::endl;

  std::cout << "A descending: ";

  counting_sort_descending(A, B, A.size(), 10);
  for (int i = 0; i < A.size(); i++)
    std::cout << B.at(i) << " ";

  std::cout << std::endl;

  std::cout << "A ascending: ";

  counting_sort(A, B, A.size(), 10);
  for (int i = 0; i < A.size(); i++)
    std::cout << B.at(i) << " ";
}