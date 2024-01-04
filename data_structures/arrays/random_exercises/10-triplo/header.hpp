/**
 * @file header.hpp
 * @author cogotti-giulia (cogotti.giulia.irl@gmail.com)
 * @brief definizione metodi e funzioni (e struttura dati ausiliaria utilizzata)
 * @version 1.0
 * @date 2024-01-04
 *
 * @copyright Copyright (c) 2024
 *
 */
#include <string>
#include <vector>

struct ii {
  int info;
  int index;

  ii(int info, int index) : info{info}, index{index} {};
};
typedef ii *pii;

bool triplo(const std::vector<int> &A, int *i, int *j);

bool my_merge_sort(std::vector<pii> &a, int p, int r, int *i, int *j);

bool my_merge(std::vector<pii> &a, int p, int q, int r, int *index1,
              int *index2);

void print_array(const std::vector<int> &a);

std::vector<std::vector<int>> get_arrays_from_file(std::string file_name);