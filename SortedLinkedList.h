#pragma once
#include "Node.h"

class SortedLinkedList
{
public:
	SortedLinkedList();
	~SortedLinkedList();
	int& at(int index);
	void addItem(int item);
	void intersection(SortedLinkedList* L1, SortedLinkedList* L2);
	void printList();
	void removeAt(int index);
	void removeItem(int item);
	bool isEmpty() const;
private:
	int count;
	Node* head;
	void removeNode(Node*& previous, Node*& target);
};

