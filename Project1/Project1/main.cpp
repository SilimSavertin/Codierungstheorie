#include "KoerperFq.h"
#include <iostream>

void main() {
	int a;
	KoerperFq testelement(3, 3, 4);
	testelement.setvector();
	testelement.printer();
	std::cin >> a;

}