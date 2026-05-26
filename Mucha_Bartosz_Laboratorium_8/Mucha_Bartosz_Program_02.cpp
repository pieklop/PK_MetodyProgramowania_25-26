#include "Mucha_Bartosz_Program_02.h"


void wczytajWagi(std::ifstream& wejscie, int liczbaElementow, std::vector<int>& wagi) {
    //trzeba zmienić rozmiar wag do liczby elementów, bo później wyskakują błędy wyjścia poza zakres
    //vector resize() is a built-in method used to change the size of vector container after it is declared
    wagi.resize(liczbaElementow);

    for (int i=0; i<liczbaElementow; i++)
        wejscie >> wagi[i];

    walidacjaWag(wagi);
}

ZestawDanych wczytajZestaw(std::ifstream& wejscie) {
    ZestawDanych zestaw;

    int liczbaElementow{0};
    wejscie >> zestaw.pojemnosc;
    wejscie >> liczbaElementow;

    walidacjaParametrowZestawu(zestaw.pojemnosc, liczbaElementow);
    wczytajWagi(wejscie, liczbaElementow, zestaw.wagi);

    return zestaw;
}

bool znajdzKombinacje(std::vector<int>& wagi, int pozostalaPojemnosc, std::vector<bool>& czyWybrany, int indeks) {
    //Warunek końca (sukces)
    if (pozostalaPojemnosc==0)
        return true;

    //Warunek końca (porażka) - przedmiot nie mieści się w plecaku lub przedmioty się skończyły
    //static_cast<int> jest dodany aby rzutować dla pewności że zadziała podównanie inta z elementem wektoraindeks == static_cast<int>(wagi.size()
    if (pozostalaPojemnosc<0 || indeks == static_cast<int>(wagi.size()))
        return false;

    //Wywołanie następnego elemenntu przy opcji w której ładujemy do środka element o aktualnym indeksie
    //odejmujemy wagę aktualnego przedmiotu
    //przekazujemy informację że załadowaliśmy przedmiot
    //sprawdzamy przedmiot na następnym indeksie
    czyWybrany[indeks] = true;
    if (znajdzKombinacje(wagi, pozostalaPojemnosc - wagi[indeks], czyWybrany,indeks + 1))
        return true;

    //Wywołanie następnego elemenntu przy opcji w której aktualnie sprawdzany przedmiot nie sprawdził się w żadnej kombinacji
    //pojemność zostaje taka sama, bo ignorujemy przedmiot
    //przekazujemy informację że pomijamy ten przedmiot
    //sprawdzamy przedmiot na następnym indeksie
    czyWybrany[indeks] = false;
    return znajdzKombinacje(wagi, pozostalaPojemnosc, czyWybrany,indeks + 1);
}

void wypiszWynik(int pojemnosc, std::vector<int>& wagi, std::vector<bool>& czyWybrany) {
    std::cout<<pojemnosc<<" =";
    for (int i=0; i<wagi.size(); i++) {
        if (czyWybrany[i])
            std::cout<<" "<<wagi[i];
    }
    std::cout<<std::endl;
}

void przetworzZestaw(ZestawDanych& zestaw) {
    //Wektor, który będzie przechowywał zapis elementów wybranych do plecaka
    std::vector<bool> czyWybrany(zestaw.wagi.size(),false);

    //Wywołanie początkowe funkcji rekurencyjnej
    bool czyKombinacjaIstnieje = znajdzKombinacje(zestaw.wagi, zestaw.pojemnosc, czyWybrany, 0);

    if (czyKombinacjaIstnieje)
        wypiszWynik(zestaw.pojemnosc, zestaw.wagi,czyWybrany);
    else
        std::cout<<"BRAK"<<std::endl;
}


void Mucha_Bartosz_Program_02() {
    std::ifstream wejscie;
    f_otworzPlikOdczyt(wejscie);

    try {
        int liczbaZestawow = f_odczytajJednaLiczbe(wejscie);
        walidacjaLiczbyZestawow(liczbaZestawow);

        for (int i=0; i<liczbaZestawow; i++) {
            ZestawDanych zestaw = wczytajZestaw(wejscie);
            przetworzZestaw(zestaw);
        }
    }
    catch (std::exception& blad) {
        std::cerr <<"\nBlad: "<< blad.what() << std::endl;
    }


    wejscie.close();
}

/* Kolejność działania tego algorytmu:
 * 1. Funkcja startowa
 * 2. walidacjaLiczbyZestawow
 * 3. wczytajZestaw
 * 4. walidacjaParametrowZestawu
 * 5. wczytajWagi
 * 6. walidacjaWag
 * 7. przetworzZestaw
 * 8. znajdzKombinacje (funkcja rekurencyjna)
 * 9. wypiszWynik
 */