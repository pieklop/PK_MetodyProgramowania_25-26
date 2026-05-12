#ifndef LIBRANDOM_H
#define LIBRANDOM_H
#include<cstdlib>
#include<ctime>

/*
*Funckcja generuje jedna pseudolosowa liczbe z okreslonego przedzialu UWAGA! wymaga: srand(time(NULL)); przed jej uzyciem
* @param min - dolna granica
* @param max - gorna granica
* @return liczba - wygenerowana pseudolosowa liczba
*/
int r_losowaLiczba(long long min, long long max);


#endif //LIBRANDOM_H
