#include<iostream>
#include "libTables.h"
#include "Lab3.h"

int main() {
	std::cout << "Program 01: \n";
	int n = t_pobierzWartosc(1, 100);

	long long* B = nullptr;
	B = t_stworzTablice(n);

	generujPodzbiory(B, n);

	delete[] B;


	std::cout << "Program 02: \n";

	int n2 = t_pobierzWartosc(1, 100);
	int k2 = t_pobierzWartosc(1, n2-1);

	long long* B2 = nullptr;
	B2 = t_stworzTablice(n2);

	ciagPodzbiorow(B2, n2, k2);

	delete[] B2;


	std::cout << "Program 03: \n";

	int n3 = t_pobierzWartosc(1, 100);

	long long* B3 = nullptr;
	B3 = t_stworzTablice(n3);

	sumaElementow(B3, n3);

	delete[] B3;


	return 0;
}