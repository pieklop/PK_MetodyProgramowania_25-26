// Mucha Bartosz
#include "Mucha_Bartosz_Program_01.h"
#include "libTables.h"
#include "libFiles.h"	
#include <iostream>
#include <exception>

// Szukanie pierwszego wystąpienia.
void rekPier(int** tab, int liczbaWierszy, int liczbaKolumn, int szukana, int wiersz, int lewy, int prawy) {
    // Brak elementu w tablicy.
    if (wiersz >= liczbaWierszy) {
        std::cout << "RekPier: nie ma " << szukana << std::endl;
        return;
    }
    // Koniec wiersza. Przejście do następnego.
    if (lewy > prawy) {
        rekPier(tab, liczbaWierszy, liczbaKolumn, szukana, wiersz + 1, 0, liczbaKolumn - 1);
        return;
    }

    // Wyznaczenie środka.
    int srodek = lewy + (prawy - lewy) / 2;

    // Znalezienie pierwszego wystąpienia w wierszu.
    if (tab[wiersz][srodek] == szukana && (srodek == 0 || tab[wiersz][srodek - 1] != szukana)) {
        std::cout << "RekPier: " << szukana << " w (" << wiersz << "," << srodek << ")" << std::endl;
        return;
    }

    // Szukanie w lewej części.
    if (tab[wiersz][srodek] >= szukana) {
        rekPier(tab, liczbaWierszy, liczbaKolumn, szukana, wiersz, lewy, srodek - 1);
    }
    // Szukanie w prawej części.
    else {
        rekPier(tab, liczbaWierszy, liczbaKolumn, szukana, wiersz, srodek + 1, prawy);
    }
}

// Szukanie ostatniego wystąpienia.
void rekOst(int** tab, int liczbaWierszy, int liczbaKolumn, int szukana, int wiersz, int lewy, int prawy) {
    // Brak liczby
    if (wiersz < 0) {
        std::cout << "RekOst: nie ma " << szukana << std::endl;
        return;
    }
    // Koniec wiersza. Przejście linijkę wyżej.
    if (lewy > prawy) {
        rekOst(tab, liczbaWierszy, liczbaKolumn, szukana, wiersz - 1, 0, liczbaKolumn - 1);
        return;
    }

    // Wyznaczenie środka.
    int srodek = lewy + (prawy - lewy) / 2;

    // Znalezienie ostatniego elementu w wierszu.
    if (tab[wiersz][srodek] == szukana && (srodek == liczbaKolumn - 1 || tab[wiersz][srodek + 1] != szukana)) {
        std::cout << "RekOst: " << szukana << " w (" << wiersz << "," << srodek << ")" << std::endl;
        return;
    }

    // Szukanie w lewej połówce.
    if (tab[wiersz][srodek] > szukana) {
        rekOst(tab, liczbaWierszy, liczbaKolumn, szukana, wiersz, lewy, srodek - 1);
    }
    // Szukanie w prawej połówce.
    else {
        rekOst(tab, liczbaWierszy, liczbaKolumn, szukana, wiersz, srodek + 1, prawy);
    }
}

// Iteracyjne szukanie pierwszego wystąpienia.
void iterPier(int** tab, int liczbaWierszy, int liczbaKolumn, int szukana) {
    // Pętla po wierszach od początku.
    for (int wiersz = 0; wiersz < liczbaWierszy; ++wiersz) {
        int lewy = 0, prawy = liczbaKolumn - 1;
        int znalezionaKolumna = -1;

        // Wyszukiwanie binarne.
        while (lewy <= prawy) {
            int srodek = lewy + (prawy - lewy) / 2;
            if (tab[wiersz][srodek] == szukana) {
                znalezionaKolumna = srodek;
                prawy = srodek - 1; // Sprawdzanie lewej strony.
            }
            else if (tab[wiersz][srodek] > szukana) {
                prawy = srodek - 1;
            }
            else {
                lewy = srodek + 1;
            }
        }

        // Wypisanie wyniku.
        if (znalezionaKolumna != -1) {
            std::cout << "IterPier: " << szukana << " w (" << wiersz << "," << znalezionaKolumna << ")" << std::endl;
            return;
        }
    }
    std::cout << "IterPier: nie ma " << szukana << std::endl;
}

// Iteracyjne szukanie ostatniego wystąpienia.
void iterOst(int** tab, int liczbaWierszy, int liczbaKolumn, int szukana) {
    // Pętla po wierszach od końca.
    for (int wiersz = liczbaWierszy - 1; wiersz >= 0; --wiersz) {
        int lewy = 0, prawy = liczbaKolumn - 1;
        int znalezionaKolumna = -1;

        // Wyszukiwanie binarne.
        while (lewy <= prawy) {
            int srodek = lewy + (prawy - lewy) / 2;
            if (tab[wiersz][srodek] == szukana) {
                znalezionaKolumna = srodek;
                lewy = srodek + 1; // Sprawdzanie prawej strony.
            }
            else if (tab[wiersz][srodek] > szukana) {
                prawy = srodek - 1;
            }
            else {
                lewy = srodek + 1;
            }
        }

        // Wypisanie wyniku.
        if (znalezionaKolumna != -1) {
            std::cout << "IterOst: " << szukana << " w (" << wiersz << "," << znalezionaKolumna << ")" << std::endl;
            return;
        }
    }
    std::cout << "IterOst: nie ma " << szukana << std::endl;
}

// Wyświetlenie danych z tablicy.
void wyswietlDane(int** tab, int liczbaWierszy, int liczbaKolumn, int szukanaWartosc) {
    std::cout << liczbaWierszy << " " << liczbaKolumn << std::endl;

    for (int i = 0; i < liczbaWierszy; i++) {
        for (int j = 0; j < liczbaKolumn; j++) {
            std::cout << tab[i][j] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << szukanaWartosc << std::endl;
}

// Wczytywanie danych z pliku.
void wczytajDane()
{
    std::ifstream wejscie;
    f_otworzPlikOdczyt(wejscie);

    
    int iloscZestawow = f_odczytajJednaLiczbe(wejscie);

    
    for (int i = 0; i < iloscZestawow; i++)
    {
        int** tablica = nullptr;
        int liczbaWierszy = 0;

        
        try {
            liczbaWierszy = f_odczytajJednaLiczbe(wejscie);
            int liczbaKolumn = f_odczytajJednaLiczbe(wejscie);

            
            tablica = t_stworzTabliceDwuwymiarowa(liczbaWierszy, liczbaKolumn);

            
            for (int x = 0; x < liczbaWierszy; x++)
            {
                for (int y = 0; y < liczbaKolumn; y++)
                {
                    tablica[x][y] = f_odczytajJednaLiczbe(wejscie);
                }
            }

            int szukanaWartosc = f_odczytajJednaLiczbe(wejscie);

            
            rekPier(tablica, liczbaWierszy, liczbaKolumn, szukanaWartosc, 0, 0, liczbaKolumn - 1);
            rekOst(tablica, liczbaWierszy, liczbaKolumn, szukanaWartosc, liczbaWierszy - 1, 0, liczbaKolumn - 1);
            iterPier(tablica, liczbaWierszy, liczbaKolumn, szukanaWartosc);
            iterOst(tablica, liczbaWierszy, liczbaKolumn, szukanaWartosc);

            
            std::cout << "---" << std::endl;

            
            t_usunTabliceDwuwymiarowa(tablica, liczbaWierszy);
            tablica = nullptr;
        }
        // Wychwytywanie wyjątków.
        catch (const std::exception& e) {
            std::cerr << "Wystapil blad podczas przetwarzania zestawu danych: " << e.what() << std::endl;
            if (tablica != nullptr) {
                t_usunTabliceDwuwymiarowa(tablica, liczbaWierszy);
            }
        }
    }

    
    wejscie.close();
}


int main()
{
    wczytajDane();
    return 0;
}