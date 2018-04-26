/*
Chapter 8 Homework
Thomas Szymczak
CIT-245
9/28/2017
Implement an object-oriented system to keep track of money.
*/

#pragma warning(disable: 4996)

#include <string>
#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

// Class for amounts of money in U.S. Currency
class Money {
public:
	Money();
	Money(double amount);
	Money(int theDollars, int theCents);
	Money(int theDollars);
	double getAmount() const;
	int getDollars() const;
	int getCents() const;
	// Read the dollar sign as well as the amount number.
	void input();
	void output() const;
	friend ostream& operator <<(ostream& outs, const Money& amount);
	friend istream& operator >>(istream& inputSteam, Money& amount);
	Money percent(double percent);
private:
	// A negative amount is represented a snegative dollars and negative cents. Negative $4.50 is represented as -4 and -50.
	int dollars;
	int cents;
	int dollarsPart(double amount) const;
	int centsPart(double amount) const;
	int round(double numbers) const;
};

const Money operator +(const Money& amount1, const Money& amount2);
const Money operator -(const Money& amount1, const Money& amount2);
bool operator ==(const Money& amount1, const Money& amount2);
bool operator >(const Money& amount1, const Money& amount2);
bool operator <(const Money& amount1, const Money& amount2);
const Money operator -(const Money& amount);

void main() {
	Money m1;
	Money m2 = Money(10.09);
	cout << "Enter an amount of money: ";
	cin >> m1;
	cout << "Your amount is " << m1 << endl;
	cout << "My amount is " << m2 << endl;
	if (m1 == m2) {
		cout << "We both have the same amount of money." << endl;
	} else {
		cout << "One of us is richer." << endl;
		if (m1 > m2) {
			cout << "You have money money than me." << endl;
		} else {
			cout << "I have more money than you." << endl;
		}
	}

	Money fraction = m1.percent(10.0);
	cout << "10% of your money is: " << fraction << endl;

	cout << m1 << " + " << m2 << " equals " << (m1 + m2) << endl;
	cout << m1 << " - " << m2 << " equals " << (m1 - m2) << endl;
	system("pause");
}

const Money operator +(const Money& amount1, const Money& amount2) {
	int allCents1 = amount1.getCents() + amount1.getDollars() * 100;
	int allCents2 = amount2.getCents() + amount2.getDollars() * 100;
	int sumAllCents = allCents1 + allCents2;
	int absAllCents = abs(sumAllCents);
	int finalDollars = absAllCents / 100;
	int finalCents = absAllCents % 100;

	if (sumAllCents < 0) {
		finalDollars = -finalCents;
		finalCents = -finalCents;
	}

	return Money(finalDollars, finalCents);
}

const Money operator -(const Money& amount1, const Money& amount2) {
	int allCents1 = amount1.getCents() + amount1.getDollars() * 100;
	int allCents2 = amount2.getCents() + amount2.getDollars() * 100;
	int diffAllCents = allCents1 - allCents2;
	int absAllCents = abs(diffAllCents);
	int finalDollars = absAllCents / 100;
	int finalCents = absAllCents % 100;

	if (diffAllCents < 0) {
		finalDollars = -finalDollars;
		finalCents = -finalCents;
	}

	return Money(finalDollars, finalCents);
}

bool operator ==(const Money& amount1, const Money& amount2) {
	return ( (amount1.getDollars() == amount2.getDollars())
		&& (amount1.getCents() == amount2.getCents()));
}

bool operator >(const Money& amount1, const Money& amount2) {
	int total1 = amount1.getDollars() * 100 + amount2.getCents();
	int total2 = amount2.getDollars() * 100 + amount2.getCents();
	return total1 > total2;
}

bool operator <(const Money& amount1, const Money& amount2) {
	int total1 = amount1.getDollars() * 100 + amount2.getCents();
	int total2 = amount2.getDollars() * 100 + amount2.getCents();
	return total1 < total2;
}


const Money operator -(const Money& amount) {
	return Money(-amount.getDollars(), -amount.getCents());
}

Money::Money() : dollars(0), cents(0)
{/*Body intentionally empty*/}

Money::Money(double amount) : dollars(dollarsPart(amount)), cents(centsPart(amount))
{/*Body intentionally empty*/}

Money::Money(int theDollars) : dollars(theDollars), cents(0)
{/*Body intentionally empty*/}

//Uses cstdlib:
Money::Money(int theDollars, int theCents) {
	if ((theDollars < 0 && theCents > 0) || (theDollars > 0 && theCents < 0)) {
		cout << "Inconsistent money data.\n";
	}
	dollars = theDollars;
	cents = theCents;
}

double Money::getAmount() const {
	return (dollars + cents*0.01);
}

int Money::getDollars() const {
	return dollars;
}

int Money::getCents() const{
	return cents;
}

// Uses iostream and cstdlib:
void Money::output() const {
	int absDollars = abs(dollars);
	int absCents = abs(cents);
	if (dollars < 0 || cents < 0) // account for dollars == 0 or cents == 0
		cout << "$-";
	else
		cout << '$';
	cout << absDollars;

	if (absCents >= 10)
		cout << '.' << absCents;
	else
		cout << '.' << '0' << absCents;
}

//Uses iostream and cstdlib:
void Money::input() {
	char dollarSign;
	cin >> dollarSign; //hopefully
	if (dollarSign != '$') {
		cout << "No dollar sign in Money input.\n";
		exit(1);
	}

	double amountAsDouble;
	cin >> amountAsDouble;
	dollars = dollarsPart(amountAsDouble);
	cents = centsPart(amountAsDouble);
}

int Money::dollarsPart(double amount) const {
	return static_cast<int>(amount);
}

int Money::centsPart(double amount) const {
	double doubleCents = amount * 100;
	// % can misbehave on negatives
	int intCents = (round(fabs(doubleCents))) % 100;
	if (amount < 0) {
		intCents = -intCents;
	}
	return intCents;
}

int Money::round(double number) const {
	return static_cast<int>(floor(number + 0.5));
}

ostream& operator <<(ostream& outputStream, const Money& amount) {
	int absDollars = abs(amount.dollars);
	int absCents = abs(amount.cents);
	if (amount.dollars < 0 || amount.cents < 0) // account for dollars == 0 or cents == 0
		cout << "$-";
	else
		cout << '$';
	cout << absDollars;

	if (absCents >= 10)
		cout << '.' << absCents;
	else
		cout << '.' << '0' << absCents;

	return outputStream;
}

istream& operator >>(istream& inputStream, Money& amount) {
	char dollarSign;
	cin >> dollarSign; //hopefully
	if (dollarSign != '$') {
		cout << "No dollar sign in Money input.\n";
		exit(1);
	}

	double amountAsDouble;
	cin >> amountAsDouble;
	amount.dollars = amount.dollarsPart(amountAsDouble);
	amount.cents = amount.centsPart(amountAsDouble);

	return inputStream;
}

Money Money::percent(double percent) {
	int totalCents = dollars * 100 + cents;
	// We divide by 10,000 because we have to divide by 100 to convert cents to dollars,
	// then divide by 100 again to make it a percentage.
	double finalAmount = percent * totalCents / 10000.0;
	return Money(finalAmount);
}