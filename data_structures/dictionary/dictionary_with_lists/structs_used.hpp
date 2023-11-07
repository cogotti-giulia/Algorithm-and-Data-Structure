/**
 * @file structs_used.hpp
 * @author me, myself and I
 * @brief strutture dati utilizzate per implementare il dizionario
 * @version 1.0
 * @date 2023-11-07
 */

// elementi dizionario
struct record {
  record *next;
  record *prev;
  int key;
  int info;
};
typedef struct record *elem;

// lista con un puntatore alla testa
struct my_list {
  record *head;
};

typedef my_list *L;
