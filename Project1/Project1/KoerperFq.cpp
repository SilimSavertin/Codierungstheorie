#include "KoerperFq.h"
#include <iostream>


KoerperFq::KoerperFq(int q, int k, int n)
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
		//M.push_back
		//this->M.push_back(new std::vector<int>);
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
	int col = 0, row = 0;
	std::vector<int> speicher(n);


	while (col < G.getn) {
		




		col++;
	}
}

KoerperFq::~KoerperFq()
{
}
