
#include "header.hpp"
#include <iostream>

MyStruct arrows;

void bottomup_LCS(std::string X, std::string Y,
                  std::vector<std::vector<int>> &c,
                  std::vector<std::vector<char>> &b) {
  int m = X.size();
  int n = Y.size();

  /* riempe prima riga e prima colonna con zero (confronta una lettera con la
   * stringa vuota, non hanno nulla in comune) */
  for (int i = 0; i <= m; i++)
    c.at(i).at(0) = 0;

  for (int j = 0; j <= n; j++)
    c.at(0).at(j) = 0;

  for (int i = 1; i <= m; i++)
    for (int j = 1; j <= n; j++)
      if (X.at(i - 1) == Y.at(j - 1)) {
        c.at(i).at(j) = c.at(i - 1).at(j - 1) + 1;
        b.at(i).at(j) = arrows.OBLI;
      } else {
        if (c.at(i - 1).at(j) >= c.at(i).at(j - 1)) {
          // l'uguale da precedenza alla riga
          c.at(i).at(j) = c.at(i - 1).at(j);
          b.at(i).at(j) = arrows.TOP;
        } else {
          c.at(i).at(j) = c.at(i).at(j - 1);
          b.at(i).at(j) = arrows.LEFT;
        }
      }
}

void print_LCS(std::string X, std::string Y, std::vector<std::vector<int>> &c,
               std::vector<std::vector<char>> &b) {
  bottomup_LCS(X, Y, c, b);
  print_LCS_REC(X, b, X.size(), Y.size());
}

void print_LCS_REC(std::string X, std::vector<std::vector<char>> b, int i,
                   int j) {
  if (i > 0 && j > 0) {
    if (b.at(i).at(j) == arrows.OBLI) {
      print_LCS_REC(X, b, i - 1, j - 1);
      std::cout << X.at(i - 1);
    } else {
      if (b.at(i).at(j) == arrows.TOP)
        print_LCS_REC(X, b, i - 1, j);
      else
        print_LCS_REC(X, b, i, j - 1);
    }
  }
}

void bottomup_LCS_OTT(std::string X, std::string Y,
                      std::vector<std::vector<int>> &c) {
  int m = X.size();
  int n = Y.size();

  /* riempe prima riga e prima colonna con zero (confronta una lettera con la
   * stringa vuota, non hanno nulla in comune) */
  for (int i = 0; i <= m; i++)
    c.at(i).at(0) = 0;

  for (int j = 0; j <= n; j++)
    c.at(0).at(j) = 0;

  for (int i = 1; i <= m; i++)
    for (int j = 1; j <= n; j++)
      if (X.at(i - 1) == Y.at(j - 1)) {
        c.at(i).at(j) = c.at(i - 1).at(j - 1) + 1;
      } else {
        if (c.at(i - 1).at(j) >= c.at(i).at(j - 1)) {
          // l'uguale da precedenza alla riga
          c.at(i).at(j) = c.at(i - 1).at(j);
        } else {
          c.at(i).at(j) = c.at(i).at(j - 1);
        }
      }
}

void print_LCS_OTT(std::string X, std::string Y,
                   std::vector<std::vector<int>> &c) {
  bottomup_LCS_OTT(X, Y, c);
  print_LCS_REC_OTT(X, c, X.size(), Y.size());
}

void print_LCS_REC_OTT(std::string X, std::vector<std::vector<int>> c, int i,
                       int j) {
  // L'ORDINE DEI TEST È FONDAMENTALE
  if (i > 0 && j > 0) {
    if (c.at(i).at(j) == c.at(i - 1).at(j)) {
      print_LCS_REC_OTT(X, c, i - 1, j);
    } else {
      if (c.at(i).at(j) == c.at(i).at(j - 1))
        print_LCS_REC_OTT(X, c, i, j - 1);
      else {
        print_LCS_REC_OTT(X, c, i - 1, j - 1);
        std::cout << X.at(i);
      }
    }
  }
}