/*
Chapter 7 Homework
Thomas Szymczak
CIT-245
9/23/2017
Implement a simple counter.
*/

#pragma warning(disable: 4996)

#include <string>
#include <iostream>
using namespace std;

class Counter {
private:
	int count;
	// Keep track of the number of increments and decrements.
	static int incCount;
	static int decCount;
public:
	Counter();
	Counter(int start);
	void inc() {
		count++;
		incCount++;
	}
	void dec() {
		count--;
		decCount++;
	}
	void display() {
		cout << "Current count: " << count << endl;
	}
	static int getIncCount() {
		return incCount;
	}
	static int getDecCount() {
		return decCount;
	}
};

int Counter::incCount = 0, Counter::decCount = 0;

Counter::Counter() {
	this->count = 0;
}

Counter::Counter(int start) {
	this->count = start;
}

void main() {
	Counter C1 = Counter();
	Counter C2 = Counter(200);

	cout << "Current state of C1 (created with the default constructor)" << endl;
	C1.display();
	cout << "Total increments and decrements: " << Counter::getIncCount() + Counter::getDecCount() << endl;
	cout << "Current state of C2 (created as C2(200))" << endl;
	C2.display();
	cout << "Total increments and decrements: " << Counter::getIncCount() + Counter::getDecCount() << endl;

	// Increment C1 85 times to set it to a value of 85.
	for (int i = 0; i < 85; i++) {
		C1.inc();
	}

	cout << "Current state of C1 after 85 inc()" << endl;
	C1.display();
	cout << "Total increments and decrements: " << Counter::getIncCount() + Counter::getDecCount() << endl;

	// Decrement C2 242 times.
	for (int i = 0; i < 242; i++) {
		C2.dec();
	}

	cout << "Current state of C2 after 242 dec()" << endl;
	C2.display();

	cout << "Total increments and decrements: " << Counter::getIncCount() + Counter::getDecCount() << endl;
	system("pause");
}