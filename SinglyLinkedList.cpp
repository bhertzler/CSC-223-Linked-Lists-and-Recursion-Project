// SinglyLinkedList.cpp: this file contains the implementation for the SinglyLinkedList class.
//

// Benjamin Hertzler
// CSC 223
// Linked Lists and Recursion Project
//

#pragma once

#include "SinglyLinkedList.h"
#include <string>
#include <iostream>
using namespace std;

template <typename T>
SinglyLinkedList<T>::~SinglyLinkedList()
{
	Node* temp;
	while (head)
	{
		temp = head;
		head = head->next;
		delete temp;
	}
}

template <typename T>
void SinglyLinkedList<T>::insertAtBeginning(T value)
{
	Node* p = new Node;
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

template <typename T>
void SinglyLinkedList<T>::insertAtEnd(T value)
{
	Node* p = new Node;
	p->data = value;
	p->next = nullptr;
	if (head == nullptr)
	{
		head = p;
	}
	else
	{
		Node* prev = nullptr;
		Node* h = head;
		while (h != nullptr)
		{
			prev = h;
			h = h->next;
		}
		prev->next = p;
	}
}

template <typename T>
void SinglyLinkedList<T>::insertAfter(T afterValue, T newValue) 
	throw (EmptyListException, NodeNotFoundException)
{
	Node* a;
	if (head == nullptr)
		throw EmptyListException();
	a = head;
	while (a != nullptr && a->data != afterValue)
		a = a->next;
	if (a == nullptr)
		throw NodeNotFoundException();
	else
	{
		Node* p;
		p = new Node;
		p->data = newValue;
		p->next = a->next;
		a->next = p;
	}
}

template <typename T>
void SinglyLinkedList<T>::deleteNode(T value) 
	throw (EmptyListException, NodeNotFoundException)
{
	Node* prev, * p, * q;
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

template <typename T>
void SinglyLinkedList<T>::print()
throw (EmptyListException)
{
	if (head == nullptr)
		throw EmptyListException();
	Node* p = head;
	while (p != nullptr)
	{
		cout << p->data << " -> ";
		p = p->next;
	}
	cout << endl;
}
