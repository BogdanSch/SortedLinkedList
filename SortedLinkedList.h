#pragma once
#include "Node.h"
#include<vector>

using std::vector;

class SortedLinkedList
{
public:
	SortedLinkedList();
	SortedLinkedList(vector<int> inputNumbers);
	~SortedLinkedList();
	size_t getCount() const;
	int& at(int index);
	bool contains(int item) const;
	void addItem(int item);
	SortedLinkedList merge(SortedLinkedList& other);
	SortedLinkedList intersection(SortedLinkedList& other);
	void printList();
	void removeAt(int index);
	void removeItem(int item);
	bool isEmpty() const;
private:
	size_t count;
	Node* head;
	void removeNode(Node*& previous, Node*& target);
};

