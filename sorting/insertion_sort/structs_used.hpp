/**
 * @author me, myself and I
 * @brief strutture dati utilizzate per implementare l'array
 * @version 1.0
 * @date 2023-11-14
 */

// creo una struct solo per portarmi sempre dietro la size, lo so, avrei potuto
// usare vector o array ma va bene anche così per quel che ci devo fare
struct array {
  int *key;
  int size;

  array(int *a, int n) : key{a}, size{n} {};
};

typedef array *my_array;