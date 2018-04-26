#pragma warning(disable: 4996)
#include <string>
#include <iostream>
#include "pistol.h"
using namespace std;


Pistol::Pistol() {
	semiAuto = false;
}

Pistol::Pistol(string inManufacturer, string inCaliber, string inGrips, string inSights, bool inLaser, bool inSemiAuto) {
	setManufacturer(inManufacturer);
	setCaliber(inCaliber);
	setGrips(inGrips);
	setSights(inSights);
	setLaser(inLaser);
	semiAuto = inSemiAuto;
}

void Pistol::setSemiAuto(bool input) {
	semiAuto = input;
}

bool Pistol::getSemiAuto() {
	return semiAuto;
}

void Pistol::print() {
	cout << "Pistol: " << getManufacturer() << ", ";
	cout << getCaliber() << ", ";
	if (getSemiAuto())
		cout << "semi-auto, ";
	else
		cout << "no semi-auto, ";
	cout << getGrips() << " grips, ";
	if (getLaser())
		cout << "laser, ";
	else
		cout << "no laser, ";
	cout << getSights() << endl;
}