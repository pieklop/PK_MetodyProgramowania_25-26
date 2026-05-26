#ifndef MUCHA_BARTOSZ_PROGRAM_02_H
#define MUCHA_BARTOSZ_PROGRAM_02_H
#include<iostream>
#include<fstream>
#include <vector>

#include "Program02_valid.h"
#include"libFiles.h"
#include "libTables.h"

/*Struktura ZestawDanych odnosi się do zestawów z pliku tekstowego (liczbaElementow jest poza strukturą [w sumie można było ją dać tutaj, może miałoby to większy sens])
 * @param pojemnosc - pierwszy argument określający ile na końcu powinny ważyć wszystkie przedmioty w plecaku
 * @param wagi - wagi poszczegolnych przedmiotów które można zapakować do plecaka
 */
struct ZestawDanych {
    int pojemnosc;
    std::vector<int> wagi;
};



/*
 * Wczytuje wagi z pliku tekstowego, a następnie korzysta z funkcji do walidacji tych wag
 * @param wejscie - referencja do p[liku tekstowego
 * @param liczbaElementow - liczba wag do wczytania
 * @param wagi - referencja do wyjściowego wektora wag
 */
void wczytajWagi(std::ifstream& wejscie, int liczbaElementow, std::vector<int>& wagi);

/*
 * * Wczytuje pojedynczy zestaw danych (pojemnosc, liczbe elementow oraz ich wagi). Korzysta z funkcji walidacyjnych
 * @param wejscie - referencja do pliku wejsciowego
 * @return gotowa struktura ZestawDanych - DLA JEDNEGO ZESTAWU
 */
ZestawDanych wczytajZestaw(std::ifstream& wejscie);

/*
 * Właściwa funkcja rekurencyjna, która ma 4 opcje do wyboru:
 * 2 zakończenia:
 * 1. SUKCES - plecak jest w pełni załadowany (pozostalaPojemnosc = 0)
 * 2. PORAŻKA - przedmioty przekraczają pojemność plecaka, w tej kombinacji nie zadziała
 * 2 możliwości wywołania samej siebie:
 * 3. Pakujemy aktualny element i wywołujemy następny element sprawdzając warunki 1 i 2
 * 4. Omijamy ten przedmiot i próbujemy następny
 * @param wagi - wektor wszystkich dostepnych wag
 * @param pozostalaPojemnosc - ile jeszcze brakuje do zapełnienia plecaka
 * @param czyWybrany - wektor określający czy dana waga została zapakowana do plecaka
 * @param indeks - aktualnie rozwazany indeks w wektorze wag
 * @return true w przypadku gdy istnieje taka kombinacja, false gdy jej nie ma
 */
bool znajdzKombinacje(std::vector<int>& wagi, int pozostalaPojemnosc, std::vector<bool>& czyWybrany, int indeks = 0);

/*
 * Funkcja wypisująca działającą konfigurację do zapakowania plecaka
 * @param pojemnosc - pojemność plecaka
 * @param wagi - referencja do wektora wag, który będzie porównywany z czyWybrany
 * @param czyWybrany - referencja do wektora wybranych elementów, jeśli dla danego indeksu jest true, wypisze wagę o tym samym indeksie
 */
void wypiszWynik(int pojemnosc, std::vector<int>& wagi, std::vector<bool>& czyWybrany);

/*
 * Funkcja, która dla pwczytanych zestawów danych przekazuje je do funkcji rekurencyjnej, a następnie do funkcji wypisującej dane jeśli kombinacja istnieje
 * @param zestaw - referencja do struktury z danymi zestawu
 */
void przetworzZestaw(ZestawDanych& zestaw);

/*Funkcja obsługująca Program 02*/
void Mucha_Bartosz_Program_02();

#endif //MUCHA_BARTOSZ_PROGRAM_02_H