/**
 * @file structs_used.hpp
 * @author me, myself and I
 * @brief struttura dati utilizzata per descrivere gli elementi dell'array
 * @version 1.0
 * @date 2023-11-15
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
