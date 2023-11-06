#include <bits/stdc++.h>

using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution {
    public:
  	
  	void preOrder(Node *root) {
		
      	if( root == NULL )
          	return;
      
      	std::cout << root->data << " ";
      	
      	preOrder(root->left);
      	preOrder(root->right);
    }

/*
Node is defined as 

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

*/

    Node * insert(Node * root, int data) {
       
        Node* y = nullptr; //padre del nodo con cui scorro
        Node* node = new Node(data); //nuovo nodo da inserire
        
        Node* scorri = root; //nodo per scorrere
        while(scorri != nullptr){
            y = scorri; 
            if(node->data < scorri->data) 
            /* il valore da inserire e' < di quello del nodo che sto analizzando, 
            allora devo andare nel sottoalbero sinistro, altrimenti nel destro*/
                scorri = scorri->left;
            else 
                scorri = scorri->right;   
        }
        
        //a questo punto y contiene il nodo foglia a cui attacare il nuovo nodo
        //se l'albero fosse vuoto, allora il nuovo nodo è la radice dell'albero
        if(y == nullptr){
            root = node;
            return root;
        }else{
            /*altrimenti in base al valore della chiave lo inserisco a sinistra o a destra*/
            if(node->data < y->data)
                y->left = node;
            else
                y->right = node;
        }
        
        
        return root;
    }

};

int main() {
  
    Solution myTree;
    Node* root = NULL;
    
    int t;
    int data;

    std::cin >> t;

    while(t-- > 0) {
        std::cin >> data;
        root = myTree.insert(root, data);
    }
  	
    myTree.preOrder(root);
  
    return 0;
}
