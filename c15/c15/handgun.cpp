#pragma warning(disable: 4996)
#include <string>
#include <iostream>
#include "handgun.h"
using namespace std;

Handgun::Handgun() {
	grips = "";
	sights = "";
	laser = false;
}

Handgun::Handgun(string inManufacturer, string inCaliber, string inGrips, string inSights, bool inLaser) {
	setManufacturer(inManufacturer);
	setCaliber(inCaliber);
	grips = inGrips;
	sights = inSights;
	laser = inLaser;
}

void Handgun::setGrips(string input) {
	grips = input;
}

string Handgun::getGrips() {
	return grips;
}

void Handgun::setSights(string input) {
	sights = input;
}

string Handgun::getSights() {
	return sights;
}

void Handgun::setLaser(bool input) {
	laser = input;
}

bool Handgun::getLaser() {
	return laser;
}

void Handgun::print() {
	cout << "Handgun: " << getManufacturer() << ", ";
	cout << getCaliber() << endl;
}