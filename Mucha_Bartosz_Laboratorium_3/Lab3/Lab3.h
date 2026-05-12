#ifndef LAB3_H
#define LAB3_H
#include<fstream>
#include "libFiles.h"
#include "libRandom.h"
#include "libSort.h"
#include "libTables.h"

/*
 * Generuje zestawy do pliku zgodnie z zalozeniami pliku wejsciowego
 * @param write - referencja do pliku
 * @param iloscZestawow
 * @param iloscLiczb - ilosc liczb, ktore beda generowane do wyszukiwania
 * @param iloscZapytan 
 * @param szukaneLiczby - szukane liczby, ktorych beda szukane ilosci wystapien
*/
void generujZestawy(std::ofstream& write, int iloscZestawow, int iloscLiczb, int szukaneLiczby);

/*
* Funkcja odczytuje dane z pliku i wypisuje je na ekran oraz do dwóch tablic (na potrzeby pliku Laboratorium 3)
*/
void odczytajDane();

/*
* Funkcja znajduje pierwsze wystąpienie szukanej liczby w posortowanej tablicy za pomocą zmodyfikowanego wyszukiwania binarnego
* @param tab - posortowana tablica, w której szukamy wartości
* @param dlugosc - długość tablicy
* @param szukana - wartość, której szukamy
*/
long long znajdzPoczatek(long long tab[], long long dlugosc, long long szukana);

/*
* Funkcja znajduje ostatnie wystąpienie szukanej liczby w posortowanej tablicy za pomocą zmodyfikowanego wyszukiwania binarnego
* @param tab - posortowana tablica, w której szukamy wartości
* @param dlugosc - długość tablicy
* @param szukana - wartość, której szukamy
*/
long long znajdzKoniec(long long tab[], long long dlugosc, long long szukana);

/*
* Funkcja oblicza ile jest wystapien szukanej liczby w posortowanej tablicy, wykorzystując funkcje znajdzPoczatek i znajdzKoniec
* @param tab - posortowana tablica, w której szukamy wartości
* @param dlugosc - długość tablicy
* @param szukana - wartość, której szukamy
*/
long long iloscWystapien(long long tab[], long long dlugosc, long long szukana);

/*
* Funkcja oblicza ile jest wystapien szukanej liczby w posortowanej tablicy, wykorzystując funkcje znajdzPoczatek i znajdzKoniec
* @param tab - posortowana tablica, w której szukamy wartości
* @param dlugosc - długość tablicy
* @param szukana - wartość, której szukamy
*/
long long wyszukiwanieInterpolacyjne(long long tab[], long long dlugosc, long long szukana);

/*
* Funkcja usuwa duplikaty z posortowanej tablicy i zwraca nową długość tablicy po usunięciu duplikatów
* @param tab - posortowana tablica, w której szukamy wartości
* @param dlugosc - długość tablicy
*/
long long usuwanieDuplikatow(long long tab[], long long dlugosc);

#endif //LAB3_H