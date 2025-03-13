#pragma once

class Node
{
public:
	Node();
	Node(int item);
	int& getItem();
	int getItem() const;
	void setItem(int newItem);
	Node* getNext();
	void setNext(Node* next);
private:
	int item;
	Node* next;
};

