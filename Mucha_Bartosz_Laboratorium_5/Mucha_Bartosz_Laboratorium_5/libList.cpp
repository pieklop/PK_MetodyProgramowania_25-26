#include<iostream>
#include<stack>
#include "libFiles.h"
#include "libList.h"

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

/* Koniec podpunktu b (lista jednokierunkowa) */