// SinglyLinkedList.h: this is the specification file for the SinglyLinkedList class.
//

// Benjamin Hertzler
// CSC 223
// Linked Lists and Recursion Project
//

#pragma once
#include <string>

//template<typename T>


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
	~SinglyLinkedList();

	// Public Functions

	// Function to build a backward list.
	// Precondition: The value of the data field is supplied
	// Postcondition: If list is empty, a new node is created
	// and head points to new node, otherwise, a new node
	// is created and is added to the beginning of the list
	//
	void insertAtBeginning(T value);

	// Function to build a forward list.
	// Precondition: The value of the data field is supplied
	// Postcondition: If list is empty, a new node is created
	// and head points to new node, otherwise, a new node
	// is created and is added to the end of the list
	//
	void insertAtEnd(T value);

	// Function to insert a node into the interior of the list.
	// Precondition: The values of the node to insert after
	// and the new node are supplied
	// Postcondition: A new node is created and is added
	// to the list after the node with the value supplied
	// If the list is empty, or the supplied node is not found,
	// an exception is thrown
	//
	void insertAfter(T afterValue, T newValue)
		throw (EmptyListException, NodeNotFoundException);

	// Function to remove the first node with a specified value.
	// Precondition: The value of the node to be removed is supplied
	// Postcondition: The node is removed from the list and the
	// memory for that node is released
	// If the list is empty, or the supplied node is not found
	// an exception is thrown
	//
	void deleteNode(T value)
		throw (EmptyListException, NodeNotFoundException);

	// Function to display the list.
	// Postcondition: Displays the value of each
	// info field starting with the first node and
	// ending with the last node
	// If the list is empty, an exception is thrown
	//
	void print() throw (EmptyListException);

private:
	// Creates a new node in the list with a .data info field and .next pointer
	struct Node
	{
		T data;
		Node* next;

		// Default Constructor
		Node(int value = 0) : data(value), next(nullptr) {}
	};
	Node* head;			// Pointer to first node.
};

#include "SinglyLinkedList.cpp"