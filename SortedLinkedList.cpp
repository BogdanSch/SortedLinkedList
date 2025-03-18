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

	throw std::exception("Index not found");
}

void SortedLinkedList::addItem(int item)
{
	Node* newNode = new Node(item);

	if (isEmpty() || item < head->getItem())
	{
		newNode->setNext(head);
		head = newNode;
		count++;
		return;
	}

	Node* current = head;
	while (current->getNext() != nullptr && current->getNext()->getItem() < item)
	{
		current = current->getNext();
	}

	newNode->setNext(current->getNext());
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

bool SortedLinkedList::contains(int item) const
{
	Node* current = head;

	while (current != nullptr && current->getItem() <= item)
	{
		if (current->getItem() == item)
			return true;
		current = current->getNext();
	}

	return false;
}

bool SortedLinkedList::isEmpty() const
{
	return head == nullptr;
}

SortedLinkedList SortedLinkedList::merge(SortedLinkedList& other)
{
	SortedLinkedList result;

	Node* current1 = this->head;

	while (current1 != nullptr)
	{
		int currentItem = current1->getItem();

		if (!result.contains(currentItem))
		{
			result.addItem(current1->getItem());
		}
		current1 = current1->getNext();
	}

	Node* current2 = other.head;

	while (current2 != nullptr)
	{
		int currentItem = current2->getItem();

		if (!result.contains(currentItem))
		{
			result.addItem(current2->getItem());
		}
		current2 = current2->getNext();
	}

	return result;
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