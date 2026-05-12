#include<iostream>
#include "Mucha_Bartosz_Program_01.h"
#include "libTables.h"

int main() {
	std::cout << "Wybierz zadanie (1-3): "<<std::endl;
	std::cout << "1. Stos za pomoca tablicy dynamicznej" << std::endl;
	std::cout << "2. Stos za pomoca listy jednokierunkowej " << std::endl;
	std::cout << "3. Adapter stosu" << std::endl;
	//std::cout << "4. ONP" << std::endl;
	//std::cout << "5. ONP (minimalna ilosc nawiasow) " << std::endl;
	int wybor = t_pobierzWartosc(1, 3);
	
	switch (wybor)
	{
	case 1:
		StosTablicowy();
		break;
	case 2:
		ListaJednokierunkowa();
		break;
	case 3:
		stack();
		break;
	case 4:
		//ONP();
		break;
	case 5:
		//ONP_minimalnaIloscNawiasow();
		break;
	default:
		break;
	}

	return 0;
}