#include <iostream>
#include "libFiles.h"
#include "libMath.h"
#include "libTables.h"
#include "Mucha_Bartosz_Program_01.h"

int obliczPrzyrost(int modul) {
    int c = 2; // Zaczynamy szukać od mniejszych wartości
    while (m_NWDeuklides(c, modul) != 1) {
        c++;
    }
    return c;
}

int obliczMnoznik(int modul, const std::vector<int>& czynnikiModulu) {
    int maxLambda = 0;
    std::vector<int> kandydaci;


    for (int a = 2; a < modul; ++a) {
        if (m_NWDeuklides(a, modul) != 1) continue;

        int lambda = 1;
        int potega = a % modul;
        while (potega != 1 && lambda <= modul) {
            potega = (potega * a) % modul;
            lambda++;
        }

        if (potega == 1) {
            if (lambda > maxLambda) {
                maxLambda = lambda;
                kandydaci.clear();
                kandydaci.push_back(a);
            } else if (lambda == maxLambda) {
                kandydaci.push_back(a);
            }
        }
    }

    int najlepszeA = -1;


    for (int a : kandydaci) {
        int b = a - 1;
        bool warunkiSpelnione = true;

        for (int p : czynnikiModulu) {
            if (b % p != 0) {
                warunkiSpelnione = false;
                break;
            }
        }

        if (warunkiSpelnione && (modul % 4 == 0)) {
            if (b % 4 != 0) warunkiSpelnione = false;
        }

        if (warunkiSpelnione) {
            if (a > najlepszeA) najlepszeA = a;
        }
    }


    if (najlepszeA != -1) {
        return najlepszeA;
    }
    else {
        int maxA = 0;
        for (int a : kandydaci) {
            if (a > maxA) maxA = a;
        }
        return maxA;
    }
}

void LCG(int liczbaElementow, int ziarno, int wartoscMaksymalna) {
    std::cout<<"LCG"<<std::endl;
    std::ofstream wyjscie;
    f_otworzPlikZapis(wyjscie);

    // 0 <= a(mnoznik) < modul
    // 0 <= c(przyrost) < modul
    // 0 <= x0(wartoscPoczatkowa) < modul

    int modul = wartoscMaksymalna + 1; //m
    std::vector<int> czynnikiModulu = RozkladNaCzynnikiPierwsze(modul);

    // Pętla wypisująca wszystkie czynniki obliczonego modułu
    // for (int x : czynnikiModulu) {
    //     std::cout << x << " ";
    // }

    int c = obliczPrzyrost(modul);
    int a = obliczMnoznik(modul, czynnikiModulu); //2 <= a(mnoznik) < m(modul)

    int aktualnaWartosc = ziarno;

    for (int i=0;i<liczbaElementow;i++) {
        aktualnaWartosc=(a*aktualnaWartosc+c)%modul;
        wyjscie<<aktualnaWartosc<<std::endl;
    }

    wyjscie.close();
}

void odwrocTablice(int* tablica, int liczbaElementow) {
    for (int i = 0; i < liczbaElementow / 2; i++) {
        int tymczasowa = tablica[i];
        tablica[i] = tablica[liczbaElementow - 1 - i];
        tablica[liczbaElementow - 1 - i] = tymczasowa;
    }
}


void ACG(int liczbaElementow, int m, int j, int k, int ziarno) {
    LCG(liczbaElementow, ziarno, m-1);
    std::cout<<"ACG"<<std::endl;
    std::ifstream wejscie;
    f_otworzPlikOdczyt(wejscie);

    int *tab = nullptr;
    tab = t_stworzTablice(liczbaElementow);

    f_odczytajXElementow(wejscie,tab,liczbaElementow);

    odwrocTablice(tab,liczbaElementow);

    j = j - 1;
    k = k - 1;

    std::ofstream wyjscie;
    f_otworzPlikZapis(wyjscie);

    for (int i = 0; i < liczbaElementow; i++) {
        tab[k] = (tab[j] + tab[k]) % m;
        wyjscie<<tab[k]<<std::endl;
        // std::cout << "Wygenerowano: " << tab[k] << "\n";

        k = k - 1;
        j = j - 1;

        // Gdy indeks spadnie poniżej zera wraca na n-1
        if (k < 0) k = liczbaElementow - 1;
        if (j < 0) j = liczbaElementow - 1;
    }

    delete[] tab;
    wejscie.close();
    wyjscie.close();
}