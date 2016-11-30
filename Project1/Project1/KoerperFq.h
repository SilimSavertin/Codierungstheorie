#ifndef KOERPERFQ_H_
#define KOERPERFQ_H_

#include <vector>

class Cell {
public:
	int row;
	int col;
	Cell(int row, int col);
};

class KoerperFq
{
private:
	std::vector< std::vector<int> > zusammenRM(std::vector< std::vector<int> > Moben, std::vector< std::vector<int> >Munten);
public:
	int q, n, k,anzPivot=0;
	std::vector< std::vector<int> > M;
	std::vector< std::vector<int> > Mkanon;
	std::vector< std::vector<int> > H;
	std::vector< std::vector<int> > HT;
	std::vector< std::vector<int> > Hemm;
	std::vector< std::vector<int> > Syndromtbl; //Vektor e1-whatever
	std::vector< std::vector<int> > SyndromtblE; //e*HT
	void printMatrik(std::vector< std::vector<int> > M);
	KoerperFq(int q, int k, int n);
	~KoerperFq();
	void setvector();
	void printM();
	void printMkanon();
	void printH();
	void printHT();
	void print();

	int getelement(int row, int col);
	std::vector<int> getrow(int row);
	int elementAddition(int a, int b);
	int elementMultiplikation(int a, int b);
	int additiveInverse(int a);
	int multiInverse(int a);
	std::vector<int> Nachfolger(std::vector<int> g, int pos);
	std::vector<int> hemmingFehler(std::vector< std::vector<int> > Hem, std::vector<int> VektorY);
	std::vector< std::vector<int> > Paritaet(std::vector< std::vector<int> > Matrix);
	std::vector< std::vector<int> > RM(int m, int t);
	std::vector< std::vector<int> > kanon(KoerperFq G);
	std::vector< std::vector<int> > kontroll(KoerperFq G);
	std::vector<int> VektorMultMatrix(std::vector<int> ein, std::vector<std::vector<int>> M);
	std::vector< std::vector<int> > Hemming(int q, int n, int k);
	std::vector< std::vector<int> > trans(std::vector< std::vector<int> > H);
	void BestimmeSyndromtabelle();
	std::vector<int> Vektoraddition(std::vector<int> a, std::vector<int> b);
	int getn();
	int getk();
	std::vector<Cell> getPivotElements(std::vector< std::vector<int> > M);
	std::vector<int> getNichtPivotElements(std::vector<Cell> pivotElements, int colSize);
	std::vector< std::vector<int> > getCheckedH();
	bool checkH();
	//std::vector< std::vector<int> > syndrom(KoerperFq G, int colSize);
};

#endif /* KOERPERFQ_H_ */
