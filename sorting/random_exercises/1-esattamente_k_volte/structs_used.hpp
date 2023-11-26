/**
 * @file structs_used.hpp
 * @author me, myself and I
 * @brief strutture dati ausiliarie
 * @version 1.0
 * @date 2023-11-26
 */

/**
 * @brief struttura composta da due indici q e t, serve a rendere un doppio
 * indice nella tripartizione del quick sort
 *
 */
struct double_index {
  int q;
  int t;

  double_index(int min, int max) : q{min}, t{max} {};
};

typedef double_index *my_double_index;