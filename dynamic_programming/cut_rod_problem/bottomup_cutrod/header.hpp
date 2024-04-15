
#include <vector>

/**
 * @brief dato il vettore dei prezzi e la dimensione dell'asta calcola il
 * guadagno massimo con un approccio di tipo bottom up
 *
 * @param p vettore dei prezzi p[0...n-1], dove p[i] è il prezzo del taglio di
 * dimensione i (con i = 0,...,n-1)
 * @param n dimensione asta
 * @return ricavo massimo
 */
int bottomup_cutrod(std::vector<int> p, int n);

/**
 * @brief salva la posizione dei tagli in modo da poter ricostruire la soluzione
 *
 * @param p vettore dei prezzi p[0...n-1], dove p[i] è il prezzo del taglio di
 * dimensione i (con i = 0,...,n-1)
 * @param n dimensione asta
 * @param r vettore ricavi massimi
 * @param s vettore degli indici della posizione dei tagli
 */
void ext_bottomup_cutrod(std::vector<int> p, int n, std::vector<int> &r,
                         std::vector<int> &s);

/**
 * @brief dato il vettore dei prezzi e la dimensione dell'asta chiama la
 * ext_bottomup_cutrod e stampa la posizione dei tagli e il vettore dei
 * guadagni, rendendo possibile la ricostruzione della soluzione
 *
 * @param p vettore dei prezzi p[0...n-1], dove p[i] è il prezzo del taglio di
 * dimensione i (con i = 0,...,n-1)
 * @param n dimensione asta
 */
void print_bottomup_cutrod_solution(std::vector<int> p, int n);