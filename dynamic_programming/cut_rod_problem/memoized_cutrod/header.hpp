
#include <vector>

/**
 * @brief data la lunghezza dell'asta e il vettore dei prezzi calcola il ricavo
 * massimo tramite metodo top down
 *
 * @param p vettore dei prezzi p[0...n-1], dove p[i] è il prezzo del taglio di
 * dimensione i (con i = 0,...,n-1)
 * @param n dimensione asta
 * @return ricavo massimo
 */
int memoized_cutrod(std::vector<int> p, int n);

/**
 * @brief funzione ausiliaria per il ricavo massimo
 *
 * @param p vettore dei prezzi p[0...n-1], dove p[i] è il prezzo del taglio di
 * dimensione i (con i = 0,...,n-1)
 * @param j taglio (????)
 * @param r vettore che memorizza i ricavi massimi, dove r[i] rappresenta il
 * ricavo ottimo per aste di lunghezza i (con i = 0,...,n-1)
 * @return int
 */
int memoized_cutrod_AUX(std::vector<int> p, int j, std::vector<int> r);

/**
 * @brief salva la posizione dei tagli in modo da poter ricostruire la soluzione
 *
 * @param p p[0...n-1], dove p[i] è il prezzo del taglio di
 * dimensione i (con i = 0,...,n-1)
 * @param n dimensione asta
 * @param r vettore ricavi massimi
 * @param s vettore degli indici della posizione dei tagli
 */
void ext_memoized_cutrod(std::vector<int> p, int n, std::vector<int> &r,
                         std::vector<int> &s);

/**
 * @brief funzione ausiliaria di ext_memoized_cutrod
 *
 * @param p p[0...n-1], dove p[i] è il prezzo del taglio di
 * dimensione i (con i = 0,...,n-1)
 * @param j tagli
 * @param r vettore ricavi massimi
 * @param s vettore degli indici della posizione dei tagli
 */
void ext_memoized_cutrod_AUX(std::vector<int> p, int j, std::vector<int> &r,
                             std::vector<int> &s);

/**
 * @brief chiama la ext_memoized_cutrod per ricavare il vettore dei guadagni
 * massimi e il vettore degli indici. Da quest'ultimo ricava le posizioni dei
 * tagli rendendo possibile la ricostruzione della soluzione.
 *
 * @param p vettore prezzi
 * @param n dimensione asta
 */
void print_memoized_cutrod_solution(std::vector<int> p, int n);