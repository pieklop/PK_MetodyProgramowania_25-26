#ifndef MUCHA_BARTOSZ_PROGRAM_01_H
#define MUCHA_BARTOSZ_PROGRAM_01_H
#include<vector>

/*Funkcja zamienia ze sobą wartości dwóch zmiennych
@param a - zmienna 1
@param b - zmienna 2
*/
void zamiana(int& a, int& b);

/*Funkcja sortująca krawędzie leksykograficznie za pomocą zmodyfikowanego sortowania bąbelkowego
@param krawedzie - tablica krawędzi, gdzie parzyste indeksy reprezentują wyjścia, a nieparzyste indeksy reprezentują wejścia
@param iloscKrawedziX2 - liczba krawędzi pomnożona przez 2 (ponieważ każda krawędź jest reprezentowana przez dwie liczby)
*/
void sortowanieLeksykograficznie(int* krawedzie, int iloscKrawedziX2);


/*Funkcja tworzy macierz incydencji na podstawie tablicy krawędzi
@param krawedzie - tablica krawędzi, gdzie parzyste indeksy reprezentują wyjścia, a nieparzyste indeksy reprezentują wejścia
@param iloscKrawedziX2 - liczba krawędzi pomnożona przez 2 (jest to jednocześnie długość tablicy krawedzie)
@param macierzIncydencji - wskaźnik do macierzy incydencji, która zostanie wypełniona
@param wierzcholki - liczba wierzchołków w grafie
*/
void utworzMacierzIncydencji(int* krawedzie, int iloscKrawedziX2, int** macierzIncydencji, int wierzcholki);

void wyznaczSasiadow(int** macierzIncydencji, int wiersze, int kolumny);

/* Funkcja pośrednia uruchamiająca zadanie 1a*/
void Mucha_Bartosz_Program_01a();

/* Funkcja tworzy macierz incydencji na podstawie wektora krawędzi
@param krawedzie - wektor par, gdzie każda para reprezentuje krawędź (wyjście, wejście)
@param macierz - wektor wektorów, który zostanie wypełniony macierzą incydencji
@param wierzcholki - liczba wierzchołków w grafie
*/
void utworzMacierzIncydencjiWektor(const std::vector<std::pair<int, int>>& krawedzie, std::vector<std::vector<int>>& macierz, int wierzcholki);

/* Funkcja wyznacza sąsiadów na podstawie macierzy incydencji w formie wektora
@param macierz - wektor wektorów reprezentujący macierz incydencji
@param wierzcholki - liczba wierzchołków w grafie
*/
void wyznaczSasiadowWektor(const std::vector<std::vector<int>>& macierz, int wierzcholki);

/* Funkcja pośrednia uruchamiająca zadanie 1a*/
void Mucha_Bartosz_Program_01b();

#endif //MUCHA_BARTOSZ_PROGRAM_01_H
