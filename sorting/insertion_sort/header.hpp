/**
 * @file header.hpp
 * @author me, myself and I
 * @brief definizione metodi e funzioni
 * @version 1.0
 * @date 2023-11-14
 */
#include "structs_used.hpp"
#include <array>
#include <cstddef>

/**
 * @brief ordina l'array di input
 *
 * @tparam n size dell'array
 * @param arr array da ordinare
 */
template <std::size_t n> 
void insertion_sort(std::array<my_elem, n> arr);

template <std::size_t n> 
void stampa_array(std::array<int, n> arr);