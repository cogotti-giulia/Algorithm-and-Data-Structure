
#include <string>
#include <vector>

/**
 * @brief struttura per rappresentare la direzione delle freccette, utilizzate
 * nella matrice utile a ricostruire la soluzione nella versione non ottimizzata
 */
struct MyStruct {
  char LEFT = 'L';
  char TOP = 'T';
  char OBLI = 'O';
  char EMPTY = 'E';
};

/**
 * @brief date due stringe trova la loro LCS tramite approccio bottom up,
 * utilizzando la proprietà della sotto struttura ottima
 *
 * @param X stringa 1
 * @param Y stringa 2
 * @param c matrice di interi dove c[i, j] rappresenta la lunghezza della
 * LCS(X^i, Y^j)
 * @param b matrice di caratteri dove b[i, j] contiene informazioni utili per
 * recuperare la soluzione
 */
void bottomup_LCS(std::string X, std::string Y,
                  std::vector<std::vector<int>> &c,
                  std::vector<std::vector<char>> &b);

/**
 * @brief chiama la bottomup_LCS per ricavare la LCS tra le stringhe X e Y e
 * stampa la soluzione (ricavandola tramite le matrici b e c)
 *
 * @param X stringa 1
 * @param Y stringa 2
 * @param c matrice di interi dove c[i, j] rappresenta la lunghezza della
 * LCS(X^i, Y^j)
 * @param b matrice di caratteri dove b[i, j] contiene informazioni utili per
 * recuperare la soluzione
 */
void print_LCS(std::string X, std::string Y, std::vector<std::vector<int>> &c,
               std::vector<std::vector<char>> &b);

/**
 * @brief funzione ricorsiva ausiliaria per stampare la soluzione, utilizza la
 * matrice b di informazioni per la ricostruzione della soluzione
 *
 * @param X stringa 1 (ne basta una, devo stampare la LCS che appartiene ad
 * entrambe!)
 * @param b matrice di caratteri dove b[i, j] contiene informazioni utili per
 * recuperare la soluzione
 * @param i indice riga matrice
 * @param j indice riga colonna
 */
void print_LCS_REC(std::string X, std::vector<std::vector<char>> b, int i,
                   int j);

/**
 * @brief date due stringe trova la loro LCS tramite approccio bottom up,
 * utilizzando la proprietà della sotto struttura ottima
 *
 * @param X stringa 1
 * @param Y stringa 2
 * @param c matrice di interi dove c[i, j] rappresenta la lunghezza della
 * LCS(X^i, Y^j)
 */
void bottomup_LCS_OTT(std::string X, std::string Y,
                      std::vector<std::vector<int>> &c);
/**
 * @brief chiama la bottomup_LCS_OTT per ricavare la LCS tra X e Y e stampa la
 * soluzione, ottimizzata rispetto all'uso della memoria (utilizza soltanto la
 * matrice c)
 *
 * @param X stringa 1
 * @param Y stringa 2
 * @param c matrice di interi dove c[i, j] rappresenta la lunghezza della
 * LCS(X^i, Y^j)
 */
void print_LCS_OTT(std::string X, std::string Y,
                   std::vector<std::vector<int>> &c);

/**
 * @brief funzione ricorsiva ausiliaria per stampare la soluzione, ottimizzata
 * rispetto all'uso della memoria (utilizza soltanto la matrice c e le tre celle
 * adiacenti al punto in cui ci si trova)
 * @param X stringa 1
 * @param c matrice di interi dove c[i, j] rappresenta la lunghezza della
 * LCS(X^i, Y^j)
 * @param i indice riga matrice
 * @param j indice riga colonna
 */
void print_LCS_REC_OTT(std::string X, std::vector<std::vector<int>> c, int i,
                       int j);