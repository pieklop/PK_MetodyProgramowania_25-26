#include<iostream>
#include "libTables.h"
#include "libFiles.h"

void generujPodzbiory(long long* B, int n) {
	std::ofstream write;
	f_otworzPlikZapis(write);

	for (int temp = 0; temp < n; temp++) 
		B[temp] = 0;

	int i = 0,p,j;

	do {
		//Zapis aktualnego podzbioru do pliku
		for (int temp = 0;temp < n;++temp)
				write << B[temp] << " ";
		write << std::endl;

		i += 1;
		p = 0;
		j = i;

		while (j%2 == 0) {
			j /= 2;
			p++;
		}

		if (p < n)
			B[p] = 1 - B[p];

	} while (p<n);

	write.close();
}