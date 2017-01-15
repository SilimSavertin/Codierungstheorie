#include "KoerperFq.h"
#include <iostream>
#include <string.h>
#include <math.h>
#include <string>

Cell::Cell(int row = 0, int col = 0) {
	this->row = row;
	this->col = col;
}

KoerperFq::KoerperFq(int q, int k, int n) //q Dimension, k Zeilen, n Spalten
{
	this->q = q; //Dimension
	this->k = k; //Zeilen
	this->n = n; //Spalten
	//this->M = new std::vector<std::vector<int>>(k);
	
}

void KoerperFq::printMatrik(std::vector< std::vector<int> > M) {
	for (int row = 0; row < M.size(); row++) {
		std::cout << "	";
		for (int col = 0; col < M[row].size(); col++) {
			std::cout << M[row][col] << " ";
		}
		std::cout << std::endl;
	}
}

bool KoerperFq::checkH() {
	int sum=0;

	for (int gz = 0; gz < this->Mkanon.size(); gz++) {
		for (int hts = 0; hts < this->HT[0].size(); hts++) {
			int wert = 0;
			for (int gs = 0; gs < this->Mkanon[gz].size(); gs++) {
				wert = this->elementAddition(wert, this->elementMultiplikation(this->Mkanon[gz][gs], this->HT[gs][hts]));
			}
			sum += wert;
		}
	}

	return (sum == 0);
}

std::vector< std::vector<int> > KoerperFq::getCheckedH() {
	std::vector< std::vector<int> > Ergebnis;

	for (int gz = 0; gz < this->Mkanon.size(); gz++) {
		std::vector<int> ErgebnisZ;
		for (int hts = 0; hts < this->HT[0].size(); hts++) {
			int wert = 0;
			for (int gs = 0; gs < this->Mkanon[gz].size(); gs++) {
				wert = this->elementAddition(wert, this->elementMultiplikation(this->Mkanon[gz][gs], this->HT[gs][hts]));
			}
			ErgebnisZ.push_back(wert);
		}
		Ergebnis.push_back(ErgebnisZ);
	}

	return Ergebnis;
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

void KoerperFq::printM() {
	std::cout <<  "Koerper:" << std::endl;
	this->printMatrik(this->M);
}

void KoerperFq::printMkanon() {
	std::cout <<  "Koerper kanonisch:" << std::endl;
	this->printMatrik(this->Mkanon);
}

void KoerperFq::printH() {
	std::cout <<  "Kontrolmatrix H:" << std::endl;
	this->printMatrik(this->H);
}

void KoerperFq::printHT() {
	std::cout <<  "transponierte Kontrolmatrix H:" << std::endl;
	this->printMatrik(this->HT);
}

void KoerperFq::print() {
	std::cout << "/***************************************/" << std::endl;
	std::cout << "q (Raum)   : " << this->q << std::endl;
	std::cout << "k (Zeilen) : " << this->k << std::endl;
	std::cout << "n (Spalten): " << this->n << std::endl;
	this->printM();
	std::cout << std::endl;
	this->printMkanon();
	std::cout << std::endl;
	std::vector<Cell> pivots = this->getPivotElements(this->Mkanon);
	std::cout << "Pivot = {";
	std::string tmp = "";
	for (int idx = 0; idx < pivots.size(); idx++) {
		std::cout << tmp << "([" << pivots[idx].row << "][" << pivots[idx].col << "])";
		tmp = ", ";
	}
	std::cout << "}" << std::endl << std::endl;
	std::vector<int> npivots = this->getNichtPivotElements(pivots, this->n);
	std::cout << "Nicht pivot Spalten = {";
	tmp = "";
	for (int idx = 0; idx < npivots.size(); idx++) {
		std::cout << tmp << npivots[idx];
		tmp = ", ";
	}
	std::cout << "}" << std::endl << std::endl;
	this->printH();
	std::cout << std::endl;
	this->printHT();
	std::cout << std::endl;
	std::cout << "Die Kontrolmatrix ist ";
	if (this->checkH() == false) {
		std::cout << "nicht ";
	}
	std::cout << "eine Generatormatrix des dualen Codes" << std::endl;
	this->printMatrik(this->getCheckedH());
	std::cout << std::endl;
	std::cout << "/***************************************/" << std::endl;
	std::cout << "Die Syndromtabelle ist:" << std::endl;
	
	for (int i = 0; i < Syndromtbl.size();i++) {
		std::cout << "e" << i << "*H^T ";
		for (int j=0; j < SyndromtblE[i].size(); j++) {
			std::cout << SyndromtblE[i][j];
		}
		std::cout << " ;Mit e" << i << " von: ";
		for (int k=0; k < Syndromtbl[i].size(); k++) {
			std::cout<< Syndromtbl[i][k];
		}
		std::cout << std::endl;
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

std::vector<Cell> KoerperFq::getPivotElements(std::vector< std::vector<int> > M) {
	std::vector<Cell> result;
	//Pivotelemente bestimmen: Gehe von links oben, Spaltenweise. Finde an Punkt oben links !=0, dann lege als Pivotelement fest.
	//Zähle hoch Spalte und Zeile (Matrixreduktion) und fange wieder oben links an mit der Suche, gehe durch Spalte bis !=0
	//Zähle Spalte hoch wenn gefunden und ignoriere alle Zeilen bis einschlie�lich gefundener (Matrixreduktion)
	//Wiederhole bis alle Pivotelemente gefunden
	int sizeCols = 0;
	int sizeRows = M.size();
	if (sizeRows > 0) {
		sizeCols = M[0].size();
	}
	int rowwalker = 0;
	for (int col = 0; col < sizeCols; col++) {
		for (int row = rowwalker; row < sizeRows; row++) {
			if (M[row][col] != 0) {
				result.push_back(Cell(row, col));
				int uberspringen = 0;
				int nextRow = row + 1;
				while ((nextRow < sizeRows) && (M[nextRow][col] != 0)) {
					uberspringen++;
					nextRow++;
				}
				rowwalker = row + 1 + uberspringen;
				break; //Verlasse aktuelle Zeilenschleife und gehe zur nächsten Zeile

			}
		}
	}
	return result;
};

std::vector<int> KoerperFq::getNichtPivotElements(std::vector<Cell> pivotElements, int colSize) {
	std::vector<int> result;
	int idx = 0;
	for(int col = 0; col < colSize; col++) {
		if ((idx<pivotElements.size())&&(pivotElements[idx].col == col)) {
			idx++;
		} else {
			result.push_back(col);
		}
	}
	return result;
}

std::vector<int> KoerperFq::VektorMultMatrix(std::vector<int> ein, std::vector<std::vector<int>> M) {
	
	std::vector<int> ergebnis(M[0].size(),0);

	for (int i = 0; i < M[0].size(); i++) {

		for (int j = 0; j < ein.size(); j++) {

			ergebnis[i] = elementAddition(ergebnis[i], elementMultiplikation(ein[j],M[j][i]));

		}

	}

	return ergebnis;

}

std::vector<int> KoerperFq::Vektoraddition(std::vector<int> a, std::vector<int> b) {
	std::vector<int> ergebnis(a.size(), 0);
	for (int i=0; i < a.size(); i++) {
		ergebnis[i] = elementAddition(a[i], b[i]);
	}
	return ergebnis;
}

void KoerperFq::BestimmeSyndromtabelle() {

	int SyndromAnzahl = pow(this->q, (this->n-this->k));
	int syndromzaehler = 0;
	
	std::vector< std::vector<int> > moglichesSyndrom;
	std::vector<int> n(this->n, 0);
	moglichesSyndrom.push_back(n);
	//Erstelle alle Vektoren, die sich nur an einer Stelle vom Nullvektor unterscheiden
	for (int j = 1; j < this->q; j++) {

		for (int i = 0; i < this->n; i++) {
			
			std::vector<int> moglicherSyndromVector(this->n, 0);
			moglicherSyndromVector[i] = j;
			moglichesSyndrom.push_back(moglicherSyndromVector);

		}
	}
	


		for (int i = 0; i < moglichesSyndrom.size(); i++) {

			//testen ob neues SyndromElement
			bool istsyndrom = true;

			if (this->SyndromtblE.empty() == false) {
				std::vector<int> ergebnis(this->HT[0].size(),0);
				ergebnis = VektorMultMatrix(moglichesSyndrom[i], this->HT);
				for (int k = 0; k < SyndromtblE.size(); k++) {
					if (ergebnis == SyndromtblE[k]) {
						istsyndrom = false;
					}
				}
				if (istsyndrom == true) {
					this->SyndromtblE.push_back(ergebnis);
					this->Syndromtbl.push_back(moglichesSyndrom[i]);
					syndromzaehler++;
				}
			}

			else {
				this->Syndromtbl.push_back(moglichesSyndrom[i]);
				this->SyndromtblE.push_back(VektorMultMatrix(moglichesSyndrom[i], this->HT));
				syndromzaehler++;
			}

			//erzeuge weitere mögliche Vektoren zur Syndromgenerierung
			for (int j = 0; j < moglichesSyndrom.size(); j++) {
				if ((moglichesSyndrom[i]==moglichesSyndrom[j])==false) {
					std::vector<int> ablage(this->n, 0);
					ablage = Vektoraddition(moglichesSyndrom[i], moglichesSyndrom[j]);
					bool istneu = true;
					for (int g = 0; g < moglichesSyndrom.size(); g++) {
						if ((ablage == moglichesSyndrom[g]) == true) {
							istneu = false;
						}
					}
					if (istneu == true) {
						moglichesSyndrom.push_back(ablage);
					}
				}
			}
		
			//falls alle Syndrome gefunden, verlasse Schleife
			if (syndromzaehler == SyndromAnzahl) {
				break;
			}
		}


}

/*std::vector< std::vector<int> > FindeSyndrome(std::vector< std::vector<int> > vorherige, int index) {

	std::vector< std::vector<int> > zwischenspeicher(vorherige);
	int naechsterindex = 0;

	for (int i = 0; i < index; i++) {



	}

}*/



std::vector<int> KoerperFq::Nachfolger(std::vector<int> g, int pos) {

	std::vector<int> neuerVektor(g);
	
	if (g[pos] < (this->q - 1)) {
		neuerVektor[pos]++;
	}
	else {
		neuerVektor[pos] = 0;
		neuerVektor = Nachfolger(neuerVektor, (pos - 1));
	}
	return neuerVektor;

}

std::vector< std::vector<int> > KoerperFq::RM(int m, int t) {
	if (t > m ) {
		t = m;
	}
	std::vector< std::vector<int> > r;
	if (t == 0) {
		std::vector<int> einser(pow(2, m), 1);
		r.push_back(einser);
	}
	else if (m == 0) {		
		std::vector<int> eins(1, 1);
		r.push_back(eins);
	}
	else {
		r = zusammenRM(RM(m - 1, t), RM(m - 1, t - 1));
	}
	return r;
}

std::vector< std::vector<int> > KoerperFq::zusammenRM(std::vector< std::vector<int> > Moben, std::vector< std::vector<int> >Munten) {
	std::vector< std::vector<int> > ergebnis;
	std::vector<int> Zeile;
	for (int i = 0; i < Moben.size(); i++) {
		std::vector<int> Zeile;
		Zeile = Moben[i];
		
		for (int j = 0; j < Moben[i].size(); j++) {
			Zeile.push_back(Moben[i][j]);
		}
		ergebnis.push_back(Zeile);
	}
	for (int i = 0; i < Munten.size(); i++) {
		std::vector<int> Zeile(Munten[i].size(), 0);

		for (int j = 0; j < Munten[i].size(); j++) {
			Zeile.push_back(Munten[i][j]);
		}
		ergebnis.push_back(Zeile);
	}
	return ergebnis;
}

std::vector< std::vector<int> > KoerperFq::Hemming(int q, int n, int k) {
	int m = n - k;
	std::vector< std::vector<int> > ergebnis;
	int anzEq = ((pow(q,m)-1)/(q-1));

	//bestimme Aequivalenzklassen

	for (int i = m-1; i >= 0; i--) {
		std::vector<int> speicher(m, 0);

		speicher[i] = 1;
		//ergebnis.push_back(speicher);
		while (speicher[i] == 1) {
			ergebnis.push_back(speicher);
			speicher = Nachfolger(speicher, speicher.size() - 1);	
		}
	}	
	ergebnis = trans(ergebnis);
	printMatrik(ergebnis);
	return ergebnis;

}

std::vector<int> KoerperFq::hemmingFehler(std::vector< std::vector<int> > Hem, std::vector<int> VektorY) {

	std::vector< std::vector<int> > HemT(trans(Hem));

	std::vector<int> synd(VektorMultMatrix(VektorY,HemT));
	std::vector<int> NullVektor(synd.size(), 0);
	if (synd == NullVektor) return VektorY;
	int skalar=1;
	for (int i = 0; i < synd.size(); i++) {
		if (synd[i] != 0) {
			skalar = multiInverse(synd[i]);
			i = synd.size();
		}
	}
	for (int j = 0; j < synd.size(); j++) {
		synd[j] = elementMultiplikation(skalar, synd[j]);
	}
	int SpaltenNr = 0;
	for (int k = 0; k < HemT.size(); k++) {
		if (HemT[k] == synd) {
			SpaltenNr = k;
		}
	}

	VektorY[SpaltenNr] = elementAddition(VektorY[SpaltenNr], additiveInverse(skalar));
	return VektorY;
}

std::vector< std::vector<int> > KoerperFq::Paritaet(std::vector< std::vector<int> > Matrix) {
	int xi = 0;
	//std::vector<int> erw(Matrix[0].size(), 0);

	for (int i = 0; i < Matrix.size(); i++) {
		xi = 0;
		for (int j = 0; j < Matrix[i].size(); j++) {
			xi = elementAddition(xi, Matrix[i][j]);
		}
		Matrix[i].push_back(additiveInverse(xi));
	}
	return Matrix;
}


std::vector< std::vector<int> > KoerperFq::kontroll(KoerperFq G) {
	std::vector< std::vector<int> > M;
	M = G.kanon(G);

	int col = 0, row = 0, rowwalker = 0, indexwalker = 0;
	std::vector<int> PivotindexZ;
	std::vector<int> PivotindexS;
	std::vector<int> NichtPivotindexS;
	int anzPivot = 0;
	std::vector< std::vector<int> > H;


	while (col < G.getn()) {
		row = rowwalker;
		while (row < G.getk()) {

			if (M[row][col] != 0) {
				PivotindexZ.push_back(row);
				PivotindexS.push_back(col);
				anzPivot++;
				rowwalker = row + 1;
				row = G.getk(); //Verlasse aktuelle Zeilenschleife und gehe zur n�chsten Zeile

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
	std::vector< std::vector<int> > HT;

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

std::vector< std::vector<int> > KoerperFq::trans(std::vector< std::vector<int> > H) {

	std::vector< std::vector<int> > HT;

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
	return HT;

}

std::vector< std::vector<int> > KoerperFq::kanon(KoerperFq G) {
	int rowwalker = 0;
	bool signal = false;
	std::vector< std::vector<int> > M(G.M);
	std::vector<int> speicher(n);

	//Tauschalgorithmus zur Ordnung der Matrix nach Vertauschungsregel
	for (int col = 0; col < G.getn(); col++) {
		for (int row = rowwalker; row < G.getk(); row++) {
			if ((M[row][col] != 0)) {
				M[rowwalker].swap(M[row]); //Tausche Inhalt von aktuellem Startpunkt mit gefundener Zeile die unterschiedlich von 0 ist
				if (row != rowwalker) {
					signal = true;
				}
				rowwalker++; //N�chster Start sollte eine Zeile �berspringen hiermit, sollte bei n�chstem Swap in selber Zeile auch daf�r sorgen den letzten Swap nicht r�ckg�ngig zu machen
			}
		}
	}
	
//Anwendung der Unformungsregeln zum Erreichen der kanonischen Form
//Beginn von unten nach oben ben�tigt! Abgekl�rt in Vorlesung
	std::vector<Cell> PivotElements = this->getPivotElements(M);
	this->anzPivot = PivotElements.size();
	//return M;
	//Umformung in kanonische Form nun, da Position von Pivotelementen bekannt. Unten nach oben MUSS gemacht werden!
	for (int pivotL = this->anzPivot-1; pivotL >= 0; pivotL--) {
		Cell pivotE = PivotElements[pivotL];

		// Pivotelement auf 1 setzten (mittels Multiplativen inversen)
		if (M[pivotE.row][pivotE.col] > 1) {
			for (int col = pivotE.col; col < G.getn(); col++) {
				M[pivotE.row][col] = G.elementMultiplikation(M[pivotE.row][col], G.multiInverse(M[pivotE.row][pivotE.col]));
			}
		}

		// Alle Spaltenelemente unter dem Pivotelement Nullen
		for (int nextRow = (pivotE.row + 1); nextRow < G.getk(); nextRow++) {
			if (M[nextRow][pivotE.col] != 0) {
				signal = true;
				int addInvers = G.additiveInverse(M[nextRow][pivotE.col]);
				for (int col = 0; col < G.getn(); col++) {
					M[nextRow][col] = G.elementAddition(M[nextRow][col], G.elementMultiplikation(addInvers, M[pivotE.row][col]));
				}
			}
		}

		// Alle Spaltenelemente über dem Pivotelement Nullen
		for (int prevRow = (pivotE.row - 1); prevRow >= 0; prevRow--) {
			if (M[prevRow][pivotE.col] != 0) {
				signal = true;
				int addInvers = G.additiveInverse(M[prevRow][pivotE.col]);
				for (int col = 0; col < G.getn(); col++) {
					M[prevRow][col] = G.elementAddition(M[prevRow][col], G.elementMultiplikation(addInvers, M[pivotE.row][col]));
				}
			}
		}
	}
	if (signal) {
		KoerperFq G2(G.q,G.k,G.n);
		G2.M = M;
		M = G2.kanon(G2);
	} else {
		this->Mkanon = M;
	}

	return M;
}

/*std::vector< std::vector<int> > KoerperFq::syndrom(KoerperFq G, int colSize) {
	int anz = pow(G.q, (G.n - G.k));
}*/

KoerperFq::~KoerperFq()
{
}
