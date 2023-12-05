
struct elem {
  elem *prev;
  elem *next;
  int info;

  elem(int i, elem *p = nullptr, elem *n = nullptr)
      : prev{p}, next{n}, info{i} {};
};

typedef elem *my_list;