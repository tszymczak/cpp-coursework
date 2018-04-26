/*
Chapter 9 Homework
Thomas Szymczak
CIT-245
10/4/2017
Reverse strings.
*/

#pragma warning(disable: 4996)

#include <iostream>
#include <string>
#include <cstdlib>
#include <stack>
using namespace std;

string reverse(const string& str);

// Instead of using C-strings like in the example, I decided to use
// the string class because it's easier to work with.
int main() {
	int repeat = 1, chr = 0;
	string input, reversed;

	cout << "This program reverses a string using the STL stack." << endl;

	while (repeat == 1) {
		// Get the input string. We use the string class so we don't have
		// to worry about handling memory manually or a maximum length,
		// the class takes care of that for us.
		cout << "Enter your string followed by an ENTER." << endl;
		getline(cin, input);

		// Reverse the input string and print the result.
		reversed = reverse(input);
		cout << reversed << endl;

		// Ask the user if they want to repeat the program. 
		cout << "Enter another? 1 = continue. Anything else to stop" << endl;
		cin >> repeat;
		// Read one character (the newline) from the input buffer to ensure that
		// getline() works properly.
		chr = getchar();
	}
}

// Reverse a string using the STL stack.
string reverse(const string& str) {
	string reverse;

	stack <char> myStack;

	// First, take each character of the string and put it in the stack.
	for (unsigned int i = 0; i < str.length(); i++) {
		myStack.push(str[i]);
	}


	// Then pop each character off the stack, giving us each character
	// but in the opposite order as before.
	while (!myStack.empty()) {
		reverse += myStack.top();
		myStack.pop();
	}
	return reverse;
}