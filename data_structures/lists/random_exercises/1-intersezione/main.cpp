
#include "structs_used.hpp"
#include <cstdlib>
#include <iostream>
#include <vector>

void add_elem_coda(my_list &pt_testa, my_list &pt_coda, int info) {
  my_list nuovo = new elem(info);
  nuovo->next = nullptr;
  nuovo->prev = pt_coda;

  if (pt_coda != nullptr)
    pt_coda->next = nuovo;

  pt_coda = nuovo;

  if (pt_testa == nullptr)
    pt_testa = nuovo;
}
void print_list(my_list l) {
  if (l) {
    std::cout << l->info << " ";
    print_list(l->next);
  }
}

void delete_elem(my_list &l1_pt_testa, my_list &l1_pt_coda,
                 my_list &scorri_n1) {
  // elimino da n1

  my_list tmp = scorri_n1;

  // elimino in testa, devo sistemare il puntatore
  // altrimenti sistemo next e prev normalmente
  if (tmp->prev == nullptr /*scorri_n1 == l1_pt_testa*/)
    l1_pt_testa = tmp->next;
  else {
    tmp->prev->next = tmp->next;
  }

  // elimino in coda, devo sistemare il puntatore
  // altrimenti sistemo next e prev normalmente
  if (tmp->next == nullptr /*scorri_n1 == l1_pt_coda*/)
    l1_pt_coda = tmp->prev;
  else
    tmp->next->prev = tmp->prev;

  scorri_n1 = scorri_n1->prev;
  free(tmp);
}

void intersezione(my_list &l1_pt_testa, my_list &l1_pt_coda,
                  my_list &l2_pt_testa) {

  my_list scorri_n1 = l1_pt_coda;
  my_list scorri_n2 = l2_pt_testa;

  while (scorri_n1 != nullptr) {
    if (scorri_n2 != nullptr) {
      if (scorri_n1->info == scorri_n2->info) {

        scorri_n1 = scorri_n1->prev;
        scorri_n2 = scorri_n2->next;
      } else {
        if (scorri_n1->info > scorri_n2->info) {
          // elimino da n1
          delete_elem(l1_pt_testa, l1_pt_coda, scorri_n1);

        } else {
          scorri_n2 = scorri_n2->next;
        }
      }
    } else {
      // elimino da n1
      delete_elem(l1_pt_testa, l1_pt_coda, scorri_n1);
    }
  }
}

int main() {
  my_list l1_head = nullptr;
  my_list l1_tail = nullptr;

  my_list l2_head = nullptr;
  my_list l2_tail = nullptr;

  std::vector<int> l1_arr = {-2, 1, 3, 3, 4, 9, 9, 12, 15};
  std::vector<int> l2_arr = {9, 7, 5, 3, 3, 1};

  for (int i = 0; i < l1_arr.size(); i++)
    add_elem_coda(l1_head, l1_tail, l1_arr.at(i));

  print_list(l1_head);
  std::cout << std::endl;

  for (int i = 0; i < l2_arr.size(); i++)
    add_elem_coda(l2_head, l2_tail, l2_arr.at(i));

  print_list(l2_head);
  std::cout << std::endl;

  intersezione(l1_head, l1_tail, l2_head);

  print_list(l1_head);
  std::cout << std::endl;
}