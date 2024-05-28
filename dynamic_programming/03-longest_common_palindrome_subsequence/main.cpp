

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int longest_common_palindromic_subseq_top_down_AUX(
    std::string X, std::string Y, std::vector<std::vector<int>> &lcps, int i,
    int j) {

  if (lcps[i][j] == -1) {

    if (i == 0 || j == 0)
      lcps[i][j] = 0;
    else if (X.at(i - 1) == Y.at(j - 1)) {

      lcps[i][j] = longest_common_palindromic_subseq_top_down_AUX(
                       X, Y, lcps, i - 1, j - 1) + 1;

      std::cout << std::endl;
      for (int i = 0; i <= X.size(); i++) {
        for (int j = 0; j <= X.size(); j++)
          std::cout << lcps[i][j] << " ";

        std::cout << std::endl;
      }
    } else
      lcps[i][j] = std::max(
          longest_common_palindromic_subseq_top_down_AUX(X, Y, lcps, i - 1, j),
          longest_common_palindromic_subseq_top_down_AUX(X, Y, lcps, i, j - 1));
  }

  return lcps[i][j];
}

int longest_common_palindromic_subseq_top_down(std::string X) {
  int n = X.size();
  std::string Y = X;
  std::reverse(Y.begin(), Y.end());

  std::vector<std::vector<int>> lcps;

  for (int i = 0; i <= n; i++) {
    std::vector<int> tmp;
    for (int j = 0; j <= n; j++) {
      tmp.push_back(-1);
    }
    lcps.push_back(tmp);
  }

  return longest_common_palindromic_subseq_top_down_AUX(X, Y, lcps, n, n);
}

int longest_common_palindromic_subseq(std::string X) {
  int n = X.size();
  std::string Y = X;
  std::reverse(Y.begin(), Y.end());

  std::vector<std::vector<int>> lcps;

  for (int i = 0; i <= n; i++) {
    std::vector<int> tmp;
    for (int j = 0; j <= n; j++) {
      tmp.push_back(0);
    }
    lcps.push_back(tmp);
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (X.at(i - 1) == Y.at(j - 1)) {
        lcps[i][j] = lcps[i - 1][j - 1] + 1;
      } else {
        lcps[i][j] = std::max(lcps[i - 1][j], lcps[i][j - 1]);
      }
    }
  }

  return lcps[n][n];
}

int main() {

  std::vector<std::string> words = {"ciao",    "abba",     "abllpdoba",
                                    "colonna", "aaxfgxaa", "a",
                                    "abc",     "bab",      "aba"};

  for (int i = 0; i < words.size(); i++) {
    std::cout << words.at(i) << std::endl;
    std::cout << "LCPS: " << longest_common_palindromic_subseq(words.at(i))
              << " " << longest_common_palindromic_subseq_top_down(words.at(i))
              << std::endl
              << std::endl;
  }
}