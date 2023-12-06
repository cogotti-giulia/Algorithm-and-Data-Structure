/**
 * @file main.cpp
 * @author cogotti-giulia (cogotti.giulia.irl@gmail.com)
 * @brief test su qualche array preso da file
 * @version 1.0
 * @date 2023-12-06
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include "header.cpp"
#include <string>
#include <vector>

int main() {

  std::vector<std::vector<int>> vv = get_arrays_from_file("test.txt");

  for (int i = 0; i < vv.size(); i++) {
    std::vector<int> A = vv.at(i);

    print_vector_and_mod3(A);

    merge_sort_mod3(&A, 0, A.size() - 1);

    std::cout << "*** SORTING A[i] % 3 ***" << std::endl;
    print_vector_and_mod3(A);
    std::cout << "-------------------------" << std::endl << std::endl;
  }
}