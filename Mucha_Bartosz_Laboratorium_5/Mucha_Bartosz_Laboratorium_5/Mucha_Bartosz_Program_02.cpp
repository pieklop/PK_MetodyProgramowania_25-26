#include "Mucha_Bartosz_Program_02.h"
#include<iostream>
#include "libFiles.h"
#include "libTables.h"



void wczytywanie(std::ifstream& wejscie, int n, int*& u, int*& v, int& max_wierzcholek) {
	u = t_stworzTablice(n);
	v = t_stworzTablice(n);
	max_wierzcholek = 0;

	for (int i = 0; i < n; ++i) {
		wejscie >> u[i] >> v[i];
		if (u[i] > max_wierzcholek) max_wierzcholek = u[i];
		if (v[i] > max_wierzcholek) max_wierzcholek = v[i];
	}
}

lista** listaIncydencji(int n, int* u, int* v, int max_wierzcholek) {
	lista** incydencja = new lista * [max_wierzcholek + 1];
	for (int i = 0; i <= max_wierzcholek; ++i) {
		incydencja[i] = nullptr;
	}

	for (int i = 0; i < n; ++i) {
		Lista_dodajNaPoczatek(incydencja[u[i]], v[i]);
		Lista_dodajNaPoczatek(incydencja[v[i]], u[i]);
	}
	return incydencja;
}

void wypiszIncydencje(lista** incydencja, int max_wierzcholek) {
	for (int i = 1; i <= max_wierzcholek; ++i) {
		if (incydencja[i] != nullptr) {
			std::cout << i << ": ";

			lista* temp = incydencja[i];
			while (temp != nullptr) {
				std::cout << temp->liczba << " ";
				temp = temp->next;
			}

			std::cout << " Stopien: " << Lista_rozmiarListy(incydencja[i]) << std::endl;
		}
	}
}

void czyszczenie(lista** incydencja, int max_wierzcholek) {
	for (int i = 1; i <= max_wierzcholek; ++i) {
		while (!Lista_czyPusta(incydencja[i])) {
			Lista_usunElement(incydencja[i]);
		}
	}
	delete[] incydencja;
}

void Mucha_Bartosz_Program_02a() {
	std::ifstream wejscie;
	f_otworzPlikOdczyt(wejscie);

	int n = f_odczytajJednaLiczbe(wejscie);

	int* u = nullptr;
	int* v = nullptr;
	int max_wierzcholek = 0;

	wczytywanie(wejscie, n, u, v, max_wierzcholek);
	lista** incydencja = listaIncydencji(n, u, v, max_wierzcholek);

	wypiszIncydencje(incydencja, max_wierzcholek);
	czyszczenie(incydencja, max_wierzcholek);

	delete[] u;
	delete[] v;

	wejscie.close();
}

void wczytywanieLista(std::ifstream& wejscie, int n, int*& u, int*& v, int& max_wierzcholek) {
	u = t_stworzTablice(n);
	v = t_stworzTablice(n);
	max_wierzcholek = 0;

	for (int i = 0; i < n; ++i) {
		wejscie >> u[i] >> v[i];
		if (u[i] > max_wierzcholek) max_wierzcholek = u[i];
		if (v[i] > max_wierzcholek) max_wierzcholek = v[i];
	}
}

std::list<int>* listaIncydencjiLista(int n, int* u, int* v, int max_wierzcholek) {
	std::list<int>* incydencja = new std::list<int>[max_wierzcholek + 1];

	for (int i = 0; i < n; ++i) {
		incydencja[u[i]].push_front(v[i]);
		incydencja[v[i]].push_front(u[i]);
	}
	return incydencja;
}

void wypiszIncydencjeLista(std::list<int>* incydencja, int max_wierzcholek) {
	for (int i = 1; i <= max_wierzcholek; ++i) {
		if (!incydencja[i].empty()) {
			std::cout << i << ": ";

			for (int sasiad : incydencja[i]) {
				std::cout << sasiad << " ";
			}

			std::cout << " Stopien: " << incydencja[i].size() << std::endl;
		}
	}
}


void Mucha_Bartosz_Program_02b() {
	std::ifstream wejscie;
	f_otworzPlikOdczyt(wejscie);

	int n = f_odczytajJednaLiczbe(wejscie);

	int* u = nullptr;
	int* v = nullptr;
	int max_wierzcholek = 0;

	wczytywanieLista(wejscie, n, u, v, max_wierzcholek);
	std::list<int>* incydencja = listaIncydencjiLista(n, u, v, max_wierzcholek);

	wypiszIncydencjeLista(incydencja, max_wierzcholek);
	

	delete[] u;
	delete[] v;
	delete[] incydencja;
	wejscie.close();
}
