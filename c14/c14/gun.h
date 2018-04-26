#pragma once
#pragma warning(disable: 4996)
#include <string>
#include <iostream>
using namespace std;

class Gun {
public:
	Gun();
	Gun(string inMan, string inCal);
	void setManufacturer(string input);
	string getManufacturer();
	void setCaliber(string input);
	string getCaliber();
private:
	string manufacturer;
	string caliber;
};