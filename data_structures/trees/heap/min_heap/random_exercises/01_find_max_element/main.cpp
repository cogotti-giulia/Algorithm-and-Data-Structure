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
#include <vector>

int main() {

  std::vector<p_heap> heaps = get_heaps_from_file("test.txt");

  for (int i = 0; i < heaps.size(); i++) {
    p_heap heap = heaps.at(i);

    print_heap(heap);

    std::cout << "massimo elemento: " << find_maximum(heap) << std::endl;
  }
}