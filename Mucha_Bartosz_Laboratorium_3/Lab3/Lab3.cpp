#include "Lab3.h"
#include<iostream>
#include "libTables.h"



void generujZestawy(std::ofstream& write, int iloscZestawow, int iloscLiczb, int szukaneLiczby) {
	write << iloscZestawow << std::endl;
	write << iloscLiczb << std::endl;

	for (int i = 0;i < iloscZestawow;i++) {
		long long* tab1 = nullptr;
		tab1 = t_stworzTablice(iloscLiczb);

		for (int j = 0;j < iloscLiczb;j++) {
			tab1[j] = r_losowaLiczba(-281474976710656, 281474976710656); //2^48
		}

		s_sortowanieBabelkowe(tab1, iloscLiczb);

		for (int j = 0;j < iloscLiczb;j++) {
			write << tab1[j] << " ";
		}
		write << std::endl;



		write << szukaneLiczby << std::endl;

		for (int j = 0;j < szukaneLiczby;j++) {
			write << r_losowaLiczba(-32768, 32768) << " ";
		}
		write << std::endl;

		delete[]tab1;
	}
}

void odczytajDane() {
	std::ifstream read;
	f_otworzPlikOdczyt(read);
	double* tab1 = nullptr;
	double* tab2 = nullptr;
	tab1 = new double[100];
	tab2 = new double[100];
	while (f_odczytajDwieLinie(read, tab1, tab2, 100)) {
		for (int i = 0;i < 100;i++) {
			std::cout << tab1[i] << " " << tab2[i] << std::endl;
		}
	}
	delete[]tab1;
	delete[]tab2;
	read.close();
}

long long znajdzPoczatek(long long tab[], long long dlugosc, long long szukana) {
	long long left = 0, right = dlugosc - 1, index = -1;
	while (left <= right) {
		long long mid = left + (right - left) / 2;
		if (tab[mid] == szukana) {
			index = mid;
			right = mid - 1;
		}
		else if (tab[mid] < szukana) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	return index;
}

long long znajdzKoniec(long long tab[], long long dlugosc, long long szukana) {
	long long left = 0, right = dlugosc - 1, res = -1;
	while (left <= right) {
		long long mid = left + (right - left) / 2;
		if (tab[mid] == szukana) {
			res = mid;
			left = mid + 1;
		}
		else if (tab[mid] < szukana) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	return res;
}

long long iloscWystapien(long long tab[], long long dlugosc, long long szukana) {
	long long poczatek = znajdzPoczatek(tab, dlugosc, szukana);
	if (poczatek == -1) {
		return 0;
	}
	long long koniec = znajdzKoniec(tab, dlugosc, szukana);
	return koniec - poczatek + 1;
}

long long wyszukiwanieInterpolacyjne(long long tab[], long long dlugosc, long long szukana) {
	long long left = 0, right = dlugosc - 1, index=-1, res=-1;
	
	while (tab[left] <= szukana && szukana <= tab[right]) {
		if (tab[right] == tab[left]) {
            if (tab[left] == szukana) return left;
            else break;
        }
		index = left + (((szukana - tab[left]) * (right - left)) / (tab[right] - tab[left]));

		if (szukana != tab[index]) {
			if (szukana < tab[index]) {
				right = index - 1;
			}
			else {
				left = index + 1;
			}
		}
		else {
			res = index;
			return res;
		}
		
		
	}
	return -1;
	
}

long long usuwanieDuplikatow(long long tab[], long long dlugosc) {
	if (dlugosc <= 1) return dlugosc;
	int unikalne = 0;

	for(int i=0; i<dlugosc-1;i++) {
		if (tab[i] != tab[i + 1]) {
			tab[unikalne++] = tab[i];
		}
	}

	tab[unikalne++] = tab[dlugosc - 1];

	return unikalne; //ilość unikalnych elementów to długość tablicy
}
