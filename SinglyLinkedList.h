// SinglyLinkedList.h: this is the specification file and inline implementation for the SinglyLinkedList class.
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
	T data{};				// Info field for the list element
	Node* next;				// Link pointer for next element

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
	
	// Friend Classes

	friend class SplitLinkedList;
	
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
	SinglyLinkedList() : head(nullptr), tail(nullptr), size(0) {}

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
			head = tail = p;
		}
		else
		{
			p->next = head;
			head = p;
		}
		++size;
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
			head = tail = p;
		}
		else
		{
			tail->next = p;
			tail = p;
		}
		++size;
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
			if (head == nullptr)
				tail = nullptr;
			delete p;
			--size;
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
			else if (prev->next == tail)
			{
				q = tail;
				prev->next = nullptr;
				delete q;
				tail = prev;
				--size;
			}
			else
			{
				q = prev->next;
				prev->next = prev->next->next;
				delete q;
				--size;
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
		std::cout << "Head -> ";
		Node<T>* p = head;
		while (p != nullptr)
		{
			std::cout << p->data << " -> ";
			p = p->next;
		}
		std::cout << "nullptr" << std::endl;
	}

	// Function to display the list in reverse order.
	// Postcondition: Displays the value of each
	// info field starting with the last node and
	// ending with the first node
	// If the list is empty, an exception is thrown
	//
	void reversePrint() throw (EmptyListException)
	{
		if (head == nullptr)
			throw EmptyListException();
		reversePrint(head);
		std::cout << "Head" << std::endl;
	}

	// Function to return the total number of elements in the list.
	size_t length() const { return size; }

private:
	// Private Member Functions

	// Private recursive function to display the list in reverse order
	//		(Recursive overload of the public reversePrint function)
	//
	void reversePrint(Node<T>* p)
	{
		if (p != nullptr)
		{
			reversePrint(p->next);
			std::cout << p->data << " <- ";
		}
		else
			std::cout << "nullptr <- ";
	}

	// Private Instance Variables

	Node<T>* head;			// Pointer to the first node
	Node<T>* tail;			// Pointer to the last node
	size_t size;			// Total number of elements in the list
};