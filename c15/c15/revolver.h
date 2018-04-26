#pragma once
#pragma warning(disable: 4996)
#include <string>
#include <iostream>
#include "handgun.h"
#include "gun.h"
using namespace std;

class Revolver : public Handgun {
public:
	Revolver();
	Revolver(string inManufacturer, string inCaliber, string inGrips, string inSights, bool inLaser, bool inSingleAction, int inNumberOfRounds);
	void setSingleAction(bool input);
	bool getSingleAction();
	void setNumberOfRounds(int input);
	int getNumberOfRounds();
	virtual void print();
private:
	bool singleAction;
	int numberOfRounds;
};