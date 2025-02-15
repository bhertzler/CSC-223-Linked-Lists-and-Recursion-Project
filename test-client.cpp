// test-client.cpp: test program for the SinglyLinkedList class, this file contains the 'main' function.
//

// Benjamin Hertzler
// CSC 223
// Linked Lists and Recursion Project
//

#include "SinglyLinkedList.h"
#include "SplitLinkedList.h"
#include <string>
#include <iostream>
using namespace std;

int main()
{
	SplitLinkedList list;
	SinglyLinkedList<int> evens;
	SinglyLinkedList<int> odds;

	string input;
	cout << "Enter a list of integers, enter '.' to finish." << endl;
	cin >> input;
	while (input != ".")
	{
		for (char ch : input)
		{
			if (!isdigit(ch))
			{
				cerr << "Invalid Input." << endl;
				return -1;
			}
		}
		list.insertAtEnd(stoi(input));
		cin >> input;
	}

	cout << "Your List (" << list.length() << " items): ";
	try { list.print(); }
	catch (SinglyLinkedList<int>::EmptyListException e)
	{
		cout << e.what() << endl;
		return 0;
	}

	

	list.splitEvensOdds(evens, odds);

	cout << "Evens List (" << evens.length() << " items): ";
	evens.print();

	cout << "Odds List(" << odds.length() << " items): ";
	odds.print();

	cout << "List (" << list.length() << " items): ";
	try { list.print(); }
	catch (SinglyLinkedList<int>::EmptyListException e)
	{
		cout << e.what() << endl;
		return 0;
	}

	return 0;
}

