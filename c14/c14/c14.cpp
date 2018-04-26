/*
Chapter 14 Homework
Thomas Szymczak
CIT-245
10/15/2017
Make classes to represent firearms to demonstrate inheritance.
*/

#include "gun.h"
#include "handgun.h"
#include "pistol.h"
#include "revolver.h"

int main() {
	const int numGuns = 2;
	Gun gunCabinet[numGuns];

	Revolver sw("Smith & Wesson", "0.357", "hoague", "Trijicon", true, false, 6);
	Pistol glock("Glock", "9mm", "manufacturers", "3 dot", false, true);

	sw.print();
	glock.print();

	system("pause");
	return 0;
}