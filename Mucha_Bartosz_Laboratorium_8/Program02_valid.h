#ifndef PROGRAM02_VALID_H
#define PROGRAM02_VALID_H
#include<stdexcept>
#include<vector>

/*
 * Walidacja liczby zestawow odczytanej z pierwszej linii pliku.
 * @param liczbaZestawow - liczba zestawow danych
 */
void walidacjaLiczbyZestawow(int liczbaZestawow);

/*
 * Walidacja liczby parametrów zestawów z pliku - pojemności i liczbyElementów
 * @param mmax - pojemnosc plecaka
 * @param liczbaElementow - liczba elementow w zestawie
 */
void walidacjaParametrowZestawu(int mmax, int liczbaElementow);

/*
 * Walidacja wag elementow, które można zapakować
 * @param wagi - referencja do wektora wag tych elementów
 */
void walidacjaWag(std::vector<int>& wagi);

#endif //PROGRAM02_VALID_H