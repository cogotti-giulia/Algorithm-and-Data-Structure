/**
 * @file header.cpp
 * @author cogotti-giulia (cogotti.giulia.irl@gmail.com)
 * @brief implementazione funzioni
 * @version 1.0
 * @date 2024-01-05
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "header.hpp"
#include <cmath>
#include <fstream>
#include <iostream>
#include <sstream>

bool check_property(T t) {
  if (t->root == nullptr)
    return true;
  else {
    pnode scorri = tree_minumum(t->root);

    bool is_ok = true;

    while (scorri != nullptr && is_ok) {
      int k = scorri->key;

      pnode succ = tree_successor(scorri);
      if (succ != nullptr && k + 2 == succ->key)
        is_ok = false;

      scorri = succ;
    }

    return is_ok;
  }
}

pnode tree_minumum(pnode x) {
  while (x->left != nullptr)
    x = x->left;

  return x;
}

pnode tree_successor(pnode x) {
  if (x->right != nullptr)
    return tree_minumum(x->right);
  else {
    pnode y = x->p;

    while (y != nullptr && y->left != x) {
      x = y;
      y = x->p;
    }
    return y;
  }
}

T build_BST(const std::vector<int> &A) {
  T t = new tree();
  t->root = build_BST_AUX(A, 0, A.size() - 1, nullptr);

  return t;
}

pnode build_BST_AUX(const std::vector<int> &A, int p, int r, pnode padre) {
  if (p > r)
    return nullptr;
  else {
    int med = std::floor((p + r) / 2);
    pnode nuovo = new node(A.at(med));
    nuovo->p = padre;
    nuovo->left = build_BST_AUX(A, p, med - 1, nuovo);
    nuovo->right = build_BST_AUX(A, med + 1, r, nuovo);

    return nuovo;
  }
}

void print_bst(T t) {
  if (t->root != nullptr) {
    pnode scorri = tree_minumum(t->root);

    while (scorri != nullptr) {
      std::cout << scorri->key << " ";
      pnode tmp = scorri;
      scorri = tree_successor(tmp);
    }
  }
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