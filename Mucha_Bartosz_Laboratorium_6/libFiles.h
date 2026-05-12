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
 * Funkcja odczytuje jedna liczbe z pliku
 * @param read - referencja do pliku
 * @return odczytana liczba
*/
int f_odczytajJednaLiczbe(std::ifstream& read);

/*
 * Funkcja odczytuje okreslona liczbe elementow z pliku i wczytuje je do tablicy o tym rozmiarze
 * @param read - plik wejsciowy
 * @param *tab - wskaznik do tablicy
 * @param liczbaElementow - liczba elementow do odczytania i zapisania w tablicy
*/
void f_odczytajXElementow(std::ifstream& read, long long* tab, int iloscElementow);

/*
 * Funkcja odczytuje jedną linię i zapisuje ją do stringa
 * @param read - referencja do pliku
 * @param *tab - referencja do stringa
 * @return true, jeśli odczytanie linii się powiodło, false w przeciwnym razie
*/
bool f_odczytajJednaLinieDoStringa(std::ifstream& read, std::string& linia);

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