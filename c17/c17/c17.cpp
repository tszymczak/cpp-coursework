/*
Chapter 17 Homework
Thomas Szymczak
Code written by Professor Moore and extended by Thomas Szymczak
CIT-245
11/2/2017
Implement a doubly linked list.
*/
/*
Written by Professor Kenneth L Moore
For CIT245 Data Structures and Programming C++
This code implements a singly linked list
Students must change it to a doubly linked list
*/
#include <iostream>
#include <string>
using namespace std;

// define a node for storage and linking
class node {
public:
	// The name we're storing
	string name;
	// Pointer to the next node
	node *next;
	// Pointer to the previous node.
	node *prev;
};

class linkedList {
public:
	linkedList() :top(NULL),end(NULL) {}
	bool empty() { return top == NULL; }
	node *getTop() { return top; }
	void setTop(node *n) { top = n; }
	void add(string);
	int menu();
	void remove(string);
	~linkedList();
	void reversePrint(); // to be implemented by students
	void debugPrint();
	friend ostream& operator << (ostream&, const linkedList&); // default output is in-order print.
private:
	node *top;
	node *end;
};

void main() {
	linkedList l;
	cout << l.empty() << endl;
	int option = 0;
	string s;
	bool go = true;
	while (go) {
		option = l.menu();
		switch (option) {
		case 1: cout << "enter a name: "; cin >> s; l.add(s); break;
		case 2: cout << "enter name to be deleted: "; cin >> s; l.remove(s); break;
		case 3: cout << l; break;
		case 4: l.reversePrint(); break;
		case 5: cout << "exiting" << endl; go = false; break;
		}
	}
	// l goes out of scope and calls ~linkedList()
	system("pause");
}

// can not call this method "delete" - "delete" is a reserved keyword.
void linkedList::remove(string s) {
	bool found = false;
	node *curr = getTop();
	while (curr != NULL) {

		// match found, delete
		if (curr->name == s) {
			found = true;

			// If we are deleting the top node.
			if (curr->prev == NULL) {
				// If we are deleting the only node.
				if (curr->next == NULL) {
					// Pull out the old top and delete it.
					node *temp = getTop();
					delete(temp);
					// List is now empty.
					top = NULL;
					end = NULL;
				}
				else {
					// Take note of the old top.
					node *temp = getTop();
					// Set top to the next node.
					top = temp->next;
					top->prev = NULL;
					// Now we're done with the old top; delete it.
					delete(temp);
				}

			}
			// If we are deleting a node at the end
			else if (curr->next == NULL) {
				curr->prev->next = NULL;
				end = curr->prev;
				delete(curr);
			// If we are deleting a node in the middle.
			} else {
				curr->prev->next = curr->next;
				curr->next->prev = curr->prev;
				delete(curr);
			}
		}

		// not found, advance pointers
		if (!found) {
			curr = curr->next;
		}

		// found, exit loop
		else curr = NULL;
	}
	if (found)cout << "Deleted " << s << endl;
	else cout << s << " Not Found " << endl;
}

void linkedList::add(string s) {
	node *n = new node();
	n->name = s;
	n->next = NULL;
	n->prev = NULL;

	// take care of empty list case
	if (empty()) {
		top = n;
		end = n;

	}
	// take care of node belongs at beginning case
	else if (getTop()->name > s) {
		n->next = getTop();
		getTop()->prev = n;
		setTop(n);

	}
	// take care of inorder end insert
	else {

		// insert in order case
		node *curr = getTop();
		while (curr != NULL) {
			if (curr->name > s)break;
			curr = curr->next;
		}
		if (curr != NULL) { // search found insert point
			n->next = curr;
			n->prev = curr->prev;
			curr->prev = n;
			n->prev->next = n;
		}

		// take care of end of list insertion
		else if (curr == NULL) {// search did not find insert point
			end->next = n;
			n->prev = end;
			end = n;
		}
	}
}

ostream& operator << (ostream& os, const linkedList& ll) {
	//linkedList x = ll; // put this in and the code blows up - why?
	node *n = ll.top;
	if (n == NULL)cout << "List is empty." << endl;
	else
		while (n != NULL) {
			os << n->name << endl;
			n = n->next;
		}
	return os;
}

// return memory to heap
linkedList::~linkedList() {
	cout << "~linkedList called." << endl;
	node *curr = getTop(), *del;
	while (curr != NULL) {
		del = curr;
		curr = curr->next;
		delete(del);
	}
}

int linkedList::menu() {
	int choice = 0;
	while (choice < 1 || choice > 5) {
		cout << "\nEnter your choice" << endl;
		cout << " 1. Add a name." << endl;
		cout << " 2. Delete a name." << endl;
		cout << " 3. Show list." << endl;
		cout << " 4. Show reverse list. " << endl;
		cout << " 5. EXIT " << endl;
		cin >> choice;
	}
	return choice;
}

void linkedList::reversePrint() {
	node *n = this->end;
	if (n == NULL)cout << "List is empty." << endl;
	else
		while (n != NULL) {
			cout << n->name << endl;
			n = n->prev;
		}
}

// This is something I made to help me debug my code. Might as well
// leave it in here.
void linkedList::debugPrint() {
	node *n = top;
	int pos = 0;
	while (n != NULL) {
		cout << pos << ":   " << n->name << endl;
		if (n->prev == NULL) {
			cout << "     <-- NULL" << endl;
		}
		else {
			cout << "     <-- " << n->prev->name << endl;
		}
		if (n->next == NULL) {
			cout << "     --> NULL" << endl;
		} else {
			cout << "     --> " << n->next->name << endl;
		}
		n = n->next;
		pos++;
	}
}