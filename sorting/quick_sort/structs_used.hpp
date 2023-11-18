
/**
 * @file structs_used.hpp
 * @author me, myself and I
 * @brief struttura dati utilizzata per descrivere gli elementi dell'array
 * @version 1.0
 * @date 2023-11-18
 */

struct elem {
  int key;
  char satellite;

  elem(int k, char s) : key{k}, satellite{s} {};

  int get_key() { return key; }
  void set_key(int k) { key = k; }

  char get_satellite() { return satellite; }
  void set_satellite(char s) { satellite = s; }
};

typedef elem *my_elem;

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