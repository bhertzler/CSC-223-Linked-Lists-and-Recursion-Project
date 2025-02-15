// test-client.cpp: test program for the SinglyLinkedList class, this file contains the 'main' function.
//

// Benjamin Hertzler
// CSC 223
// Linked Lists and Recursion Project
//

#include "SinglyLinkedList.h"
#include <iostream>
using namespace std;

int main()
{
	SinglyLinkedList<int> list;

	for (int i = 1; i < 11; i++)
	{
		list.insertAtEnd(i * 5);
	}

	cout << "Print the list:" << endl;
	list.print();

	cout << "Reverse print the list:" << endl;
	list.reversePrint();

	return 0;
}

