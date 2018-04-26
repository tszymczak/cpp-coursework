/*
Chapter 2 Homework
Thomas Szymczak
CIT-245
9/12/2017
Calculate the buoyant force on a sphere, given its radius and weight.
*/

#pragma warning(disable: 4996)

#include <string>
#include <iostream>
using namespace std;
#include <cmath>

// Given the radius and weight of a sphere, determine whether it floats in water.
void sphereCalc();

void main() {
	int recalc = 1;

	cout << "This program computes Buoyant Force in water given sphere radius." << endl;
	cout << "Based on the weight of the sphere, it determines whether the sphere floats or sinks." << endl;
	cout << endl;

	while (recalc == 1) {
		sphereCalc();

		cout << "Recalculate? (1 = yes, 0 = exit)" << endl;
		cin >> recalc;
	}
	system("pause");
}

void sphereCalc() {
	const double PI = 3.141592;
	const double WATER_DENSITY = 62.4;
	int radius = 0;
	int weight = 0;
	double volume = 0;
	double buoyantForce = 0;

	// Get input
	cout << endl;
	cout << "Enter the radius of the sphere." << endl;
	cin >> radius;
	cout << "You entered " << radius << endl;
	cout << endl;

	cout << "Enter the weight of the sphere." << endl;
	cin >> weight;
	cout << "You entered " << weight << endl;
	cout << endl;

	// Calculate the buoyant force and determine if it floats.
	volume = (4.0 / 3.0) * PI * radius * radius * radius;
	buoyantForce = volume * WATER_DENSITY;

	cout << "Buoyant Force = " << buoyantForce << endl;

	if (buoyantForce >= weight) {
		cout << "Egads, it floats!" << endl;
	}
	else {
		cout << "It sunk..." << endl;
	}
}