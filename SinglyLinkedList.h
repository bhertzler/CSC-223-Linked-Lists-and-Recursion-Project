// SinglyLinkedList.h: this is the specification file for the SinglyLinkedList class.
//

// Benjamin Hertzler
// CSC 223
// Linked Lists and Recursion Project
//

#pragma once
#include <string>
#include <iostream>

// Creates a new node in the list with a .data info field and .next pointer
template<typename T>
struct Node
{
	T data;				// Info field for the list element
	Node* next;			// Link pointer for next element

	// Constructors

	// Default Constructor
	Node() : next(nullptr) {}
	// Constructor with Parameter
	Node(T value) : data(value), next(nullptr) {}
};

template<typename T>
class SinglyLinkedList
{
public:

	// Exception Classes

	class EmptyListException
	{
	public:
		EmptyListException() { message = "List is empty."; }
		std::string what() { return message; }
	private:
		std::string message;
	};

	class NodeNotFoundException
	{
	public:
		NodeNotFoundException() { message = "Node not found in list."; }
		std::string what() { return message; }
	private:
		std::string message;
	};
	
	// Default Constructor 
	// Postcondition: Initializes head to nullptr
	//
	SinglyLinkedList() : head(nullptr) {}

	// Destructor
	// Postcondition: Deletes all nodes
	//
	~SinglyLinkedList()
	{
		Node<T>* temp;
		while (head)
		{
			temp = head;
			head = head->next;
			delete temp;
		}
	}

	// Public Functions

	// Function to build a backward list.
	// Precondition: The value of the data field is supplied
	// Postcondition: If list is empty, a new node is created
	// and head points to new node, otherwise, a new node
	// is created and is added to the beginning of the list
	//
	void insertAtBeginning(T value)
	{
		Node<T>* p = new Node<T>;
		p->data = value;
		p->next = nullptr;
		if (head == nullptr)
		{
			head = p;
		}
		else
		{
			p->next = head;
			head = p;
		}
	}

	// Function to build a forward list.
	// Precondition: The value of the data field is supplied
	// Postcondition: If list is empty, a new node is created
	// and head points to new node, otherwise, a new node
	// is created and is added to the end of the list
	//
	void insertAtEnd(T value)
	{
		Node<T>* p = new Node<T>;
		p->data = value;
		p->next = nullptr;
		if (head == nullptr)
		{
			head = p;
		}
		else
		{
			Node<T>* prev = nullptr;
			Node<T>* h = head;
			while (h != nullptr)
			{
				prev = h;
				h = h->next;
			}
			prev->next = p;
		}
	}

	// Function to insert a node into the interior of the list.
	// Precondition: The values of the node to insert after
	// and the new node are supplied
	// Postcondition: A new node is created and is added
	// to the list after the node with the value supplied
	// If the list is empty, or the supplied node is not found,
	// an exception is thrown
	//
	void insertAfter(T afterValue, T newValue)
		throw (EmptyListException, NodeNotFoundException)
	{
		Node<T>* a;
		if (head == nullptr)
			throw EmptyListException();
		a = head;
		while (a != nullptr && a->data != afterValue)
			a = a->next;
		if (a == nullptr)
			throw NodeNotFoundException();
		else
		{
			Node<T>* p;
			p = new Node<T>;
			p->data = newValue;
			p->next = a->next;
			a->next = p;
		}
	}

	// Function to remove the first node with a specified value.
	// Precondition: The value of the node to be removed is supplied
	// Postcondition: The node is removed from the list and the
	// memory for that node is released
	// If the list is empty, or the supplied node is not found
	// an exception is thrown
	//
	void deleteNode(T value)
		throw (EmptyListException, NodeNotFoundException)
	{
		Node<T>* prev, * p, * q;
		if (head == nullptr)
			throw EmptyListException();
		if (head->data == value)
		{
			p = head;
			head = head->next;
			delete p;
		}
		else
		{
			prev = nullptr;
			p = head;
			while (p != nullptr && p->data != value)
			{
				if (p->next != nullptr)
					prev = p;
				p = p->next;
			}
			if (p == nullptr)
				throw NodeNotFoundException();
			else if (prev->next->next == nullptr)
			{
				q = prev->next;
				prev->next = nullptr;
				delete q;
			}
			else
			{
				q = prev->next;
				prev->next = prev->next->next;
				delete q;
			}

		}
	}

	// Function to display the list.
	// Postcondition: Displays the value of each
	// info field starting with the first node and
	// ending with the last node
	// If the list is empty, an exception is thrown
	//
	void print() throw (EmptyListException)
	{
		if (head == nullptr)
			throw EmptyListException();
		Node<T>* p = head;
		while (p != nullptr)
		{
			std::cout << p->data << " -> ";
			p = p->next;
		}
		std::cout << std::endl;
	}

private:
	Node<T>* head;			// Pointer to first node.
};