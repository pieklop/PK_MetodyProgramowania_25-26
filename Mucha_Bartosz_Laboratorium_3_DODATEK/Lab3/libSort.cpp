#include "libSort.h"

void s_zamiana(long long& a, long long& b) {
	long long temp{};
	temp = a;
	a = b;
	b = temp;
}

void s_sortowanieBabelkowe(long long *tab, int iloscElementow) {
	
	
	for (int i = 0;i < iloscElementow;i++) {
		for (int j = 0; j < iloscElementow - i - 1;j++) {
			if (tab[j] > tab[j + 1])
				s_zamiana(tab[j], tab[j + 1]);
		}
	}
}