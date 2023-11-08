
struct Node {
  int key;
  char col;
  Node *left;
  Node *right;

  Node(int k, char c, Node *sx = nullptr, Node *dx = nullptr)
      : key{k}, col{c}, left{sx}, right{dx} {}
};
typedef Node *PNode;

struct tree {
  Node *root;

  tree() : root{nullptr} {};
};

typedef tree *T;