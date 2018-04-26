/*
Chapter 12 Homework
Thomas Szymczak
CIT-245
10/8/2017
Make an advice file, demonstrating use of file I/O.
*/

#pragma warning(disable: 4996)
#include <string>
#include <cstdlib>
#include <iostream>
#include <fstream>
using namespace std;
using std::ofstream;
using std::ifstream;
using std::ios;

int main() {
	ifstream infile;
	ofstream outfile;
	fstream inoutfile;
	string temp;
	string newAdvice;

	// If we can open the advice file, print out the contents.
	// If we can't, create the advice file.
	infile.open("advice.txt");
	if (infile.fail()) {
		infile.close();
		cout << "Could not open advice file." << endl;
		// Create the advice file.
		cout << "Assumption: first run - creating a new file..." << endl;
		inoutfile.open("advice.txt", ios::in | ios::out | ios::trunc);  // create new file
		inoutfile.close();
	} else {
		cout << "Old Advice:" << endl;
		while (!infile.eof()) {
			getline(infile,temp);
			cout << temp << endl;
		}
		infile.close();
	}

	// Get the new advice phrase from the user:
	cout << "Enter your phrase for the next user:" << endl;
	getline(cin, newAdvice);

	// Append the new advice to the file:
	outfile.open("advice.txt", ios::app);
	outfile << newAdvice << endl;
	outfile.close();

	system("pause");
	return 0;
}