#ifndef LIBFILES_H
#define LIBFILES_H
#include<fstream>

/*
 * Funkcja otwiera plik o podanej nazwie w trybie do odczytu
 * @param read - referencja do pliku
*/
void f_otworzPlikOdczyt(std::ifstream& read);


/*
 * Funkcja wypisuje elementy pliku az do jego zakonczenia element po elemencie
 * @param read - referencja do pliku
*/
void f_odczytajPlik(std::ifstream& read);

/*
 * Funkcja odczytuje dwie linie z pliku i wczytuje każdą z nich do osobnej tablicy
 * @param read - plik wejsciowy
 * @param *tab1 - wskaznik do tablicy 1
 * @param *tab2 - wskaznik do tablicy 2
 * @param rozmiarTablicy - rozmiar tablic wejsciowych
*/
bool f_odczytajDwieLinie(std::ifstream& read, double *tab1, double *tab2, int rozmiarTablicy);

/*
 * Funkcja otwiera plik o podanej nazwie w trybie do zapisu (jako append)
 * @param read - referencja do pliku
*/
void f_otworzPlikZapis(std::ofstream& write);


#endif //LIBFILES_H