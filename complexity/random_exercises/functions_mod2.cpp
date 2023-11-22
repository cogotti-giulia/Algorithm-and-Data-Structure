/**
 * @file functions.cpp
 * @author me, myself and I
 * @brief qualche funzione a caso di cui calcolare la complessità
 * @version 1.0
 * @date 2023-11-07
 */
#include <cmath>
#include <iostream>

using namespace std;

int A(int n);
int B(int m);

int foo(int n);

int fun(int *A, int n); // A array
int proc(int m);        //? per ipotesi T_proc(m)=Teta(sqrt(m))

int calcola(int n);

int main() {}

/******************************************************************************************/

//! T_A(n) = d+k(sum(da i=1 a n)i) = d + [k(n(n+1))/2] = Teta(n^2)
//! NON È EFFICIENTE, posso fare una funzione costante che fa il return della
//! serie (n(n+1))/2
int A(int n) {
  int s = 0;
  for (int i = 0; i < n; i++) //? n-volte
    s = s + B(i);             //? ki volte perché varia in funzione di i
  return s;
}

//! T_B(m) = Teta(m)
int B(int m) {
  int s = 0;
  for (int j = 1; j < m; j++)
    s = s + 1;
  return s;
}

/*******************************************************************************************/
//! T_foo(n) = c + T_foo(n/3) = ... [t. master - 2° caso] ... = Teta(log n)
int foo(int n) {
  if (n <= 2)
    return 1;
  else if (n > 321) { //? considero solo questo if (comportamento asintotico,
                      //per n sufficientemente grande)
    int i = n / 3;
    return 2 * foo(i) +
           n * n * n * i; //? considero solo foo(i), le altre sono costanti che
                          //non mi dicono nulla dopo la chiamata ric
  } else
    return foo(n - 3) + foo(n - 2);
}

/*******************************************************************************************/

//! T_fun(n)= 2*T_fun(n/2)+Teta(n*sqrt(n)) = ... [t. master - 3° caso] ... =
//! Teta(n+sqrt(n))
int fun(int *A, int n) {
  if (n < 1)
    return 1;
  else {
    int t = fun(A, n / 2);
    if (t >
        A[n]) //? lo considero perché worst case dato che fa una chiamata ric
      t = t + fun(A, n / 2);
    for (int j = 0; j < n; j++)
      t = t + A[j] + proc(n);
    return t;
  }
}

/********************************************************************************************/

//! T_calcola(n) = Teta(n^2) ... [ usando l'albero delle ricorsioni :( ]
int calcola(int n) {
  if (n < 1)
    return 5;
  else {
    int k = 1;
    for (int i = 0; i < n; i++)
      k = k * 2;
    return calcola(n - 1) + k;
  }
}

/*********************************************************************************************/
//! T_compute(n) = c+2*T_compute(n/2) = ... [t. master] ... = Teta(n)
int compute(int n) {
  if (n >= 10) {
    for (int i = n; i >= n - 3; i--)
      int j = floor(n / 2);
    return compute(floor(n / 2)) * compute(floor(n / 2)) * 5 * n;

  } else if (n >= 20) { //? DEAD CODE
    if (n >= 20)
      return compute(n + 1);
    else
      return n;
  }
}