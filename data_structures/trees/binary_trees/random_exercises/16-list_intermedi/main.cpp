

#include "header.cpp"
#include <list>
#include <vector>

int main(){
  std::vector<T> v_tree = get_trees_from_file("test.txt");
  
  for(int i = 0; i < v_tree.size(); i++){
    pnode root = v_tree.at(i)->root;
    std::cout<<"post order: ";
    post_order(root);
    std::cout<<std::endl;
    std::list<pnode> list_intermedi = intermedi(root);
    std::cout<<"lista nodi intermedi: ";
    print_list(list_intermedi);
  }
}