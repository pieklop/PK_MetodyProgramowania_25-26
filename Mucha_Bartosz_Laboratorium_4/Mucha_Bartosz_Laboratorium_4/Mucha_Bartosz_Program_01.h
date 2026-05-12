#ifndef MUCHA_BARTOSZ_PROGRAM_01_H
#define MUCHA_BARTOSZ_PROGRAM_01_H

//A - start
	struct Tablica{
		int* tab;
		int head;
		int rozmiar;
	};

	void inicjalizacjaTablicy(Tablica& t, int rozmiar);
	bool Tablica_czyPusta(Tablica& t);
	int Tablica_rozmiarTablicy(Tablica& t);
	int Tablica_gornyElement(Tablica& t);
	void Tablica_dodajNaPoczatek(Tablica& t, int liczba);
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
