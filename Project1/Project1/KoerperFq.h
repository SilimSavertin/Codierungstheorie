#pragma once
#include <vector>

class KoerperFq
{
public:
	int q, n, k;
	std::vector<std::vector<int>> M;
	//int N[][];
	KoerperFq(int q, int k, int n);
	~KoerperFq();
	void setvector();
	void printer();
	int getelement(int row, int col);
	std::vector<int> getrow(int row);
	int elementAddition(int a, int b);
	int elementMultiplikation(int a, int b);
	int additiveInverse(int a);
	int multiInverse(int a);
	KoerperFq kanon(KoerperFq G);
	int getn();
	int getk();
};

