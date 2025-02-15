// test-client.cpp: test program for the SinglyLinkedList class, this file contains the main() function.
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
	SinglyLinkedList<int> fwd_list;
	SinglyLinkedList<int> bck_list;
	
	// Build Backward
	for (int i = 1; i < 6; i++)
	{
		int num = i * 10;
		bck_list.insertAtBeginning(num);
	}
	cout << "Backward List: " << endl;
	bck_list.print();

	// Delete first element
	bck_list.deleteNode(50);
	cout << "Delete the first node: " << endl;
	bck_list.print();

	// Delete last element
	bck_list.deleteNode(10);
	cout << "Delete the last node: " << endl;
	bck_list.print();

	// Delete interior element
	bck_list.deleteNode(30);
	cout << "Delete the middle node: " << endl;
	bck_list.print();

	// Build Forward
	for (int i = 1; i < 6; i++)
	{
		int num = i * 10;
		fwd_list.insertAtEnd(num);
	}
	cout << "Forward List: " << endl;
	fwd_list.print();

	// Delete the first element
	fwd_list.deleteNode(10);
	cout << "Delete the first node: " << endl;
	fwd_list.print();

	// Delete last element
	fwd_list.deleteNode(50);
	cout << "Delete the last node: " << endl;
	fwd_list.print();

	// Delete interior element
	fwd_list.deleteNode(30);
	cout << "Delete the middle node: " << endl;
	fwd_list.print();
}
