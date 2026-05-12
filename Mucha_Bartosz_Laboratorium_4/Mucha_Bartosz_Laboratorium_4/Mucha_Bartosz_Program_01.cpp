#include<iostream>
#include<stack>
#include "libFiles.h"
#include "Mucha_Bartosz_Program_01.h"

/* Początek podpunktu a (tablica dynamiczna) */
void inicjalizacjaTablicy(Tablica& t, int rozmiar) {
	t.tab = new int[rozmiar];
	t.head = -1;
	t.rozmiar = rozmiar;
}

bool Tablica_czyPusta(Tablica& t) {
	return t.head == -1;
}

int Tablica_rozmiarTablicy(Tablica& t) {
	return t.head + 1;
}

int Tablica_gornyElement(Tablica& t) {
	if (Tablica_czyPusta(t)) {
		std::cerr << "Tablica jest pusta!" << std::endl;
		return -1;
	}
	return t.tab[t.head];
}

void Tablica_dodajNaPoczatek(Tablica& t, int liczba) {
	if (t.head >= t.rozmiar - 1) {
		std::cerr << "Tablica jest pelna!" << std::endl;
		return;
	}
	t.head++;
	t.tab[t.head] = liczba;
}

void Tablica_usunElement(Tablica& t) {
	if (Tablica_czyPusta(t)) {
		std::cerr << "Tablica jest pusta!" << std::endl;
		return;
	}
	t.head--;
}

void StosTablicowy() {
	std::ifstream wejscie;
	f_otworzPlikOdczyt(wejscie);
	int n = f_odczytajJednaLiczbe(wejscie);
	
	Tablica stos;
	inicjalizacjaTablicy(stos, n);
	
	std::cout << "Czy tablica jest pusta? " << (Tablica_czyPusta(stos) ? "Tak" : "Nie") << std::endl;
	
	for (int i = 0; i < n; i++) {
		int liczba = f_odczytajJednaLiczbe(wejscie);
		std::cout << "Odczytana liczba: " << liczba << std::endl;
		Tablica_dodajNaPoczatek(stos, liczba);
	}

	std::cout << "Czy tablica jest pusta? " << (Tablica_czyPusta(stos) ? "Tak" : "Nie") << std::endl;
	std::cout << "Rozmiar tablicy: " << Tablica_rozmiarTablicy(stos) << std::endl;
	
	while (!Tablica_czyPusta(stos)) {
		std::cout << "Gorny element: " << Tablica_gornyElement(stos) << std::endl;
		std::cout << "Usuwanie gornego elementu" << std::endl;
		Tablica_usunElement(stos);
	}

	delete[] stos.tab;
	wejscie.close();
}

/* Koniec podpunktu a (tablica dynamiczna) */


/* Początek podpunktu b (lista jednokierunkowa) */
bool Lista_czyPusta(lista* head) {
	return head == nullptr;
}

int Lista_rozmiarListy(lista* head) {
	int licznik = 0;
	lista* nowy = head;
	while (nowy != nullptr) {
		licznik++;
		nowy = nowy->next;
	}
	return licznik;
}

int Lista_gornyElement(lista* head) {
	if (Lista_czyPusta(head)) {
		std::cerr << "Lista jest pusta!" << std::endl;
		return -1;
	}
	return head->liczba;
}

void Lista_dodajNaPoczatek(lista*& head, int liczba) {
	lista* nowy = new lista;
	nowy->liczba = liczba;
	nowy->next = head;
	head = nowy;
}

void Lista_usunElement(lista*& head) {
	if (Lista_czyPusta(head)) {
		std::cerr << "Lista jest pusta!" << std::endl;
		return;
	}
	lista* temp = head;
	head = head->next;
	delete temp;
}

void ListaJednokierunkowa() {
	std::ifstream wejscie;
	f_otworzPlikOdczyt(wejscie);
	int n = f_odczytajJednaLiczbe(wejscie);

	lista* stos = nullptr;


	std::cout << "Czy lista jest pusta? " << (Lista_czyPusta(stos) ? "Tak" : "Nie") << std::endl;

	for (int i = 0; i < n; i++) {
		int liczba = f_odczytajJednaLiczbe(wejscie);
		std::cout << "Odczytana liczba: " << liczba << std::endl;
		Lista_dodajNaPoczatek(stos, liczba);
	}

	std::cout << "Czy lista jest pusta? " << (Lista_czyPusta(stos) ? "Tak" : "Nie") << std::endl;
	std::cout << "Rozmiar listy: " << Lista_rozmiarListy(stos) << std::endl;

	while (!Lista_czyPusta(stos)) {
		std::cout << "Gorny element: " << Lista_gornyElement(stos) << std::endl;
		std::cout << "Usuwanie gornego elementu" << std::endl;
		Lista_usunElement(stos);
	}

	wejscie.close();
}

/* Koniec podpunktu b (lista jednokierunkowa) */

/* Początek podpunktu c (stack) */
void stack() {
	std::ifstream wejscie;
	f_otworzPlikOdczyt(wejscie);
	int n = f_odczytajJednaLiczbe(wejscie);

	std::stack<int> stos;
	
	std::cout << "Czy lista jest pusta? " << (stos.empty() ? "Tak" : "Nie") << std::endl;

	for (int i = 0; i < n; i++) {
		int liczba = f_odczytajJednaLiczbe(wejscie);
		stos.push(liczba);
		std::cout << "Odczytana liczba: " << liczba << std::endl;
	}

	std::cout << "Gorny element stosu: " << stos.top() << std::endl;
	// Usuwanie elementów ze stosu
	while (!stos.empty()) {
		std::cout << "Usuwanie gornego elementu: " << stos.top() << std::endl;
		stos.pop();
	}

	wejscie.close();
}

/* Koniec podpunktu c (stack) */