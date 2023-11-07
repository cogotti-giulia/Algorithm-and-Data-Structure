/**
 * @file header.cpp
 * @author me, myself and I
 * @brief implementazione funzioni e metodi
 * @version 1.0
 * @date 2023-11-07
 */
#include "header.hpp"
#include <iostream>

/*********************************** insert *********************************/
//! T_insert(n) = Teta(1) costante, inserisco SEMPRE in testa (possibili
//! duplicati)
void insert(L list, int k, int v) {
  // crea il nuovo record
  elem p_nuovo = new record;
  p_nuovo->key = k;
  p_nuovo->info = v;

  // fa in modo che il suo next sia il primo elemento della lista
  p_nuovo->next = list->head;
  p_nuovo->prev = nullptr;

  // se L->head punta a un elemento, sposto il puntatore al nuovo
  if (list->head != nullptr)
    list->head->prev = p_nuovo;

  list->head = p_nuovo;
}

/************************************ search **********************************/
//! T_search(n) = O(n)
elem search(L list, int k) {
  elem scorri = list->head;

  while (scorri->next != nullptr &&
         scorri->key != k) //? al più O(n), vedi INVARIANTE negli appunti :(
    scorri = scorri->next;

  if (scorri->next != nullptr)
    return scorri;
  else
    return nullptr;
}

/************************************ delete **********************************/
//! T_delete(n) = Teta(n)
void delete_(L list, int k) {
  elem scorri = list->head;

  while (scorri != nullptr) { //? eseguito n volte, devo scorrere tutto perché
                              //possono esserci duplicati
    if (scorri->key == k) {
      if (scorri->next != nullptr)
        scorri->next->prev = scorri->prev;

      if (scorri->prev != nullptr)
        scorri->prev->next = scorri->next;
      else
        list->head->next = scorri->next;

      record *tmp = scorri;
      scorri = scorri->next;
      delete tmp;
    } else
      scorri = scorri->next;
  }
}

/************************************ print ***********************************/
void print_list(elem e) {
  if (e) {
    std::cout << "key:" << e->key << " info:" << e->info << " ; ";
    print_list(e->next);
  }
}