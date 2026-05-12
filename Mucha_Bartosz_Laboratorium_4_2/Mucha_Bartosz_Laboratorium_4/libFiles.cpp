#include "libFiles.h"
#include<sstream>
#include<iostream>

void f_otworzPlikOdczyt(std::ifstream& read) {
    char nazwaPliku[30] = {};

    do {
        std::cout << "\nPodaj nazwe pliku wejsciowego: ";
        std::cin >> nazwaPliku;

        read.open(nazwaPliku,std::ios::in);

        if (!read) {
            std::cout << "\nNie ma takiego pliku!";
        }


    }while (!read);

}

void f_odczytajPlik(std::ifstream& read){
    long long element = 0;

    while (read >> element) {
            std::cout << element << " ";
    }
}

int f_odczytajJednaLiczbe(std::ifstream& read)
{
    int liczba{};

	read >> liczba;

    return liczba;
}

void f_odczytajXElementow(std::ifstream&read, long long* tab, int iloscElementow) {
    for (int i = 0; i < iloscElementow; i++) {
        read >> tab[i];
    }
}

bool f_odczytajJednaLinieDoStringa(std::ifstream& read, std::string& linia) {
    if (std::getline(read, linia)) {
        return true;
    }
    return false;


}

bool f_odczytajDwieLinie(std::ifstream &read, double *tab1, double *tab2, int rozmiarTablicy) {
    std::string linia1, linia2;

    if (getline(read, linia1) && getline(read, linia2)) {
        std::stringstream ss1(linia1);
        std::stringstream ss2(linia2);

        for (int i = 0; i < rozmiarTablicy; i++) {
            ss1 >> tab1[i];
            ss2 >> tab2[i];
            // std::cout<<tab1[i]<<" "<<tab2[i]<<std::endl;
        }
        return true;
    }
    return false;


}

void f_otworzPlikZapis(std::ofstream& write) {
    char nazwaPliku[30] = {};

    std::cout << "\nPodaj nazwe pliku wyjsciowego: ";
    std::cin >> nazwaPliku;

    write.open(nazwaPliku,std::ios::app);
}