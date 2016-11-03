#include "KoerperFq.h"
#include <iostream>
using namespace std;

void main() {
	int a;
	cout << "W�hlen Sie bitte einer der Optionen:" << endl;
	cout << "	1: F3 [6,3]" << endl;
	cout << "		0 1 1 0 1 2" << endl;
	cout << "		1 0 1 1 2 1" << endl;
	cout << "		0 0 0 1 1 1" << endl;
	cout << "	2: F3 [6,3]" << endl;
	cout << "		0 1 1 0 1 2" << endl;
	cout << "		1 0 1 1 2 1" << endl;
	cout << "		2 0 0 1 1 1" << endl;
	cout << "	3: F4 [5,3]" << endl;
	cout << "		1 0 3 0 1" << endl;
	cout << "		0 1 1 0 1" << endl;
	cout << "		0 0 0 1 2" << endl;
	cout << "	4: F2 [5,2]" << endl;
	cout << "		1 1 0 1 0" << endl;
	cout << "		0 1 0 1 0" << endl;
	cout << "	Sonst: eigene Eingabe" << endl;
	cout << "Option: ";
	cin >> a;

	int q, k, n;
	vector< vector<int> > M;
	bool setown = false;
	switch(a) {
		case 1: {
			q = 3;
			k = 3;
			n = 6;
			vector<int> z(n, 0);
			z[0] = 0;
			z[1] = 1;
			z[2] = 1;
			z[3] = 0;
			z[4] = 1;
			z[5] = 2;
			M.push_back(z); // Zeile 1
			z[0] = 1;
			z[1] = 0;
			z[2] = 1;
			z[3] = 1;
			z[4] = 2;
			z[5] = 1;
			M.push_back(z); // Zeile 2
			z[0] = 0;
			z[1] = 0;
			z[2] = 0;
			z[3] = 1;
			z[4] = 1;
			z[5] = 1;
			M.push_back(z); // Zeile 3
			break;
		}
		case 2: {
			q = 3;
			k = 3;
			n = 6;
			vector<int> z(n, 0);
			z[0] = 1;
			z[1] = 0;
			z[2] = 2;
			z[3] = 0;
			z[4] = 1;
			M.push_back(z); // Zeile 1
			z[0] = 0;
			z[1] = 1;
			z[2] = 1;
			z[3] = 0;
			z[4] = 1;
			M.push_back(z); // Zeile 2
			z[0] = 0;
			z[1] = 0;
			z[2] = 0;
			z[3] = 1;
			z[4] = 2;
			M.push_back(z); // Zeile 3
			break;
		}
		case 3: {
			q = 4;
			k = 3;
			n = 5;
			vector<int> z(n, 0);
			z[0] = 0;
			z[1] = 1;
			z[2] = 1;
			z[3] = 0;
			z[4] = 1;
			z[5] = 2;
			M.push_back(z); // Zeile 1
			z[0] = 1;
			z[1] = 0;
			z[2] = 1;
			z[3] = 1;
			z[4] = 2;
			z[5] = 1;
			M.push_back(z); // Zeile 2
			z[0] = 2;
			z[1] = 0;
			z[2] = 0;
			z[3] = 1;
			z[4] = 1;
			z[5] = 1;
			M.push_back(z); // Zeile 3
			break;
		}
		case 4: {
			q = 4;
			k = 2;
			n = 5;
			vector<int> z(n, 0);
			z[0] = 1;
			z[1] = 1;
			z[2] = 0;
			z[3] = 1;
			z[4] = 0;
			M.push_back(z); // Zeile 1
			z[0] = 1;
			z[1] = 0;
			z[2] = 1;
			z[3] = 0;
			z[4] = 1;
			M.push_back(z); // Zeile 2
			break;
		}
		default: {
			cout << endl << "q: ";
			cin >> q;
			cout << endl << "k: ";
			cin >> k;
			cout << endl << "n: ";
			cin >> n;
		}
	}

	KoerperFq testelement(q, k, n); //3 K�rper, 3 Zeilen, 6 Spalten
	if (setown) {
		testelement.setvector();
	} else {
		testelement.M = M;
	}
	testelement.Mkanon =testelement.kanon(testelement);
	testelement.H = testelement.kontroll(testelement);
	testelement.print();
	std::cin >> a;
}
