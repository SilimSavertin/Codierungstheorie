#include "KoerperFq.h"
#include <iostream>


KoerperFq::KoerperFq(int q, int k, int n) //q Dimension, k Zeilen, n Spalten
{
	this->q = q; //Dimension
	this->k = k; //Zeilen
	this->n = n; //Spalten
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

void KoerperFq::printerH() {
	int i = 0, j = 0;
	std::cout << std::endl;
	int rows = H.size();
	int cols = 0;
	if (rows > 0)
		cols = H[0].size();
	while (i < rows) {
		while (j < cols) {
			std::cout << H[i][j] << " ";
			j++;
		}
		j = 0;
		std::cout << std::endl;
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



std::vector<std::vector<int>> KoerperFq::kontroll(KoerperFq G) {
	std::vector<std::vector<int>> M(G.M);
	int col = 0, row = 0, rowwalker = 0, indexwalker = 0;
	std::vector<int> PivotindexZ;
	std::vector<int> PivotindexS;
	std::vector<int> NichtPivotindexS;
	int anzPivot = 0;
	std::vector<std::vector<int>> H;

	M = G.kanon(G);

	while (col < G.getn()) {
		row = rowwalker;
		while (row < G.getk()) {

			if (M[row][col] != 0) {
				PivotindexZ.push_back(row);
				PivotindexS.push_back(col);
				//std::cout << "Zeile: " << row << std::endl;
				//std::cout << "Spalte: " << col << std::endl;
				anzPivot++;
				rowwalker = row + 1;
				row = G.getk(); //Verlasse aktuelle Zeilenschleife und gehe zur n‰chsten Zeile

			}
			/*else {
				NichtPivotindexS.push_back(col);
			}*/
			row++;
		}
		col++;
	}

	int anzNichtPivot = G.getn()-anzPivot;
	this->anzPivot = anzPivot;
	int z = 0;
	col = 0;
	bool nichtpivot = true;
	while (col < G.getn()) {
		nichtpivot = true;
		z = 0;
		while (z < anzPivot) {
			if (PivotindexS[z] == col) nichtpivot = false; 
			z++;
		}
		if (nichtpivot == true) {
			NichtPivotindexS.push_back(col);
		}
		col++;
	}

	

	col = 0;

	while (col < NichtPivotindexS.size()) {
		int rows = 0;
		std::vector<int> h(G.getn(),0);
		while (rows < PivotindexZ.size()) {
			h[PivotindexS[rows]] = M[rows][NichtPivotindexS[col]];
			rows++;
		}
		h[NichtPivotindexS[col]] = G.additiveInverse(1);
		H.push_back(h);
		col++;
	}
	std::vector<std::vector<int>> HT;

	int cols = 0, rows = 0;

	while (cols < H[0].size()) {

		std::vector<int> rowT;
		rows = 0;
		while (rows < H.size()) {

			rowT.push_back(H[rows][cols]);
			rows++;
		}
		HT.push_back(rowT);
		cols++;
	}
	this->HT = HT;
	
	return H;
}



std::vector<std::vector<int>> KoerperFq::kanon(KoerperFq G) {
	int col = 0, row = 0, rowwalker = 0, indexwalker = 0;
	bool signal = false;
	std::vector<std::vector<int>> M(G.M);	
	std::vector<int> speicher(n);

//Tauschalgorithmus zur Ordnung der Matrix nach Vertauschungsregel
	while (col < G.getn()) {
		rowwalker = row; //Startpunkt des Matrixdurchlaufs festlegen
		while (rowwalker < G.getk()) {

			if ((M[rowwalker][col] != 0)) {
				M[row].swap(M[rowwalker]); //Tausche Inhalt von aktuellem Startpunkt mit gefundener Zeile die unterschiedlich von 0 ist
				if (row != rowwalker) {
					signal = true;
				}
				row++; //N‰chster Start sollte eine Zeile ¸berspringen hiermit, sollte bei n‰chstem Swap in selber Zeile auch daf¸r sorgen den letzten Swap nicht r¸ckg‰ngig zu machen
				
			}
			rowwalker++; //aktuelle Zeilen weiter durchlaufen
		}
		col++; //Wiederholen f¸r n‰chste Spalte
	}
	
//Anwendung der Unformungsregeln zum Erreichen der kanonischen Form
//Beginn von unten nach oben benˆtigt! Abgekl‰rt in Vorlesung
	int row2 = 0, col2 = 0, rowwalker2=0;
	std::vector<int> PivotindexZ;
	std::vector<int> PivotindexS;
	int anzPivot = 0;
//Pivotelemente bestimmen: Gehe von links oben, Spaltenweise. Finde an Punkt oben links !=0, dann lege als Pivotelement fest.
	//Z‰hle hoch Spalte und Zeile (Matrixreduktion) und fange wieder oben links an mit der Suche, gehe durch Spalte bis !=0
	//Z‰hle Spalte hoch wenn gefunden und ignoriere alle Zeilen bis einschlieﬂlich gefundener (Matrixreduktion)
	//Wiederhole bis alle Pivotelemente gefunden

	while (col2 < G.getn()) {
		row2 = rowwalker2;
		while (row2 < G.getk()) {

			if (M[row2][col2] != 0) {
				PivotindexZ.push_back(row2);
				PivotindexS.push_back(col2);
				std::cout << "Zeile: " << row2 << std::endl;
				std::cout << "Spalte: " << col2 << std::endl;
				anzPivot++;
				//rowwalker2 = row2+1;
				int uberspringen = 0;
				int row3 = row2;
				while ((row3 + 1 < M.size()) && (M[row3+1][col2]!=0)) {
					uberspringen++;					
					row3++;
				}
				rowwalker2 = row2 + 1 + uberspringen;
				row2 = G.getk(); //Verlasse aktuelle Zeilenschleife und gehe zur n‰chsten Zeile
				
			}
			row2++;
		}
		col2++;
	}
	this->anzPivot = anzPivot;
	//return M;
	//Umformung in kanonische Form nun, da Position von Pivotelementen bekannt. Unten nach oben MUSS gemacht werden!

	int pivotL = anzPivot-1;
	
	while (pivotL >= 0) {

		int col3 = PivotindexS[pivotL];
		int rowM = PivotindexZ[pivotL];

		while (col3 < G.getn()) { //Pivotelement wird auf 1 gesetzt durch Multiplikation mit Inversem
			M[rowM][col3] = G.elementMultiplikation(M[rowM][col3],G.multiInverse(M[PivotindexZ[pivotL]][PivotindexS[pivotL]]));
			col3++;
		}

		int row3 = PivotindexZ[pivotL]+1, row4=PivotindexZ[pivotL]-1;
		col3 = PivotindexS[pivotL];
		while (row3 < G.getk()) {
			col3 = PivotindexS[pivotL];
			int addInvers = G.additiveInverse(M[row3][col3]);
			while (col3 < G.getn()) {
				if (M[row3][PivotindexS[pivotL]] != 0) {
					signal = true;
				}
				M[row3][col3] = G.elementAddition((M[row3][col3]),(G.elementMultiplikation((addInvers),(M[PivotindexZ[pivotL]][col3]))));
				col3++;
			}
			row3++;
		}

		while (row4 >= 0) {
			col3 = PivotindexS[pivotL];
			int addInvers = G.additiveInverse(M[row4][col3]);
			while (col3 < G.getn()) {
				if (M[row4][PivotindexS[pivotL]] != 0) {
					signal = true;
				}
				M[row4][col3] = G.elementAddition((M[row4][col3]), (G.elementMultiplikation((addInvers), (M[PivotindexZ[pivotL]][col3]))));
				col3++;
			}
			row4--;
		}


		pivotL--;
	}
	if (signal == true) {
		KoerperFq G2(G.q,G.k,G.n);
		G2.M = M;
		G2.kanon(G2);
	}

	return M;
}

KoerperFq::~KoerperFq()
{
}
