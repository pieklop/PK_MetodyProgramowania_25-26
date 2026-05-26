#include "Mucha_Bartosz_Program_01.h"


void wczytajDane(std::ifstream& read, int& mmax, std::vector<Przedmiot>& przedmioty) {
    mmax = f_odczytajJednaLiczbe(read);

    if (mmax <= 0) {
        throw std::runtime_error("Pojemnosc plecaka musi byc dodatnia.");
    }

    Przedmiot przedmiot;
    while (read >> przedmiot.nazwa >> przedmiot.masa >> przedmiot.cena) {
        przedmioty.push_back(przedmiot);
    }

    if (przedmioty.empty()) {
        throw std::runtime_error("Brak przedmiotow w pliku wejsciowym.");
    }
}

void zerujTablice(int** tab, int wiersze, int kolumny) {
    for (int i = 0; i < wiersze; i++)
        for (int j = 0; j < kolumny; j++)
            tab[i][j] = 0;
}

int uzupelnianieP(int** P, int wiersz, int kolumna, Przedmiot& przedmiot) {
    if (przedmiot.masa > kolumna) //jeżeli masa przedmiotu nie mieści się w aktualnym kroku
        return P[wiersz-1][kolumna]; //zwraca poprzednią konfigurację, bo była bardziej opłacalna

    int bezPrzedmiotu = P[wiersz-1][kolumna]; //nie dokłada przedmiotu, bierze poprzednią konfigurację
    int zPrzedmiotem = P[wiersz][kolumna - przedmiot.masa] + przedmiot.cena; //dokłada przedmiot i dopisuje wartośc z aktualnej konfiguracji

    if (zPrzedmiotem > bezPrzedmiotu) //wybiera na koniec lepszą możliwą do realizacji opcję
        return zPrzedmiotem;
    return bezPrzedmiotu;
}

int uzupelnianieQ(int **P, int **Q, int wiersz, int kolumna, Przedmiot& przedmiot) {
    if (przedmiot.masa > kolumna) //jeżeli masa przedmiotu nie mieści się w aktualnym kroku
        return Q[wiersz-1][kolumna]; //zwraca poprzednią konfigurację, bo była bardziej opłacalna

    int bezPrzedmiotu = P[wiersz-1][kolumna]; //nie dokłada przedmiotu, bierze poprzednią konfigurację
    int zPrzedmiotem = P[wiersz][kolumna - przedmiot.masa] + przedmiot.cena; //dokłada przedmiot i dopisuje wartośc z aktualnej konfiguracji

    if (zPrzedmiotem > bezPrzedmiotu) //wybiera na koniec lepszą możliwą do realizacji opcję
        return wiersz; // będzie to id aktualnie badanego przedmiotu
    return Q[wiersz-1][kolumna]; //weźmie poprzednią działającą konfigurację (któryś z poprzednich przedmiotów)
}

void wypelnianieTabel(int** P, int** Q, std::vector<Przedmiot>& przedmioty, int mmax, int liczbaPrzedmiotow) {
    for (int i =1; i<=liczbaPrzedmiotow; i++) {
        for (int j=1; j<=mmax; j++) {
            P[i][j] = uzupelnianieP(P, i, j, przedmioty[i - 1]);
            Q[i][j] = uzupelnianieQ(P, Q, i, j, przedmioty[i - 1]);
        }
    }
}

/*Funkcje wypisujące tabele - START*/

void naglowek(int mmax) {
    std::cout<<"i\\j";
    for (int i=1; i<=mmax; i++)
        std::cout<<"\t"<<i;
    std::cout<<std::endl;
}

void wypiszWiersz(int** tab, int wiersz, int mmax) {
    std::cout << wiersz;
    for (int i = 1; i <= mmax; i++) {
        std::cout << "\t" << tab[wiersz][i];
    }
    std::cout << std::endl;
}

void wypiszTabele(int** tab, int liczbaPrzedmiotow, int mmax) {
    std::cout<<"\nTablica: "<<std::endl;
    naglowek(mmax);
    for (int i =1; i<= liczbaPrzedmiotow; i++)
        wypiszWiersz(tab, i, mmax);
}

/*Funkcje wypisujące tabele - KONIEC*/

void Mucha_Bartosz_Program_01() {
    std::ifstream wejscie;
    f_otworzPlikOdczyt(wejscie);

    try {
        int mmax{0}; // liczba określająca pojemność plecaka

        std::vector<Przedmiot> przedmioty;

        wczytajDane(wejscie, mmax, przedmioty);

        int liczbaPrzedmiotow = przedmioty.size(); //liczba przedmiotów podanych w pliku z których można wybierać
        int wiersze = liczbaPrzedmiotow + 1;
        int kolumny = mmax + 1;

        int** P = t_stworzTabliceDwuwymiarowa(wiersze, kolumny);
        int** Q = t_stworzTabliceDwuwymiarowa(wiersze, kolumny);

        zerujTablice(P, wiersze, kolumny);
        zerujTablice(Q, wiersze, kolumny);

        wypelnianieTabel(P,Q,przedmioty,mmax,liczbaPrzedmiotow);

        std::cout<<"\nPojemnosc plecaka: "<<mmax<<std::endl;
        std::cout<<"Liczba przedmiotow: "<<liczbaPrzedmiotow<<std::endl;
        std::cout<<"NajwyzszaWartosc: "<<P[liczbaPrzedmiotow][mmax]<<std::endl;//ostatnia kolumna i wiersz

        wypiszTabele(P,liczbaPrzedmiotow,mmax);
        wypiszTabele(Q,liczbaPrzedmiotow,mmax);

        t_usunTabliceDwuwymiarowa(P,wiersze);
        t_usunTabliceDwuwymiarowa(Q,wiersze);
    }
    catch (const std::exception& wyjatek){
        std::cerr <<"\nBłąd: " << wyjatek.what() << std::endl;
    }

    wejscie.close();
}
