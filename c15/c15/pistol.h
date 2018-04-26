#pragma once
#pragma warning(disable: 4996)
#include <string>
#include <iostream>
using namespace std;

#include "handgun.h"

class Pistol : public Handgun {
public:
	Pistol();
	Pistol(string inManufacturer, string inCaliber, string inGrips, string inSights, bool inLaser, bool inSemiAuto);
	void setSemiAuto(bool input);
	bool getSemiAuto();
	virtual void print();
private:
	bool semiAuto;
};