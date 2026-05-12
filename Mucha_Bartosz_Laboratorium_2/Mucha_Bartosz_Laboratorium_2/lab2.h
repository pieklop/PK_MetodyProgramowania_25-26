#ifndef LAB2_H
#define LAB2_H
#include<fstream>

/*
 * Funkcja oblicza wartości błędów mse dla każdej z siatek oraz wyświetla najlepsze dopasowanie
 * @param read - referencja do pliku z klasycznym modelem
 * @param nieznany - referencja do pliku z nieznanym modelem
 */
void mse(std::ifstream& read, std::ifstream& nieznany);

#endif //LAB2_H