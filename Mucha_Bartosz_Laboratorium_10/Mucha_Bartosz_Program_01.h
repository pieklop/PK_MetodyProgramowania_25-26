#ifndef MUCHA_BARTOSZ_PROGRAM_01_H
#define MUCHA_BARTOSZ_PROGRAM_01_H

#include "libQueue.h"
#include <vector>
#include <iostream>
#include"libExeptions.h"


//Struktura odpowiadająca za przechowywanie węzła i wskaźników do jego gałęzi
struct Wezel {
    float waga;
    char litera;
    Wezel* lewy;
    Wezel* prawy;

    //Konstruktor tego węzła
    Wezel(float w, char l): waga(w), litera(l), lewy(nullptr), prawy(nullptr) {}
};

//Przeciążenie operatora tak, aby zwracane było czy lewy jest większy
struct RosnacoWezly {
    bool operator()(Wezel* a, Wezel* b) {
        return a->waga > b->waga;
    }
};

/*Funkcja buduje drzewa korzystając z naszej posortowanej bazy wystąpień, robi to dopóki nie wykorzysta każdej litery i nie zbuduje spójnego drzewa o jednym korzeniu (Najczęściej występujące litery będą miały najmniej bitów)
 * @param litery - posortowana kolejka liter i ich częstotliwości/wystąpień z której będzie układane drzewo
 * @return Zwraca jedno wielkie drzewo złożone z mniejszych drzewek
 */
Wezel* budowaDrzewa(Kolejka litery);

/*
 * Funkcja rekurencyjna generująca kod litery od korzenia, aż do liścia. Warunkiem stopu jest brak kolejnych gałęzi
 * @param wezel - bierze aktualnie badany węzeł, a następnie do lewej gałęzi przypisuje 0, a do prawej 1
 * @param kod - string przechowujący dalsze fragmenty przejść po gałęziach
 * @return gotowy kod binarny kompresji huffmana dla określonej litery
 */
void generowanieKodu(Wezel* wezel, std::string kod);

/*
 * Funkcja wywołująca generowanie drzewa i kodu dla liter
 * @param litery - posortowana kolejka liter i ich częstotliwości/wystąpień z której będzie układane drzewo
 */
void huffman(Kolejka litery);

/*
 * Funkcja obsługująca działanie programu
 */
int main();

#endif //MUCHA_BARTOSZ_PROGRAM_01_H