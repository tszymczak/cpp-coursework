/*
Chapter 4 Homework
Thomas Szymczak
CIT-245
9/12/2017
Simplify fractions.
*/

#pragma warning(disable: 4996)

#include <string>
#include <iostream>
using namespace std;

// Get simplfy a fraction. This function also does the job of gathering input.
void simplifyFraction();

// Reduce a fraction.
void reduce(int num, int den);

// Calculate the greatest common denominator of two numbers.
int gcd(int a, int b);

void main() {
	int repeat = 1;
	cout << "This program takes a numerator and denominator and reduces it to lowest terms." << endl;

	while (repeat == 1) {
		cout << endl;
		simplifyFraction();
		cout << "Try again? (1 = yes, 0 = exit)" << endl;
		cin >> repeat;
	}

}

void simplifyFraction() {
	int num = 0, den = 0;

	cout << "Enter the numerator." << endl;
	cin >> num;

	cout << "Enter the denominator." << endl;
	cin >> den;

	reduce(num, den);
}

void reduce(int num, int den) {
	int g = 0, reducedNum = 0, reducedDen = 0;

	g = gcd(num, den);
	reducedNum = num / g;
	reducedDen = den / g;

	cout << "  The greatest common denominator is " << g << endl;
	cout << "  Your fraction reduced is " << reducedNum << "/" << reducedDen << endl;
	cout << endl;
}

int gcd(int a, int b) {
	int t = 0;

	while (b != 0) {
		t = b;
		b = a % b;
		a = t;
	}

	return a;
}