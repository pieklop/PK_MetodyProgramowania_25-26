#ifndef LIBMATH_H
#define LIBMATH_H
#include <vector>

/*
 * Funkcja oblicza czynniki pierwsze podanej liczby
 * @param n - podana liczba
 * @return Wskaźnik do wektora z czynnikami pierwszymi
 */
std::vector<int> RozkladNaCzynnikiPierwsze(int n);

/*
 * Funkcja oblicza NWD algorytmem Euklidesa
 * @param a - pierwszy składnik obliczeń
 * @param b - drugi składnik obliczeń
 * @return Wartość NWD dwóch podanych liczb
 */
int m_NWDeuklides(int a, int b);

#endif //LIBMATH_H