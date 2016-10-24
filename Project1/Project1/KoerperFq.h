#pragma once
#include <vector>

class KoerperFq
{
private:
	int q, n, k;
	std::vector<std::vector<int>> M;
	//int N[][];
public:
	KoerperFq(int q, int k, int n);
	~KoerperFq();
	void setvector();
	void printer();
	int getelement(int row, int col);
	std::vector<int> getrow(int row);
};

