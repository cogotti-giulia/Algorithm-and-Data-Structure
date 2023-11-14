/**
 * @author me, myself and I
 * @brief strutture dati utilizzate per implementare l'array in modo da avere
 * anche dei dati satellite collegati alla chiave
 * @version 1.0
 * @date 2023-11-14
 */

struct elem {
  int key;
  char satellite;

  elem(int k, char s) : key{k}, satellite{s} {};

  int get_key() { return key; }
  void set_key(int k) { key = k; }

  char get_satellite() { return satellite; }
  void set_satellite(int s) { satellite = s; }
};

typedef elem *my_elem;
