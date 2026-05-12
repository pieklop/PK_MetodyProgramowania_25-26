#include "libRandom.h"

int r_losowaLiczba(long long min, long long max) {
	int liczba{};
	
	liczba = min + rand() % (max - min + 1);
	return liczba;
}