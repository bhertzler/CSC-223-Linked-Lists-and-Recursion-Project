// SplitLinkedList.cpp: this file contains the implementation of the SplitLinkedList class
//

// Benjamin Hertzler
// CSC 223
// Linked List and Recursion Project
//

#include "SplitLinkedList.h"

void SplitLinkedList::splitEvensOdds(SinglyLinkedList<int>& evenList, SinglyLinkedList<int>& oddList)
{
	Node<int>* cursor = new Node<int>;
	cursor = head;
	while (cursor != nullptr)
	{
		if (cursor->data % 2 == 0)
			evenList.insertAtEnd(cursor->data);
		else
			oddList.insertAtEnd(cursor->data);
		cursor = cursor->next;
	}
	cleanup();
}

void SplitLinkedList::cleanup()
{
	head = nullptr;
	tail = nullptr;
	size = 0;
}