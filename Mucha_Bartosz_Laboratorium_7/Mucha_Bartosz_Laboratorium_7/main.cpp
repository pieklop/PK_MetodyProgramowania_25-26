#include <iostream>
#include <climits>

#include "libTables.h"
#include "Mucha_Bartosz_Program_01.h"

int main() {
    std::cout << "1 - Liniowa metoda kongruencyjna \n2 - Addytywna metoda kongruencyjna" << std::endl;
    int n = t_pobierzWartosc(1,2);

    std::cout << "liczbaElementow" << std::endl;
    int liczbaElementow = t_pobierzWartosc(0,INT_MAX);



    std::cout << "wartoscMaksymalna" << std::endl;
    int wartoscMaksymalna = t_pobierzWartosc(1,INT_MAX);

    std::cout << "ziarno" << std::endl;
    int ziarno = t_pobierzWartosc(1,wartoscMaksymalna);


    switch (n) {
        case 1:
            LCG(liczbaElementow, ziarno, wartoscMaksymalna);
            break;
        case 2:
            ACG(liczbaElementow,wartoscMaksymalna,2,5,ziarno);
            break;
        default:
            break;
    }

    return 0;
}