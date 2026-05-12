#include<iostream>
#include "Mucha_Bartosz_Program_01.h"
#include "Mucha_Bartosz_Program_02.h"
#include "libTables.h"

int main() {
	std::cout << "1 - Zadanie 1a\n2 - Zadanie 1b\n3 - Zadanie 2a\n4 - Zadanie 2b" << std::endl;
	int n = t_pobierzWartosc(1, 4);
	switch (n)
	{
	case 1:
		Mucha_Bartosz_Program_01a();
		break;
	case 2:
		Mucha_Bartosz_Program_01b();
		break;
	case 3:
		Mucha_Bartosz_Program_02a();
		break;
	case 4:
		Mucha_Bartosz_Program_02b();
		break;
	default:
		break;
	}
	
	return 0;
}