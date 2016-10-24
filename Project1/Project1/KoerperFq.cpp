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

KoerperFq::~KoerperFq()
{
}
