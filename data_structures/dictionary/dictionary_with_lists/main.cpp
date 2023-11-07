/**
 * @file main.cpp
 * @author me, myself and I
 * @brief test del dizionario implementato tramite liste concatenate
 * @version 1.0
 * @date 2023-11-07
 */
#include "header.cpp"
#include <iostream>
#include <list>

int main() {

  L list_ = new my_list;

  std::cout << "[INSERT] inserendo elementi nella lista"
            << " ..." << std::endl
            << "~> ";
  insert(list_, 1, 1);
  insert(list_, 9, 12);
  insert(list_, -7, 55);
  insert(list_, 1, 78);
  insert(list_, 3, -21);

  print_list(list_->head);
  std::cout << std::endl << std::endl;

  int k_seach = 77;
  std::cout << "[SEARCH] cercando elemento con chiave " << k_seach << " ..."
            << std::endl;
  record *res = search(list_, k_seach);
  if (res != nullptr)
    std::cout << "~> Elemento trovato! k: " << k_seach << " v: " << res->info
              << std::endl
              << std::endl;
  else
    std::cout << "~> Nessun elemento contenete la chiave cercata" << std::endl
              << std::endl;

  int k_del = 1;
  std::cout << "[DELETE] eliminando elementi con chiave " << k_del << " ..."
            << std::endl
            << "~> ";
  delete_(list_, k_del);
  print_list(list_->head);
}