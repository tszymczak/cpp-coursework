/*
Chapter 6 Homework
Thomas Szymczak
CIT-245
9/17/2017
Store information about players in a game.
*/

#pragma warning(disable: 4996)

#include <string>
#include <iostream>
using namespace std;

struct Position {
	int x;
	int y;
};

class Player {
private:
	string name;
	string password;
	// xp is experience points.
	int xp;
	// Inventory is a pointer that we use to pass arrays.
	string* inventory;
	Position location;

public:
	void setName(string input) {
		name = input;
	}
	string getName() {
		return name;
	}
	void setPassword(string input) {
		password = input;
	}
	string getPassword() {
		return password;
	}
	void setXP(int input) {
		xp = input;
	}
	int getXP() {
		return xp;
	}
	void setInv(string * input) {
		inventory = input;
	}
	string * getInv() {
		return inventory;
	}
	void setLocation(Position input) {
		location = input;
	}
	void setLocation(int x, int y) {
		location = { x, y };
	}
	Position getLocation() {
		return location;
	}
	void display();
};

// Print out information about a player.
void Player::display() {
	cout << endl << "Player Info -" << endl;
	cout << "Name: " << this->name << endl;
	cout << "Password: " << this->password << endl;
	cout << "Experience: " << this->xp << endl;
	cout << "Position: " << this->location.x << ", " << this->location.y << endl;
	cout << "Inventory:" << endl;

	// Print each element of the inventory array. To go to the next element,
	// we increment the pointer.
	string* p = this->inventory;
	for (int i = 0; i < 4; i++) {
		cout << " " << *(p+i) << endl;
	}
}

void main() {
	cout << "This program generates three player objects and displays them." << endl;

	string nemInventory[4] = { "sword", "shield", "food", "potion" };
	string ompInventory[4] = { "sword of magic", "shield of power", "mana potion", "anti-fire potion" };
	string tokInventory[4] = { "axe of damage", "shield of warding", "strength potion", "healing potion" };

	Player nem;
	nem.setName("Nematocyst");
	nem.setPassword("obfuscator");
	nem.setXP(1098);
	nem.setLocation(55689, 76453);
	nem.setInv(nemInventory);
	nem.display();

	Player omp;
	omp.setName("Omphaloskeps");
	omp.setPassword("obstreperous");
	omp.setXP(11456);
	omp.setLocation(12, 5108);
	omp.setInv(ompInventory);
	omp.display();

	Player tok;
	tok.setName("Tokamakfusion");
	tok.setPassword("toroid");
	tok.setXP(15678);
	tok.setLocation(99, 108);
	tok.setInv(tokInventory);
	tok.display();

	system("pause");
}