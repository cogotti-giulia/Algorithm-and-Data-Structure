
//realizzazione tramite strutture collegate: puntatore a left e right
struct node_left_right {
    //node *p; //puntatore al padre
    node_left_right *left; //puntatore al figlio sinistro
    node_left_right *right; //puntatore al figlio destro
    char key; //contenuto informativo nodo

    //costruttore
    node_left_right(char k) : key{k}, left{nullptr}, right{nullptr} {}
    node_left_right(char k, node_left_right * sx, node_left_right * dx) : key{k}, left{sx}, right{dx} {}

};
typedef node_left_right * pnode;

struct tree_left_right{
    node_left_right * root;

    tree_left_right():root{nullptr}{};
};
typedef tree_left_right * T;