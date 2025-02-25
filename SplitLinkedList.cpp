// SplitLinkedList.cpp: this file contains the implementation of the SplitLinkedList class
//

// Benjamin Hertzler
// CSC 223
// Linked List and Recursion Project
//

#include "SplitLinkedList.h"
#include <iostream>
using namespace std;

void SplitLinkedList::splitEvensOdds(SplitLinkedList& evenList, SplitLinkedList& oddList)
{
	Node<int>* cursor = new Node<int>;
	Node<int>* link = new Node<int>;
	cursor = head;
	while (cursor != nullptr)
	{
		link = cursor->next;
		if (cursor->data % 2 == 0)
			moveNode(cursor, evenList);
		else
			moveNode(cursor, oddList);
		cursor = link;
	}
	cleanup();
}

void SplitLinkedList::moveNode(Node<int>* current, SplitLinkedList& target_list)
{
	if (target_list.length() == 0)
		target_list.head = current;
	else
		target_list.tail->next = current;
	target_list.tail = current;
	target_list.size++;
	target_list.tail->next = nullptr;
	current->next = nullptr;
}

void SplitLinkedList::cleanup()
{
	head = nullptr;
	tail = nullptr;
	size = 0;
}