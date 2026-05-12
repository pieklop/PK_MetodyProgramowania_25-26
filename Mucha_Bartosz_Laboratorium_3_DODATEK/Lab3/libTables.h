#ifndef LIBTABLES_H
#define LIBTABLES_H

/*
 * Funkcja tworzaca tablice dynamiczna o rozmiarze podanym w zmiennej
 * @param rozmiarTablicy - ilosc elementow ktore ma pomiescic tablica
 * @return wskaznik do pierwszego elementu tablicy
*/
long long* t_stworzTablice(int rozmiarTablicy);

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
void t_wypiszTablice(int iloscWartosci,long long *tablica);

#endif //LIBTABLES_H