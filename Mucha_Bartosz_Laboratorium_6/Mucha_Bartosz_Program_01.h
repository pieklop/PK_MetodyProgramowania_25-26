#ifndef MUCHA_BARTOSZ_PROGRAM_01_H
#define MUCHA_BARTOSZ_PROGRAM_01_H

/* Funkcja rekurencyjnie wyszukuje pierwsze wystąpienie cyfry w tablicy dwuwymiarowej.
* @param tab - wskaźnik do tablicy dwuwymiarowej
* @param liczbaWierszy - liczba wierszy w tablicy
* @param liczbaKolumn - liczba kolumn w tablicy
* @param szukana - wartość, której szukamy
* @param wiersz - aktualny wiersz, który jest przeszukiwany
* @param lewy - indeks lewej granicy przeszukiwania w aktualnym wierszu
* @param prawy - indeks prawej granicy przeszukiwania w aktualnym wierszu
*/
void rekPier(int** tab, int liczbaWierszy, int liczbaKolumn, int szukana, int wiersz, int lewy, int prawy);

/* Funkcja rekurencyjnie wyszukuje ostatnie wystąpienie cyfry w tablicy dwuwymiarowej.
* @param tab - wskaźnik do tablicy dwuwymiarowej
* @param liczbaWierszy - liczba wierszy w tablicy
* @param liczbaKolumn - liczba kolumn w tablicy
* @param szukana - wartość, której szukamy
* @param wiersz - aktualny wiersz, który jest przeszukiwany
* @param lewy - indeks lewej granicy przeszukiwania w aktualnym wierszu
* @param prawy - indeks prawej granicy przeszukiwania w aktualnym wierszu
*/
void rekOst(int** tab, int liczbaWierszy, int liczbaKolumn, int szukana, int wiersz, int lewy, int prawy);

/* Funkcja iteracyjnie wyszukuje pierwsze wystąpienie cyfry w tablicy dwuwymiarowej.
* @param tab - wskaźnik do tablicy dwuwymiarowej
* @param liczbaWierszy - liczba wierszy w tablicy
* @param liczbaKolumn - liczba kolumn w tablicy
* @param szukana - wartość, której szukamy
*/
void iterPier(int** tab, int liczbaWierszy, int liczbaKolumn, int szukana);

/* Funkcja iteracyjnie wyszukuje ostatnie wystąpienie cyfry w tablicy dwuwymiarowej.
* @param tab - wskaźnik do tablicy dwuwymiarowej
* @param liczbaWierszy - liczba wierszy w tablicy
* @param liczbaKolumn - liczba kolumn w tablicy
* @param szukana - wartość, której szukamy
*/
void iterOst(int** tab, int liczbaWierszy, int liczbaKolumn, int szukana);

/* Funkcja wyświetla dane z wczytanej tablicy dwuwymiarowej.
* @param tab - wskaźnik do tablicy dwuwymiarowej
* @param liczbaWierszy - liczba wierszy w tablicy
* @param liczbaKolumn - liczba kolumn w tablicy
* @param szukanaWartosc - wartość, której szukamy
*/
void wyswietlDane(int** tab, int liczbaWierszy, int liczbaKolumn, int szukanaWartosc);

/* Funkcja wczytuje dane do tablicy dwuwymiarowej. */
void wczytajDane();
#endif // MUCHA_BARTOSZ_PROGRAM_01_H
