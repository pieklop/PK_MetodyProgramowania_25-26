#include "Program02_valid.h"

/* Walidacja - START */
void walidacjaLiczbyZestawow(int liczbaZestawow) {
    if(liczbaZestawow<1||liczbaZestawow>1000000)
        throw std::runtime_error("Liczba zestawow poza zakresem <1,1000000>");
}

void walidacjaParametrowZestawu(int mmax, int liczbaElementow) {
    if (mmax < 1 || mmax > 1000000) {
        throw std::runtime_error("Niepoprawna pojemnosc plecaka. <1,1000000>");
    }
    if (liczbaElementow < 1 || liczbaElementow > 1000000) {
        throw std::runtime_error("Niepoprawna liczba elementow. <1,1000000>");
    }
}

void walidacjaWag(std::vector<int>& wagi) {
    for (int waga:wagi)
        if (waga<1 || waga>1000000)
            throw std::runtime_error("Waga elementu poza dopuszczalnym zakresem <1,1000000>");
}
/* Walidacja - KONIEC */