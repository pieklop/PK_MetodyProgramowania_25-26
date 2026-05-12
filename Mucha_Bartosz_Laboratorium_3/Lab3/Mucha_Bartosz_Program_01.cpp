#include "Lab3.h"
#include<iostream>


int main() {
	/* Początek generowania zestawow */
	srand(time(NULL));
	std::ofstream write;
	f_otworzPlikZapis(write);

	generujZestawy(write, 1, 1000, 100);

	write.close();
	/* Koniec generowania zestawow*/

	/* Początek odczytywania danych wstepnych*/
	std::ifstream read;
	f_otworzPlikOdczyt(read);

	int iloscZestawow = f_odczytajJednaLiczbe(read);

	/* Koniec odczytywania danych wstepnych*/

	f_otworzPlikZapis(write);

	long long liczbaElementow{}, liczbaSzukanych{};
	for (int i = 0;i < iloscZestawow;i++) { // obsluga kazdego zestawu
		//Pierwsza linia zestawu
		liczbaElementow = f_odczytajJednaLiczbe(read);

		//Druga linia zestawu
		long long* elementy = nullptr;
		elementy = new long long[liczbaElementow];
		f_odczytajXElementow(read, elementy, liczbaElementow);

		//Trzecia linia zestawu
		liczbaSzukanych = f_odczytajJednaLiczbe(read);

		//Czwarta linia zestawu
		long long* szukane = nullptr;
		szukane = new long long[liczbaSzukanych];
		f_odczytajXElementow(read, szukane, liczbaSzukanych);


		//Część właściwa
		for (int j = 0;j < liczbaSzukanych;j++) {
			//Podpunkt a
			//std::cout << "(" << iloscWystapien(elementy, liczbaElementow, szukane[j]);
			write << "(" << iloscWystapien(elementy, liczbaElementow, szukane[j]);
			//Podbunkt b
			//std::cout<< " " << wyszukiwanieInterpolacyjne(elementy, liczbaElementow, szukane[j]) << ")";
			write << " " << wyszukiwanieInterpolacyjne(elementy, liczbaElementow, szukane[j])<<")";
		}
		std::cout << std::endl;
		write << std::endl;

		//Podpunkt c - usuwanie duplikatów
		liczbaElementow = usuwanieDuplikatow(elementy, liczbaElementow);
		//t_wypiszTablice(liczbaElementow, elementy);
		for (int i = 0;i < liczbaElementow;i++) {
			write << elementy[i] << " ";
		}

		delete[]elementy;
		delete[]szukane;

	}
	write.close();
	read.close();
}
