/*
Chapter 5 Homework
Thomas Szymczak
CIT-245
9/17/2017
Generate random numbers and put them in a sorted array.
*/

#pragma warning(disable: 4996)

#include <string>
#include <iostream>
#include <ctime>
#include <algorithm>
using namespace std;

// Generate random numbers, put them in an array, then sort them.
void arrayDemo();

// Generate a random number between 1 and 10.
int getRand();

void main() {
	int repeat = 1;
	cout << "This program generates random numbers and tabulates the results." << endl;

	// Set up the pseudorandom number generator. Here we use the current time
	// as the seed. In order to convert the time_t value returned to the
	// unsigned int that srand() wants, we use a cast.
	srand((unsigned int)time(NULL));

	while (repeat == 1) {
		cout << endl;
		arrayDemo();
		cout << "Try again? (1 = yes, 0 = exit)" << endl;
		cin >> repeat;
	}
	system("pause");
}

void arrayDemo() {
	const int RN_SIZE = 20;
	const int CT_SIZE = 10;
	int randomNumbers[RN_SIZE];
	// Initialize the array to zero to comply with the teacher's rule that all variables must be initialized.
	for (int i = 0; i < RN_SIZE; i++) { randomNumbers[i] = 0; }
	int count[CT_SIZE];
	for (int i = 0; i < CT_SIZE; i++) { count[i] = 0; }

	// Fill the array with random numbers.
	for (int i = 0; i < RN_SIZE; i++) {
		randomNumbers[i] = getRand();
	}

	// Sort the array.
	sort(randomNumbers, randomNumbers + 20);

	// Tabulate the frequency of how often each number occurs.
	for (int i = 0; i < RN_SIZE; i++) {
		count[randomNumbers[i] - 1]++;
	}

	// Print the results.
	cout << "  Original List Sorted:" << endl;
	for (int i = 0; i < RN_SIZE; i++) {
		printf("a[%2d]%3d\n", i, randomNumbers[i]);
	}

	cout << endl << "  N Count:" << endl;
	for (int i = 0; i < CT_SIZE; i++) {
		printf("%2d:%3d\n", i+1, count[i]);
	}
	cout << endl;
}

int getRand() {
	return rand() % 10 + 1;
}