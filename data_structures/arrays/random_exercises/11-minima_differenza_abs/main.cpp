/**
 * @file main.cpp
 * @author cogotti-giulia (cogotti.giulia.irl@gmail.com)
 * @brief test
 * @version 1.0
 * @date 2024-01-05
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "header.cpp"

int main() {
  std::vector<std::vector<int>> arrays = get_arrays_from_file("test.txt");

  for (int k = 0; k < arrays.size(); k++) {
    std::vector<int> A = arrays.at(k);
    print_array(A);

    int x, y;
    int min_diff = min_distance_abs(A, &x, &y);

    std::cout<<"MIN DISTANCE |x-y|: "<< y<<"(y) - "<<x<<"(x) = "<<min_diff<<std::endl<<std::endl;
  }
}