#include "Mucha_Bartosz_Program_01.h"
#include "libTables.h"
#include "libFiles.h"
#include<iostream>


void zamiana(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

void sortowanieLeksykograficznie(int* krawedzie, int iloscKrawedziX2) {
	for (int i = 0; i < iloscKrawedziX2 - 2; i += 2) {
		for (int j = 0; j < iloscKrawedziX2 - 2 - i; j += 2) {
			if (krawedzie[j] > krawedzie[j + 2] || (krawedzie[j] == krawedzie[j + 2] && krawedzie[j + 1] > krawedzie[j + 3])) {
				zamiana(krawedzie[j], krawedzie[j + 2]);
				zamiana(krawedzie[j + 1], krawedzie[j + 3]);
			}
		}
	}
}

void utworzMacierzIncydencji(int* krawedzie, int iloscKrawedziX2, int** macierzIncydencji, int wierzcholki) {
	for (int i = 0; i < iloscKrawedziX2 / 2; i++) {
		for (int j = 0; j < wierzcholki; j++) {
			macierzIncydencji[i][j] = 0;
		}
	}

	for (int i = 0; i < iloscKrawedziX2; i += 2) {
		int wyjscie = krawedzie[i];
		int wejscie = krawedzie[i + 1];
		macierzIncydencji[i / 2][wyjscie - 1] = -1; // Oznaczamy wyjście krawędzi jako -1
		macierzIncydencji[i / 2][wejscie - 1] = 1;   // Oznaczamy wejście krawędzi jako 1
	}
}

void wyznaczSasiadow(int** macierzIncydencji, int wiersze, int kolumny) {
	for (int i = 0; i < kolumny; ++i) {
		std::cout << i+1 << ": ";

		for (int j = 0; j < kolumny; ++j) {
			if (i == j) continue;
				for (int k = 0; k < wiersze; ++k) {
					if (macierzIncydencji[k][i] != 0 && macierzIncydencji[k][j] != 0) {
						std::cout << j+1 << " ";
						break;
					}
				}
		}
		std::cout << std::endl;
	}
}

void Mucha_Bartosz_Program_01a() {
	std::ifstream wejscie;
	f_otworzPlikOdczyt(wejscie);
	
	//Tablica krawedzi z pliku | parzyste -> wyjście; nieparzyste -> wejście (5 -> 1, 1 -> 2 etc.)
	int* krawedzie = nullptr;
	int iloscKrawedziX2 = f_odczytajJednaLiczbe(wejscie)*2;
	krawedzie = t_stworzTablice(iloscKrawedziX2);

	int maks = 0;
	for (int i = 0; i < iloscKrawedziX2; i++) {
		krawedzie[i] = f_odczytajJednaLiczbe(wejscie);
		if (krawedzie[i] > maks) {
			maks = krawedzie[i];
		}
	}
	wejscie.close();

	sortowanieLeksykograficznie(krawedzie, iloscKrawedziX2);

	//Wypisanie krawedzi po sortowaniu 
	//for (int i = 0; i < iloscKrawedziX2; i++) {
	//	std::cout << krawedzie[i] << " ";
	//}

	int** macierzIncydencji = t_stworzTabliceDwuwymiarowa(iloscKrawedziX2 / 2, maks);
	utworzMacierzIncydencji(krawedzie, iloscKrawedziX2, macierzIncydencji, maks);
	t_wypiszTabliceDwuwymiarowa(iloscKrawedziX2 / 2, maks, macierzIncydencji);
	wyznaczSasiadow(macierzIncydencji, iloscKrawedziX2 / 2, maks);

	t_usunTabliceDwuwymiarowa(macierzIncydencji, iloscKrawedziX2 / 2);

	delete[] krawedzie;
}

void utworzMacierzIncydencjiWektor(const std::vector<std::pair<int, int>>& krawedzie, std::vector<std::vector<int>>& macierz, int wierzcholki) {
	macierz.assign(krawedzie.size(), std::vector<int>(wierzcholki, 0));

	for (size_t i = 0; i < krawedzie.size(); i++) {
		macierz[i][krawedzie[i].first - 1] = -1;
		macierz[i][krawedzie[i].second - 1] = 1;
	}
}

void wyznaczSasiadowWektor(const std::vector<std::vector<int>>& macierz, int wierzcholki) {
	for (int i = 0; i < wierzcholki; ++i) {
		std::cout << i + 1 << ": ";
		for (int j = 0; j < wierzcholki; ++j) {
			if (i == j) continue;
			for (size_t k = 0; k < macierz.size(); ++k) {
				if (macierz[k][i] != 0 && macierz[k][j] != 0) {
					std::cout << j + 1 << " ";
					break;
				}
			}
		}
		std::cout << std::endl;
	}
}

void Mucha_Bartosz_Program_01b() {
	std::ifstream wejscie;
	f_otworzPlikOdczyt(wejscie);

	int iloscKrawedzi;
	wejscie >> iloscKrawedzi;

	std::vector<std::pair<int, int>> krawedzie(iloscKrawedzi);
	int maks = 0;

	for (int i = 0; i < iloscKrawedzi; i++) {
		wejscie >> krawedzie[i].first >> krawedzie[i].second;
		if (krawedzie[i].first > maks) maks = krawedzie[i].first;
		if (krawedzie[i].second > maks) maks = krawedzie[i].second;
	}
	wejscie.close();

	
	for (size_t i = 0; i < krawedzie.size(); ++i) {
		for (size_t j = 0; j < krawedzie.size() - 1 - i; ++j) {
			if (krawedzie[j].first > krawedzie[j + 1].first ||
				(krawedzie[j].first == krawedzie[j + 1].first && krawedzie[j].second > krawedzie[j + 1].second)) {
				std::pair<int, int> temp = krawedzie[j];
				krawedzie[j] = krawedzie[j + 1];
				krawedzie[j + 1] = temp;
			}
		}
	}

	std::vector<std::vector<int>> macierzIncydencji;
	utworzMacierzIncydencjiWektor(krawedzie, macierzIncydencji, maks);

	// Wypisanie macierzy
	for (auto& wiersz : macierzIncydencji) {
		for (int val : wiersz) {
			std::cout << val << " ";
		}
		std::cout << "\n";
	}
	wyznaczSasiadowWektor(macierzIncydencji, maks);
}
