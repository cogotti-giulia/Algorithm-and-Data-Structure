
#include "header.cpp"
#include <iostream>
#include <string>
#include <vector>

int main() {
  std::vector<std::vector<int>> c;
  std::vector<std::vector<char>> b;

  std::string X = "ABACA";
  std::string Y = "ACDAB";

  MyStruct arrows;

  for (int i = 0; i <= X.size(); i++) {
    std::vector<int> tmp;

    for (int j = 0; j <= Y.size(); j++)
      tmp.push_back(0);

    c.push_back(tmp);
  }

  for (int i = 0; i <= X.size(); i++) {
    std::vector<char> tmp;

    for (int j = 0; j <= Y.size(); j++)
      tmp.push_back(arrows.EMPTY);

    b.push_back(tmp);
  }

  std::cout << "S1: " << X << std::endl;
  std::cout << "S2: " << Y << std::endl;

  std::cout << "LCS: ";
  print_LCS(X, Y, c, b);
  std::cout << std::endl;
  std::cout << std::endl;

  std::cout
      << "Matrice c, dove c[i,j] rappresenta la lunghezza della LCS(X^i, Y^j)"
      << std::endl;
  for (int i = 0; i <= X.size(); i++) {
    for (int j = 0; j <= Y.size(); j++)
      std::cout << c.at(i).at(j) << " ";
    std::cout << std::endl;
  }

  std::cout << std::endl;

  std::cout << "Matrice b, dove b[i,j] contiene le informazioni utili per "
               "recuperare la soluzione"
            << std::endl;
  for (int i = 0; i <= X.size(); i++) {
    for (int j = 0; j <= Y.size(); j++)
      std::cout << b.at(i).at(j) << " ";
    std::cout << std::endl;
  }

  std::cout << std::endl;

  std::cout << "**************************************************************";
  std::cout << std::endl << std::endl;

  std::cout << "Versione ottimizzata (per lo spazio in memoria), non utilizza "
               "la tabella b"
            << std::endl;
  std::cout << "S1: " << X << std::endl;
  std::cout << "S2: " << Y << std::endl;

  std::cout << "LCS: ";
  print_LCS(X, Y, c, b);
  std::cout << std::endl << std::endl;
  std::cout
      << "Matrice c, dove c[i,j] rappresenta la lunghezza della LCS(X^i, Y^j)"
      << std::endl;
  for (int i = 0; i <= X.size(); i++) {
    for (int j = 0; j <= Y.size(); j++)
      std::cout << c.at(i).at(j) << " ";
    std::cout << std::endl;
  }
}