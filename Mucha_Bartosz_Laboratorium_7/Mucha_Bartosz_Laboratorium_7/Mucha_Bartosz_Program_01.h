#ifndef MUCHA_BARTOSZ_PROGRAM_01_H
#define MUCHA_BARTOSZ_PROGRAM_01_H
#include <vector>

/*
 * Funkcja oblicza c(przyrost) na podstawie NWD modulu i potencjalnego przyrostu
 * @param modul - zakres generowanych liczb
 * @return - przyrost
 */
int obliczPrzyrost(int modul);

/*
 * Funkcja mnożnik a(przyrost) na warunku o reszcie z dzielenia przez moduł
 * @param modul - zakres generowanych liczb
 * @param czynnikiModulu - czynniki pierwsze rozkładu wartości modułu w postaci vektora
 * @return - mnożnik
 */
int obliczMnoznik(int modul, const std::vector<int>& czynnikiModulu);

/*
 * Funkcja wyznacza liczby pseudolosowe korzystając z algorytmu liniowej metody kongruencyjnej
 * @param liczbaElementow - liczba elementów które należy wygenerować
 * @param ziarno - seed, który należy do generowanego okresu liczb
 * @param wartoscMaksymalna - wartość do której generujemy liczny
 */
void LCG(int liczbaElementow, int ziarno, int wartoscMaksymalna);

/*Funkcja odwraca tablicę dynamiczną przy użyciu tablicy pomocniczej
 * @param tablica - wskaźnik do tablicy
 * @param liczbaElementów - liczba elementów w tej tablicy
 */
void odwrocTablice(int* tablica, int liczbaElementow);

/*
 * Funkcja wyznacza liczby pseudolosowe korzystając z algorytmu addytywnej metody kongruencyjnej
 * @param liczbaElementow - liczba elementów które należy wygenerować
 * @param m - moduł (zakres generowanych liczb)
 * @param j - indeks opóźnienia
 * @param k - indeks opóźnienia
 * @param ziarno - seed, który należy do generowanego okresu liczb
 */
void ACG(int liczbaElementow, int m, int j, int k, int ziarno);

#endif