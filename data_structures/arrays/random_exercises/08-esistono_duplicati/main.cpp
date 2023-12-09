

#include <cmath>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

bool ha_duplicati(const std::vector<int> &A, int p, int r) {
  if (p < r) { // almeno due elementi
    int med = std::floor((p + r) / 2);
    bool risSX = ha_duplicati(A, p, med);
    bool risDX = ha_duplicati(A, med + 1, r);

    if (A.at(med) == A.at(med + 1))
      return true;
    else
      return risSX || risDX;
  } else {
    return false;
  }
}

void print_array(const std::vector<int> &a) {
  for (int i = 0; i < a.size(); i++)
    std::cout << a.at(i) << " ";

  std::cout << std::endl;
}

std::vector<std::vector<int>> get_arrays_from_file(std::string file_name) {
  std::string line;

  std::vector<std::vector<int>> arrays;

  std::ifstream my_file(file_name);
  if (my_file.is_open()) {
    while (!my_file.eof()) {
      std::vector<int> arr;

      if (getline(my_file, line)) {
        std::stringstream ss(line);
        int n;
        while (ss >> n)
          arr.push_back(n);
      }
      arrays.push_back(arr);
    }

    my_file.close();
  }

  return arrays;
}

int main() {

  std::vector<std::vector<int>> arrays = get_arrays_from_file("test.txt");

  for (int i = 0; i < arrays.size(); i++) {
    std::vector<int> a = arrays.at(i);
    print_array(a);

    std::cout << (ha_duplicati(a, 0, a.size() - 1)
                      ? "contiene almeno un elemento duplicato"
                      : "non ha duplicati");
    std::cout << std::endl;
    std::cout << std::endl;
  }
}