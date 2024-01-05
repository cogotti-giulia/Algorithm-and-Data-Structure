
/**
 * @file header.cpp
 * @author cogotti-giulia (cogotti.giulia.irl@gmail.com)
 * @brief implementazione metodi e funzioni
 * @version 1.0
 * @date 2024-01-05
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "header.hpp"
#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

int find_maximum(const p_heap &A) {
  int index_first_leaf = std::floor(A->heap_size / 2) - 1;
  return find_maximum_AUX(A, index_first_leaf, A->heap_size - 1);
}

int find_maximum_AUX(const p_heap &A, int p, int r) {
  if (p == r) {
    return A->arr.at(p);
  } else if (p < r) {
    int med = std::floor((p + r) / 2);
    int maxSX = find_maximum_AUX(A, p, med);
    int maxDX = find_maximum_AUX(A, med + 1, r);

    return std::max(maxSX, maxDX);
  } else {
    throw "error, heap empty :(";
  }
}

void build_min_heap(p_heap &A) {
  A->heap_size = A->length;

  for (int i = std::floor(A->length / 2) - 1; i >= 0; i--)
    min_heapify(A, i);
}

// i figli left(i) e right(i) sono dei min heap
void min_heapify(p_heap &A, int i) {
  int l = left(i);
  int r = right(i);

  int min;

  if (l < A->heap_size && A->arr.at(l) < A->arr.at(i))
    min = l;
  else
    min = i;

  if (r < A->heap_size && A->arr.at(r) < A->arr.at(min))
    min = r;

  if (min != i) {
    my_swap(A, i, min);
    min_heapify(A, min);
  }
}

int left(int i) { return i * 2 + 1; }

int right(int i) { return i * 2 + 1 + 1; }

void my_swap(p_heap &A, int i1, int i2) {
  int tmp = A->arr.at(i1);
  A->arr.at(i1) = A->arr.at(i2);
  A->arr.at(i2) = tmp;
}

void print_heap(const p_heap &A) {
  for (int i = 0; i < A->heap_size; i++)
    std::cout << A->arr.at(i) << " ";

  std::cout << std::endl;
}

std::vector<p_heap> get_heaps_from_file(std::string file_name) {
  std::string line;

  std::vector<p_heap> heaps;

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

      p_heap A = new my_heap(arr, 0, arr.size());
      build_min_heap(A);
      heaps.push_back(A);
    }

    my_file.close();
  }

  return heaps;
}