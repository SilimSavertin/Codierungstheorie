#pragma once
#include <cmath>
#include <vector>
#include <iostream>
class Polynom

{
public:
	int grad;
	std::vector<int> koeff;
	int prim;
	Polynom();
	Polynom(int g, std::vector<int> kf, int p);
	Polynom reduktion(Polynom a, Polynom f);
	~Polynom();
	void printPoly(Polynom pol);
	Polynom PolyMulti(Polynom poly1, Polynom poly2);
	Polynom PolyAddition(Polynom poly1, Polynom poly2);
	int degree(Polynom a);
	//Polynom PolyAddition(Polynom poly1, Polynom poly2);
};

