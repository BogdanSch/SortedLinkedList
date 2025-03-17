#include <iostream>
#include "SortedLinkedList.h"

using std::cout;

int main()
{
	// Test 1: Adding and removing items from list a
	SortedLinkedList a;
	a.addItem(20);
	a.addItem(22);
	a.addItem(25);
	a.removeAt(0);
	a.removeItem(20);
	a.removeAt(1);
	cout << "List a after removals: ";
	a.at(0) = 1;
	a.addItem(78);
	a.printList();  // Expected output: [1, 78]

	// Test 2: Adding, removing, and printing list b
	SortedLinkedList b;
	b.addItem(15);
	b.addItem(20);
	b.addItem(25);
	b.addItem(30);
	b.removeAt(1);
	b.removeItem(15);
	b.removeAt(1);
	cout << "List b after removals: ";
	b.printList();  // Expected output: [25]

	// Test 3: Intersection of lists a and b
	b.addItem(1);
	SortedLinkedList c = a.intersection(b);
	cout << "The result of intersection: ";
	c.printList(); // Expected output: [1]

	// Test 4:
	SortedLinkedList d({0, 1, 2, 3, 4, 5});
	d.addItem(6);
	d.removeItem(6);
	d.printList();
	cout << d.getCount();
}