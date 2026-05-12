#include<iostream>
#include "libTables.h"
#include "libFiles.h"

void sumaElementow(long long* B3, int n) {
	std::ofstream write;
	f_otworzPlikZapis(write);

	long long* R = nullptr;
	R = t_stworzTablice(n + 1);

	B3[0] = n;
	R[0] = 1;
	int d = 0;

	//Wypisanie podziału
	for (int temp = 0; temp <= d;temp++)
		write << B3[temp] << " ";
	write << std::endl;

	while (B3[0] > 1) {
		long long suma = 0;

		if (B3[d] == 1) {
			suma += R[d];
			d--;
		}

		suma += B3[d];
		R[d]--;
		long long l = B3[d] - 1;

		if (R[d] > 0)
			d++;

		B3[d] = l;
		R[d] = suma/l;
		l = suma % l;

		if (l != 0) {
			d++;
			B3[d] = l;
			R[d] = 1;
		}

		for(int temp=0; temp <= d; temp++)
			for (int temp2 = 0; temp2 < R[temp]; temp2++)
				write << B3[temp] << " ";
		write << std::endl;
	}

	delete[] R;

	write.close();
}