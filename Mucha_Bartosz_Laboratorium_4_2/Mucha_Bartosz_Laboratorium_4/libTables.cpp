#include "libTables.h"
#include <iostream>

long long* t_stworzTablice(int rozmiarTablicy){
    long long *tab = nullptr;

    try{
        tab =  new long long[rozmiarTablicy];
    }
    catch(const std::bad_alloc){
        std::cerr << "Bledny zakres tablicy";
        exit(0);
    }
    return tab;
}

int t_pobierzWartosc(int zakresMinimalny, int zakresMaksymalny){
    //Pobiera wartosc wczytywana z klawiatury z zakresu domknietego od pierwszej zmiennej do dugiej zmiennej
    //Zwraca wartosc ktora miesci sie w podanym przedziale
    int temp=0;
    do{
        std::cin>>temp;
    }while(temp<zakresMinimalny || temp>zakresMaksymalny);
    return temp;
}

void t_uzupelnijTablice(int iloscWartosci, int *tablica, int minimalnaWartosc, int maksymalnaWartosc){
    //Pobiera wiele wartosci, ilosc podana w pierwszej zmiennej, a nastepnie zapisuje je do tablicy podanej w drugiej zmiennej o rozmiarze ilosci tych wartosci
    for (int i=0;i<iloscWartosci;i++) {
        tablica[i] = t_pobierzWartosc(minimalnaWartosc,maksymalnaWartosc);
    }
}

void t_wypiszTablice(int iloscWartosci,long long *tablica) {
    //Wypisuje zawartość dynamicznej tablicy jednowymiarowej o określonej wartości elementów
    for (int i=0;i<iloscWartosci;i++) {
        std::cout << tablica[i] << " ";
    }
}

void t_usunSpacjeZeStringa(std::string &linia) {
    std::string temp;

	for (int i = 0;i < linia.size();i++) {
        if(linia[i] != ' ') {
            temp += linia[i];
        }
    }
    linia = temp;
}