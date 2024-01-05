/**
 * @file header.hpp
 * @author cogotti-giulia (cogotti.giulia.irl@gmail.com)
 * @brief definizione metodi e funzioni
 * @version 1.0
 * @date 2024-01-05
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <string>
#include <vector>

int min_distance_abs(std::vector<int> &A, int *x, int *y);
void my_merge_sort(std::vector<int> &A, int p, int r);
void my_merge(std::vector<int> &A, int p, int q, int r);

void print_array(const std::vector<int> &a);

std::vector<std::vector<int>> get_arrays_from_file(std::string file_name);