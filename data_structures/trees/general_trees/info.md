# Altre cose importanti

## File di test

I file dai quali vengono presi i casi di testi sono formattati nel seguente modo

```txt
i:5 -1 4 2 10 -3 7 8
p:-1 0 0 0 1 1 2 2
l:0 1 0 0 1 0 1 0
```

Gli alberi sono descritti in tre righe (campi del [vettore dei padri](strutture_dati.md)), il primo carattere di ogni riga identifica cosa conterrà l'array

- i : info, contenuto informativo del nodo (visita a livelli)
- p : parent, padre del nodo (-1 radice)
- l : is_left_child, 1 se il nodo è un left child 0 altrimenti

i due punti (':") separano questa lettera dai valori effettivi contenuti nell'array.

Ogni elemento dell'array è separato da uno spazio.

### Codice c++

LA funzione legge il file riga per riga, crea i vettori parent info e child position per ogni albero presente e a partire da essi crea un vettore di parent e lo aggiunge all'array che li contiene tutti.

Come finisce di leggere il file, scorre il vettore dei parent e crea un albero per ciascuno di essi, conservandolo in un array che verrà restituito al chiamante.

```c++

std::vector<T> get_trees_from_file(std::string file_name) {
  std::vector<parrG> v_parent;
  std::vector<T> v_tree;

  std::ifstream my_file(file_name);
  std::string line;

  if (my_file.is_open()) {
    while (!my_file.eof()) {
      std::vector<int> info;
      std::vector<int> parent;
      std::vector<bool> is_left_child;

      int count_correct_lines = 0;
      for (int i = 0; i < 3; i++) {
        if (getline(my_file, line)) {

          std::string delimiter = ":";
          std::string type = line.substr(0, line.find(delimiter));
          line.erase(0, 2);

          std::stringstream ss(line);

          switch (type.at(0)) {
          case 'i': {
            int tmp;
            while (ss >> tmp)
              info.push_back(tmp);
            count_correct_lines++;
          } break;
          case 'p': {
            int tmp;
            while (ss >> tmp)
              parent.push_back(tmp);
            count_correct_lines++;
          } break;
          case 'l': {
            int tmp;
            while (ss >> tmp) {
              if (tmp == 1)
                is_left_child.push_back(true);
              else
                is_left_child.push_back(false);
            }
            count_correct_lines++;
          } break;
          default: {
            std::cout
                << "Ooops, something went wrong! (check your file, maybe you "
                   "write something wrong)";
            exit(false);
          }
          }
        } else {
          std::cout
              << "Ooops, something went wrong! (check your file, maybe you "
                 "write something wrong)";
          exit(false);
        }
      }

      if (count_correct_lines < 3) {
        std::cout << "Ooops, something went wrong! (check your file, maybe you "
                     "write something wrong)";
        exit(false);
      }
      v_parent.push_back(new vector_parent(parent, info, is_left_child));
    }
    my_file.close();
  } else {
    std::cout << "The file doesn t exist!";
    exit(false);
  }

  for (int i = 0; i < v_parent.size(); i++) {
    T t = new tree();
    t->root = crea_albero(v_parent.at(i));
    v_tree.push_back(t);
  }

  return v_tree;
}
```