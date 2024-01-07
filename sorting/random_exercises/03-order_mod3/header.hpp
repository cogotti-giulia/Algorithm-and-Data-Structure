/**
 * @file header.hpp
 * @author cogotti-giulia (cogotti.giulia.irl@gmail.com)
 * @brief definizione metodi e funzioni
 * @version 1.0
 * @date 2023-12-06
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <string>
#include <vector>

void merge_sort_mod3(std::vector<int> *A, int p, int r);

void merge_mod3(std::vector<int> *A, int p, int q, int r);

std::vector<std::vector<int>> get_arrays_from_file(std::string file_name);

void print_vector_and_mod3(const std::vector<int> &A);