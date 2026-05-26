#include <iostream>

#include "Mucha_Bartosz_Program_01.h"
#include "Mucha_Bartosz_Program_02.h"

int main() {
    std::cout<<"Wybierz program 1 lub 2"<<std::endl;
    int n = t_pobierzWartosc(1,2);

    switch(n) {
        case 1:
            Mucha_Bartosz_Program_01();
            break;
        case 2:
            Mucha_Bartosz_Program_02();
            break;
        default:
            break;
    }
    return 0;
}
