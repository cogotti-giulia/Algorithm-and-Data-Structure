
#include "header.cpp"

int main(){
  int n = 10;
  int A[10] = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7};

  p_heap heap = new my_heap(A, 0, n);
  my_heap_sort(heap);

  stampa_array(heap);
}