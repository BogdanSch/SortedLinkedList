#include "SortedLinkedList.h"
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

SortedLinkedList::SortedLinkedList() : head(nullptr), count(0) {}

SortedLinkedList::SortedLinkedList(vector<int> inputNumbers) : SortedLinkedList()
{
	for (size_t i = 0; i < inputNumbers.size(); i++)
	{
		addItem(inputNumbers[i]);
	}
}

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

size_t SortedLinkedList::getCount() const
{
	return count;
}

int& SortedLinkedList::at(int index)
{
	if (index < 0 || index >= count)
		throw std::invalid_argument("Received invalid index");
	else if (isEmpty())
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

	if (isEmpty())
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
	else if (isEmpty())
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
	if (isEmpty())
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

bool SortedLinkedList::isEmpty() const
{
	return head == nullptr;
}

SortedLinkedList SortedLinkedList::intersection(SortedLinkedList& other)
{
	SortedLinkedList result;

	Node* current1 = this->head;
	Node* current2 = other.head;

	while (current1 != nullptr)
	{
		while (current2 != nullptr)
		{
			if (current1->getItem() == current2->getItem())
			{
				result.addItem(current1->getItem());
				break;
			}
			current2 = current2->getNext();
		}
		current1 = current1->getNext();
		current2 = other.head;
	}

	return result;
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