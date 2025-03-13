#include "SortedLinkedList.h"
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

SortedLinkedList::SortedLinkedList() : head(nullptr), count(0){}

SortedLinkedList::~SortedLinkedList()
{
	Node* current = head;
	while (current != nullptr)
	{
		Node* temp = current->getNext();
		delete current;
		current = temp;
	}
}

int& SortedLinkedList::operator[](int index)
{
	if (index < 0 || index >= count)
		throw std::invalid_argument("Received invalid index");
	else if (head == nullptr)
		throw std::exception("List is empty");

	int currentIndex = 0;
	Node* current = head;

	while (current != nullptr)
	{
		if (currentIndex == index)
		{
			return current->getItem();
		}
		current = current->getNext();
		currentIndex++;
	}
}

void SortedLinkedList::addItem(int item)
{
	Node* newNode = new Node(item);
	Node* current = head;

	if (head == nullptr)
	{
		head = newNode;
		count++;
		return;
	}

	while (current->getNext() != nullptr)
	{
		current = current->getNext();
	}
	current->setNext(newNode);
	count++;
}

void SortedLinkedList::removeNode(Node*& previous, Node*& target)
{
	if (target == nullptr) return;

	if (previous == nullptr)
	{
		head = target->getNext();
	}
	else
	{
		previous->setNext(target->getNext());
	}

	delete target;
	count--;
}

void SortedLinkedList::removeAt(int index)
{
	if (index < 0 || index >= count)
		throw std::invalid_argument("Received invalid index");
	else if (head == nullptr)
		throw std::invalid_argument("List is empty");

	int currentIndex = 0;
	Node* current = head;
	Node* previous = nullptr;

	while (current != nullptr)
	{
		if (currentIndex == index)
		{
			removeNode(previous, current);
			return;
		}

		previous = current;
		current = current->getNext();
		currentIndex++;
	}
}

void SortedLinkedList::removeItem(int item)
{
	if (head == nullptr)
		throw std::exception("List is empty");

	Node* current = head;
	Node* previous = nullptr;

	while (current != nullptr)
	{
		if (current->getItem() == item)
		{
			removeNode(previous, current);
			return;
		}

		previous = current;
		current = current->getNext();
	}
}

void SortedLinkedList::printList()
{
	Node* current = head;

	cout << "[";
	while (current != nullptr)
	{
		string separator = (current->getNext() != nullptr) ? ", " : "";

		cout << current->getItem() << separator;
		current = current->getNext();
	}
	cout << "]";
	cout << endl;
}

void SortedLinkedList::intersection(SortedLinkedList* L1, SortedLinkedList* L2)
{

}