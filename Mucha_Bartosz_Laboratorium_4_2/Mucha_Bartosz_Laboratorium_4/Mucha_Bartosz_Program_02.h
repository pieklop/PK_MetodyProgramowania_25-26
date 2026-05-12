#ifndef MUCHA_BARTOSZ_PROGRAM_02_H
#define MUCHA_BARTOSZ_PROGRAM_02_H
#include<stack>
#include<string>


/*Funkcja określająca priorytet operatora
@param op - operator
@return priorytet operatora */
int priorytrt(char op);

/*Funkcja określająca, czy operator jest prawostronny
@param op - operator
@return true, jeśli operator jest prawostronny, false w przeciwnym razie */
bool czyPrawostronny(char op);

/*Funkcja waliduje czy w linii znajdują się tylko małe litery oraz znaki dozowlonych operatorów
@param linia - referencja do tekstu zawierającego dane*/
bool walidacja(std::string& linia);


/*Funkcja przeliczająca notację infiksową na odwróconą notację polską
@param inf - wyrażenie w notacji infiksowej
@return wyrażenie w notacji ONP */
std::string INF2ONP(const std::string& inf);

/*Funkcja przeliczająca odwróconą notację polską na notację infiksową
@param inf - wyrażenie w ONP
@return wyrażenie w notacji infiksowej */
std::string ONP2INF(const std::string& onp);

/* Funkcja pośrednia pozwalająca na uruchomienie programu 02 */
void Program_02();
#endif // MUCHA_BARTOSZ_PROGRAM_02_H

