#include<iostream>
#include "libTables.h"
#include "libFiles.h"

void ciagPodzbiorow(long long* B2, int n, int k) {
	std::ofstream write;
	f_otworzPlikZapis(write);
	
	for (int i = 1;i <= k;i++)
		B2[i-1]=i;

	int p = k;

	while (p >= 1) {
		for (int temp = 1;temp <= k;temp++)
			write << B2[temp-1] << " ";
		write << std::endl;

		if (B2[k-1] == n)
			p--;
		else
			p = k;

		if (p >= 1) {
			for (int temp = k; temp >= p; temp--)
				B2[temp-1] = B2[p-1]+temp-p+1;
		}
	}

	write.close();
}