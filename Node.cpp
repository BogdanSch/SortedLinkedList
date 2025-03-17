#include "Node.h"

Node::Node() : item(0), next(nullptr) { }

Node::Node(int item)
{
	this->item = item;
	next = nullptr;
}

int& Node::getItem()
{
    return item;
}

int Node::getItem() const
{
	return item;
}

void Node::setItem(int newItem)
{
    item = newItem;
}

Node* Node::getNext()
{
	return next;
}

void Node::setNext(Node* next)
{
	this->next = next;
}
