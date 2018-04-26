/*
Chapter 15 Homework
Thomas Szymczak
CIT-245
10/22/2017
Make classes to represent firearms to demonstrate polymorphism.
*/

#include "gun.h"
#include "handgun.h"
#include "pistol.h"
#include "revolver.h"

int main() {
	const int numGuns = 2;
	Gun *gunCabinet[numGuns];

	gunCabinet[0] = new Revolver("Smith & Wesson", "0.357", "hoague", "Trijicon", true, false, 6);
	gunCabinet[1] = new Pistol("Glock", "9mm", "manufacturers", "3 dot", false, true);

	cout << "My Gun Cabinet Contains:" << endl;
	for (int i = 0; i < numGuns; i++) {
		gunCabinet[i]->print();
	}

	system("pause");
	return 0;
}