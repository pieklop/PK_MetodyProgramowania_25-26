#ifndef LIBTABLES_H
#define LIBTABLES_H
#include<string>

/*
 * Funkcja tworzaca tablice dynamiczna o rozmiarze podanym w zmiennej
 * @param rozmiarTablicy - ilosc elementow ktore ma pomiescic tablica
 * @return wskaznik do pierwszego elementu tablicy
*/
int* t_stworzTablice(int rozmiarTablicy);

/*
 * Pobiera wartosc wczytywana z klawiatury z zakresu domknietego od pierwszej zmiennej do dugiej zmiennej
 * @param zakresMinimalny - minimalna możliwa wartość do pobrania
 * @param zakresMaksymalny - maksymalna możliwa wartość do pobrania
 * @return Zwraca wartosc ktora miesci sie w podanym przedziale
*/
int t_pobierzWartosc(int zakresMinimalny, int zakresMaksymalny);

/*
 * Uzupelnia tablice elementami podanymi przez uzytkownika
 * @param iloscWartosci - ilosc elementow tablicy
 * @param *tablica - wskaznik do tablicy
 * @param zakresMinimalny - minimalna możliwa wartość do pobrania
 * @param zakresMaksymalny - maksymalna możliwa wartość do pobrania
 * @return Zwraca wartosc ktora miesci sie w podanym przedziale
*/
void t_uzupelnijTablice(int iloscWartosci, int *tablica, int minimalnaWartosc, int maksymalnaWartosc);

/*
 * Wypisuje zawartość dynamicznej tablicy jednowymiarowej o określonej wartości elementów
 * @param iloscWartosci - ilosc elementow tablicy
 * @param *tablica - wskaznik do tablicy
*/
void t_wypiszTablice(int iloscWartosci,int *tablica);

/* Funkcja usuwa wszystkie spacje ze stringa
 * @param linia - referencja do stringa, z którego usuwane są spacje
*/

void t_usunSpacjeZeStringa(std::string& linia);

/*
Funkcja tworzy tablicę dwuwymiarową o podanej liczbie wierszy i kolumn
@param wiersze - liczba wierszy tablicy
@param kolumny - liczba kolumn tablicy
@return wskaźnik do tablicy dwuwymiarowej
*/
int** t_stworzTabliceDwuwymiarowa(int wiersze, int kolumny);

/*
Funkcja wypisuje zawartość tablicy dwuwymiarowej o podanej liczbie wierszy i kolumn
@param wiersze - liczba wierszy tablicy
@param kolumny - liczba kolumn tablicy
@param tablica - wskaźnik do tablicy dwuwymiarowej
*/
void t_wypiszTabliceDwuwymiarowa(int wiersze, int kolumny, int** tablica);

/*
Funkcja usuwa tablicę dwuwymiarową o podanej liczbie wierszy
@param tablica - wskaźnik do tablicy dwuwymiarowej
@param wiersze - liczba wierszy tablicy
*/
void t_usunTabliceDwuwymiarowa(int** tablica, int wiersze);

#endif //LIBTABLES_H