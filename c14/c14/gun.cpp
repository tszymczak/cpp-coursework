#pragma warning(disable: 4996)
#include <string>
#include <iostream>
#include "gun.h"
using namespace std;

Gun::Gun() {
	manufacturer = "";
	caliber = "";
}

Gun::Gun(string inMan, string inCal) {
	manufacturer = inMan;
	caliber = inCal;
}

void Gun::setManufacturer(string input) {
	manufacturer = input;
}

string Gun::getManufacturer() {
	return manufacturer;
}

void Gun::setCaliber(string input) {
	caliber = input;
}

string Gun::getCaliber() {
	return caliber;
}