#ifndef MUCHA_BARTOSZ_PROGRAM_01_H
#define MUCHA_BARTOSZ_PROGRAM_01_H

//A - start
	struct Tablica{
		int* tab;
		int head;
		int rozmiar;
	};

	/*Funkcja inicjalizuje tablicę dynamiczną
	@param t - referencja do tablicy
	@param rozmiar - rozmiar tablicy dynamicznej*/
	void inicjalizacjaTablicy(Tablica& t, int rozmiar);

	/*Funkcja sprawdza czy tablica dynamiczna jest pusta
	@param t - referencja do tablicy */
	bool Tablica_czyPusta(Tablica& t);

	/*Funkcja sprawdza rozmiar tablicy dynamicznej
	* @param t - referencja do tablicy */
	int Tablica_rozmiarTablicy(Tablica& t);

	/*Funkcja podaje górny element tablicy dynamicznej
	* @param t - referencja do tablicy */
	int Tablica_gornyElement(Tablica& t);

	/*Funkcja dodaje element na początek stosu tablicy dynamicznej
	@param t - referencja do tablicy
	@param liczba - liczba, która ma zostać dodana*/
	void Tablica_dodajNaPoczatek(Tablica& t, int liczba);

	/*Funkcja usuwa górny element stosu tablicy dynamicznej
	* @param t - referencja do tablicy */
	void Tablica_usunElement(Tablica& t);

	/*Funkcja pośrednia wywołująca cały podpunkt a*/
	void StosTablicowy();
//A - koniec


//B - start
	struct lista {
		int liczba;
		lista* next;
	};

	/*Funkcja sprawdza czy lista jednokierunkowa jest pusta
	@param head - wskaźnik na wierzchni element listy
	@return true jeśli lista jest pusta, false jeśli zawiera elementy*/
	bool Lista_czyPusta(lista* head);

	/*Funkcja sprawdza rozmiar listy jednokierunkowej
	@param head - wskaźnik na wierzchni element listy
	@return rozmiar listy jednokierunkowej*/
	int Lista_rozmiarListy(lista* head);
	
	/*Funkcja podaje górny element listy jednokierunkowej
	* @param head - wskaźnik na wierzchni element listy
	@return górny element listy jednokierunkowej*/
	int Lista_gornyElement(lista* head);

	/*Funkcja dodaje element na początek listy jednokierunkowej
	* @param head - wskaźnik na wierzchni element listy
	*/
	void Lista_dodajNaPoczatek(lista*& head, int liczba);

	/*Funkcja usuwa górny element listy jednokierunkowej
	* @param head - wskaźnik na wierzchni element listy */
	void Lista_usunElement(lista*& head);

	/*Funkcja pośrednia wywołująca cały podpunkt b*/
	void ListaJednokierunkowa();

//B - koniec

//C - start
	/*Funkcja pośrednia wywołująca cały podpunkt c*/
	void stack();
//C - koniec


#endif
