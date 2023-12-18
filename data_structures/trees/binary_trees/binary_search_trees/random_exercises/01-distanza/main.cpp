/**
 * @file main.cpp
 * @author me, myself and I
 * @brief test distanza minima BST
 * @version 1.0
 * @date 2023-11-08
 */
#include "header.cpp"

int main() {

  size_t n = 6;
  int arr_ordinato[] = {-1, 3, 6, 9, 15, 17};
  T t = build_BST_OTT(arr_ordinato, n);

  in_order(t->root);
  std::cout << std::endl;

  int min_dist = min_distance(t);
  std::cout << "minima distanza: " << min_dist << std::endl;
}
