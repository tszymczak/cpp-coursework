#pragma once
#pragma warning(disable: 4996)
#include <string>
#include <iostream>
using namespace std;

#include "gun.h"

class Handgun : public Gun {
public:
	Handgun();
	Handgun(string inManufacturer, string inCaliber, string inGrips, string inSights, bool inLaser);
	void setGrips(string input);
	string getGrips();
	void setSights(string input);
	string getSights();
	void setLaser(bool input);
	bool getLaser();
private:
	string grips;
	string sights;
	bool laser;
};