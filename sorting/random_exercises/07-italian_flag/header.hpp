/**
 * @file header.hpp
 * @author cogotti-giulia (cogotti.giulia.irl@gmail.com)
 * @brief definizione metodi e funzioni
 * @version 1.0
 * @date 2024-01-07
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <string>
#include <vector>

void italian_flag(std::vector<char>& A);

void my_swap(std::vector<char>& A, int i1, int i2);

void print_array(const std::vector<char>& A);

std::vector<std::vector<char>> get_arrays_from_file(std::string file_name);