#ifndef MUCHA_BARTOSZ_PROGRAM_01_H
#define MUCHA_BARTOSZ_PROGRAM_01_H
#include <iostream>
#include "libFiles.h"
#include "libTables.h"
#include <stdexcept>
#include <vector>

struct Przedmiot {
    std::string nazwa;
    int masa;
    int cena;
};

/*
 * Funkcja wczytuje dane wejściowe do wektora
 * @param read - referencja do pliku, w którym wypisano przedmioty, ich masę oraz cenę
 * @param mmax - referencja do maksymalnej pojemności plecaka
 * @param przedmioty - vector, który będzie zawierał dane z pliku tekstowego.
 */
void wczytajDane(std::ifstream& read, int& mmax, std::vector<Przedmiot>& przedmioty);

/*
 * Funkcja zeruje całą tablicę dwuwymiarową
 * @param tab - adres tablicy dwuwymiarowej
 * @param wiersze - ilość wierszy
 * @param kolumny - ilość kolumn
 */
void zerujTablice(int** tab, int wiersze, int kolumny);

/*
 * Funkcja oblicza czy można włożyć wprzedmiot do plecaka, a następnie wpisuje najwyższą dostępną wartość plecaka
 * @param **P - adres tablicy dwuwymiarowej zawierającej wartości plecaka
 * @param wiersz - aktualnie badany wiersz
 * @param kolumna - aktualnie badana kolumna
 * @param przedmiot - referencja do badanego przedmiotu
 * @return Zwraca wartość plecaka w danej konfiguracji
 */
int uzupelnianieP(int** P, int wiersz, int kolumna, Przedmiot& przedmiot);

/*
 * Funkcja wpisuje id wkładanego przedmiotu do tabeli Q
 * @param **P - adres tablicy dwuwymiarowej zawierającej wartości plecaka
 * @param **Q - adres tablicy dwuwymiarowej zawierającej id przedmiotów w plecaku
 * @param wiersz - aktualnie badany wiersz
 * @param kolumna - aktualnie badana kolumna
 * @param przedmiot - referencja do badanego przedmiotu
 * @return Zwraca id ostatnio dodanego przedmiotu
 */
int uzupelnianieQ(int **P, int **Q, int wiersz, int kolumna, Przedmiot& przedmiot);

/*
 * Funkcja uzupełnia tabele P, Q korzystając z utworzonych algorytmów uzupelnianieP oraz uzupelnianieQ
 * @param **P - adres tablicy dwuwymiarowej zawierającej wartości plecaka
 * @param **Q - adres tablicy dwuwymiarowej zawierającej id przedmiotów w plecaku
 * @param przedmioty - vector zawierający listę wszystkich przedmiotow i ich danych
 * @param mmax - maksymalna pojemność plecaka
 * @param liczbaPrzedmiotow - liczba przedmiotow dostępnych do włożenia
 */
void wypelnianieTabel(int** P, int** Q, std::vector<Przedmiot>& przedmioty, int mmax, int liczbaPrzedmiotow);

/*
 * Funkcja wypisuje nagłówki do tabel P i Q
 * @param mmax - maksymalna pojemność plecaka
 */
void naglowek(int mmax);

/*
 * Funkcja wypisuje wiersz tabeli P lub Q
 * @param tab - adres tabeli której wiersz ma wypisać
 * @param wiersz
 * @param mmax - maksymalna pojemność plecaka
 */
void wypiszWiersz(int** tab, int wiersz, int mmax);

/*
 * Funkcja wypisuje tabelię P lub Q wiersz po wierszu
 * @param tab - adres tabeli której wiersz ma wypisać
 * @param liczbaPrzedmiotow
 * @param mmax - maksymalna pojemność plecaka
 */
void wypiszTabele(int** tab, int liczbaPrzedmiotow, int mmax);

/*
 * Funkcja obsługuje działanie Programu 01 (plik pdf w katalogu)
 */
void Mucha_Bartosz_Program_01();

#endif //MUCHA_BARTOSZ_PROGRAM_01_H