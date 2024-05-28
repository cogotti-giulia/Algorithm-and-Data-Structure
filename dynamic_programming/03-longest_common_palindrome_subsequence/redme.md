## Massima sotto sequenza palindroma

Scrivere un algoritmo per individuare, all’interno di una stringa x1 . . . xn la lunghezza massima di una sotto sequenza palindroma.

### Idea

Trovare la LCS tra la stringa e il suo contrario. 

sia X = x<sub>1<sub>...x<sub>n<sub> e Y = y<sub>1<sub>...y<sub>n<sub> = x<sub>n<sub>...x<sub>1<sub> (Y è il rovescio/contrario di X).

Dovrebbe funzionare perché

1. La sotto sequenza palindroma più lunga  (LCPS) è lunga _al massimo_ quanto la LCS della stringa e il suo rovescio.<br>Questo è sicuramente vero dato che, se la LCPS più lunga allora avrei trovato anche una LCS più lunga (assurdo rispetto all'ipotesi di partenza)

2. La sotto sequenza palindroma più lunga è lunga _almeno_ quanto la LCS della stringa e il suo rovescio. Questo è più difficile da dimostrare. Si può affermare che _in media_ si possono derivare due LCPS lunghe quanto la LCS. Quindi in media una o entrambe saranno lunghe uguali.

    ```
    esempio
    X = A C B A C
        1 2 3 4 5
         
    Y = C A B C A
        5 4 3 2 1
    
    estraggo A B C come LCS
             1 3 5
             4 3 2
    da questa posso derivare i prefissi palindromi dove i <= j.  
    quindi A B A     (in X) 
           1 3 4     
    al contrario C B C     (in Y)
                 2 3 5
    
    ogni lettera viene usata due volte (tranne la lettera centrale), quindi il discorso sulla media ha senso.
                 
    ```

Essendo vere entrambe, il ragionamento dovrebbe avere senso e funzionare sempre.

### Caratterizzazione sotto struttura ottima

indico con L[i, j] la lunghezza della LCS(X<sup>i</sup>, Y<sup>i</sup>) con 0<=i<=n e 0<=j<=n

        
L[i, j] = 
- 0 se i=0 OR j=0 (_una stringa è vuota_)
- L[i-1, j-1]+1 (_ho un carattere in comune_) se i>0 AND j>0 AND x<sub>i</sub>=y<sub>i</sub>
- max(L[i-1, j], L[i, j-1]) se i>0 AND j>0 AND x<sub>i</sub>!=y<sub>i</sub>

Tempo di esecuzione: **O(n\*n) = O(n<sup>2</sup>)**, tante quante sono le possibili chiamate ricorsive. Se l'intera stringa fosse palindroma allora _T(n) = O(n)_.

### Codice c++

```c++
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
```