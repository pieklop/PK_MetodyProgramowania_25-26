#include<iostream>
#include "Mucha_Bartosz_Program_01.h"
#include "Mucha_Bartosz_Program_02.h"
#include "libTables.h"

int main() {
	std::cout << "Wybierz zadanie (1-4): "<<std::endl;
	std::cout << "1. Stos za pomoca tablicy dynamicznej" << std::endl;
	std::cout << "2. Stos za pomoca listy jednokierunkowej " << std::endl;
	std::cout << "3. Adapter stosu" << std::endl;
	std::cout << "4. ONP" << std::endl;
	int wybor = t_pobierzWartosc(1, 4);
	
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
		Program_02();
		break;
	default:
		break;
	}

	return 0;
}