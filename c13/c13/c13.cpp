/*
Chapter 13 Homework
Thomas Szymczak
CIT-245
10/15/2017
Solve the Towers of Hanoi, demonstrating use of recursion.
*/

#pragma warning(disable: 4996)
#include <string>
#include <iostream>
#include <cstdlib>
#include <stack>
#include <cmath>
using namespace std;

// Set up a Towers of Hanoi puzzle.
void hanoisetup(int n);

// Solve the Towers of Hanoi puzzle recursively.
int hanoi(int disk, stack <int> &source, stack <int> &destinaion, stack <int> &temp, int moves, int a, int b, int c);

int main() {
	int n = 0;
	int repeat = 1;

	while (repeat == 1) {
		cout << endl << "enter number of disks" << endl;
		cin >> n;
		hanoisetup(n);
		cout << endl << "Continue? (1=yes 0=no)" << endl;
		cin >> repeat;
	}
}

void hanoisetup(int n) {
	int moves = 0;
	int power = 0;

	// Represent each peg as a stack, which lends itself well
	// to the way we work with the pegs.
	stack <int> source;
	stack <int> destination;
	stack <int> temp;

	cout << "source 1 target 2 temporary 3" << endl;

	// Populate the source peg with the initial disks.
	for (int i = n; i > 0; i--) {
		source.push(i);
	}

	// Start solving the puzzle.
	moves = hanoi(n, source, destination, temp, 0, 1, 2, 3);
	power = static_cast <int> (pow(2, n));
	cout << "2 to the 3 power = " << power << endl;
	cout << "Number of moves " << moves << endl;
}

int hanoi(int disk, stack <int> &source, stack <int> &destination, stack <int> &temp, int moves, int a, int b, int c) {
	// The disk we're moving at the moment.
	int active = 0;
	if (disk == 1) {
		// Move the disk from the source to the destination.
		active = source.top();
		source.pop();
		destination.push(active);
		cout << "From " << a << " to " << b << endl;
		moves++;
	}
	else {
		moves = hanoi(disk - 1, source, temp, destination, moves, a, c, b);
		// Move a disk from the source to the destinaion.
		active = source.top();
		source.pop();
		destination.push(active);
		moves++;
		cout << "From " << a << " to " << b << endl;
		moves = hanoi(disk - 1, temp, destination, source, moves, c, b, a);
	}
	return moves;
}