#include "KoerperFq.h"
#include <iostream>


KoerperFq::KoerperFq(int q, int k, int n) //q Dimension, k Zeilen, n Spalten
{
	this->q = q;
	this->k = k;
	this->n = n;
	//this->M = new std::vector<std::vector<int>>(k);
	
}

void KoerperFq::setvector() {
	int i = 0, j = 0, e=0;
	std::vector<int> zwischenspeicher(this->n);
	while (i < this->k) {
		while (j < this->n) {
			std::cout << "Zeile " << i + 1 << " Spalte " << j + 1 << std::endl;
			std::cin >> e;
			if (e <= this->q - 1) {
				zwischenspeicher[j] = e;
				j++;
			}
			else {
				std::cout << "Ungueltige Eingabe";
			}
		}
		j = 0;
		M.push_back(zwischenspeicher);
		i++;
	}
}

void KoerperFq::printer() {
	int i = 0, j = 0;
	std::cout<< std::endl;
	while (i < this->k) {
		while (j < this->n) {
			std::cout << M[i][j]<<" ";		
			j++;
		}
		j = 0;
		std::cout << std::endl;
		i++;
	}

}

int KoerperFq::getelement(int row, int col) {
	return M[row][col];
}

std::vector<int> KoerperFq::getrow(int row) {
	return M[row];
}

int KoerperFq::elementAddition(int a, int b) {
	if (q == 2) {
		int Ergebnistabelle[2][2];
		Ergebnistabelle[0][0] = 0;
		Ergebnistabelle[1][0] = 1;
		Ergebnistabelle[1][1] = 0;
		Ergebnistabelle[0][1] = 1;
		return Ergebnistabelle[a][b];
	}
	if (q==3){
		int ET[3][3];
		ET[0][0] = 0;
		ET[0][1] = 1;
		ET[0][2] = 2;
		ET[1][0] = 1;
		ET[1][1] = 2;
		ET[1][2] = 0;
		ET[2][0] = 2;
		ET[2][1] = 0;
		ET[2][2] = 1;
		return ET[a][b];
	}
	if (q == 4) {
		int ET[4][4];
		ET[0][0] = 0;
		ET[0][1] = 1;
		ET[0][2] = 2;
		ET[0][3] = 3;
		ET[1][0] = 1;
		ET[1][1] = 0;
		ET[1][2] = 3;
		ET[1][3] = 2;
		ET[2][0] = 2;
		ET[2][1] = 3;
		ET[2][2] = 0;
		ET[2][3] = 1;
		ET[3][0] = 3;
		ET[3][1] = 2;
		ET[3][2] = 1;
		ET[3][3] = 0;
		return ET[a][b];

	}
}

int KoerperFq::additiveInverse(int a) {
	if (q==2){
		if (a == 0) {
			return 0;
		}
		else {
			return 1;
		}
	}
	if (q == 3) {
		if (a == 0) {
			return 0;
		}
		else if (a == 1) {
			return 2;
		}
		else {
			return 1;
		}

	}
	if (q == 4) {
		return a;
	}
}

int KoerperFq::elementMultiplikation(int a, int b) {
	if (q == 2) {
		int Ergebnistabelle[2][2];
		Ergebnistabelle[0][0] = 0;
		Ergebnistabelle[1][0] = 0;
		Ergebnistabelle[1][1] = 1;
		Ergebnistabelle[0][1] = 0;
		return Ergebnistabelle[a][b];
	}
	if (q == 3) {
		int ET[3][3];
		ET[0][0] = 0;
		ET[0][1] = 0;
		ET[0][2] = 0;
		ET[1][0] = 0;
		ET[1][1] = 1;
		ET[1][2] = 2;
		ET[2][0] = 0;
		ET[2][1] = 2;
		ET[2][2] = 1;
		return ET[a][b];
	}
	if (q == 4) {
		int ET[4][4];
		ET[0][0] = 0;
		ET[0][1] = 0;
		ET[0][2] = 0;
		ET[0][3] = 0;
		ET[1][0] = 0;
		ET[1][1] = 1;
		ET[1][2] = 2;
		ET[1][3] = 3;
		ET[2][0] = 0;
		ET[2][1] = 2;
		ET[2][2] = 3;
		ET[2][3] = 1;
		ET[3][0] = 0;
		ET[3][1] = 3;
		ET[3][2] = 1;
		ET[3][3] = 2;
		return ET[a][b];

	}
}

int KoerperFq::multiInverse(int a) {
	if (a == 0) return 0;
	if (q == 2) {
		if (a == 0) {
			return 0;
		}
		else {
			return 1;
		}
	}
	if (q == 3) {
		if (a == 0) {
			return 0;
		}
		else if (a == 1) {
			return a;
		}
		else {
			return a;
		}

	}
	if (q == 4) {
		if (a == 1) {
			return 1;
		}
		if (a == 2) {
			return 3;
		}
		if (a == 3) {
			return 2;
		}
	}
}

int KoerperFq::getn() {
	return n;
}
int KoerperFq::getk() {
	return k;
}


KoerperFq KoerperFq::kanon(KoerperFq G) {
	int col = 0, row = 0, rowwalker = 0, indexwalker = 0;
	bool signal = true;
	std::vector<int> PivotindexZ(G.q);
	std::vector<int> PivotindexS(G.q);
	std::vector<int> speicher(n);

//Tauschalgorithmus zur Ordnung der Matrix nach Vertauschungsregel
	while (col < G.getn()) {
		rowwalker = row; //Startpunkt des Matrixdurchlaufs festlegen
		while (rowwalker < G.getk()) {

			if (G.M[col][rowwalker] != 0) {
				G.M[row].swap(G.M[rowwalker]); //Tausche Inhalt von aktuellem Startpunkt mit gefundener Zeile die unterschiedlich von 0 ist
				row++; //Nächster Start sollte eine Zeile überspringen hiermit, sollte bei nächstem Swap in selber Zeile auch dafür sorgen den letzten Swap nicht rückgängig zu machen
				if (signal == true) {
					PivotindexZ[indexwalker] = rowwalker; //Nötig um 'oberste' Zeile zu finden welche an einer der gefundenen Stellen != 0 ist
					PivotindexS[indexwalker] = col; //Nötig um die Spalte des Pivotindexes zu merken
					indexwalker++;
					signal = false;
				}
			 }
			rowwalker++; //aktuelle Zeilen weiter durchlaufen
		}
		signal = true;
		col++; //Wiederholen für nächste Spalte
	}
//Anwendung der Unformungsregeln zum Erreichen der kanonischen Form
//Beginn von unten nach oben
	int verbleibend = G.n, row2 = 0, col2 = 0;

	while (verbleibend>0) {
		col2 = 0;
		int multinverse = G.multiInverse(G.M[PivotindexZ[verbleibend]][PivotindexS[verbleibend]]); //Multiplikative inverse bestimmen für erste PV Zeile
		while ((col2+PivotindexS[verbleibend]) < (G.n)) {
			//Errechnung der Pivotzeile mit multiplikativer Inverser
			speicher[col2 + PivotindexS[verbleibend]] = G.elementMultiplikation(multinverse, G.M[PivotindexZ[verbleibend]][col2 + PivotindexS]);
		}
		G.M[PivotindexZ[verbleibend]].swap(speicher);

		//Nächster Schritt, alle Zeilen über der


		verbleibend--;
	}


	return G;
}

KoerperFq::~KoerperFq()
{
}
