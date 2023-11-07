
// struttura dati utilizzata per implementare gli elementi del dizionario
struct record {
    record *next;
    record *prev;
    int key;
    int info;
};
typedef struct record * elem;

// lista con un puntatore alla testa
struct my_list{
    record *head;
};

typedef my_list * L;

