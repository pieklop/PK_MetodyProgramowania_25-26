#ifndef LIBSORT_H
#define LIBSORT_H

/*
* Funcja zamienia ze soba wartosci dwoch zmiennych
* @param a - zmienna 1
* @param b - zmienna 2
*/
void s_zamiana(long long& a, long long& b);

/*
* Funkcja sortuje elementy tablicy
* @param tab - referencja do sortowanej tablicy
* @param iloscElementow - ilosc elementow sortowanej tablicy
*/
void s_sortowanieBabelkowe(long long* tab, int iloscElementow);

#endif //LIBSORT_H
