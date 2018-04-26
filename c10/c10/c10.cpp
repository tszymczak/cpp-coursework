/*
Chapter 10 Homework
Thomas Szymczak
CIT-245
10/4/2017
Work with pointers.
*/

#pragma warning(disable: 4996)

#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

void pointerDemo();
void copyDemo();

// This class stores a small array of characters and uses deep copying to
// properly copy objects.
class WrapArrayDeep {
private:
	char *pch;

public:
	WrapArrayDeep() {
		pch = new char[5];
		*pch = 97;
		*(pch + 1) = 98;
		*(pch + 2) = 99;
		*(pch + 3) = 100;
		*(pch + 4) = 101;
	}

	// Perform a deep copy on the array of characters, allocating a new
	/// char array and then copying each character.
	WrapArrayDeep(const WrapArrayDeep& wad) {
		pch = new char[5];
		for (int i = 0; i < 5; i++) {
			pch[i] = wad.pch[i];
		}
	}

	~WrapArrayDeep() {
		cout << "Executing destructor for WrapArrayDeep." << endl;
		delete [] pch;
	}

	void print() {
		for (int i = 0; i < 5; i++) {
			cout << pch[i] << " ";
		}
		cout << endl;
	}

	void set(int index, char newVal) {
		if (index >= 0 && index <= 4) {
			pch[index] = newVal;
		} else {
			cout << "Invalid array index." << endl;
			exit(1);
		}
	}

	WrapArrayDeep& operator =(const WrapArrayDeep& rightSide) {
		if (this != &rightSide) {
			pch = new char[5];
			for (int i = 0; i < 5; i++) {
				pch[i] = rightSide.pch[i];
			}
		}
		return *this;
	}
};


// This class stores a small array of characters, but we _delibrately_
// use shallow copies despite knowing it's the wrong way to do things,
// in order to demonstrate the problems associated with shallow copying.
class WrapArrayShallow {
private:
	char *pch;

public:
	WrapArrayShallow() {
		pch = new char[5];
		pch[0] = 'a';
		pch[1] = 'b';
		pch[2] = 'c';
		pch[3] = 'd';
		pch[4] = 'e';
	}

	// Perform a shallow copy, which results in incorrect behavior.
	// Just set the array reference in the new object to the
	// array reference in the old object. Now we have two objects
	// which both point to the same array.
	WrapArrayShallow(WrapArrayShallow& was) {
		pch = was.pch;
	}

	// Destructor for WrapArrayShallow. I commented this out because it causes
	// me a crash at runtime, probably because it tries to delete the array
	// held by each WrapArrayShallow object, but because we copied them incorrectly
	// there's really only one array. So we try to delete the same array twice.
	/*~WrapArrayShallow() {
		cout << "Executing destructor for WrapArrayShallow." << endl;
		delete[] pch;
	}*/

	void print() {
		for (int i = 0; i < 5; i++) {
			cout << *(pch + i) << " ";
		}
		cout << endl;
	}

	void set(int index, char newVal) {
		if (index >= 0 && index <= 4) {
			pch[index] = newVal;
		}
		else {
			cout << "Invalid array index." << endl;
			exit(1);
		}
	}

	// In order to get the behavior we need, we must do a shallow copy
	// here too.
	WrapArrayShallow& operator =(const WrapArrayShallow& rightSide) {
		if (this != &rightSide) {
			pch = rightSide.pch;
		}
		return *this;
	}
};

int main() {
	pointerDemo();
	cout << endl;
	copyDemo();
	system("pause");
	return 0;
}

void pointerDemo() {
	int i = 7;
	int* pi = &i;
	int** ppi = &pi;

	cout << "this program section uses 3 variables" << endl;
	cout << "i = 7, pi a pointer to i and ppi a pointer to pi" << endl;
	cout << "pi = " << pi << endl;
	cout << "dereference pi " << *pi << endl;
	cout << "address of pi " << &pi << endl;
	cout << "address of i " << &i << endl;
	cout << endl;
	cout << "ppi = " << ppi << endl;
	cout << "dereference of ppi " << *ppi << endl;
	cout << "address of ppi " << &ppi << endl;
	cout << "double dereference of ppi " << **ppi << endl;
}


void copyDemo() {
	WrapArrayDeep wad1, wad2;
	WrapArrayShallow was1, was2;

	wad2 = WrapArrayDeep(wad1);
	was2 = WrapArrayShallow(was1);

	cout << "this section instantiates a wrapper class for a dynamic array of 5 elements" << endl;
	cout << "WrapArrayDeep 1" << endl;
	wad1.print();
	cout << "WrapArrayDeep 2 created using the copy constructor on 1" << endl;
	wad2.print();

	// Change the contents of the array.
	wad1.set(0, '{');
	wad1.set(1, '|');
	wad1.set(2, '}');
	wad1.set(3, '~');
	wad1.set(4, 'o');

	cout << "after changing the contents of WrapArrayDeep 1, 2, and 3 =" << endl;
	wad1.print();
	wad2.print();
	cout << endl;
	
	cout << "Now doing the same thing with WrapArrayShallow" << endl;
	cout << "wrapArrayShallow 1" << endl;
	was1.print();
	cout << "wrapArrayShallow 2 created using the copy constructor on 1" << endl;
	was2.print();

	// Change the contents of the array.
	was1.set(0, '{');
	was1.set(1, '|');
	was1.set(2, '}');
	was1.set(3, '~');
	was1.set(4, 'o');

	cout << "after changing the contents of WrapArrayShallow 1, 1 and 3 =" << endl;
	was1.print();
	was2.print();
	
}