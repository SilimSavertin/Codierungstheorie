#include "KoerperFq.h"
#include <iostream>

void main() {
	int a;
	KoerperFq testelement(2, 2, 5); //3 Körper, 3 Zeilen, 6 Spalten
	testelement.setvector();
	testelement.M=testelement.kanon(testelement);
	testelement.H = testelement.kontroll(testelement);
	testelement.printer();
	testelement.printerH();
	std::cin >> a;

}

std::vector<std::vector<int>> matrixmult(std::vector<std::vector<int>>G, std::vector<std::vector<int>>HT) {

	std::vector<std::vector<int>> Ergebnis;
	std::vector<int> ErgebnisZ;

	for (int gz = 0; gz < G.size(); gz++) {
		for (int gs = 0; gs < G[gz].size(); gs++) {
			int wert = 0;
			for (int hts = 0; hts < HT.size(); hts++) {
				wert += G[gz][gs] * HT[0][hts];
			}
			ErgebnisZ.push_back(wert);
		}
		Ergebnis.push_back(ErgebnisZ);
	}




	return Ergebnis;
}