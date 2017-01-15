#include "Polynom.h"
#include <cmath>


Polynom::Polynom()
{
}

Polynom::Polynom(int gr, std::vector<int> kf, int p)
{
	grad = gr;
	koeff = kf;
	prim = p;
}

bool istPrim(int a) {

	for (int i = 2; i < a; i++) {
		if (a%i == 0) return false;
	}
	return true;
}

void Polynom::printPoly(Polynom pol) {
	std::cout << "Grad: " << pol.grad << std::endl;
	std::cout << "Zahlenkoerper: " << pol.prim << std::endl;
	std::cout << "Vektor:" << std::endl;
	for (int i = 0; i < pol.koeff.size(); i++) {
		std::cout << pol.koeff[i] << " | ";
	}
	
}
Polynom Polynom::PolyMulti(Polynom poly1, Polynom poly2) {
	std::vector<int> containervector(1, 0);
	Polynom Container(containervector.size()-1, containervector, poly1.prim);


	for (int p1 = 0; p1 < poly1.koeff.size(); p1++) {

		std::vector<int> tmp(poly1.grad + 1 - p1 + poly2.grad, 0);
		for (int p2 = 0; p2 < poly2.koeff.size(); p2++) {
			tmp[p2] = poly1.koeff[p1] * poly2.koeff[p2];
		}
		Polynom Container2(tmp.size()-1, tmp, poly1.prim);
		Container = PolyAddition(Container, Container2);
	}
	return Container;
}

Polynom Polynom::PolyAddition(Polynom poly1, Polynom poly2) {
	std::vector<int> ergebnis;
	if (poly1.grad>poly2.grad) {
		int unterschied = poly1.grad - poly2.grad;
		std::vector<int> neuesergebnis(poly1.koeff);
		for (int i = 0; i < poly2.koeff.size(); i++) {
			neuesergebnis[i + unterschied] = (neuesergebnis[i + unterschied] + poly2.koeff[i]) % poly1.prim;
		}
		ergebnis = neuesergebnis;
	}
	else if (poly1.grad == poly2.grad) {
		std::vector<int> neuesergebnis(poly1.koeff.size(), 0);
		for (int i = 0; i < neuesergebnis.size(); i++) {
			neuesergebnis[i] = (poly1.koeff[i] + poly2.koeff[i]) % poly1.prim;
		}
		ergebnis = neuesergebnis;
	}
	else {
		int unterschied = poly2.grad - poly1.grad;
		std::vector<int> neuesergebnis(poly2.koeff);
		for (int i = 0; i < poly1.koeff.size(); i++) {
			neuesergebnis[i + unterschied] = (neuesergebnis[i + unterschied] + poly1.koeff[i]) % poly2.prim;
		}
		ergebnis = neuesergebnis;
	}
	Polynom pol(ergebnis.size()-1, ergebnis, poly1.prim);
	Polynom pols2;
	if (ergebnis.size()-1>degree(pol)) {
		ergebnis.erase(ergebnis.begin(), ergebnis.begin() + (ergebnis.size() - degree(pol)-1));
		Polynom pols(degree(pol), ergebnis, poly1.prim);
		pols2 = pols;
	}
	else {
		pols2 = pol;
	}
	return pols2;
}
int Polynom::degree(Polynom a) {
	for (int i = 0; i < a.grad; i++) {
		if (a.koeff[i] != 0) return a.grad - i;
	}
	return 0;
}


int mul_inv(int a, int b)
{
	int b0 = b, t, q;
	int x0 = 0, x1 = 1;
	if (b == 1) return 1;
	while (a > 1) {
		q = a / b;
		t = b, b = a % b, a = t;
		t = x0, x0 = x1 - q * x0, x1 = t;
	}
	if (x1 < 0) x1 += b0;
	return x1;
}
inline int modulo(int a, int b) {
	const int result = a % b;
	return result >= 0 ? result : result + b;
}
Polynom Polynom::reduktion(Polynom a, Polynom f) {
	Polynom zureduzieren = a;
	Polynom reduzierenmit = f;

	while (degree(zureduzieren) >= degree(reduzierenmit)) {
		std::vector<int> zwischenpolynomkoeff(degree(zureduzieren)-degree(reduzierenmit)+1,0);
		int auslagern1 = modulo((-zureduzieren.koeff[zureduzieren.grad - degree(zureduzieren)]),zureduzieren.prim);
		int auslagern2 = (mul_inv(reduzierenmit.koeff[0], reduzierenmit.prim));
		zwischenpolynomkoeff[0] = modulo(auslagern1*auslagern2,reduzierenmit.prim);

		Polynom zwischending(degree(zureduzieren) - degree(reduzierenmit), zwischenpolynomkoeff, a.prim);

		Polynom test = PolyMulti(zwischending, reduzierenmit);

		zureduzieren = PolyAddition(zureduzieren,test);
	}

	return zureduzieren;

}



Polynom::~Polynom()
{
}
