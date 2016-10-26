#include "KoerperFq.h"
#include <iostream>

void main() {
	int a;
	KoerperFq testelement(3, 3, 6); //3 Körper, 3 Zeilen, 6 Spalten
	testelement.setvector();
	testelement.kanon(testelement).printer();
	std::cin >> a;

}