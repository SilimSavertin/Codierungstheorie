#pragma once
#include <vector>

class KoerperFq
{
public:
	int q, n, k,anzPivot=0;
	std::vector<std::vector<int>> M;
	std::vector<std::vector<int>> H;
	std::vector<std::vector<int>> HT;
	//int N[][];
	KoerperFq(int q, int k, int n);
	~KoerperFq();
	void setvector();
	void printer();
	void printerH();

	int getelement(int row, int col);
	std::vector<int> getrow(int row);
	int elementAddition(int a, int b);
	int elementMultiplikation(int a, int b);
	int additiveInverse(int a);
	int multiInverse(int a);
	std::vector<std::vector<int>> kanon(KoerperFq G);
	std::vector<std::vector<int>> kontroll(KoerperFq G);
	int getn();
	int getk();
};

