/**
 * @file header.hpp
 * @author cogotti-giulia (cogotti.giulia.irl@gmail.com)
 * @brief definizione metodi e funzioni utilizzate
 * @version 1.0
 * @date 2024-01-05
 *
 * @copyright Copyright (c) 2024
 *
 */
#include "structs_used.hpp"
#include <string>

int find_maximum(const p_heap &A);

int find_maximum_AUX(const p_heap &A, int p, int r);

void build_min_heap(p_heap &A);
void min_heapify(p_heap &A, int i);

int left(int i);
int right(int i);

void my_swap(p_heap &A, int i1, int i2);

void print_heap(const p_heap &A);

std::vector<p_heap> get_heaps_from_file(std::string file_name);