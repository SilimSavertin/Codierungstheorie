#pragma once
#include <cmath>
#include <vector>
class Polynom

{
public:
	int grad;
	std::vector<int> koeff;
	int prim;
	Polynom();
	~Polynom();
};

