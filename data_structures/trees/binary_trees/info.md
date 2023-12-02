# Altre cose importanti

## File di test

I file dai quali vengono presi i casi di testi sono formattati nel seguente modo

```txt
i:2 3 2 -1 0 7
p:-1 0 0 1 1 2
c:z l r l r r
```

Gli alberi sono descritti in tre righe (campi del [vettore dei padri](strutture_dati.md)), il primo carattere di ogni riga identifica cosa conterrà l'array

- i : info, contenuto informativo del nodo (visita a livelli)
- p : parent, padre del nodo (-1 radice)
- c : child_position, posizione del nodo rispetto al padre (z radice, l left ed r right)

i due punti (':") separano questa lettera dai valori effettivi contenuti nell'array.

Ogni elemento dell'array è separato da uno spazio.

### Codice c++

Assumendo che il file sia formattato nel modo corretto, legge il file riga per riga, crea i vettori parent info e child position per ogni albero presente e a partire da essi crea un vettore di parent e lo aggiunge all'array che li contiene tutti.

Come finisce di leggere il file, scorre il vettore dei parent e crea un albero per ciascuno di essi, conservandolo in un array che verrà restituito al chiamante.

```c++
std::vector<T> get_trees_from_file(std::string file_name) {
  std::vector<parr> v_parent;
  std::vector<T> v_tree;

  std::ifstream my_file(file_name);
  std::string line;

  if (my_file.is_open()) {
    while (!my_file.eof()) {
      std::vector<int> info;
      std::vector<int> parent;
      std::vector<char> child_posi;
      
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
          case 'c': {
            char tmp;
            while (ss >> tmp)
              child_posi.push_back(tmp);
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
      v_parent.push_back(new vector_parent(parent, info, child_posi));
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
