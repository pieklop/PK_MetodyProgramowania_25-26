#ifndef MUCHA_BARTOSZ_PROGRAM_02_H
#define MUCHA_BARTOSZ_PROGRAM_02_H
#include "libList.h"
#include<fstream>
#include<list>

/*Funkcja wczytuje krawędzie z pliku do dwóch tablic reprezentujących wyjścia i wejścia oraz znajduje maksymalny numer wierzchołka
@param wejscie - referencja do pliku wejściowego
@param n - liczba krawędzi do wczytania
@param u - wskaźnik do tablicy, która zostanie wypełniona wyjściami krawędzi
@param v - wskaźnik do tablicy, która zostanie wypełniona wejściami krawędzi
@param max_wierzcholek - referencja do zmiennej, która zostanie ustawiona na maksymalny numer wierzchołka
*/
void wczytywanie(std::ifstream& wejscie, int n, int*& u, int*& v, int& max_wierzcholek);


/*Funkcja tworzy listę incydencji na podstawie tablicy krawędzi
@param n - liczba krawędzi
@param u - tablica reprezentująca wyjścia krawędzi
@param v - tablica reprezentująca wejścia krawędzi
@param max_wierzcholek - maksymalny numer wierzchołka, rozmiar listy incydencji
*/
lista** listaIncydencji(int n, int* u, int* v, int max_wierzcholek);

/*Funkcja wypisuje listę incydencji grafu
@param incydencja - lista incydencji grafu
@param max_wierzcholek - maksymalny numer wierzchołka
*/
void wypiszIncydencje(lista** incydencja, int max_wierzcholek);

/*
* Funkcja czyści pamięć zajmowaną przez listę incydencji
* @param incydencja - lista incydencji grafu
* @param max_wierzcholek - maksymalny numer wierzchołka, rozmiar listy incydencji
*/
void czyszczenie(lista** incydencja, int max_wierzcholek);

/*Funkcja pośrednia uruchamiająca zadanie 2a*/
void Mucha_Bartosz_Program_02a();

/*
* Funkcja wczytuje krawędzie z pliku do dwóch tablic reprezentujących wyjścia i wejścia oraz znajduje maksymalny numer wierzchołka
* @param wejscie - referencja do pliku wejściowego
* @param n - liczba krawędzi do wczytania
* @param u - wskaźnik do tablicy, która zostanie wypełniona wyjściami krawędzi
* @param v - wskaźnik do tablicy, która zostanie wypełniona wejściami krawędzi
* @param max_wierzcholek - referencja do zmiennej, która zostanie ustawiona na maksymalny numer wierzchołka
*/
void wczytywanieLista(std::ifstream& wejscie, int n, int*& u, int*& v, int& max_wierzcholek);


/*
* Funkcja tworzy listę incydencji na podstawie tablicy krawędzi
* @param n - liczba krawędzi
* @param u - tablica reprezentująca wyjścia krawędzi
* @param v - tablica reprezentująca wejścia krawędzi
* @param max_wierzcholek - maksymalny numer wierzchołka, rozmiar listy incydencji
*/
std::list<int>* listaIncydencjiLista(int n, int* u, int* v, int max_wierzcholek);

/*
* Funkcja wypisuje listę incydencji grafu
* @param incydencja - lista incydencji grafu
* @param max_wierzcholek - maksymalny numer wierzchołka
*/
void wypiszIncydencjeLista(std::list<int>* incydencja, int max_wierzcholek);

/*Funkcja pośrednia uruchamiająca zadanie 2*/
void Mucha_Bartosz_Program_02b();



#endif //MUCHA_BARTOSZ_PROGRAM_02_H
