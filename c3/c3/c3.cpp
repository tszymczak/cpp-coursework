/*
Chapter 3 Homework
Thomas Szymczak
CIT-245
9/12/2017
Simulate rolling dice.
*/

#pragma warning(disable: 4996)

#include <string>
#include <iostream>
using namespace std;
#include <ctime>
#include <cmath>

// Roll dice repeatedly to see how many times you get each possible number,
// and compare the results to what you would expect.
void diceExperiment();

// Simulate rolling a die by returning a random number between 1 and 6. We
// use the rand() function to get a random number. Because the max number
// that rand() can return is very large, we can use a simple modulo to
// reduce the range to 0-5. then we add 1 so it gives us a range of 1 to 6.
int rollDie();

void main() {
	int repeat = 1;

	cout << "This program rolls two dice and tabulates the results." << endl;
	cout << endl;

	// Set up the pseudorandom number generator. Here we use the current time
	// as the seed. In order to convert the time_t value returned to the
	// unsigned int that srand() wants, we use a cast.
	srand((unsigned int)time(NULL));

	while (repeat == 1) {
		diceExperiment();

		cout << "Try again? (1 = yes, 0 = exit)" << endl;
		cin >> repeat;
	}

}

void diceExperiment() {
	int n = 0;
	int array[13] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	// The probability of rolling the die and getting each sum.
	double odds[13] = { 0, 0, (1.0 / 36), (2.0 / 36), (3.0 / 36), (4.0 / 36),
		(5.0 / 36), (6.0 / 36), (5.0 / 36), (4.0 / 36), (3.0 / 36), (2.0 / 36), (1.0 / 36) };
	int expected = 0;
	double error = 0;
	int sum = 0;
	int i = 0;

	cout << "Please enter the number of rolls you want: ";
	cin >> n;

	for (i = 0; i < n; i++) {
		sum = rollDie() + rollDie();
		array[sum]++;
	}


	printf("%5s %10s %10s %10s\n", "Sum", "#Rolled", "Odds", "%Error");
	for (i = 2; i <= 12; i++) {
		expected = (int)round(odds[i] * n);

		if (expected == 0) {
			if (array[i] == 0) {
				error = 0.0;
			} else {
				error = 100.0;
			}
		}
		else {
			error = abs((double)(expected - array[i]) / expected * 100);
		}

		// Debug code
		//cout << i << " " << array[i] << " " << odds[i] << " " << expected << " " << error << endl;
		printf("%4d: %10d %10d %10.4f\n", i, array[i], expected, error);
	}
}

int rollDie() {
	return rand() % 6 + 1;
}