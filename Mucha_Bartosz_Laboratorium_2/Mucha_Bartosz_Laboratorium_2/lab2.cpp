#include "lab2.h"
#include "libTables.h"
#include "libFiles.h"
#include<cmath>
#include<fstream>

/* Odnosnik do zadania z Laboratorium 2
 * https://delta.pk.edu.pl/pluginfile.php/64843/mod_resource/content/7/Laboratorium2.pdf
 */
void mse(std::ifstream& read, std::ifstream& nieznany) {
    double X{0},Y{0}, min{100};

    std::ofstream write;
    f_otworzPlikZapis(write);

    double *znanyY = nullptr;
    double *znanyX = nullptr;
    double *nmY = nullptr;
    double *nmX = nullptr;
    double *minY = nullptr;
    double *minX = nullptr;

    znanyY = t_stworzTablice(106);
    znanyX = t_stworzTablice(106);
    nmY = t_stworzTablice(106);
    nmX = t_stworzTablice(106);
    minY = t_stworzTablice(106);
    minX = t_stworzTablice(106);

    f_odczytajDwieLinie(nieznany, nmY, nmX, 106);

    // std::cout<<"Wartosci bledow mse dla kazdej z siatek:\n\n";
    write<<"Wartosci bledow mse dla kazdej z siatek:\n\n";
    while (f_odczytajDwieLinie(read, znanyY, znanyX, 106)) {
        for (int i=6;i<106;i++) {
            Y += (znanyY[i]-nmY[i])*(znanyY[i]-nmY[i]); //pow(znanyY[i]-nmY[i],2)
            X += (znanyX[i]-nmX[i])*(znanyX[i]-nmX[i]); //pow(znanyX[i]-nmX[i],2)

        }
        // std::cout<<"X: "<<X<<" Y: "<<Y<<std::endl;
        double diff = std::sqrt(Y+X);
        if (diff<=min) {
            min = diff;

            for (int i=0;i<106;i++) {
                minY[i] = znanyY[i];
                minX[i] = znanyX[i];
            }
        }
        // std::cout<<diff<<" ";
        write<<diff<<" ";
        X = 0,Y = 0;
    }
    // std::cout<<"\nMinimalny blad mse: "<<min<<std::endl;
    write<<"\n\nMinimalny blad mse: "<<min<<std::endl;

    for (int i=0;i<106;i++) {
        // std::cout<<minY[i]<<" ";
        write<<minY[i]<<" ";
    }
    // std::cout<<std::endl;
    write<<std::endl<<std::endl;

    for (int i=0;i<106;i++) {
        // std::cout<<minX[i]<<" ";
        write<<minX[i]<<" ";
    }
    // std::cout<<std::endl;
    write<<std::endl<<std::endl;
    write.close();
}

