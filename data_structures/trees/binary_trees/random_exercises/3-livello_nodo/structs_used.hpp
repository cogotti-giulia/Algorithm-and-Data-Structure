struct node{
    int key;
    node *left;
    node *right;

    node(int k, node * sx = nullptr, node * dx = nullptr) : key{k}, left{sx}, right{dx} {};
};
typedef node * pnode ;

struct tree{
    node * root;

    tree():root{nullptr}{};
};
typedef tree * T ;
