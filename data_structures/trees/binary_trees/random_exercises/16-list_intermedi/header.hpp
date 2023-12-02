
#include "structs_used.hpp"
#include <list>
#include <string>
#include <vector>

std::list<pnode> intermedi(pnode u);

void intermedi_aux(pnode u, std::list<pnode>& list_intermedi, int sumPercorso, int *sumKeysSubtree);

pnode crea_albero(parr vector_parent);

std::vector<T> get_trees_from_file(std::string file_name);

void print_list(const std::list<pnode>& list);