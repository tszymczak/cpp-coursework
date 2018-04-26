/*
Chapter 11 Homework
Thomas Szymczak
CIT-245
10/8/2017
Work with separate compilation and namespaces.
*/

#pragma warning(disable: 4996)

#include <string>
#include <iostream>
#include "f.h"
#include "g.h"

int main() {
	{
		using namespace f;
		hello();
	}
	{
		using namespace g;
		hello();
	}

	system("pause");
	return 0;
}