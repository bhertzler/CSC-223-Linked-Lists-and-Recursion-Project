// SplitLinkedList.h: this is the specification file for the SplitLinkedList class.
//

// Benjamin Hertzler
// CSC 223
// Linked List and Recursion Project
//

#pragma once
#include "SinglyLinkedList.h"

class SplitLinkedList : public SinglyLinkedList<int>
{
public:
	// Function to split the list into separate even and odd lists.
	// Preconditions: evenList and oddList are empty SinglyLinkedList int lists
	//		The SplitLinkedList object is a list of even and odd ints
	// Postconditions: evenList will be populated with all even ints in the initial list
	//		oddList will be populated with all odd ints in the initial list
	//		the initial list will be cleared and replaced with nullptrs
	//
	void splitEvensOdds(SinglyLinkedList<int>& evenList, SinglyLinkedList<int>& oddList);

	// Default Constructor
	SplitLinkedList() {}

private:
	// Private internal function used for cleanup
	// Postcondition: The size of the SplitLinkedList object will be set to 0
	//		The head and tail nodes will be replaced with nullptr
	//
	void cleanup();
};

