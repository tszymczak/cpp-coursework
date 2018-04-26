#pragma warning(disable: 4996)
#include <string>
#include <iostream>
#include "revolver.h"
using namespace std;

Revolver::Revolver() {
	singleAction = false;
	numberOfRounds = 0;
}

Revolver::Revolver(string inManufacturer, string inCaliber, string inGrips, string inSights, bool inLaser, bool inSingleAction, int inNumberOfRounds) {
	setManufacturer(inManufacturer);
	setCaliber(inCaliber);
	setGrips(inGrips);
	setSights(inSights);
	setLaser(inLaser);
	singleAction = inSingleAction;
	numberOfRounds = inNumberOfRounds;
}

void Revolver::setSingleAction(bool input) {
	singleAction = input;
}

bool Revolver::getSingleAction() {
	return singleAction;
}

void Revolver::setNumberOfRounds(int input) {
	numberOfRounds = input;
}

int Revolver::getNumberOfRounds() {
	return numberOfRounds;
}

void Revolver::print() {
	cout << "Revolver: " << getManufacturer() << ", ";
	cout << getCaliber() << ", ";
	cout << getNumberOfRounds() << " shot, ";
	if (getSingleAction())
		cout << "single action, ";
	else
		cout << "double action, ";
	cout << getGrips() << " grips, ";
	if (getLaser())
		cout << "laser, ";
	else
		cout << "no laser, ";
	cout << getSights() << endl;
}