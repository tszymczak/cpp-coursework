/*
Chapter 16 Homework
Thomas Szymczak
CIT-245
11/2/2017
Implement a binary search using generics.
*/

#pragma warning(disable: 4996)
#include <string>
#include <iostream>
using namespace std;

template<class T>
int binSearch(const T a[], T x, int n);

template<class T>
void printBinSearch(const T a[], T x, int n);

int main() {
	int a[] = { 0, 1, 1, 2, 3, 5, 6, 13, 21, 32, 55 };
	string s[] = { "head", "knees", "shoulders", "toes" };
	int numInt = 11, numStr = 4;
	string elbows = "elbows";
	string knees = "knees";

	cout << "Integer test array contains:" << endl;
	for (int i = 0; i < numInt; i++) {
		cout << a[i] << " ";
	}
	cout << endl;

	printBinSearch(a, -1, numInt);
	printBinSearch(a, 0, numInt);
	printBinSearch(a, 1, numInt);
	printBinSearch(a, 2, numInt);
	printBinSearch(a, 3, numInt);
	printBinSearch(a, 4, numInt);
	printBinSearch(a, 5, numInt);
	printBinSearch(a, 6, numInt);
	printBinSearch(a, 7, numInt);

	cout << "String test array contains:" << endl;
	for (int i = 0; i < numStr; i++) {
		cout << s[i] << " ";
	}
	cout << endl;

	printBinSearch(s, elbows, numStr);
	printBinSearch(s, knees, numStr);
	system("pause");
	return 0;
}

/*
Search a sorted array a for a number x. If x appears in the list,
return the index it's located at. If x does not appear in the
list, return -1. n is the length of the array.
*/
template<class T>
int binSearch(const T a[], T x, int n) {
	// n is the length of the array.
	int left = 0, right = n - 1, middle = 0;
	while (left <= right) {
		middle = (right - left) / 2 + left;
		if (a[middle] == x) {
			return middle;
		}
		if (x < a[middle]) {
			right = middle - 1;
		} else {
			left = middle + 1;
		}
	}

	// If we get to the end of the loop and we haven't found it,
	// it doesn't exist in the list.
	return -1;
}

/*
Does the same thing as binSearch but prints the results instead of
returning them.
*/
template<class T>
void printBinSearch(const T a[], T x, int n) {
	int result = 0;
	result = binSearch(a, x, n);
	if (result == -1)
		cout << x << " is not in the array." << endl;
	else
		cout << x << " is at index " << result << endl;
}