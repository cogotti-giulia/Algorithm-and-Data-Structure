/**
 * @file header.hpp
 * @author cogotti-giulia (cogotti.giulia.irl@gmail.com)
 * @brief definizione metodi e funzioni usate
 * @version 1.0
 * @date 2023-12-09
 *
 * @copyright Copyright (c) 2023
 *
 */
#include "structs_used.hpp"
#include <string>
#include <vector>

/**
 * @brief dato un array un array A di n elementi, costruisce ricorsivamente un
 * albero binario bilanciato tale che A[i] sia l’(i+1)-esimo campo u.key in
 * ordine di visita posticipata (post ordine)
 * @param A array di input A[0...n]
 * @param p inizio porzione su cui sto operando (alla prima chiamata p = 0)
 * @param r fine porzione su cui sto operando (alla prima chiamata r = n-1)
 * @return radice dell'albero bilanciato appena costruito
 */
pnode build_tree_balanced(const std::vector<int> &A, int p, int r);

void post_order(pnode u);

void print_array(const std::vector<int> &a);

std::vector<std::vector<int>> get_arrays_from_file(std::string file_name);