#include <fstream>

#include "libFiles.h"
#include "libTables.h"
#include "lab2.h"

/*
 * Testowanie:
 * silnikSEAK/siatka_SEAK.txt
 * silnikSEAK/nmSEAK.txt
 * [Podaj sciezke do pliku wyjsciowego].txt
 * silnikSEB/siatkaSEB.txt
 * silnikSEB/nmSEB.txt
 * [Podaj sciezke do pliku wyjsciowego].txt
 */
int main() {
    std::ifstream read;
    std::ifstream nieznany;

    //Dla SEAK
    f_otworzPlikOdczyt(read); // silnikSEAK/siatka_SEAK.txt
    f_otworzPlikOdczyt(nieznany); // silnikSEAK/nmSEAK.txt

    mse(read, nieznany);

    read.close();
    nieznany.close();

    //Dla SEB
    f_otworzPlikOdczyt(read); // silnikSEB/siatkaSEB.txt
    f_otworzPlikOdczyt(nieznany); // silnikSEB/nmSEB.txt

    mse(read, nieznany);

    read.close();
    nieznany.close();


    return 0;
}